/********************************************************************************
** Form generated from reading UI file 'editar.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITAR_H
#define UI_EDITAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_editar
{
public:

    void setupUi(QDialog *editar)
    {
        if (editar->objectName().isEmpty())
            editar->setObjectName("editar");
        editar->resize(400, 566);

        retranslateUi(editar);

        QMetaObject::connectSlotsByName(editar);
    } // setupUi

    void retranslateUi(QDialog *editar)
    {
        editar->setWindowTitle(QCoreApplication::translate("editar", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editar: public Ui_editar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITAR_H
