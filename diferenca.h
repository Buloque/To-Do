#ifndef DIFERENCA_H
#define DIFERENCA_H

#include <QDialog>
#include <qlineedit.h>
#include <qtextedit.h>

namespace Ui {
class diferenca;
}

class diferenca : public QDialog
{
    Q_OBJECT

public:
    explicit diferenca(int idBloco,int idDiff,QWidget *parent = nullptr);
    ~diferenca();
    void chamandoBanco();
    void chamandoDiff();


private:
    Ui::diferenca *ui;

    void compararTextos();
};

#endif // DIFERENCA_H
