#include "diferenca.h"
#include "ui_diferenca.h"

#include <QTextEdit>
#include <QString>
#include <QStringList>
#include <algorithm>
#include <QScrollBar>
#include <QtSql>

int idB; // id do bloco
int idD; // id do Diff
QString tituloOriginal;
QString textoOriginal;

QString tituloDiff;
QString textoDiff;

diferenca::diferenca(int idBloco,int idDiff,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::diferenca)
{
    ui->setupUi(this);

    idB = idBloco;
    idD = idDiff;

    chamandoBanco();
    chamandoDiff();

    ui->leOriginal->setText(tituloOriginal);
    ui->txtOriginal->setText(textoOriginal);

    ui->leDiff->setText(tituloDiff);
    ui->txtDiff->setText(textoDiff);


    compararTextos();

    ui->leOriginal->setReadOnly(true);
    ui->txtOriginal->setReadOnly(true);
    ui->leDiff->setReadOnly(true);
    ui->txtDiff->setReadOnly(true);

}

diferenca::~diferenca()
{
    delete ui;
}



void diferenca::chamandoBanco(){

    QSqlQuery abrenota;
    abrenota.prepare("SELECT nome,bloco FROM infoUsers WHERE id = :id");
    abrenota.bindValue(":id", idB);

    if(abrenota.exec()){

        if(abrenota.next()){

            tituloOriginal = abrenota.value(0).toString();
            textoOriginal = abrenota.value(1).toString();

        }

    }else{

        qDebug() << "Erro ao executar chamando bloco:" << abrenota.lastError().text();

    }



}

void diferenca::chamandoDiff(){

    QSqlQuery abreDiff;
    abreDiff.prepare("SELECT nome,bloco FROM diffInfo WHERE id = :id");
    abreDiff.bindValue(":id", idD);

    if(abreDiff.exec()){

        if(abreDiff.next()){

            tituloDiff = abreDiff.value(0).toString();
            textoDiff = abreDiff.value(1).toString();

        }

    }else{

        qDebug() << "Erro ao executar chamandoDiff:" << abreDiff.lastError().text();

    }



}


