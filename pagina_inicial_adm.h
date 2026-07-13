#ifndef PAGINA_INICIAL_ADM_H
#define PAGINA_INICIAL_ADM_H

#include <QDialog>
#include <QListWidgetItem>

#include "login.h"

namespace Ui {
class pagina_inicial_ADM;
}

class pagina_inicial_ADM : public QDialog
{
    Q_OBJECT

public:
    explicit pagina_inicial_ADM(int i,int iuser,QString user,QWidget *parent = nullptr);
    ~pagina_inicial_ADM();
    void carregaUsers();

private slots:
    void on_lwUsers_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_lwUsers_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::pagina_inicial_ADM *ui;
    Login telaLogin;
};

#endif // PAGINA_INICIAL_ADM_H
