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
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_pagina_inicial_ADM
{
public:
    QListWidget *lwUsers;
    QLabel *lblNome;

    void setupUi(QDialog *pagina_inicial_ADM)
    {
        if (pagina_inicial_ADM->objectName().isEmpty())
            pagina_inicial_ADM->setObjectName("pagina_inicial_ADM");
        pagina_inicial_ADM->resize(400, 600);
        pagina_inicial_ADM->setMinimumSize(QSize(400, 600));
        pagina_inicial_ADM->setMaximumSize(QSize(400, 600));
        lwUsers = new QListWidget(pagina_inicial_ADM);
        lwUsers->setObjectName("lwUsers");
        lwUsers->setGeometry(QRect(10, 70, 381, 501));
        lblNome = new QLabel(pagina_inicial_ADM);
        lblNome->setObjectName("lblNome");
        lblNome->setGeometry(QRect(30, 10, 188, 24));
        lblNome->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(pagina_inicial_ADM);

        QMetaObject::connectSlotsByName(pagina_inicial_ADM);
    } // setupUi

    void retranslateUi(QDialog *pagina_inicial_ADM)
    {
        pagina_inicial_ADM->setWindowTitle(QCoreApplication::translate("pagina_inicial_ADM", "Dialog", nullptr));
        lblNome->setText(QCoreApplication::translate("pagina_inicial_ADM", "User", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pagina_inicial_ADM: public Ui_pagina_inicial_ADM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGINA_INICIAL_ADM_H
