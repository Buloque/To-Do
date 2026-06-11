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
#include <QtGui/QIcon>
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
        editar->resize(655, 400);
        editar->setMinimumSize(QSize(655, 400));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/IMG/Imagens/Icone Sem Fundopng.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        editar->setWindowIcon(icon);

        retranslateUi(editar);

        QMetaObject::connectSlotsByName(editar);
    } // setupUi

    void retranslateUi(QDialog *editar)
    {
        editar->setWindowTitle(QCoreApplication::translate("editar", "Editar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editar: public Ui_editar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITAR_H
