#ifndef PAGINA_INICIAL_H
#define PAGINA_INICIAL_H

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class Pagina_Inicial;
}

class Pagina_Inicial : public QDialog
{
    Q_OBJECT

public:
    explicit Pagina_Inicial(QWidget *parent = nullptr);
    void guardandoID(int ID);
    ~Pagina_Inicial();

    void carregarDados();

private slots:
    void on_lwTodosT_itemDoubleClicked(QListWidgetItem *item);

    void on_btnCriar_clicked();

private:
    Ui::Pagina_Inicial *ui;

};

#endif // PAGINA_INICIAL_H
