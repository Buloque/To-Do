#include "pagina_inicial.h"
#include "ui_pagina_inicial.h"

#include <QtSql>
#include <QListWidget>
#include <QListWidgetItem>
#include <QSize>

#include <QMessageBox>

#include "editar.h"
#include "criar.h"
#include "abrirnota.h"

int idGuardada;
int idBlocoSelecionado;

void Pagina_Inicial::guardandoID(int ID){

    idGuardada = ID;
    carregarDados(); // trocado o local para carregar o ID antes de tudo.

}

Pagina_Inicial::Pagina_Inicial(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Pagina_Inicial)
{

    ui->setupUi(this);

}

Pagina_Inicial::~Pagina_Inicial()
{
    delete ui;
}

void Pagina_Inicial::carregarDados(){

    QSqlQuery pDados;
    pDados.prepare("select nome,andamento,id from infoUsers WHERE userPropId = :idUsuario");
    pDados.bindValue(":idUsuario", idGuardada);
    pDados.exec();

    ui->lwTodosT->clear(); // evita duplicar

    //QListWidget* lista = new QListWidget(ui->lwTodosT); // QListWidget = não pode chamar com variavel

    while(pDados.next()){


        int idBanco = pDados.value(2).toInt();

        QString lista = pDados.value(0).toString() + " " + // pegando apenas o nome e dá um espaço maneiro
                        ((pDados.value(1) == 0) ? "✅" : "❎"); // verifica se a tarefa já foi feita

        QListWidgetItem *bInterno = new QListWidgetItem(lista,ui->lwTodosT);//pode chamar com variavel
        bInterno->setSizeHint(QSize(0, 30));


        bInterno->setData(Qt::UserRole,idBanco);
        // esconde a id do usuario
        //set data é um método do Qt que permite anexar dados extras e invisíveis a um item.

    }


}
void Pagina_Inicial::on_lwTodosT_itemDoubleClicked(QListWidgetItem *item)
{

    abrirNota abrirB;

    abrirB.idNota(idBlocoSelecionado);

    abrirB.setModal(true);

    abrirB.exec();

    carregarDados();
}

void Pagina_Inicial::on_btnCriar_clicked()
{

    criar abrirCr;

    abrirCr.guardandoID(idGuardada);

    abrirCr.setModal(true);

    abrirCr.exec();

    carregarDados();

}

void Pagina_Inicial::on_btnEditar_clicked()
{ // selecionar a linha e puxar os dados

    editar abrirEd;

    abrirEd.setModal(true);

    abrirEd.exec();

    carregarDados();
}

////////////////////voltar para o login
void Pagina_Inicial::limpaDados(){

    idGuardada = 0;
    ui->lwTodosT->clear();
}

void Pagina_Inicial::on_pbSair_clicked()//Não funciona, não sei o que fazer, botão desativado.
{

    this -> hide();
    telaLogin.show();

}
////////////////////voltar para o login







void Pagina_Inicial::on_lwTodosT_itemClicked(QListWidgetItem *item)
{

    if (!item) return;

    idBlocoSelecionado = item->data(Qt::UserRole).toInt(); // unifica a base



    qDebug() << "Id clicado: " << idBlocoSelecionado;

}

