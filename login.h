#ifndef LOGIN_H
#define LOGIN_H


#include <QMainWindow>
#include <QtSql>

#include <QDialog> //para conseguir chamar o Login No

QT_BEGIN_NAMESPACE
namespace Ui {
class Login ;
}
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login() override;




private slots:
    void on_btnEntrar_clicked();

    void on_pushButton_clicked();

private:
    Ui::Login *ui;
};
#endif // LOGIN_H
