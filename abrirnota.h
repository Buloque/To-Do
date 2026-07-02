#ifndef ABRIRNOTA_H
#define ABRIRNOTA_H

#include <QDialog>

namespace Ui {
class abrirNota;
}

class abrirNota : public QDialog
{
    Q_OBJECT

public:
    explicit abrirNota(int id,int idUser,bool historico,QWidget *parent = nullptr);
    ~abrirNota();
    void idNota(int id);
    void carregaDados();
    void diffBloco(int andamento);


private slots:
    void on_cbAndamento_currentIndexChanged(int index);

    void on_pbHistorico_clicked();

private:
    Ui::abrirNota *ui;
};

#endif // ABRIRNOTA_H
