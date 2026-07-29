#include "criar.h"
#include "ui_criar.h"

#include <QDateTime> // para pegar a data
#include <QMessageBox>
#include <QComboBox>
#include <QLayout>

#include <QTextStream>
#include <QFileDialog>
#include <QtSql>
#include <QStringList>

QFont fonte;
QFont orig; // Correção Strike
QFile arquivo;

int idRecuperada;
bool editando;
int blocoPush;

int editarADMFiltro = 1;

bool ADMEditando = false;
int IdDoCriador;

bool criarParaMultiplosUsers = false;
int idGrupoRecuperado;
bool criadoID = false;
bool passouDenovo = false;

QDateTime horaDiaAtual = QDateTime::currentDateTime();

void criar::guardandoID(int ID,bool editar,int idBloco){

    ////retirar

}

criar::criar(int ID,bool editar,int idBloco,bool editarADM,int IDCriador,bool criarMult,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::criar)
{

    idRecuperada = ID;
    editando = editar;
    blocoPush = idBloco;

    ADMEditando = editarADM;
    IdDoCriador = IDCriador;

    criarParaMultiplosUsers = criarMult;

    ui->setupUi(this);

    subtextos();
}

criar::~criar()
{

    delete ui;


}

void criar::confADM(){

    //editar ou retirar do codigo


}

void criar::subtextos(){

    if(ADMEditando == true){

        ui->editavelADM->setDisabled(false);

    }else{

        ui->editavelADM->setDisabled(true);

    }


    ui->leTitulo->setPlaceholderText("Titulo");
    ui->texto->setPlaceholderText("Escreva suas notas aqui");

    QSqlQuery abreDiff;

    //////////////////////////////fazer maneira de ver qual e o maior valor, e salvar pra quando salvar, não salvar o mesmo
    /// Edit do futuro: OQ EU QUIS DIZER COM ISSO PESTE

    if(editando == false){

        ui->timeEdit->setDateTime(horaDiaAtual);
        ui->dateEdit->setDateTime(horaDiaAtual);

    }else{

        this->setWindowTitle("Editar");

        QSqlQuery abreNotas;
        abreNotas.prepare("SELECT nome,bloco,data,horas,urgencia,andamento,editavel FROM infoUsers WHERE id = :id");
        abreNotas.bindValue(":id", blocoPush);
        //

        if(abreNotas.exec()){

            //verifica se encontrou o id
            if(abreNotas.next()){

                QString titulo = abreNotas.value(0).toString();
                QString textoB = abreNotas.value(1).toString();

                QVariant data = abreNotas.value(2);
                QString dataTexto = data.toString().trimmed();//convertendo para String // trimmed() = limpa espaços vazios
                QDate dConv = QDate::fromString(dataTexto, "dd/MM/yyyy");

                QVariant horas = abreNotas.value(3);
                QTime hConv = horas.toTime();

                bool editavel = abreNotas.value(6).toBool();

                int urgencia = abreNotas.value(4).toInt();

                int andamento = abreNotas.value(5).toInt();

                ui->leTitulo->setText(titulo);
                ui->texto->setMarkdown(textoB);
                ui->dateEdit->setDate(dConv);
                ui->timeEdit->setTime(hConv);
                ui->cbUrgencia->setCurrentIndex(urgencia);

                ui->editavelADM->setChecked(editavel);




            }else{

                //Erro ao encontrar a ID
                QMessageBox::warning(this,"Erro","Nenhum registro encontrado com o ID."); // mudar para texto para usuario
            }

        }else{

            //erro ao executar a requesição
            QMessageBox::warning(this,"Erro","Erro ao executar o SELECT:" + abreNotas.lastError().text());

        }

    }

}

void criar::on_pbNegrito_clicked()
{

    if((veficaTexto()) == false){

        ui->texto->setFontWeight(QFont::Bold);

    }else{

        ui->texto->setFontWeight(QFont::Normal);

    }

}

void criar::on_pbItalic_clicked()
{

    if((veficaTexto()) == false){

        ui->texto->setFontItalic(true);

    }else{

        ui->texto->setFontItalic(false);

    }
}

