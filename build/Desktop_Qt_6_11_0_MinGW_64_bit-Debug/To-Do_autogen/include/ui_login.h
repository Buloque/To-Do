/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralwidget;
    QLabel *label_4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *txtLogin;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *txtSenha;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnEntrar;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(350, 549);
        Login->setMinimumSize(QSize(350, 549));
        Login->setMaximumSize(QSize(350, 549));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/IMG/Imagens/Icone Sem Fundopng.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Login->setWindowIcon(icon);
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName("centralwidget");
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(90, 30, 161, 151));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/new/IMG/Imagens/Icone Sem Fundopng.png")));
        label_4->setScaledContents(true);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 180, 311, 262));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(14);
        label->setFont(font);

        verticalLayout->addWidget(label);

        txtLogin = new QLineEdit(layoutWidget);
        txtLogin->setObjectName("txtLogin");

        verticalLayout->addWidget(txtLogin);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        txtSenha = new QLineEdit(layoutWidget);
        txtSenha->setObjectName("txtSenha");
        txtSenha->setMaxLength(50);
        txtSenha->setEchoMode(QLineEdit::EchoMode::PasswordEchoOnEdit);

        verticalLayout_2->addWidget(txtSenha);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);

        btnEntrar = new QPushButton(layoutWidget);
        btnEntrar->setObjectName("btnEntrar");

        verticalLayout_2->addWidget(btnEntrar);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(verticalLayout_2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");

        verticalLayout_3->addWidget(pushButton);

        Login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Login);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 350, 21));
        Login->setMenuBar(menubar);
        statusbar = new QStatusBar(Login);
        statusbar->setObjectName("statusbar");
        Login->setStatusBar(statusbar);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "To-Do", nullptr));
        label_4->setText(QString());
        label->setText(QCoreApplication::translate("Login", "Usu\303\241rio:", nullptr));
        txtLogin->setText(QCoreApplication::translate("Login", "Teste", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "Senha:", nullptr));
        txtSenha->setText(QCoreApplication::translate("Login", "Teste", nullptr));
        btnEntrar->setText(QCoreApplication::translate("Login", "Entrar", nullptr));
        pushButton->setText(QCoreApplication::translate("Login", "Registre-se", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
