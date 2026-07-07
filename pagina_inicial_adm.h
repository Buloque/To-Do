#ifndef PAGINA_INICIAL_ADM_H
#define PAGINA_INICIAL_ADM_H

#include <QDialog>

namespace Ui {
class pagina_inicial_ADM;
}

class pagina_inicial_ADM : public QDialog
{
    Q_OBJECT

public:
    explicit pagina_inicial_ADM(int i,QWidget *parent = nullptr);
    ~pagina_inicial_ADM();
    void carregaUsers();

private:
    Ui::pagina_inicial_ADM *ui;
};

#endif // PAGINA_INICIAL_ADM_H