void criar::on_pbStrikeOut_clicked()
{



    if((veficaTexto()) == false){

        orig = ui->texto->currentFont();//salva as caracteri do texto

        fonte.setStrikeOut(true);
        ui->texto->setCurrentFont(fonte);

    }else{

        //orig = ui->texto->currentFont();
        fonte.setStrikeOut(false);
        ui->texto->setCurrentFont(orig);//devolve as caracteristicas



    }

}

void criar::on_pbUnderline_clicked()
{

    if((veficaTexto()) == false){

        ui->texto->setFontUnderline(true);

    }else{

        ui->texto->setFontUnderline(false);

    }
}

bool criar::veficaTexto(){

    //pega o local no ponteiro no texto selecionado
    QTextCursor cursor = ui->texto->textCursor();

    //traduz o texto para char
    QTextCharFormat formato = cursor.charFormat();

    //extrai a configuração da fonte
    QFont fonte = formato.font();

    //Entrega qual a propriedade
    bool negrito = (fonte.weight() >= QFont::Bold);
    bool italic = fonte.italic();
    bool strike = fonte.strikeOut();
    bool underline = fonte.underline();



    if(negrito == true || italic == true || strike == true || underline == true){

        return true;

    }else{

        return false;

    }
}

void criar::on_pbReset_clicked()//deixa a letra normal
{

    ui->texto->setFontWeight(QFont::Normal);

    ui->texto->setFontItalic(false);

    fonte.setStrikeOut(false);
    ui->texto->setCurrentFont(orig);

    ui->texto->setFontUnderline(false);

}

void criar::on_pushButton_clicked()
{
    //salvar
}
void criar::on_pbDia_clicked()
{
    ui->dateEdit->setDateTime(QDateTime::currentDateTime());
}


void criar::on_pbHora_clicked()
{
    ui->timeEdit->setDateTime(QDateTime::currentDateTime());
}


void criar::on_texto_cursorPositionChanged(){
    //pega o local no ponteiro no texto selecionado
    QTextCursor cursor = ui->texto->textCursor();

    int linha = cursor.blockNumber();//numero da linha
    int coluna = cursor.columnNumber();//coluna

    ui->lblInfo->setText("Linha: " + QString::number(linha) + " coluna: "+ QString::number(coluna));
}

void criar::on_pbCancelar_clicked()
{
    //pega o local no ponteiro no texto selecionado
    QTextCursor cursor = ui->texto->textCursor();
    int coluna = cursor.columnNumber();

    QMessageBox::StandardButton conf;

    if(coluna > 1){

        conf = QMessageBox::question(this,"Aviso",
                             "Tem certeza que deseja sair?");

        if(conf == QMessageBox::Yes){

            this->close();
        }

    }else{

        this->close();

    }
}

int criar::verificaUrgencia(){

    QString urgString = ui->cbUrgencia->currentText();

    if(urgString == "🟢 Baixo"){

        return 0;

    }else if(urgString == "🟡 Médio"){

        return 1;

    }else if(urgString == "🟠 Alto"){

        return 2;

    }else if(urgString == "🔴 Urgente"){

        return 3;

    }

    return 0;

}

void criar::on_editavelADM_stateChanged(int arg1)//0 - desativado | 1 - ativado
{
    //(arg1 == 2) ? editarADMFiltro = 1 : editarADMFiltro = 0;

    if(arg1 == 2){

        editarADMFiltro = 1;

    }else if(arg1 == 0){

        editarADMFiltro = 0;

    }

}

void criar::on_pbSalvar_clicked()
{
    if(criarParaMultiplosUsers == true){

        salvarParaMultiplosUsuarios();

    }else{

        salvar();

    }


}

