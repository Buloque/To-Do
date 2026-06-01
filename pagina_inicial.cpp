#include "pagina_inicial.h"
#include "ui_pagina_inicial.h"

#include <QtSql>
#include <QListWidget>
#include <QListWidgetItem>
#include <QSize>

#include <QMessageBox>

#include "editar.h"

int idGuardada;

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
    pDados.prepare("select * from infoUsers WHERE userPropId = :idUsuario");
    pDados.bindValue(":idUsuario", idGuardada);
    pDados.exec();

    ui->lwTodosT->clear(); // evita duplicar

    //QListWidget* lista = new QListWidget(ui->lwTodosT); // QListWidget = não pode chamar com variavel

    while(pDados.next()){

        QString lista = pDados.value(0).toString() + " " + // pegando apenas o nome e dá um espaço maneiro
                        ((pDados.value(4) == 1) ? "✅" : "❎"); // verifica se a tarefa já foi feita

        QListWidgetItem *bInterno = new QListWidgetItem(lista,ui->lwTodosT);//pode chamar com variavel
        bInterno->setSizeHint(QSize(0, 30));


    }

}
void Pagina_Inicial::on_lwTodosT_itemDoubleClicked(QListWidgetItem *item)
{
    editar abrirEd;

    abrirEd.setModal(true);

    abrirEd.exec();
}

void Pagina_Inicial::on_btnCriar_clicked()
{

}

