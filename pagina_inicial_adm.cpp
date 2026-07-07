#include "pagina_inicial_adm.h"
#include "ui_pagina_inicial_adm.h"

#include "QSql"
#include <qsqlquery.h>

pagina_inicial_ADM::pagina_inicial_ADM(int i,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::pagina_inicial_ADM)
{
    ui->setupUi(this);
}

pagina_inicial_ADM::~pagina_inicial_ADM()
{
    delete ui;

    carregaUsers();
}

void pagina_inicial_ADM::carregaUsers(){

    QSqlQuery users;
    //1 - carregar: usuario | blocos em andamento, e se tem algum em atraso



}
