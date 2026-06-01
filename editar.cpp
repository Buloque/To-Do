#include "editar.h"
#include "ui_editar.h"

editar::editar(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::editar)
{
    ui->setupUi(this);
}

editar::~editar()
{
    delete ui;
}
