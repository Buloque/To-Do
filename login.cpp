#include "login.h"
#include "./ui_login.h"

#include <QtSql>
#include <QMessageBox>
#include <QFile>
#include <QStringList>

#include "pagina_inicial.h"
#include "pagina_inicial_adm.h"
#include "registrar.h"


static QSqlDatabase bancoDados;

//mudar para extern, para não precisar chamar na propria função, já que todos os codigos usam ele, TEM MUITO CODIGO, CUIDA PELO O AMOR DE DEUS, FAZ BACKUP
static int id;

//para poder acessar de outros arquivos
extern QString nomeUser;
//QString nomeUser;

int intADM; //tipo de ADM

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

void Login::verificaADM(){

    QSqlQuery consultaADM;

    consultaADM.prepare("select Perm from Users WHERE Usuario = :nomeUser");
    consultaADM.bindValue(":nomeUser", nomeUser);

    if(consultaADM.exec()){
        while(consultaADM.next()){

            int consulta = consultaADM.value(0).toInt();

            if(consulta == 1){

                intADM = 1;

            }else if(consulta == 2){

                intADM = 2;

            }else{

                intADM = 0;

            }

        }

    }else{

        qDebug() << "erro";// mostrar para o usuario

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
        qDebug() << "Erro fatal: O banco de dados não está aberto.";//fazer mostrar para o usuario
        qDebug() << "Detalhes do banco:" << bancoDados.lastError().text();//fazer mostrar para o usuario
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

                //armazena o nome o user
                nomeUser = user;
                verificaADM(); // verifica se o user é adm

                if(intADM == 1 || intADM == 2){

                    this->hide();
                    //pagina_inicial_ADM abrirADM(intADM,id,nomeUser);
                    pagina_inicial_ADM *abrirADM = new pagina_inicial_ADM(intADM, id, nomeUser);

                    abrirADM->setModal(true);

                    abrirADM->exec();

                    abrirADM->deleteLater();


                }else{

                    this->hide();
                    Pagina_Inicial abrirTI(id,nomeUser,false,0);

                    abrirTI.setModal(true);

                    abrirTI.exec();

                }

                this->show();


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

