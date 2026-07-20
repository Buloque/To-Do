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
    abreDiff.prepare("SELECT nome,bloco,userEditId FROM diffInfo WHERE id = :id");
    abreDiff.bindValue(":id", idD);

    if(abreDiff.exec()){

        if(abreDiff.next()){

            tituloDiff = abreDiff.value(0).toString();
            textoDiff = abreDiff.value(1).toString();
            idUserDiff = abreDiff.value(2).toInt();

            qDebug() << textoDiff;
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
    // Um bloco de mudança já separado em "o que saiu" e "o que entrou".
    struct Hunk {
        QString removido;
        QString inserido;
    };

    // ------------------------------------------------------------------
    // 1) CAPTURA DO TEXTO BRUTO (markdown) DOS DOIS QTextEdit
    // ------------------------------------------------------------------
    const QString textoOriginalBruto = ui->txtOriginal->toPlainText();
    const QString textoNovoBruto     = ui->txtDiff->toPlainText();

    // ------------------------------------------------------------------
    // 2) TOKENIZADOR: quebra o texto em palavras e blocos de espaço/quebra
    //    de linha.
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
    // 5) AGRUPAMENTO EM BLOCOS DE MUDANÇA ("hunks")
    //    Só uma palavra IGUAL de verdade fecha um bloco. Um espaço igual
    //    fica "pendente": se depois dele vier mais mudança real, o espaço
    //    entra nos dois lados (mantendo a frase fluindo); se depois vier
    //    uma palavra igual (ou acabar o texto), o espaço pendente é
    //    descartado - ele não fazia parte de nenhuma mudança de verdade.
    // ------------------------------------------------------------------
    auto ehTokenDeEspaco = [](const QString &s) {
        return !s.isEmpty() && s.at(0).isSpace();
    };

    QVector<Hunk> hunks;
    {
        QString removidoAtual;
        QString inseridoAtual;
        bool hunkAberto = false;
        QString espacosPendentes;

        auto fecharBloco = [&]() {
            if (hunkAberto) {
                hunks.append({removidoAtual, inseridoAtual});
                removidoAtual.clear();
                inseridoAtual.clear();
                hunkAberto = false;
            }
            espacosPendentes.clear();
        };

        for (const OperacaoDiff &op : operacoes) {
            if (op.tipo == TipoToken::Igual) {
                if (ehTokenDeEspaco(op.texto)) {
                    if (hunkAberto) {
                        espacosPendentes += op.texto; // decide depois
                    }
                } else {
                    fecharBloco(); // palavra igual de verdade
                }
            } else {
                if (hunkAberto && !espacosPendentes.isEmpty()) {
                    removidoAtual += espacosPendentes;
                    inseridoAtual += espacosPendentes;
                    espacosPendentes.clear();
                }
                hunkAberto = true;
                if (op.tipo == TipoToken::Removido)
                    removidoAtual += op.texto;
                else
                    inseridoAtual += op.texto;
            }
        }
        fecharBloco();
    }

    // ------------------------------------------------------------------
    // 6) MONTAGEM DO HTML
    //    txtOriginal: mostra só o "removido" de cada bloco, em vermelho.
    //    txtDiff: mostra só o "inserido" de cada bloco - amarelo se o
    //    bloco também tinha remoção (substituição), verde se foi inserção
    //    pura (nada removido nesse bloco).
    // ------------------------------------------------------------------
    auto escaparEQuebrarLinha = [](const QString &texto) -> QString {
        QString escapado = texto.toHtmlEscaped();
        escapado.replace(QLatin1Char('\n'), QStringLiteral("<br>"));
        return escapado;
    };

    QString htmlOriginal = QStringLiteral("<div style=\"white-space:pre-wrap;\">");
    {
        bool algumBlocoValido = false;
        for (const Hunk &h : hunks) {
            if (h.removido.isEmpty()) continue; // nada removido nesse bloco -> nao aparece aqui
            if (algumBlocoValido) htmlOriginal += QStringLiteral("<br><br>");
            algumBlocoValido = true;
            htmlOriginal += QStringLiteral("<span style=\"color:#C62828; text-decoration: line-through;\">%1</span>")
                                .arg(escaparEQuebrarLinha(h.removido));
        }
        if (!algumBlocoValido) {
            htmlOriginal += QStringLiteral("<i>Nenhuma alteração encontrada.</i>");
        }
    }
    htmlOriginal += QStringLiteral("</div>");

    QString htmlDiff = QStringLiteral("<div style=\"white-space:pre-wrap;\">");
    {
        bool algumBlocoValido = false;
        for (const Hunk &h : hunks) {
            if (h.inserido.isEmpty()) continue; // nada inserido nesse bloco -> nao aparece aqui
            if (algumBlocoValido) htmlDiff += QStringLiteral("<br><br>");
            algumBlocoValido = true;
            // amarelo = substituição (também tinha remoção) | verde = inserção pura
            const QString corHex = h.removido.isEmpty() ? QStringLiteral("#66BB6A") : QStringLiteral("#FDD835");
            htmlDiff += QStringLiteral("<span style=\"color:%1; text-decoration: underline;\">%2</span>")
                            .arg(corHex, escaparEQuebrarLinha(h.inserido));
        }
        if (!algumBlocoValido) {
            htmlDiff += QStringLiteral("<i>Nenhuma alteração encontrada.</i>");
        }
    }
    htmlDiff += QStringLiteral("</div>");

    // ------------------------------------------------------------------
    // 7) APLICA O RESULTADO NA UI
    // ------------------------------------------------------------------
    ui->txtOriginal->setHtml(htmlOriginal);
    ui->txtDiff->setHtml(htmlDiff);
}
