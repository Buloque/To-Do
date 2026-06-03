/********************************************************************************
** Form generated from reading UI file 'registrar.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRAR_H
#define UI_REGISTRAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registrar
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lbllogconf;
    QLabel *label;
    QLineEdit *txtLogin;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *txtSenha;
    QLabel *label_3;
    QLineEdit *txtSenha_2;
    QLabel *VerificaSenha;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *dbCriar;
    QPushButton *pushButton_2;

    void setupUi(QDialog *registrar)
    {
        if (registrar->objectName().isEmpty())
            registrar->setObjectName("registrar");
        registrar->resize(350, 549);
        registrar->setMinimumSize(QSize(350, 549));
        registrar->setMaximumSize(QSize(350, 549));
        layoutWidget = new QWidget(registrar);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 30, 311, 373));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        lbllogconf = new QLabel(layoutWidget);
        lbllogconf->setObjectName("lbllogconf");
        lbllogconf->setTextInteractionFlags(Qt::TextInteractionFlag::NoTextInteraction);

        verticalLayout->addWidget(lbllogconf);

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

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        verticalLayout_2->addWidget(label_3);

        txtSenha_2 = new QLineEdit(layoutWidget);
        txtSenha_2->setObjectName("txtSenha_2");
        txtSenha_2->setMaxLength(50);
        txtSenha_2->setEchoMode(QLineEdit::EchoMode::PasswordEchoOnEdit);

        verticalLayout_2->addWidget(txtSenha_2);

        VerificaSenha = new QLabel(layoutWidget);
        VerificaSenha->setObjectName("VerificaSenha");

        verticalLayout_2->addWidget(VerificaSenha);


        verticalLayout_3->addLayout(verticalLayout_2);

        widget = new QWidget(registrar);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(160, 470, 168, 26));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        dbCriar = new QPushButton(widget);
        dbCriar->setObjectName("dbCriar");
        dbCriar->setCheckable(false);
        dbCriar->setChecked(false);
        dbCriar->setFlat(false);

        horizontalLayout->addWidget(dbCriar);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);


        retranslateUi(registrar);

        QMetaObject::connectSlotsByName(registrar);
    } // setupUi

    void retranslateUi(QDialog *registrar)
    {
        registrar->setWindowTitle(QCoreApplication::translate("registrar", "Registro", nullptr));
#if QT_CONFIG(tooltip)
        registrar->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        registrar->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(accessibility)
        registrar->setAccessibleName(QString());
#endif // QT_CONFIG(accessibility)
        label_4->setText(QCoreApplication::translate("registrar", "<html><head/><body><p align=\"center\"><span style=\" font-size:48pt;\">Registro</span></p></body></html>", nullptr));
        lbllogconf->setText(QCoreApplication::translate("registrar", "\360\237\232\253 - Nenhum nome escrito", nullptr));
        label->setText(QCoreApplication::translate("registrar", "Usu\303\241rio:", nullptr));
        txtLogin->setText(QString());
        label_2->setText(QCoreApplication::translate("registrar", "Senha:", nullptr));
        txtSenha->setText(QString());
        label_3->setText(QCoreApplication::translate("registrar", "Repita a Senha:", nullptr));
        txtSenha_2->setText(QString());
        VerificaSenha->setText(QCoreApplication::translate("registrar", "<html><head/><body><p style=\"color: red;\">N\303\243o pode deixar o campo em branco.</p></body></html>", nullptr));
        dbCriar->setText(QCoreApplication::translate("registrar", "Criar", nullptr));
        pushButton_2->setText(QCoreApplication::translate("registrar", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registrar: public Ui_registrar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRAR_H
