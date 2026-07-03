#include "diferenca.h"
#include "ui_diferenca.h"

#include <QTextEdit>
#include <QString>
#include <QStringList>
#include <QScrollBar>
#include <QtSql>

int idB; // id do bloco
int idD; // id do Diff
QString tituloOriginal;
QString textoOriginal;

QString tituloDiff;
QString textoDiff;

int idUserDiff;

diferenca::diferenca(int idBloco,int idDiff,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::diferenca)
{
    ui->setupUi(this);

    idB = idBloco;
    idD = idDiff;

    chamandoBanco();
    chamandoDiff();
    chamandoUser();

    ui->leOriginal->setText(tituloOriginal);
    ui->txtOriginal->setText(textoOriginal);

    ui->leDiff->setText(tituloDiff);
    ui->txtDiff->setText(textoDiff);


    compararTextos();
    comparaTitulo();

    ui->leOriginal->setReadOnly(true);
    ui->txtOriginal->setReadOnly(true);
    ui->leDiff->setReadOnly(true);
    ui->txtDiff->setReadOnly(true);
    ui->cbTitulo->setAttribute(Qt::WA_TransparentForMouseEvents, true);//não deixa o mouse interagir com o Check Box
    ui->cbEditavel->setAttribute(Qt::WA_TransparentForMouseEvents, true);
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
    abreDiff.prepare("SELECT nome,bloco,userPropId FROM diffInfo WHERE id = :id");
    abreDiff.bindValue(":id", idD);

    if(abreDiff.exec()){

        if(abreDiff.next()){

            tituloDiff = abreDiff.value(0).toString();
            textoDiff = abreDiff.value(1).toString();
            idUserDiff = abreDiff.value(2).toInt();
        }

    }else{

        qDebug() << "Erro ao executar chamandoDiff:" << abreDiff.lastError().text();

    }

}

void diferenca::chamandoUser(){

    QSqlQuery solicitaNome;
    solicitaNome.prepare("SELECT Usuario FROM Users WHERE id = :id");
    solicitaNome.bindValue(":id", idUserDiff);

    if(solicitaNome.exec()){

        if(solicitaNome.next()){

            ui->nomeUsuario->setText("Usuario que alterou: " + solicitaNome.value(0).toString());

        }

    }else{

        qDebug() << "Erro ao executar SolicitaNome:" << solicitaNome.lastError().text();

    }


}

void diferenca::comparaTitulo(){

    if(tituloOriginal == tituloDiff){

        ui->cbTitulo->setChecked(true);
        qDebug() << "titulo true";
    }else{

        ui->cbTitulo->setChecked(false);
        qDebug() << "titulo false";

    }


}

