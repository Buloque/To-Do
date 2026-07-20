#include "pagina_inicial_adm.h"
#include "ui_pagina_inicial_adm.h"

#include <QtSql>
#include <QMessageBox>
#include <QListWidget>
#include <QListWidgetItem>

#include "pagina_inicial.h"
#include "criar.h"

int idPerm;
int id;
int idUserSelecionado;
QString nomeArmazenadoUser;
QString NomeAdmUser;
//QString nomeUser;

pagina_inicial_ADM::pagina_inicial_ADM(int i,int iuser,QString user,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::pagina_inicial_ADM)
{
    ui->setupUi(this);

    idPerm = i; //qual a permissão do ADM
    id = iuser;
    NomeAdmUser = user;

    ui->lblNome->setText("Usuário: " + user);

    carregaUsers();
}

pagina_inicial_ADM::~pagina_inicial_ADM()
{
    delete ui;


}

void pagina_inicial_ADM::carregaUsers(){

    QSqlQuery users;
    int linhas = 0;

    users.prepare("SELECT id,Usuario,Perm FROM Users");

    if(users.exec()){

        while(users.next()){

            if(!(users.value(0).toInt() == id)){

                if(!(users.value(2).toInt() == 1)){//se a permissão for diferente de 1, então imprime, Impede que ADM normais possam alterar informações do ADM Master

                    int idBanco = users.value(0).toInt();
                    QString nomeUser = users.value(1).toString();

                    QString lista = "Nome do usuario: " + users.value(1).toString() + " " + users.value(2).toString();

                    QListWidgetItem *bInterno = new QListWidgetItem(lista,ui->lwUsers);//pode chamar com variavel
                    bInterno->setSizeHint(QSize(0, 30));

                    bInterno->setTextAlignment(Qt::AlignCenter);//centraliza as informações

                    bInterno->setData(Qt::UserRole,idBanco);//Armazena o ID do User selecionado
                    bInterno->setData(Qt::UserRole + 1,nomeUser);//Armazena o Nome do User selecionado
                    // esconde a id do usuario
                    //set data é um método do Qt que permite anexar dados extras e invisíveis a um item.
                    linhas++;

                }

            }


        }

    }else{

        QMessageBox::information(this,"atenção","não foi possivel apagar as informações.\n" + users.lastError().text());

    }

}



void pagina_inicial_ADM::on_lwUsers_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (!current) return;

    idUserSelecionado = current->data(Qt::UserRole).toInt(); // puxa os dados armazenados no user role 0 = id
    nomeArmazenadoUser = current->data(Qt::UserRole + 1).toString(); // puxa os dados armazenados no user role 0 = id
}


void pagina_inicial_ADM::on_lwUsers_itemDoubleClicked(QListWidgetItem *item)
{


    //Pagina_Inicial abrirTI(idUserSelecionado,nomeArmazenadoUser,true,id);
    Pagina_Inicial *abrirTI = new Pagina_Inicial(idUserSelecionado,nomeArmazenadoUser,true,id);

    abrirTI->setModal(true);

    abrirTI->exec();

    abrirTI->deleteLater();

}


void pagina_inicial_ADM::on_pbMudarSenha_clicked()
{

    /////////////////////////////////////continuar

    QSqlQuery mudaSenha;

    mudaSenha.prepare("UPDATE Senha SET :senha WHERE id = :id");

}


void pagina_inicial_ADM::on_pbPessoal_clicked()//Abrindo Pagina Pessoal do Supervisor
{

    //Pagina_Inicial abrirTI(idUserSelecionado,nomeArmazenadoUser,true,id);
    Pagina_Inicial *abrirTI = new Pagina_Inicial(id,NomeAdmUser,false,0);

    abrirTI->setModal(true);

    abrirTI->exec();

    abrirTI->deleteLater();

}


void pagina_inicial_ADM::on_pbSair_clicked()
{
    idUserSelecionado = 0;

    this -> close();
}

void pagina_inicial_ADM::closeEvent(QCloseEvent *event){//muda a função do botão de fechar do proprio windows

    on_pbSair_clicked();

}


void pagina_inicial_ADM::on_pbCriarM_clicked()
{
    criar abrirCr(id,false,0,true,id,true);

    abrirCr.setModal(true);

    abrirCr.exec();


}

