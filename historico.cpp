#include "historico.h"
#include "ui_historico.h"

#include <QtSql>
#include <QMessageBox>
#include <QListWidgetItem>

#include "diferenca.h"

int bloco;
int user;
int bSelecionado;
int editTab;

Historico::Historico(int idBloco,int idUser,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Historico)
{
    ui->setupUi(this);

    bloco = idBloco;
    user = idUser;
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

            int idBanco = pDados.value(4).toInt();

            QString lista;
            QString emoji;

            if(pDados.value(1).toInt() == 1){//finalizado

                emoji = "🚩";

            }else if(pDados.value(1).toInt() == 2){//cancelado

                emoji = "❌";

            }else{//andamento

                emoji = "🚶";

            }

            if(linhas < 1){//caso seja o primeiro, ai aparece quando foi criado

                lista = "Criado: " + pDados.value(2).toString() +
                                " " +
                                pDados.value(3).toString();
                editTab = 0;

            }else{
                if(pDados.value(0).toString() == ""){


                    lista = QString::number(linhas) + " - Tabulação: " +
                            emoji + " | " +
                            pDados.value(5).toString() ;

                    editTab = 1;//caso o usuario esteja mudando apenas a tabulação

                }else{

                    lista = QString::number(linhas) + " - Mudado Informações bloco | " +
                            pDados.value(2).toString() +
                            " " +
                            pDados.value(3).toString();
                    editTab = 0;

                }


            }


            QListWidgetItem *bInterno = new QListWidgetItem(lista,ui->lwHistorico);
            bInterno->setSizeHint(QSize(0, 30));
            bInterno->setTextAlignment(Qt::AlignCenter);
            bInterno->setData(Qt::UserRole,idBanco);
            bInterno->setData(Qt::UserRole + 1,editTab);

            linhas++;
        }

    }else{

        qDebug() << "Erro exec";

    }



}



void Historico::on_lwHistorico_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (!current) return;

    bSelecionado = current->data(Qt::UserRole).toInt();
    editTab = current->data(Qt::UserRole + 1).toInt();

    //qDebug() << bSelecionado;
    //qDebug() << editTab;
}

void Historico::on_lwHistorico_itemDoubleClicked(QListWidgetItem *item)
{

    if(editTab == 0){

        diferenca abrirD(bloco,bSelecionado);

        abrirD.setModal(true);

        abrirD.exec();

    }else{

        QSqlQuery infAlt;
        infAlt.prepare("SELECT dataFinalizado,andamento FROM diffInfo WHERE id = :id");
        infAlt.bindValue(":id", bSelecionado);

        if(infAlt.exec()){

            while(infAlt.next()){

                if((infAlt.value(1).toInt()) == 0){//andamento

                    QMessageBox::about(this,"Informações alteradas",
                                       "Alterado o andamento para: Em Andamento<br>"
                                        "Data Alterado: " + (infAlt.value(0).toString()));

                }else if((infAlt.value(1).toInt()) == 1){//Finalizado

                    QMessageBox::about(this,"Informações alteradas",
                                       "Alterado o andamento para: Finalizado<br>"
                                       "Data Alterado: " + (infAlt.value(0).toString()));

                }else if((infAlt.value(1).toInt()) == 2){//Cancelado

                    QMessageBox::about(this,"Informações alteradas",
                                       "Alterado o andamento para: Cancelado<br>"
                                       "Data Alterado: " + (infAlt.value(0).toString()));

                }

            }



        }else{//erro


        }

    }

}




void Historico::on_pushButton_clicked()
{

}

