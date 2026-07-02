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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_Historico
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QListWidget *lwHistorico;

    void setupUi(QDialog *Historico)
    {
        if (Historico->objectName().isEmpty())
            Historico->setObjectName("Historico");
        Historico->resize(400, 600);
        Historico->setMinimumSize(QSize(400, 600));
        Historico->setMaximumSize(QSize(400, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/IMG/Imagens/Icone Sem Fundopng.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Historico->setWindowIcon(icon);
        gridLayout = new QGridLayout(Historico);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        lwHistorico = new QListWidget(Historico);
        lwHistorico->setObjectName("lwHistorico");

        gridLayout->addWidget(lwHistorico, 1, 0, 1, 1);


        retranslateUi(Historico);

        QMetaObject::connectSlotsByName(Historico);
    } // setupUi

    void retranslateUi(QDialog *Historico)
    {
        Historico->setWindowTitle(QCoreApplication::translate("Historico", "Historico", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Historico: public Ui_Historico {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORICO_H
