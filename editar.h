#ifndef EDITAR_H
#define EDITAR_H

#include <QDialog>

namespace Ui {
class editar;
}

class editar : public QDialog
{
    Q_OBJECT

public:
    explicit editar(QWidget *parent = nullptr);
    ~editar();

private:
    Ui::editar *ui;
};

#endif // EDITAR_H
