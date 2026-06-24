#ifndef HISTORICO_H
#define HISTORICO_H

#include <QDialog>

namespace Ui {
class Historico;
}

class Historico : public QDialog
{
    Q_OBJECT

public:
    explicit Historico(int idBloco,QWidget *parent = nullptr);
    ~Historico();
    void carregadados();

private:
    Ui::Historico *ui;
};

#endif // HISTORICO_H
