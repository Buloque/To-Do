/********************************************************************************
** Form generated from reading UI file 'abrirnota.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABRIRNOTA_H
#define UI_ABRIRNOTA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_abrirNota
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lblTitulo;
    QComboBox *cbAndamento;
    QComboBox *cbUrgencia;
    QHBoxLayout *horizontalLayout_2;
    QLabel *DiaeHora;
    QTextEdit *bloco;

    void setupUi(QDialog *abrirNota)
    {
        if (abrirNota->objectName().isEmpty())
            abrirNota->setObjectName("abrirNota");
        abrirNota->resize(655, 400);
        abrirNota->setMinimumSize(QSize(655, 400));
        gridLayout = new QGridLayout(abrirNota);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lblTitulo = new QLabel(abrirNota);
        lblTitulo->setObjectName("lblTitulo");

        horizontalLayout->addWidget(lblTitulo);

        cbAndamento = new QComboBox(abrirNota);
        cbAndamento->addItem(QString());
        cbAndamento->addItem(QString());
        cbAndamento->addItem(QString());
        cbAndamento->setObjectName("cbAndamento");

        horizontalLayout->addWidget(cbAndamento);

        cbUrgencia = new QComboBox(abrirNota);
        cbUrgencia->addItem(QString());
        cbUrgencia->addItem(QString());
        cbUrgencia->addItem(QString());
        cbUrgencia->addItem(QString());
        cbUrgencia->setObjectName("cbUrgencia");

        horizontalLayout->addWidget(cbUrgencia);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        DiaeHora = new QLabel(abrirNota);
        DiaeHora->setObjectName("DiaeHora");

        horizontalLayout_2->addWidget(DiaeHora);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        bloco = new QTextEdit(abrirNota);
        bloco->setObjectName("bloco");
        bloco->setReadOnly(true);

        gridLayout->addWidget(bloco, 2, 0, 1, 1);


        retranslateUi(abrirNota);

        QMetaObject::connectSlotsByName(abrirNota);
    } // setupUi

    void retranslateUi(QDialog *abrirNota)
    {
        abrirNota->setWindowTitle(QCoreApplication::translate("abrirNota", "Dialog", nullptr));
        lblTitulo->setText(QCoreApplication::translate("abrirNota", "Titulo", nullptr));
        cbAndamento->setItemText(0, QCoreApplication::translate("abrirNota", "\360\237\232\266 Em andamento", nullptr));
        cbAndamento->setItemText(1, QCoreApplication::translate("abrirNota", "\360\237\232\251 Finalizado", nullptr));
        cbAndamento->setItemText(2, QCoreApplication::translate("abrirNota", "\342\235\214 Cancelado", nullptr));

        cbUrgencia->setItemText(0, QCoreApplication::translate("abrirNota", "\360\237\237\242 Baixo", nullptr));
        cbUrgencia->setItemText(1, QCoreApplication::translate("abrirNota", "\360\237\237\241 M\303\251dio", nullptr));
        cbUrgencia->setItemText(2, QCoreApplication::translate("abrirNota", "\360\237\237\240 Alto", nullptr));
        cbUrgencia->setItemText(3, QCoreApplication::translate("abrirNota", "\360\237\224\264 Urgente", nullptr));

        DiaeHora->setText(QCoreApplication::translate("abrirNota", "Dia: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class abrirNota: public Ui_abrirNota {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABRIRNOTA_H
