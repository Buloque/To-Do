#include "pagina_inicial.h"
#include "ui_pagina_inicial.h"

#include <QtSql>
#include <QListWidget>
#include <QListWidgetItem>
#include <QSize>

#include <QMessageBox>

#include "criar.h"
#include "abrirnota.h"
#include "historico.h"

int idGuardada; // id do usuario
int idBlocoSelecionado; // id do bloco
int adm = 0;
int modo = 0;
int cAZ = 0;
int cData = 0;

QString nomeUser;

void Pagina_Inicial::guardandoID(int ID){


     // Função Não utilizada, apagar

}

Pagina_Inicial::Pagina_Inicial(int ID,QString user,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Pagina_Inicial)
{
    ui->setupUi(this);

    idGuardada = ID;



    ui->lblNome->setText("Usuário: " + nomeUser);//nomeUser

    carregarDados();
}

Pagina_Inicial::~Pagina_Inicial()
{
    delete ui;
}

void Pagina_Inicial::on_comboBox_currentIndexChanged(int index)
{
    modo = index;
    //qDebug() << "index: " << index;
    carregarDados();
}
void Pagina_Inicial::on_pbAZ_clicked()//botão filtro a-z
{

    if(cAZ == 0){

        ui->pbAZ->setText("A-Z⬆");
        ui->lwTodosT->sortItems();

        cAZ++;

    }else if(cAZ == 1){

        ui->lwTodosT->sortItems(Qt::DescendingOrder);
        ui->pbAZ->setText("A-Z⬇");
        cAZ++;

    }else if(cAZ == 2){

        ui->pbAZ->setText("A-Z");

        carregarDados();

        cAZ = 0;
    }
}

void Pagina_Inicial::on_pbData_clicked()
{

    cData++;
    //qDebug() << "cData: " << cData;
    carregarDados();
}


void Pagina_Inicial::carregarDados(){

    QSqlQuery pDados;

    if(cData == 1){
        ui->pbData->setText("📅⬆");
        pDados.prepare("select nome,andamento,data,id,dataFinalizado from infoUsers WHERE userPropId = :idUsuario ORDER BY data ASC");

    }else if(cData == 2){
        ui->pbData->setText("📅⬇");
        pDados.prepare("select nome,andamento,data,id,dataFinalizado from infoUsers WHERE userPropId = :idUsuario ORDER BY data DESC");
    }else{
        ui->pbData->setText("📅");
        pDados.prepare("select nome,andamento,data,id,dataFinalizado from infoUsers WHERE userPropId = :idUsuario");
        cData = 0;
    }



    pDados.bindValue(":idUsuario", idGuardada);
    pDados.exec();

    ui->lwTodosT->clear(); // evita duplicar

    //QListWidget* lista = new QListWidget(ui->lwTodosT); // QListWidget = não pode chamar com variavel

    int linhas = 0;
    if(modo == 1){//se em andamento


        while(pDados.next()){

            int idBanco = pDados.value(3).toInt(); // id do banco, cuidar select

            if((pDados.value(1) == 0)){

                QString lista = pDados.value(0).toString() + " - "
                                + pDados.value(2).toString() +
                                "🚶";
                QListWidgetItem *bInterno = new QListWidgetItem(lista,ui->lwTodosT);//pode chamar com variavel
                bInterno->setSizeHint(QSize(0, 30));
                bInterno->setTextAlignment(Qt::AlignCenter);//centraliza as informações
                bInterno->setBackground(QColor(Qt::darkYellow));
                bInterno->setData(Qt::UserRole,idBanco);
                // esconde a id do usuario
                //set data é um método do Qt que permite anexar dados extras e invisíveis a um item.
                linhas++;

            }

        }

    }else if(modo == 2){//finalizado

        while(pDados.next()){

            int idBanco = pDados.value(3).toInt(); // id do banco, cuidar select

            if((pDados.value(1) == 1)){

                QString lista = pDados.value(0).toString() + " - "
                                + pDados.value(2).toString() + " - "
                                + // pegando apenas o nome e dá um espaço maneiro
                                "🚩 " + pDados.value(4).toString(); // verifica se a tarefa já foi feita

                QListWidgetItem *bInterno = new QListWidgetItem(lista,ui->lwTodosT);//pode chamar com variavel
                bInterno->setSizeHint(QSize(0, 30));
                bInterno->setTextAlignment(Qt::AlignCenter);//centraliza as informações
                bInterno->setBackground(QColor(Qt::darkGreen));
                bInterno->setData(Qt::UserRole,idBanco);
                // esconde a id do usuario
                //set data é um método do Qt que permite anexar dados extras e invisíveis a um item.
                linhas++;

            }

        }

    }else if(modo == 3){//cancelado

        while(pDados.next()){

            int idBanco = pDados.value(3).toInt(); // id do banco, cuidar select

            if((pDados.value(1) == 2)){

                QString lista = pDados.value(0).toString() + " - "
                                + pDados.value(2).toString() + " - "
                                + // pegando apenas o nome e dá um espaço maneiro
                                "❌ " + pDados.value(4).toString(); // verifica se a tarefa já foi feita

                QListWidgetItem *bInterno = new QListWidgetItem(lista,ui->lwTodosT);//pode chamar com variavel
                bInterno->setSizeHint(QSize(0, 30));
                bInterno->setTextAlignment(Qt::AlignCenter);//centraliza as informações
                bInterno->setBackground(QColor(Qt::darkRed));
                bInterno->setData(Qt::UserRole,idBanco);
                // esconde a id do usuario
                //set data é um método do Qt que permite anexar dados extras e invisíveis a um item.
                linhas++;

            }

        }

    }else{


        while(pDados.next()){

            int idBanco = pDados.value(3).toInt(); // id do banco, cuidar select

            QString lista = pDados.value(0).toString() + " - "
                                + pDados.value(2).toString() + " - "
                                + // pegando apenas o nome e dá um espaço maneiro
                                (((pDados.value(1) == 0) ? "🚶 " : ((pDados.value(1) == 1) ? "🚩 " + pDados.value(4).toString() : "❌ " + pDados.value(4).toString()))); // verifica se a tarefa já foi feita

            QListWidgetItem *bInterno = new QListWidgetItem(lista,ui->lwTodosT);//pode chamar com variavel
            bInterno->setSizeHint(QSize(0, 30));

            bInterno->setTextAlignment(Qt::AlignCenter);//centraliza as informações

            if(pDados.value(1) == 0){//andamento

                bInterno->setBackground(QColor(Qt::darkYellow));

            }else if(pDados.value(1) == 1){//Finalizado

                bInterno->setBackground(QColor(Qt::darkGreen));


            }else{

                bInterno->setBackground(QColor(Qt::darkRed));

            }



            bInterno->setData(Qt::UserRole,idBanco);
            // esconde a id do usuario
            //set data é um método do Qt que permite anexar dados extras e invisíveis a um item.
            linhas++;
        }

    }

    ui->lblReg->setText("Total de Registros: " + QString::number(linhas));

}

