#ifndef REGISTRAR_H
#define REGISTRAR_H

#include <QDialog>

#include "login.h"

namespace Ui {
class registrar;
}

class registrar : public QDialog
{
    Q_OBJECT

public:
    explicit registrar(QWidget *parent = nullptr);

    ~registrar();

private slots:
    void on_txtSenha_2_textChanged(const QString &arg1);

    void on_txtLogin_editingFinished();

    void on_dbCriar_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::registrar *ui;
    Login telaLogin;
};

#endif // REGISTRAR_H
