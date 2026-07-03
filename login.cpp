#include "login.h"
#include "./ui_login.h"

#include <QtSql>
#include <QMessageBox>
#include <QFile>
#include <QStringList>

#include "pagina_inicial.h"
#include "registrar.h"


static QSqlDatabase bancoDados;

static int id;

bool primeiroLogin;

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    iniciandoBanco();

    verificaUsers();

}

Login::~Login()
{
    delete ui;
}

void Login::iniciandoBanco(){

    QFileInfo infoArquivo("bancoDoTodo.db");
    bancoDados = QSqlDatabase::addDatabase("QSQLITE");
    bancoDados.setDatabaseName("bancoDoTodo.db");

    //Preparando o banco de dados
    if (!bancoDados.open()) {
        ui->statusbar->showMessage("Erro ao abrir o banco de dados: " + bancoDados.lastError().text());
        return;
    }else{

        ui->statusbar->showMessage("Banco aberto com sucesso!");

    }

    qint64 tamanhoEmBytes = infoArquivo.size();
    if (QFile::exists("bancoDoTodo.db") && tamanhoEmBytes == 0) {
        criandoBanco();
    }



}

void Login::verificaUsers(){

    QSqlQuery consultaQUsers;
    qDebug() << "Entrou na consulta";
    int contaRegEncontrados = 0;
    if(consultaQUsers.exec("SELECT * FROM Users")){

        while(consultaQUsers.next()){

            contaRegEncontrados++;

        }

    }


    if(contaRegEncontrados > 0){

        ui->btnEntrar->setDisabled(false);
        primeiroLogin = false;
    }else{

        ui->btnEntrar->setDisabled(true);
        primeiroLogin = true;
    }

}

void Login::criandoBanco(){

    QStringList tabelas;

    tabelas <<  R"(CREATE TABLE IF NOT EXISTS diffInfo
                                            (nome TEXT (50), bloco TEXT (99999), data TEXT (10), horas TEXT (5), dataFinalizado TEXT (10), dataAlterado TEXT (10), urgencia INTEGER (1), andamento INTEGER (1), editavel INTEGER (1), userPropId INTEGER, idBloco INTEGER, quantidadeSalvas INTEGER, id INTEGER PRIMARY KEY AUTOINCREMENT);)"
            <<
                R"(CREATE TABLE IF NOT EXISTS infoUsers
                                            (nome TEXT (50), bloco TEXT (99999), data TEXT (10), horas TEXT (5), dataFinalizado TEXT (10), urgencia INTEGER (1), andamento INTEGER (1), userPropId INTEGER, id INTEGER PRIMARY KEY AUTOINCREMENT);)"
            <<

                R"(CREATE TABLE IF NOT EXISTS Users (id INTEGER PRIMARY KEY AUTOINCREMENT, Usuario TEXT (20), Senha TEXT (20), Perm INTEGER (1) DEFAULT (0));)";

    QSqlQuery criando;

    if (!bancoDados.isOpen()) {
        qDebug() << "Erro fatal: O banco de dados não está aberto.";
        qDebug() << "Detalhes do banco:" << bancoDados.lastError().text();
    }

    for(const QString &tabela : std::as_const(tabelas)){//

        if(!criando.exec(tabela)){

            ui->statusbar->showMessage("Erro ao executar a criação de tabela:" + criando.lastError().text());

        }else{

            ui->statusbar->showMessage("Banco Criado!");

        }

    }

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


                Pagina_Inicial abrirTI(id);

                //Envia o ID para a Pagina Inicial
               //abrirTI.guardandoID(id);

                //abrirTI.setModal(true);

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




void Login::on_pushButton_clicked()//registrar
{

    registrar *abrirReg = new registrar(primeiroLogin); // mesma coisa que Pagina_Inicial abrirTI;


    abrirReg->setModal(true);//não deixa o usuario mudar nada na pagina anterior

    this -> hide();//fecha temporariamente a tela

    abrirReg->exec();



    verificaUsers();

}

