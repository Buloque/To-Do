/********************************************************************************
** Form generated from reading UI file 'historico.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORICO_H
#define UI_HISTORICO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_Historico
{
public:
    QListWidget *lwHistorico;

    void setupUi(QDialog *Historico)
    {
        if (Historico->objectName().isEmpty())
            Historico->setObjectName("Historico");
        Historico->resize(400, 600);
        Historico->setMaximumSize(QSize(400, 600));
        lwHistorico = new QListWidget(Historico);
        lwHistorico->setObjectName("lwHistorico");
        lwHistorico->setGeometry(QRect(20, 40, 361, 541));

        retranslateUi(Historico);

        QMetaObject::connectSlotsByName(Historico);
    } // setupUi

    void retranslateUi(QDialog *Historico)
    {
        Historico->setWindowTitle(QCoreApplication::translate("Historico", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Historico: public Ui_Historico {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORICO_H
