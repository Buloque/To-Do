#include "abrirnota.h"
#include "ui_abrirnota.h"

#include <QtSql>

int idBloco = 0;

abrirNota::abrirNota(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::abrirNota)
{
    ui->setupUi(this);

    carregaDados();


}

void abrirNota::idNota(int id){

    idBloco = id;

}

abrirNota::~abrirNota()
{

    delete ui;

}

void abrirNota::carregaDados(){

    QSqlQuery abreNotas;
    abreNotas.prepare("SELECT nome,bloco,data,horas,urgencia,andamento FROM infoUsers WHERE id = :id");
    abreNotas.bindValue(":id", idBloco);
    //

    if(abreNotas.exec()){

        //verifica se encontrou o id
        if(abreNotas.next()){

            QString titulo = abreNotas.value(0).toString();
            QString textoB = abreNotas.value(1).toString();
            QString data = abreNotas.value(2).toString();
            QString horas = abreNotas.value(3).toString();
            QString dhFormatado = "Até dia " + data + " " + horas + " deve ser feito a tarefa";

            int urgencia = abreNotas.value(4).toInt();

            int andamento = abreNotas.value(5).toInt();

            ui->lblTitulo->setText(titulo);
            ui->bloco->setHtml(textoB);
            ui->DiaeHora->setText(dhFormatado);
            ui->cbUrgencia->setCurrentIndex(urgencia);
            ui->cbAndamento->setCurrentIndex(andamento);



        }else{

            //Erro ao encontrar a ID
            qDebug() << "Aviso: Nenhum registro encontrado com o ID.";
        }

    }else{

        //erro ao executar a requesição
        qDebug() << "Erro ao executar o SELECT:" << abreNotas.lastError().text();

    }


}
