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

    void setupUi(QDialog *Pagina_Inicial)
    {
        if (Pagina_Inicial->objectName().isEmpty())
            Pagina_Inicial->setObjectName("Pagina_Inicial");
        Pagina_Inicial->resize(404, 586);
        lblTeste = new QLabel(Pagina_Inicial);
        lblTeste->setObjectName("lblTeste");
        lblTeste->setGeometry(QRect(130, 20, 49, 16));
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

        horizontalLayout->addWidget(btnEditar);

        btnApagar = new QPushButton(layoutWidget);
        btnApagar->setObjectName("btnApagar");

        horizontalLayout->addWidget(btnApagar);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        lwTodosT = new QListWidget(layoutWidget);
        lwTodosT->setObjectName("lwTodosT");

        gridLayout->addWidget(lwTodosT, 1, 0, 1, 1);


        retranslateUi(Pagina_Inicial);

        QMetaObject::connectSlotsByName(Pagina_Inicial);
    } // setupUi

    void retranslateUi(QDialog *Pagina_Inicial)
    {
        Pagina_Inicial->setWindowTitle(QCoreApplication::translate("Pagina_Inicial", "Dialog", nullptr));
        lblTeste->setText(QCoreApplication::translate("Pagina_Inicial", "TextLabel", nullptr));
        btnCriar->setText(QCoreApplication::translate("Pagina_Inicial", "Criar", nullptr));
        btnEditar->setText(QCoreApplication::translate("Pagina_Inicial", "Editar", nullptr));
        btnApagar->setText(QCoreApplication::translate("Pagina_Inicial", "Apagar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Pagina_Inicial: public Ui_Pagina_Inicial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGINA_INICIAL_H
