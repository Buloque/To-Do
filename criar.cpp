#include "criar.h"
#include "ui_criar.h"

#include <QDateTime> // para pegar a data
#include <QMessageBox>
#include <QTextStream>
#include <QFileDialog>
#include <QtSql>

#include "pagina_inicial.h"

QFont fonte;
QFont orig; // Correção Strike
QFile arquivo;

int idRecuperada;

void criar::guardandoID(int ID){

    idRecuperada = ID;
    subtextos(); // trocado o local para carregar o ID antes de tudo.

}

criar::criar(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::criar)
{
    ui->setupUi(this);




}

criar::~criar()
{

    delete ui;

}

void criar::subtextos(){

    ui->leTitulo->setPlaceholderText("Titulo");
    ui->texto->setPlaceholderText("Escreva suas notas aqui");

    //atualiza para o mesmo horario que o do usuario

    //Criando variavel para receber utc
    QDateTime horaDiaAtual = QDateTime::currentDateTime();

    //pega o fuso horario do computador
    //bug - Horas sai errada
    //QTimeZone fuso = QTimeZone::systemTimeZone();
    //horaDiaAtual.setTimeSpec(Qt::LocalTime);

    //Coloca as horas como a de brasilia
    //horaDiaAtual.setTimeZone(fuso);

    ui->timeEdit->setDateTime(horaDiaAtual);
    ui->dateEdit->setDateTime(horaDiaAtual);




}

void criar::on_pbNegrito_clicked()
{

    if((veficaTexto()) == false){

        ui->texto->setFontWeight(QFont::Bold);

    }else{

        ui->texto->setFontWeight(QFont::Normal);

    }

}

void criar::on_pbItalic_clicked()
{

    if((veficaTexto()) == false){

        ui->texto->setFontItalic(true);

    }else{

        ui->texto->setFontItalic(false);

    }
}

void criar::on_pbStrikeOut_clicked()
{



    if((veficaTexto()) == false){

        orig = ui->texto->currentFont();//salva as caracteri do texto

        fonte.setStrikeOut(true);
        ui->texto->setCurrentFont(fonte);

    }else{

        //orig = ui->texto->currentFont();
        fonte.setStrikeOut(false);
        ui->texto->setCurrentFont(orig);//devolve as caracteristicas



    }

}

void criar::on_pbUnderline_clicked()
{

    if((veficaTexto()) == false){

        ui->texto->setFontUnderline(true);

    }else{

        ui->texto->setFontUnderline(false);

    }


}

bool criar::veficaTexto(){

    //pega o local no ponteiro no texto selecionado
    QTextCursor cursor = ui->texto->textCursor();

    //traduz o texto para char
    QTextCharFormat formato = cursor.charFormat();

    //extrai a configuração da fonte
    QFont fonte = formato.font();

    //Entrega qual a propriedade
    bool negrito = (fonte.weight() >= QFont::Bold);
    bool italic = fonte.italic();
    bool strike = fonte.strikeOut();
    bool underline = fonte.underline();



    if(negrito == true || italic == true || strike == true || underline == true){

        return true;

    }else{

        return false;

    }
}

void criar::on_pbReset_clicked()//deixa a letra normal
{

    ui->texto->setFontWeight(QFont::Normal);

    ui->texto->setFontItalic(false);

    fonte.setStrikeOut(false);
    ui->texto->setCurrentFont(orig);

    ui->texto->setFontUnderline(false);

}

void criar::on_pushButton_clicked()
{
    //salvar
}
void criar::on_pbDia_clicked()
{
    ui->dateEdit->setDateTime(QDateTime::currentDateTime());
}


void criar::on_pbHora_clicked()
{
    ui->timeEdit->setDateTime(QDateTime::currentDateTime());
}


void criar::on_texto_cursorPositionChanged(){
    //pega o local no ponteiro no texto selecionado
    QTextCursor cursor = ui->texto->textCursor();

    int linha = cursor.blockNumber();//numero da linha
    int coluna = cursor.columnNumber();//coluna

    ui->lblInfo->setText("Linha: " + QString::number(linha) + " coluna: "+ QString::number(coluna));
}

void criar::on_pbCancelar_clicked()
{
    //pega o local no ponteiro no texto selecionado
    QTextCursor cursor = ui->texto->textCursor();
    int coluna = cursor.columnNumber();

    QMessageBox::StandardButton conf;

    if(coluna > 1){

        conf = QMessageBox::question(this,"Aviso",
                             "Tem certeza que deseja sair?");

        if(conf == QMessageBox::Yes){

            this->close();
        }

    }else{

        this->close();

    }
}

int criar::verificaUrgencia(){

    QString urgString = ui->cbUrgencia->currentText();

    if(urgString == "🟢 Baixo"){

        return 0;

    }else if(urgString == "🟡 Médio"){

        return 1;

    }else if(urgString == "🟠 Alto"){

        return 2;

    }else if(urgString == "🔴 Urgente"){

        return 3;

    }

    return 0;

}

void criar::on_pbSalvar_clicked()
{


    QString nome = ui->leTitulo->text(); // cuidar o tipo de variavel que entrega, da erro se for o errado
    QString bloco = ui->texto->toPlainText();
    QString data =  ui->dateEdit->text();
    QString hora = ui->timeEdit->text();
    QString urgencia = QString::number(verificaUrgencia());

    // DEBUG - Mostre o conteúdo das variáveis
    qDebug() << "nome:" << nome;
    qDebug() << "bloco:" << bloco;
    qDebug() << "data:" << data;
    qDebug() << "hora:" << hora;
    qDebug() << "urgencia:" << urgencia;
    qDebug() << "nome está vazio?" << nome.isEmpty();

    QSqlQuery salvaBloco;

    salvaBloco.prepare("insert into infoUsers (nome,bloco,data,horas,urgencia,andamento,userPropId) "
                       "values ('"+nome+"','"+bloco+"','"+data+"','"+hora+"','"+urgencia+"',0,'"+QString::number(idRecuperada)+"')");
    //a urgencia recebe 0 para ficar como em andamento


    if(salvaBloco.exec()){

        QMessageBox::information(this,"atenção","Registro salvo com sucesso.");

        this->close();

    }else{
        //mostra o erro
        QMessageBox::information(this,"atenção","não foi possivel salvar as informações.\n" + salvaBloco.lastError().text());

    }

}





void criar::on_pbSalvarLocal_clicked()
{


    //////////////////////////////Salvar localmente
    QTextStream caminho;
    QString nomeArquivo;

    QString pegaNome = ui->leTitulo->text();

    Pagina_Inicial idPush;

    int id = idPush.idGuardada;

    nomeArquivo = QFileDialog::getSaveFileName(this,
                                               "Salvar",
                                               pegaNome,"Arquivo TXT (*.txt)");

    if(nomeArquivo.isEmpty()){


        return;
    }

    arquivo.setFileName(nomeArquivo);

    arquivo.open(QIODevice::WriteOnly | QIODevice::Text);

    if(!arquivo.isOpen()){

        QMessageBox::critical(this,"Aviso",
                              "Erro ao salvar o arquivo");

    }

    caminho.setDevice(&arquivo);

    caminho <<"Id:"+ QString::number(id) +" " + ui->cbUrgencia->currentText() + "  Data: " +  ui->dateEdit->text() + "  Hora: " + ui->timeEdit->text() + "\n\n" +
                   ui->texto->toPlainText();
    //<< ui->texto->toPlainText() +
    arquivo.close();

    //////////////////////////////Salvar localmente


}

