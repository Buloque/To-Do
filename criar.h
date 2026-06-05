#ifndef CRIAR_H
#define CRIAR_H

#include <QDialog>

namespace Ui {
class criar;
}

class criar : public QDialog
{
    Q_OBJECT

public:
    explicit criar(QWidget *parent = nullptr);
    ~criar();
    void subtextos();
    bool veficaTexto();

private slots:
    void on_pbNegrito_clicked();

    void on_pbUnderline_clicked();

    void on_pbStrikeOut_clicked();

    void on_pbItalic_clicked();

    void on_pushButton_clicked();

    void on_pbReset_clicked();

    void on_pbDia_clicked();

    void on_pbHora_clicked();

    void on_texto_cursorPositionChanged();

private:
    Ui::criar *ui;
};

#endif // CRIAR_H
