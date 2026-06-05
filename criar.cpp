#include "criar.h"
#include "ui_criar.h"

#include <QDateTime> // para pegar a data

QFont fonte;

criar::criar(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::criar)
{
    ui->setupUi(this);
    subtextos();
}

criar::~criar()
{

    delete ui;

}

void criar::subtextos(){

    ui->leTitulo->setPlaceholderText("Titulo");
    ui->texto->setPlaceholderText("Escreva suas notas aqui");

    //atualiza para o mesmo horario que o do usuario
    ui->timeEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateEdit->setDateTime(QDateTime::currentDateTime());


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

        fonte.setStrikeOut(true);
        ui->texto->setCurrentFont(fonte);

    }else{

        fonte.setStrikeOut(false);
        ui->texto->setCurrentFont(fonte);

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
    ui->texto->setCurrentFont(fonte);

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

