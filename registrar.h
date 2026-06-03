#ifndef REGISTRAR_H
#define REGISTRAR_H

#include <QDialog>

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

private:
    Ui::registrar *ui;
};

#endif // REGISTRAR_H
