#include "historico.h"
#include "ui_historico.h"

#include <QtSql>
#include <QMessageBox>

int bloco;

Historico::Historico(int idBloco,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Historico)
{
    ui->setupUi(this);

    bloco = idBloco;

    carregadados();

}

Historico::~Historico()
{
    delete ui;
}


void Historico::carregadados(){

    int linhas = 0;

    QSqlQuery pDados;

    pDados.prepare("select nome,andamento,data,horas,id,dataFinalizado from diffInfo WHERE idBloco = :idBloco");
    pDados.bindValue(":idBloco", bloco);

    if(pDados.exec()){

        while(pDados.next()){

            int idBanco = pDados.value(3).toInt();

            QString lista;

            if(linhas < 1){//caso seja o primeiro, ai aparece quando foi criado

                lista = "Criado: " + pDados.value(2).toString() +
                                " " +
                                pDados.value(3).toString();

            }else{
                if(pDados.value(0).toString() == ""){

                    lista = QString::number(linhas) + " - Tabulação: " + pDados.value(1).toString() + " | " +
                            pDados.value(5).toString() ;

                }else{

                    lista = QString::number(linhas) + " - Mudado Informações bloco | " +
                            pDados.value(2).toString() +
                            " " +
                            pDados.value(3).toString();

                }


            }


            QListWidgetItem *bInterno = new QListWidgetItem(lista,ui->lwHistorico);
            bInterno->setSizeHint(QSize(0, 30));
            bInterno->setTextAlignment(Qt::AlignCenter);
            //bInterno->setBackground(QColor(Qt::darkYellow));
            bInterno->setData(Qt::UserRole,idBanco);

            linhas++;
        }

    }else{

        qDebug() << "Erro exec";

    }


}