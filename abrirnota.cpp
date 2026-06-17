#include "abrirnota.h"
#include "ui_abrirnota.h"

#include <QtSql>
#include <QMessageBox>

int idBloco;


void abrirNota::idNota(int id){

    ////retirar, não necessario

}

abrirNota::abrirNota(int id,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::abrirNota)
{
    ui->setupUi(this);

    idBloco = id;

    carregaDados();


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

            this->setWindowTitle(titulo);
            ui->bloco->setMarkdown(textoB);
            ui->DiaeHora->setText(dhFormatado);
            ui->cbUrgencia->setCurrentIndex(urgencia);
            ui->cbUrgencia->setEnabled(false);
            ui->cbAndamento->setCurrentIndex(andamento);

            //qDebug() << "Aviso: ID aberto banco: " << idBloco;

        }else{

            //Erro ao encontrar a ID
            qDebug() << "Aviso: Nenhum registro encontrado com o ID: " << idBloco;
        }

    }else{

        //erro ao executar a requesição
        qDebug() << "Erro ao executar o SELECT:" << abreNotas.lastError().text();

    }


}

void abrirNota::on_cbAndamento_currentIndexChanged(int index)
{

    qDebug() << index;

    QSqlQuery salvaAndamento;

    salvaAndamento.prepare("UPDATE infoUsers "
                       "SET andamento = :andamento WHERE id = :id ");
    salvaAndamento.bindValue(":andamento", index);
    salvaAndamento.bindValue(":id", idBloco);



    if(!salvaAndamento.exec()){

        QMessageBox::information(this,"atenção","não foi possivel salvar as informações.\n" + salvaAndamento.lastError().text());


    }


}

