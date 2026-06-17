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
    explicit abrirNota(int id,QWidget *parent = nullptr);
    ~abrirNota();
    void idNota(int id);
    void carregaDados();


private slots:
    void on_cbAndamento_currentIndexChanged(int index);

private:
    Ui::abrirNota *ui;
};

#endif // ABRIRNOTA_H