void Pagina_Inicial::on_lwTodosT_itemClicked(QListWidgetItem *item)
{
    // retirar função
}


void Pagina_Inicial::on_lwTodosT_itemDoubleClicked(QListWidgetItem *item)
{

    abrirNota abrirB(idBlocoSelecionado,idGuardada,false);

    abrirB.setModal(true);

    abrirB.exec();

    carregarDados();




}

void Pagina_Inicial::on_btnCriar_clicked()
{

    criar abrirCr(idGuardada,false,0);

    //abrirCr.guardandoID(idGuardada,false,0);

    abrirCr.setModal(true);

    abrirCr.exec();

    carregarDados();

}

void Pagina_Inicial::on_btnEditar_clicked()
{ // selecionar a linha e puxar os dados

    criar abrirCr(idGuardada,true,idBlocoSelecionado);
    if(!(idBlocoSelecionado == 0)){//se não tiver nada selecionado, então não autoriza

        //abrirCr.guardandoID(idGuardada,true,idBlocoSelecionado);

        abrirCr.setModal(true);

        abrirCr.exec();

    }else{

        QMessageBox::warning(this,"Aviso","Não selecionado nenhuma nota");

    }


    carregarDados();
}
void Pagina_Inicial::on_btnApagar_clicked()
{

    if(!(idBlocoSelecionado == 0)){

        auto btn = QMessageBox::warning(this,
                                        "Excluir","deseja excluir o bloco",
                                        QMessageBox::Yes | QMessageBox::No,QMessageBox::No);

        if(btn == QMessageBox::Yes){

            QSqlQuery pDados;
            pDados.prepare("DELETE from infoUsers where id ="+ QString::number(idBlocoSelecionado));

            if(pDados.exec()){
                ////criar função
                QSqlQuery apagaDiff;
                apagaDiff.prepare("DELETE from diffInfo where idBloco ="+ QString::number(idBlocoSelecionado));

                if(apagaDiff.exec()){

                    QMessageBox::information(this,"atenção","Registro apagado com sucesso.");
                    carregarDados();

                }else{
                    //mostra o erro
                    QMessageBox::information(this,"atenção","não foi possivel apagar as informações.\n" + pDados.lastError().text());

                }

            }else{
                //mostra o erro
                QMessageBox::information(this,"atenção","não foi possivel apagar as informações.\n" + pDados.lastError().text());

            }



        }

    }else{

        QMessageBox::warning(this,"Aviso","Não selecionado nenhuma nota");

        return;

    }
}

void Pagina_Inicial::on_lwTodosT_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (!current) return;

    idBlocoSelecionado = current->data(Qt::UserRole).toInt(); // unifica a base
}

////////////////////voltar para o login
void Pagina_Inicial::limpaDados(){

    idGuardada = 0;
    ui->lwTodosT->clear();
}

void Pagina_Inicial::on_pbSair_clicked()//Não funciona, não sei o que fazer, botão desativado.
{
    idBlocoSelecionado = 0;
    this -> close();

}
////////////////////voltar para o login


void Pagina_Inicial::on_pushButton_clicked()
{

    if(!(idBlocoSelecionado == 0)){

        Historico abrirH(idBlocoSelecionado,idGuardada);

        abrirH.setModal(true);

        abrirH.exec();

    }else{

        QMessageBox::warning(this,"Aviso","Não selecionado nenhuma nota");

        return;

    }
}

