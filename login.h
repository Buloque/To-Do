#ifndef LOGIN_H
#define LOGIN_H


#include <QMainWindow>
#include <QtSql>

#include <QDialog> //para conseguir chamar o Login No ???? //o q eu quis dizer com isso????

//extern QString nomeUser;

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
    void verificaUsers();
    void verificaADM();




private slots:
    void on_btnEntrar_clicked();

    void on_pushButton_clicked();

private:
    Ui::Login *ui;

    void iniciandoBanco();
    void criandoBanco();


};
#endif // LOGIN_H
