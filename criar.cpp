#include "criar.h"
#include "ui_criar.h"

criar::criar(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::criar)
{
    ui->setupUi(this);
}

criar::~criar()
{
    delete ui;
}
