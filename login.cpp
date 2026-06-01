#include "login.h"
#include "./ui_login.h"

#include <QtSql>
#include <QMessageBox>

#include "pagina_inicial.h"

static QSqlDatabase bancoDados;

static int id;

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    bancoDados = QSqlDatabase::addDatabase("QSQLITE");

    //ALTERAR: banco de dados está como caminho no pc haha
    bancoDados.setDatabaseName("D:/Projetos/QT/To-Do/bancoDoTodo.db");

    //Preparando o banco de dados
    bancoDados.open();

    //Confirmando a abertuda do banco de dados correto
    if(bancoDados.databaseName() == "D:/Projetos/QT/To-Do/bancoDoTodo.db") {

        ui->statusbar->showMessage("Banco de dados conectado com sucesso!");


    }else{

        ui->statusbar->showMessage("Erro ao conectar no Banco de Dados.");

    }

}

Login::~Login()
{
    delete ui;
}

void Login::on_btnEntrar_clicked()
{
    QString user = ui->txtLogin->text();
    QString pass = ui->txtSenha->text();
    int id = 0;

    if(bancoDados.isOpen()){

        QSqlQuery consultaNoBancoDeDados;

        if(consultaNoBancoDeDados.exec("SELECT * FROM Users WHERE Usuario='"+user+"' and Senha = '"+pass+"' ")){

            int contaRegEncontrados = 0;
            //verifica se encontrou as informações
            while(consultaNoBancoDeDados.next()){
                //Armazena o ID no ID
                id = consultaNoBancoDeDados.value(0).toInt();
                //caso tenha encontrado, contaRegEncontrados + 1, para autenticar a verificação
                contaRegEncontrados++;

            }

            if(contaRegEncontrados == 1){
                //validação feita, usuario logado

                this->close();


                Pagina_Inicial abrirTI;

                //Envia o ID para a Pagina Inicial
                abrirTI.guardandoID(id);

                abrirTI.setModal(true);

                abrirTI.exec();




            }else{
                //Validação falhou, usuario não logado
                QMessageBox::critical(this,"Atenção","Usuario ou senha invalidos");

            }

        }
    }else{

        QMessageBox::warning(this,"Erro",bancoDados.lastError().text());

    }


}



