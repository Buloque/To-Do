#include "registrar.h"
#include "ui_registrar.h"

#include <QtSql>
#include <QDebug>

bool confirmaUser = false;
bool confirmaSenha = false;

registrar::registrar(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::registrar)
{
    ui->setupUi(this);
}

registrar::~registrar()
{
    delete ui;
}

void registrar::on_txtLogin_editingFinished()
{
    QString NomeD = ui->txtLogin->text();
    QSqlQuery pDados;

    if(pDados.exec("select * FROM Users WHERE Usuario='"+NomeD+"'")){
        qDebug() << "executado";
        int contReg = 0;

        while(pDados.next()){

            contReg++;

        }

        if(contReg == 1){

            ui->lbllogconf->setText("🚫 - usuario já existente");

        }else{

            ui->lbllogconf->setText("👌 - Nome de Usuario disponivel!");

        }

    }

}

void registrar::on_txtSenha_2_textChanged(const QString &arg1)
{

    if(arg1 == ""){

        ui->VerificaSenha->setText("<head/><body><p style='color: red;'>Não pode deixar o campo em branco.</p></body>");

    }else{

        QString S1 = ui->txtSenha->text();
        QString S2 = ui->txtSenha_2->text();

        if(S1 == S2){

            ui->VerificaSenha->setText("<head/><body><p style='color: green;'>As senhas coencidem!</p></body>");

        }

    }



}