void diferenca::compararTextos()
{
    // ------------------------------------------------------------------
    // TIPOS AUXILIARES (locais à função, só existem aqui dentro)
    // ------------------------------------------------------------------
    enum class TipoToken { Igual, Removido, Inserido };
    struct OperacaoDiff {
        TipoToken tipo;
        QString texto;
    };

    // ------------------------------------------------------------------
    // 1) CAPTURA DO TEXTO BRUTO (markdown) DOS DOIS QTextEdit
    //    Pega o texto ANTES de qualquer setHtml(), já que setHtml() muda
    //    o conteúdo interno do QTextEdit.
    // ------------------------------------------------------------------
    const QString textoOriginalBruto = ui->txtOriginal->toPlainText();
    const QString textoNovoBruto     = ui->txtDiff->toPlainText();

    // ------------------------------------------------------------------
    // 2) TOKENIZADOR (função auxiliar em forma de lambda)
    //    Quebra o texto em palavras e blocos de espaço/quebra de linha.
    // ------------------------------------------------------------------
    auto tokenizar = [](const QString &texto) -> QVector<QString> {
        QVector<QString> tokens;
        QString tokenAtual;
        bool tokenAtualEhEspaco = false;
        bool existeTokenAtual = false;

        for (const QChar &c : texto) {
            const bool ehEspaco = c.isSpace();
            if (!existeTokenAtual) {
                tokenAtual = c;
                tokenAtualEhEspaco = ehEspaco;
                existeTokenAtual = true;
            } else if (ehEspaco == tokenAtualEhEspaco) {
                tokenAtual += c;
            } else {
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
    // 3) LCS (Longest Common Subsequence) - tabela de programação dinâmica
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
    // 4) BACKTRACK na tabela dp reconstruindo o que ficou Igual, foi
    //    Removido ou foi Inserido.
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
    // 5) AGRUPAMENTO EM BLOCOS DE MUDANÇA ("hunks"), já separando o texto
    //    removido do texto inserido de cada bloco. Os trechos "Igual" são
    //    descartados - só delimitam onde um bloco de mudança termina.
    // ------------------------------------------------------------------
    QVector<QString> hunksRemovido; // texto removido de cada bloco (pode ser "" se o bloco só teve inserção)
    QVector<QString> hunksInserido; // texto inserido de cada bloco (pode ser "" se o bloco só teve remoção)

    for (int i = 0; i < operacoes.size(); ) {
        if (operacoes[i].tipo == TipoToken::Igual) {
            ++i; // trecho igual: não entra no resultado, só delimita blocos
            continue;
        }

        QString removidoConcat;
        QString inseridoConcat;
        while (i < operacoes.size() && operacoes[i].tipo != TipoToken::Igual) {
            if (operacoes[i].tipo == TipoToken::Removido)
                removidoConcat += operacoes[i].texto;
            else
                inseridoConcat += operacoes[i].texto;
            ++i;
        }

        hunksRemovido.append(removidoConcat);
        hunksInserido.append(inseridoConcat);
    }

    // ------------------------------------------------------------------
    // 6) MONTAGEM DO HTML
    //    Função auxiliar reaproveitada pros dois lados (remoção/inserção):
    //    escapa o texto, pula blocos vazios (que não têm nada relevante
    //    pra esse lado) e separa blocos com linha em branco.
    // ------------------------------------------------------------------
    auto escaparEQuebrarLinha = [](const QString &texto) -> QString {
        QString escapado = texto.toHtmlEscaped();
        escapado.replace(QLatin1Char('\n'), QStringLiteral("<br>"));
        return escapado;
    };

    auto montarHtmlLado = [&](const QVector<QString> &blocos,
                              const QString &corHex,
                              const QString &decoracao) -> QString {
        QString html = QStringLiteral("<div style=\"white-space:pre-wrap;\">");
        bool algumBlocoValido = false;
        for (const QString &bloco : blocos) {
            if (bloco.isEmpty()) continue; // bloco sem conteúdo desse lado -> pula
            if (algumBlocoValido) html += QStringLiteral("<br><br>");
            algumBlocoValido = true;
            const QString textoEscapado = escaparEQuebrarLinha(bloco);
            html += QStringLiteral("<span style=\"color:%1; text-decoration: %2;\">%3</span>")
                        .arg(corHex, decoracao, textoEscapado);
        }
        if (!algumBlocoValido) {
            html += QStringLiteral("<i>Nenhuma alteração encontrada.</i>");
        }
        html += QStringLiteral("</div>");
        return html;
    };

    // vermelho tachado = removido | amarelo sublinhado = inserido
    const QString htmlOriginal = montarHtmlLado(hunksRemovido, QStringLiteral("#C62828"), QStringLiteral("line-through"));
    const QString htmlDiff     = montarHtmlLado(hunksInserido, QStringLiteral("#FDD835"), QStringLiteral("underline"));

    // ------------------------------------------------------------------
    // 7) APLICA O RESULTADO NA UI
    // ------------------------------------------------------------------
    ui->txtOriginal->setHtml(htmlOriginal);
    ui->txtDiff->setHtml(htmlDiff);
}
