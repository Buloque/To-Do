#ifndef PAGINA_INICIAL_H
#define PAGINA_INICIAL_H

#include <QDialog>
#include <QListWidgetItem>

#include "login.h"

namespace Ui {
class Pagina_Inicial;
}

class Pagina_Inicial : public QDialog
{
    Q_OBJECT

public:
    explicit Pagina_Inicial(QWidget *parent = nullptr);
    void guardandoID(int ID);
    int idGuardada;
    ~Pagina_Inicial();

    void carregarDados();

    void limpaDados();

private slots:
    void on_lwTodosT_itemDoubleClicked(QListWidgetItem *item);

    void on_btnCriar_clicked();

    void on_pbSair_clicked();

    void on_btnEditar_clicked();

    void on_lwTodosT_itemClicked(QListWidgetItem *item);

    void on_btnApagar_clicked();

    void on_lwTodosT_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_comboBox_currentIndexChanged(int index);

    void on_pbAZ_clicked();

    void on_pbData_clicked();

private:
    Ui::Pagina_Inicial *ui;
    Login telaLogin;
};

#endif // PAGINA_INICIAL_H
