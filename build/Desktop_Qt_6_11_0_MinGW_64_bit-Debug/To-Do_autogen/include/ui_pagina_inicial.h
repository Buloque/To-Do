/********************************************************************************
** Form generated from reading UI file 'pagina_inicial.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGINA_INICIAL_H
#define UI_PAGINA_INICIAL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pagina_Inicial
{
public:
    QLabel *lblTeste;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnCriar;
    QPushButton *btnEditar;
    QPushButton *btnApagar;
    QListWidget *lwTodosT;
    QPushButton *pbSair;

    void setupUi(QDialog *Pagina_Inicial)
    {
        if (Pagina_Inicial->objectName().isEmpty())
            Pagina_Inicial->setObjectName("Pagina_Inicial");
        Pagina_Inicial->resize(400, 600);
        Pagina_Inicial->setMinimumSize(QSize(400, 600));
        Pagina_Inicial->setMaximumSize(QSize(400, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/IMG/Imagens/Icone Sem Fundopng.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Pagina_Inicial->setWindowIcon(icon);
        lblTeste = new QLabel(Pagina_Inicial);
        lblTeste->setObjectName("lblTeste");
        lblTeste->setGeometry(QRect(10, 580, 201, 21));
        layoutWidget = new QWidget(Pagina_Inicial);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 80, 381, 501));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnCriar = new QPushButton(layoutWidget);
        btnCriar->setObjectName("btnCriar");

        horizontalLayout->addWidget(btnCriar);

        btnEditar = new QPushButton(layoutWidget);
        btnEditar->setObjectName("btnEditar");
        btnEditar->setEnabled(true);

        horizontalLayout->addWidget(btnEditar);

        btnApagar = new QPushButton(layoutWidget);
        btnApagar->setObjectName("btnApagar");

        horizontalLayout->addWidget(btnApagar);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        lwTodosT = new QListWidget(layoutWidget);
        lwTodosT->setObjectName("lwTodosT");

        gridLayout->addWidget(lwTodosT, 1, 0, 1, 1);

        pbSair = new QPushButton(Pagina_Inicial);
        pbSair->setObjectName("pbSair");
        pbSair->setEnabled(false);
        pbSair->setGeometry(QRect(310, 10, 80, 24));
        pbSair->setCheckable(true);
        pbSair->setAutoDefault(true);
        pbSair->setFlat(true);

        retranslateUi(Pagina_Inicial);

        pbSair->setDefault(true);


        QMetaObject::connectSlotsByName(Pagina_Inicial);
    } // setupUi

    void retranslateUi(QDialog *Pagina_Inicial)
    {
        Pagina_Inicial->setWindowTitle(QCoreApplication::translate("Pagina_Inicial", "Tela Principal", nullptr));
        lblTeste->setText(QCoreApplication::translate("Pagina_Inicial", "Total de Registros:", nullptr));
        btnCriar->setText(QCoreApplication::translate("Pagina_Inicial", "Criar", nullptr));
        btnEditar->setText(QCoreApplication::translate("Pagina_Inicial", "Editar", nullptr));
        btnApagar->setText(QCoreApplication::translate("Pagina_Inicial", "Apagar", nullptr));
        pbSair->setText(QCoreApplication::translate("Pagina_Inicial", "Sair", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Pagina_Inicial: public Ui_Pagina_Inicial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGINA_INICIAL_H