void criar::salvar(){

    QString nome = ui->leTitulo->text(); // cuidar o tipo de variavel que entrega, da erro se for o errado
    QString bloco = ui->texto->toMarkdown();
    QString data =  ui->dateEdit->text();
    QString hora = ui->timeEdit->text();
    QString urgencia = QString::number(verificaUrgencia());

    QSqlQuery salvaBloco;

    if(editando == false){

        salvaBloco.prepare("insert into infoUsers (nome,bloco,data,horas,urgencia,andamento,userPropId,userCreatorID,editavel) "
                           "values (:nome,:bloco,:data,:hora,:urgencia,0,:idProprietario,:userCreator,:editar)");

        salvaBloco.bindValue(":nome", nome);
        salvaBloco.bindValue(":bloco", bloco);
        salvaBloco.bindValue(":data", data);
        salvaBloco.bindValue(":hora", hora);
        salvaBloco.bindValue(":urgencia", urgencia);
        salvaBloco.bindValue(":idProprietario", QString::number(idRecuperada));
        //a urgencia recebe 0 para ficar como em andamento

        if(ADMEditando == true){

            salvaBloco.bindValue(":userCreator", IdDoCriador);



        }else{

            salvaBloco.bindValue(":userCreator", idRecuperada);

        }



        salvaBloco.bindValue(":editar", editarADMFiltro);//0 - desativado | 1 - ativado



    }else{

        salvaBloco.prepare("UPDATE infoUsers "
                           "SET nome = :nome, bloco = :bloco, data = :data, horas = :hora, urgencia = :urgencia WHERE id = :id ");

        salvaBloco.bindValue(":nome", nome);
        salvaBloco.bindValue(":bloco", bloco);
        salvaBloco.bindValue(":data", data);
        salvaBloco.bindValue(":hora", hora);
        salvaBloco.bindValue(":urgencia", urgencia);
        salvaBloco.bindValue(":id", blocoPush);

    }



    if(salvaBloco.exec()){

        if(editando == false){

            blocoPush = salvaBloco.lastInsertId().toInt();

        }

        diffBloco();

    }else{
        //mostra o erro
        QMessageBox::information(this,"atenção","não foi possivel salvar as informações.\n" + salvaBloco.lastError().text());

    }

}


void criar::diffBloco(){

    QString nome = ui->leTitulo->text();
    QString bloco = ui->texto->toMarkdown();
    QString data =  ui->dateEdit->text();
    QString hora = ui->timeEdit->text();
    QString urgencia = QString::number(verificaUrgencia());

    QSqlQuery salvaBloco;

    QSqlDatabase db = QSqlDatabase::database();


    int contBanco = 0;

    QSqlQuery verificaDiff;

     // Busca o maior valor já salvo na coluna 'quantidade' para o bloco específico
    verificaDiff.prepare("SELECT MAX(quantidadeSalvas) FROM diffInfo WHERE idBloco = :idBloco");//cuidar para ter exatamente a mesma palavra
    verificaDiff.bindValue(":idBloco", blocoPush);

    if(verificaDiff.exec()){
        if(verificaDiff.next()){
            QVariant valorBruto = verificaDiff.value(0);

            int valorDoMax = 0;
            //verifica se o qVariant está como null e se está vazio, impedinto tranformar um null ou texto vazio em um numero
            if(!valorBruto.isNull() && !valorBruto.toString().isEmpty()) {
                valorDoMax = valorBruto.toInt();
            }

            contBanco = valorDoMax + 1;


         }else{
            QMessageBox::warning(this,"Erro","Next Falhou");

        }
     }else{

        QMessageBox::warning(this,"Erro","exec Falhou");// mudar para texto para usuario

    }




    salvaBloco.prepare("insert into diffInfo (nome,bloco,data,horas,urgencia,dataAlterado,userPropId,idBloco,editavel,quantidadeSalvas,userEditId) "
                       "values (:nome,:bloco,:data,:hora,:urgencia,:dataAlterado,:idUser,:idBloco,:editavel,:qtdSalvo,:editorId)");

    salvaBloco.bindValue(":nome", nome);
    salvaBloco.bindValue(":bloco", bloco);
    salvaBloco.bindValue(":data", data);
    salvaBloco.bindValue(":hora", hora);
    salvaBloco.bindValue(":urgencia", urgencia);
    salvaBloco.bindValue(":dataAlterado", horaDiaAtual.toString("dd/MM/yyyy hh:mm"));
    salvaBloco.bindValue(":idBloco", blocoPush);

    if(ADMEditando == true){

        salvaBloco.bindValue(":editorId", QString::number(IdDoCriador));

    }else{

        salvaBloco.bindValue(":editorId", QString::number(idRecuperada));

    }

    salvaBloco.bindValue(":editavel", editarADMFiltro);
    salvaBloco.bindValue(":idUser", QString::number(idRecuperada));
    salvaBloco.bindValue(":qtdSalvo", contBanco);


    if(salvaBloco.exec()){

        QMessageBox::information(this,"atenção","Registro salvo com sucesso.");
        this->close();
    }else{

        QMessageBox::information(this,"atenção","não foi possivel salvar as informações Diff.\n" + salvaBloco.lastError().text());
    }

}


