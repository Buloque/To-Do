#ifndef HISTORICO_H
#define HISTORICO_H

#include <QDialog>
#include <QListWidget>
#include <QListWidgetItem>

namespace Ui {
class Historico;
}

class Historico : public QDialog
{
    Q_OBJECT

public:
    explicit Historico(int idBloco,int idUser,QWidget *parent = nullptr);
    ~Historico();
    void carregadados();

private slots:
    void on_lwHistorico_itemDoubleClicked(QListWidgetItem *item);

    void on_lwHistorico_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_pushButton_clicked();

private:
    Ui::Historico *ui;
};

#endif // HISTORICO_H
