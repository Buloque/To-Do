/********************************************************************************
** Form generated from reading UI file 'pagina_inicial_adm.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGINA_INICIAL_ADM_H
#define UI_PAGINA_INICIAL_ADM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_pagina_inicial_ADM
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblNome;
    QPushButton *pbPessoal;
    QPushButton *pbSair;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbCriarM;
    QPushButton *pbMudarSenha;
    QListWidget *lwUsers;

    void setupUi(QDialog *pagina_inicial_ADM)
    {
        if (pagina_inicial_ADM->objectName().isEmpty())
            pagina_inicial_ADM->setObjectName("pagina_inicial_ADM");
        pagina_inicial_ADM->resize(400, 600);
        pagina_inicial_ADM->setMinimumSize(QSize(400, 600));
        pagina_inicial_ADM->setMaximumSize(QSize(400, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/IMG/Imagens/Icone Sem Fundopng.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pagina_inicial_ADM->setWindowIcon(icon);
        gridLayout = new QGridLayout(pagina_inicial_ADM);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lblNome = new QLabel(pagina_inicial_ADM);
        lblNome->setObjectName("lblNome");
        lblNome->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(lblNome);

        pbPessoal = new QPushButton(pagina_inicial_ADM);
        pbPessoal->setObjectName("pbPessoal");
        pbPessoal->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(pbPessoal);

        pbSair = new QPushButton(pagina_inicial_ADM);
        pbSair->setObjectName("pbSair");
        pbSair->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_2->addWidget(pbSair);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pbCriarM = new QPushButton(pagina_inicial_ADM);
        pbCriarM->setObjectName("pbCriarM");

        horizontalLayout->addWidget(pbCriarM);

        pbMudarSenha = new QPushButton(pagina_inicial_ADM);
        pbMudarSenha->setObjectName("pbMudarSenha");

        horizontalLayout->addWidget(pbMudarSenha);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        lwUsers = new QListWidget(pagina_inicial_ADM);
        lwUsers->setObjectName("lwUsers");

        gridLayout->addWidget(lwUsers, 2, 0, 1, 1);


        retranslateUi(pagina_inicial_ADM);

        QMetaObject::connectSlotsByName(pagina_inicial_ADM);
    } // setupUi

    void retranslateUi(QDialog *pagina_inicial_ADM)
    {
        pagina_inicial_ADM->setWindowTitle(QCoreApplication::translate("pagina_inicial_ADM", "Painel do ADM", nullptr));
        lblNome->setText(QCoreApplication::translate("pagina_inicial_ADM", "User", nullptr));
        pbPessoal->setText(QCoreApplication::translate("pagina_inicial_ADM", "Bloco Pessoal", nullptr));
        pbSair->setText(QCoreApplication::translate("pagina_inicial_ADM", "Sair", nullptr));
        pbCriarM->setText(QCoreApplication::translate("pagina_inicial_ADM", "Criar Multi. Blocos", nullptr));
        pbMudarSenha->setText(QCoreApplication::translate("pagina_inicial_ADM", "Mudar Senha", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pagina_inicial_ADM: public Ui_pagina_inicial_ADM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGINA_INICIAL_ADM_H
