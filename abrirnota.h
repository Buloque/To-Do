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
    explicit abrirNota(QWidget *parent = nullptr);
    ~abrirNota();
    void idNota(int id);
    void carregaDados();


private:
    Ui::abrirNota *ui;
};

#endif // ABRIRNOTA_H
