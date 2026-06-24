#include "abrirnota.h"
#include "ui_abrirnota.h"

#include <QtSql>
#include <QMessageBox>

#include "historico.h"

int idBloco;
int idUser;

QString dataB;
QString horas;

QString dataFinalizado = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm");


void abrirNota::idNota(int id){

    ////retirar, não necessario

}

abrirNota::abrirNota(int id,int idUser,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::abrirNota)
{
    ui->setupUi(this);
    idUser = idUser;
    idBloco = id;

    carregaDados();


}


abrirNota::~abrirNota()
{

    delete ui;

}

void abrirNota::carregaDados(){

    QSqlQuery abreNotas;
    abreNotas.prepare("SELECT nome,bloco,data,horas,urgencia,andamento,dataFinalizado FROM infoUsers WHERE id = :id");
    abreNotas.bindValue(":id", idBloco);
    //

    if(abreNotas.exec()){

        //verifica se encontrou o id
        if(abreNotas.next()){

            QString titulo = abreNotas.value(0).toString();
            QString textoB = abreNotas.value(1).toString();
            dataB = abreNotas.value(2).toString();
            horas = abreNotas.value(3).toString();
            QString dhFormatado;

            int urgencia = abreNotas.value(4).toInt();

            int andamento = abreNotas.value(5).toInt();

            if(andamento == 1){

                dhFormatado = "A tarefa foi terminada no dia: "+ abreNotas.value(6).toString();

            }else{

                dhFormatado = "Até dia " + dataB + " " + horas + " deve ser feito a tarefa.";

            }

            this->setWindowTitle(titulo);
            ui->bloco->setMarkdown(textoB);
            ui->DiaeHora->setText(dhFormatado);
            ui->cbUrgencia->setCurrentIndex(urgencia);
            ui->cbUrgencia->setEnabled(false);

            ui->cbAndamento->blockSignals(true);//bloqueando o sinal da variavel para não atualizar a hora toda o banco
            ui->cbAndamento->setCurrentIndex(andamento);
            ui->cbAndamento->blockSignals(false);//desbloqueando o sinal

            //qDebug() << "Aviso: ID aberto banco: " << idBloco;

        }else{

            //Erro ao encontrar a ID
            qDebug() << "Aviso: Nenhum registro encontrado com o ID: " << idBloco;
        }

    }else{

        //erro ao executar a requesição
        qDebug() << "Erro ao executar o SELECT:" << abreNotas.lastError().text();

    }


}

void abrirNota::on_cbAndamento_currentIndexChanged(int index)
{



    QSqlQuery salvaAndamento;


    if(index == 2){

        auto btnc = QMessageBox::warning(this,
                                         "Excluir","Tem certeza que deseja cancelar?",
                                         QMessageBox::Yes | QMessageBox::No,QMessageBox::No);

        if(btnc == QMessageBox::Yes){

            salvaAndamento.prepare("UPDATE infoUsers "
                                   "SET andamento = :andamento,dataFinalizado = :dataFinalizado WHERE id = :id ");

            ui->DiaeHora->setText("A tarefa foi cancelada no dia: "+ dataFinalizado);

            salvaAndamento.bindValue(":dataFinalizado", dataFinalizado);
            //salvaAndamento.bindValue(":finalizado", 2);//cancelado
        }else{

            ui->cbAndamento->setCurrentIndex(0);

            return;
        }

    }else if(index == 1){

        auto btn = QMessageBox::warning(this,
                                        "Excluir","Tem certeza que deseja finalizar?",
                                        QMessageBox::Yes | QMessageBox::No,QMessageBox::No);

        if(btn == QMessageBox::Yes){

            salvaAndamento.prepare("UPDATE infoUsers "
                                   "SET andamento = :andamento,dataFinalizado = :dataFinalizado WHERE id = :id ");

            ui->DiaeHora->setText("A tarefa foi terminada no dia: "+ dataFinalizado);

            salvaAndamento.bindValue(":dataFinalizado", dataFinalizado);
            //salvaAndamento.bindValue(":finalizado", 1);//finalizado

            //ui->cbAndamento->setEnabled(false);

        }else{

            ui->cbAndamento->setCurrentIndex(0);

            return;
        }


    }else{

        ui->DiaeHora->setText("Até dia " + dataB + " " + horas + " deve ser feito a tarefa.");

        salvaAndamento.prepare("UPDATE infoUsers "
                               "SET andamento = :andamento,dataFinalizado = :dataFinalizado WHERE id = :id ");

        salvaAndamento.bindValue(":finalizado", "");
        //salvaAndamento.bindValue(":finalizado", 0);//em aberto

    }

    salvaAndamento.bindValue(":andamento", index);

    salvaAndamento.bindValue(":id", idBloco);

    diffBloco(index);

    if(!salvaAndamento.exec()){

        QMessageBox::information(this,"atenção","não foi possivel salvar as informações.\n" + salvaAndamento.lastError().text());


    }


}

void abrirNota::diffBloco(int andamento){


    QSqlQuery salvaBloco;

    int contBanco = 0;

    QSqlQuery verificaDiff;

    // Busca o maior valor já salvo na coluna 'quantidade' para o bloco específico
    verificaDiff.prepare("SELECT MAX(quantidadeSalvas) FROM diffInfo WHERE idBloco = :idBloco");//cuidar para ter exatamente a mesma palavra
    verificaDiff.bindValue(":idBloco", idBloco);

    if(verificaDiff.exec()){
        if(verificaDiff.next()){
            QVariant valorBruto = verificaDiff.value(0);

            int valorDoMax = 0;

            //verifica se o qVariant está como null e se está vazio, impedinto tranformar um null ou texto vazio em um numero
            if(!valorBruto.isNull() && !valorBruto.toString().isEmpty()) {
                valorDoMax = valorBruto.toInt();
            }

            contBanco = valorDoMax + 1;

            //qDebug() << "contBanco calculado:" << contBanco;

        }else{

            qDebug() << "NExt falhou";

        }
    }else{

        qDebug() << "Exec falhou";

    }

    salvaBloco.prepare("insert into diffInfo (dataFinalizado,andamento,quantidadeSalvas,idBloco,userPropId) "
                           "values (:dataFinalizado,:andamento,:qtdSalvo,:idBloco,:userPropId)");

    salvaBloco.bindValue(":dataFinalizado", dataFinalizado);
    salvaBloco.bindValue(":andamento", andamento);//colocando em andamento
    salvaBloco.bindValue(":qtdSalvo", contBanco);
    salvaBloco.bindValue(":idBloco", idBloco);
    salvaBloco.bindValue(":userPropId", idUser);

    if(salvaBloco.exec()){

        QMessageBox::information(this,"atenção","Registro salvo com sucesso.");

    }else{

        QMessageBox::information(this,"atenção","não foi possivel salvar as informações Diff.\n" + salvaBloco.lastError().text());
    }

}


void abrirNota::on_pbHistorico_clicked()
{

    Historico abrirH(idBloco);

    abrirH.setModal(true);

    abrirH.exec();

}