void criar::salvarParaMultiplosUsuarios(){

    QMap<QString, int> mapaUsuarios;
    QList<int> idsSelecionados;

    QSqlQuery users;
    users.prepare("SELECT id, Usuario, Perm FROM Users");

    if (users.exec()) {
        while (users.next()) {
            if (users.value(0).toInt() != IdDoCriador) {
                int idBanco = users.value(0).toInt();
                QString nomeUser = users.value(1).toString();
                mapaUsuarios[nomeUser] = idBanco;
            }
        }
    } else {
        QMessageBox::information(this, "Atenção", "Não foi possível puxar as informações.\n" + users.lastError().text());
        return;
    }

    if (mapaUsuarios.isEmpty()) {
        QMessageBox::information(this, "Atenção", "Nenhum usuário disponível para seleção.");
        return;
    }

    QMessageBox msgBox(this);
    msgBox.setText("Selecione os usuários na lista abaixo:");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);

    QComboBox *comboBox = new QComboBox(&msgBox);
    comboBox->addItems(mapaUsuarios.keys());

    // 1. Cria o Label para exibir a seleção. O msgBox é o pai, garantindo o tempo de vida correto.
    QLabel *labelSelecionados = new QLabel("Nenhum usuário selecionado.", &msgBox);
    labelSelecionados->setWordWrap(true); // Permite que o texto quebre a linha se a lista for longa

    // 2. A lambda agora captura também o ponteiro 'labelSelecionados'
    connect(comboBox, &QComboBox::textActivated, this,
            [&mapaUsuarios, &idsSelecionados, labelSelecionados](const QString &nome) {

                int id = mapaUsuarios.value(nome, -1);
                if (id == -1) return;

                // Lógica de alternância (toggle)
                if (idsSelecionados.contains(id)) {
                    idsSelecionados.removeAll(id);
                } else {
                    idsSelecionados.append(id);
                }

                // 3. Atualiza o texto do Label com base nos IDs atualmente na lista
                if (idsSelecionados.isEmpty()) {
                    labelSelecionados->setText("Nenhum usuário selecionado.");
                } else {
                    QStringList nomesAtuais;
                    // Percorre o mapa para encontrar os nomes correspondentes aos IDs salvos
                    for (auto it = mapaUsuarios.constBegin(); it != mapaUsuarios.constEnd(); ++it) {
                        if (idsSelecionados.contains(it.value())) {
                            nomesAtuais.append(it.key());
                        }
                    }
                    // Une os nomes com vírgula e espaço
                    labelSelecionados->setText("Selecionados: " + nomesAtuais.join(", "));
                }
            });

    QLayout *layout = msgBox.layout();
    if (layout) {
        layout->addWidget(comboBox);
        layout->addWidget(labelSelecionados); // Adiciona o Label ao layout (substituindo a antiga 'tex')
    }

    if (msgBox.exec() == QMessageBox::Ok) {

        for (int idUsuario : idsSelecionados) {

            idRecuperada = idUsuario;

            salvar();
        }
    }
}



void criar::on_pbSalvarLocal_clicked()
{


    //////////////////////////////Salvar localmente
    QTextStream caminho;
    QString nomeArquivo;

    QString pegaNome = ui->leTitulo->text();


    //int id = idPush.idGuardada;

    nomeArquivo = QFileDialog::getSaveFileName(this,
                                               "Salvar",
                                               pegaNome,"Arquivo TXT (*.txt)");

    if(nomeArquivo.isEmpty()){


        return;
    }

    arquivo.setFileName(nomeArquivo);

    arquivo.open(QIODevice::WriteOnly | QIODevice::Text);

    if(!arquivo.isOpen()){

        QMessageBox::critical(this,"Aviso",
                              "Erro ao salvar o arquivo");

    }

    caminho.setDevice(&arquivo);

    caminho <<"Id:"+ QString::number(idRecuperada) +" " + ui->cbUrgencia->currentText() + "  Data: " +  ui->dateEdit->text() + "  Hora: " + ui->timeEdit->text() + "\n\n" +
                   ui->texto->toPlainText();
    //<< ui->texto->toPlainText() +
    arquivo.close();

    //////////////////////////////Salvar localmente


}