void diferenca::compararTextos()
{
    // ------------------------------------------------------------------
    // TIPOS AUXILIARES (locais à função, só existem aqui dentro)
    // ------------------------------------------------------------------
    // Classifica cada token do diff:
    //  - Igual:    token idêntico presente nas duas versões
    //  - Removido: token que só existe no texto original
    //  - Inserido: token que só existe no texto novo (diff)
    enum class TipoToken { Igual, Removido, Inserido };

    // Um "passo" do diff: o tipo acima + o texto do próprio token.
    struct OperacaoDiff {
        TipoToken tipo;
        QString texto;
    };

    // ------------------------------------------------------------------
    // 1) COMPARAÇÃO DOS TÍTULOS (QLineEdit) + SINAL
    // ------------------------------------------------------------------
    const QString tituloOriginal = ui->leOriginal->text();
    const QString tituloDiff     = ui->leDiff->text();
    const bool tituloFoiAlterado = (tituloOriginal != tituloDiff);

    // ------------------------------------------------------------------
    // 2) CAPTURA DO TEXTO BRUTO (markdown) DOS DOIS QTextEdit
    //    Pega o texto ANTES de qualquer setHtml(), já que setHtml() muda
    //    o conteúdo interno do QTextEdit (e toPlainText() passaria a
    //    devolver outra coisa depois disso).
    // ------------------------------------------------------------------
    const QString textoOriginalBruto = ui->txtOriginal->toPlainText();
    const QString textoNovoBruto     = ui->txtDiff->toPlainText();

    // ------------------------------------------------------------------
    // 3) TOKENIZADOR (função auxiliar em forma de lambda)
    //    Quebra o texto em uma lista de pedaços: cada pedaço é OU uma
    //    palavra (sequência de caracteres que não são espaço) OU um bloco
    //    de espaços/tabs/quebras de linha. Guardar os espaços como tokens
    //    também é o que permite remontar o texto formatado igualzinho ao
    //    original na hora de gerar o HTML.
    // ------------------------------------------------------------------
    auto tokenizar = [](const QString &texto) -> QVector<QString> {
        QVector<QString> tokens;
        QString tokenAtual;
        bool tokenAtualEhEspaco = false;
        bool existeTokenAtual = false;

        for (const QChar &c : texto) {
            const bool ehEspaco = c.isSpace(); // cobre ' ', '\t', '\n', etc.
            if (!existeTokenAtual) {
                tokenAtual = c;
                tokenAtualEhEspaco = ehEspaco;
                existeTokenAtual = true;
            } else if (ehEspaco == tokenAtualEhEspaco) {
                // mesmo "tipo" (palavra continuando palavra, ou espaço
                // continuando espaço) -> acumula no token atual
                tokenAtual += c;
            } else {
                // mudou de palavra pra espaço (ou vice-versa) -> fecha o
                // token atual e começa um novo
                tokens.append(tokenAtual);
                tokenAtual = c;
                tokenAtualEhEspaco = ehEspaco;
            }
        }
        if (existeTokenAtual) {
            tokens.append(tokenAtual);
        }
        return tokens;
    };

    const QVector<QString> tokensOriginal = tokenizar(textoOriginalBruto);
    const QVector<QString> tokensNovo     = tokenizar(textoNovoBruto);

    // ------------------------------------------------------------------
    // 4) LCS (Longest Common Subsequence) - tabela de programação dinâmica
    //    dp[i][j] = tamanho da maior subsequência comum entre os primeiros
    //    i tokens do original e os primeiros j tokens do novo.
    // ------------------------------------------------------------------
    const int n = tokensOriginal.size();
    const int m = tokensNovo.size();

    QVector<QVector<int>> dp(n + 1, QVector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (tokensOriginal[i - 1] == tokensNovo[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // ------------------------------------------------------------------
    // 5) BACKTRACK na tabela dp (de trás pra frente) reconstruindo, token
    //    a token, o que ficou Igual, foi Removido ou foi Inserido. Sai na
    //    ordem invertida, por isso o std::reverse() no final do bloco.
    // ------------------------------------------------------------------
    QVector<OperacaoDiff> operacoes;
    {
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (tokensOriginal[i - 1] == tokensNovo[j - 1]) {
                operacoes.append({TipoToken::Igual, tokensOriginal[i - 1]});
                --i; --j;
            } else if (dp[i - 1][j] >= dp[i][j - 1]) {
                operacoes.append({TipoToken::Removido, tokensOriginal[i - 1]});
                --i;
            } else {
                operacoes.append({TipoToken::Inserido, tokensNovo[j - 1]});
                --j;
            }
        }
        while (i > 0) { operacoes.append({TipoToken::Removido, tokensOriginal[i - 1]}); --i; }
        while (j > 0) { operacoes.append({TipoToken::Inserido, tokensNovo[j - 1]});     --j; }
        std::reverse(operacoes.begin(), operacoes.end());
    }

    // ------------------------------------------------------------------
    // 6) REORDENAÇÃO POR BLOCOS ("hunks")
    //    A LCS pura, ao intercalar remoções/inserções, pode colocar a
    //    palavra NOVA antes da palavra ANTIGA riscada (tecnicamente
    //    correto, mas confuso de ler). Aqui a gente agrupa sequências
    //    consecutivas de Removido/Inserido e força a ordem "tachado antigo
    //    primeiro, sublinhado novo depois" - o padrão visual usado em
    //    controle de alterações (Word, Google Docs, etc.).
    // ------------------------------------------------------------------
    QVector<OperacaoDiff> operacoesOrdenadas;
    operacoesOrdenadas.reserve(operacoes.size());
    for (int i = 0; i < operacoes.size(); ) {
        if (operacoes[i].tipo == TipoToken::Igual) {
            operacoesOrdenadas.append(operacoes[i]);
            ++i;
            continue;
        }
        // início de um bloco de mudanças: acumula até achar o próximo
        // token Igual (ou o fim da lista de operações)
        QVector<OperacaoDiff> removidosDoBloco;
        QVector<OperacaoDiff> inseridosDoBloco;
        while (i < operacoes.size() && operacoes[i].tipo != TipoToken::Igual) {
            if (operacoes[i].tipo == TipoToken::Removido)
                removidosDoBloco.append(operacoes[i]);
            else
                inseridosDoBloco.append(operacoes[i]);
            ++i;
        }
        for (const auto &op : removidosDoBloco) operacoesOrdenadas.append(op);
        for (const auto &op : inseridosDoBloco) operacoesOrdenadas.append(op);
    }

    // ------------------------------------------------------------------
    // 7) MESCLAGEM DE TOKENS CONSECUTIVOS DO MESMO TIPO
    //    Só limpeza estética: "Muito" + " " (ambos Inserido, por ex.) viram
    //    uma única operação " Muito", gerando um <span> só em vez de vários
    //    grudados um no outro.
    // ------------------------------------------------------------------
    QVector<OperacaoDiff> operacoesFinais;
    operacoesFinais.reserve(operacoesOrdenadas.size());
    for (const OperacaoDiff &op : operacoesOrdenadas) {
        if (!operacoesFinais.isEmpty() && operacoesFinais.last().tipo == op.tipo) {
            operacoesFinais.last().texto += op.texto;
        } else {
            operacoesFinais.append(op);
        }
    }

    // ------------------------------------------------------------------
    // 8) MONTAGEM DO HTML FINAL
    //    Cada operação vira texto puro (Igual) ou um <span> colorido
    //    (Removido/Inserido). O texto de cada token é escapado (função
    //    auxiliar abaixo) antes de entrar no HTML, pra um "<", ">" ou "&"
    //    que exista no markdown bruto não ser interpretado como tag/
    //    entidade HTML.
    // ------------------------------------------------------------------

    // Função auxiliar: escapa caracteres especiais de HTML e converte
    // quebras de linha em <br>, já que HTML normal ignora '\n' puro.
    auto escaparEQuebrarLinha = [](const QString &texto) -> QString {
        QString escapado = texto.toHtmlEscaped(); // trata &, <, >, etc.
        escapado.replace(QLatin1Char('\n'), QStringLiteral("<br>"));
        return escapado;
    };

    // Cores do realce (fica livre pra ajustar caso queira combinar com o
    // tema da UI):
    //   #2E7D32 = verde escuro  -> texto inserido (sublinhado)
    //   #C62828 = vermelho escuro -> texto removido (tachado)
    QString htmlFinal;
    // white-space:pre-wrap preserva espaços múltiplos (útil p/ blocos de
    // código indentados em markdown) mantendo a quebra automática de linha.
    htmlFinal += QStringLiteral("<div style=\"white-space:pre-wrap;\">");
    for (const OperacaoDiff &op : operacoesFinais) {
        const QString textoEscapado = escaparEQuebrarLinha(op.texto);
        switch (op.tipo) {
        case TipoToken::Igual:
            htmlFinal += textoEscapado;
            break;
        case TipoToken::Removido:
            htmlFinal += QStringLiteral(
                             "<span style=\"color:#C62828; text-decoration: line-through;\">%1</span>"
                             ).arg(textoEscapado);
            break;
        case TipoToken::Inserido:
            htmlFinal += QStringLiteral(
                             "<span style=\"color:#2E7D32; text-decoration: underline;\">%1</span>"
                             ).arg(textoEscapado);
            break;
        }
    }
    htmlFinal += QStringLiteral("</div>");

    // ------------------------------------------------------------------
    // 9) APLICA O RESULTADO NA UI
    //    Só o txtDiff é reescrito (em HTML); txtOriginal continua exibindo
    //    o markdown puro, sem nenhuma marcação.
    // ------------------------------------------------------------------
    ui->txtDiff->setHtml(htmlFinal);
}
