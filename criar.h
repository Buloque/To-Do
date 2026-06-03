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

private:
    Ui::criar *ui;
};

#endif // CRIAR_H
