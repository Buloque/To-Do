#include "registrar.h"
#include "ui_registrar.h"

#include <QtSql>
#include <QDebug>

#include <QMessageBox>

bool confirmaUser = false;
bool confirmaSenha = false;
bool pRegistro;

bool aSenha;
int iUser;
QString nomeUserSenha;

registrar::registrar(bool primeiroRegistro,bool atualizandoSenha,int idUser,QString nomeUsuario,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::registrar)
{
    ui->setupUi(this);

    aSenha = atualizandoSenha;
    iUser = idUser;
    nomeUserSenha = nomeUsuario;
    if(aSenha == true){

        ui->txtLogin->setText(nomeUserSenha);
        ui->txtLogin->setEnabled(false);

        ui->lbllogconf->setText("");
        ui->label_4->setText("<html><head/><body><p align='center'><span style=' font-size:35pt;'>Mudar Senha</span></p></body></html>");
        this->setWindowTitle("Mudar Senha");

    }

    pRegistro = primeiroRegistro;

    if(primeiroRegistro == true){

        QMessageBox::information(this,"atenção","O Primeiro usuario será ADM, Registre com cautela.");

    }
}

registrar::~registrar()
{
    delete ui;
}

void registrar::on_txtLogin_editingFinished()
{

    if(!aSenha == true){

        QString nomeD = ui->txtLogin->text();
        QSqlQuery pDados;

        if(pDados.exec("select * FROM Users WHERE Usuario='"+nomeD+"'")){
            int contReg = 0;

            while(pDados.next()){

                contReg++;

            }
            //se o contReg achar um registro com o nome escrito então
            if(contReg == 1){//avisa que já existe e não autoriza

                ui->lbllogconf->setText("🚫 - usuario já existente");
                confirmaUser = false;

            }else if(nomeD == ""){//Não há nada escrito e não autoriza

                ui->lbllogconf->setText("🚫 - Nenhum nome escrito");
                confirmaUser = false;

            }else{//avisa que não há usuarios com esse nome e autoriza

                ui->lbllogconf->setText("👌 - Nome de Usuario disponivel!");
                confirmaUser = true;

            }

        }

    }



}

void registrar::on_txtSenha_2_textChanged(const QString &arg1)
{

    if(arg1 == ""){//Não há nada escrito e não autoriza

        ui->VerificaSenha->setText("<head/><body><p style='color: yellow;'>Não pode deixar o campo em branco.</p></body>");
        confirmaSenha = false;

    }else{

        QString S1 = ui->txtSenha->text();
        QString S2 = ui->txtSenha_2->text();

        if(S1 == S2){//avisa que as senhas são iguais e autoriza

            ui->VerificaSenha->setText("<head/><body><p style='color: green;'>As senhas coencidem!</p></body>");
            confirmaSenha = true;
        }else{//avisa que as senhas não são iguais e nao autoriza

            ui->VerificaSenha->setText("<head/><body><p style='color: red;'>As senhas não coencidem!</p></body>");
            confirmaSenha = false;
        }

    }



}





void registrar::on_dbCriar_clicked()
{

    QSqlQuery banco;
    QString nome = ui->txtLogin->text();
    QString senha = ui->txtSenha->text();


    //banco.exec(); Q ISSO TA FAZENDO AQUI????

    if(aSenha == true){

        banco.prepare("UPDATE Users SET Senha = :novaSenha WHERE id = :id");

        banco.bindValue(":novaSenha", senha);
        banco.bindValue(":id", iUser);

        if(banco.exec()){

            QMessageBox::information(this,"atenção","Senha alterada com sucesso");

        }else{//ero

            QMessageBox::information(this,"atenção","ero?");

        }

    }else{

        if(confirmaUser == true && confirmaSenha == true){
            if(pRegistro == true){

                banco.prepare("insert into Users (Usuario,Senha,Perm) values ('"+nome+"','"+senha+"',1)");


            }else{

                banco.prepare("insert into Users (Usuario,Senha) values ('"+nome+"','"+senha+"')");

            }

            if(banco.exec()){

                auto btn = QMessageBox::information(this,"atenção","Usuario salvo com sucesso<br>deseja voltar a tela de Login?",QMessageBox::Yes | QMessageBox::No,QMessageBox::Yes);

                if(btn == QMessageBox::Yes){

                    this -> hide();

                }else{

                    return;

                }



            }else{

                QMessageBox::information(this,"atenção","não foi possivel salvar as informações do usuario:\n"
                                                              + banco.lastError().text());//se der erro, ele fala qual foi pro usuario

            }

        }else{

            if(confirmaUser == false && confirmaSenha == true){

                QMessageBox::warning(this,"Aviso",
                                     "Erro ao Registrar o Nome do Usuario");

            }else if(confirmaUser == true && confirmaSenha == false){

                QMessageBox::warning(this,"Aviso",
                                     "Erro ao Registrar o senha do Usuario");

            }else{

                QMessageBox::warning(this,"Aviso",
                                     "Erro ao Registrar o Nome e senha do Usuario");

            }

        }

    }

}


void registrar::on_pushButton_2_clicked()
{

    this -> hide();

}

void registrar::atualizarSenhaUsuario(){




}

