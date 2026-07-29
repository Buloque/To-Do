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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_abrirNota
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QComboBox *cbUrgencia;
    QLabel *TxtAndamento;
    QComboBox *cbAndamento;
    QTextEdit *bloco;
    QLabel *DiaeHora;

    void setupUi(QDialog *abrirNota)
    {
        if (abrirNota->objectName().isEmpty())
            abrirNota->setObjectName("abrirNota");
        abrirNota->resize(655, 400);
        abrirNota->setMinimumSize(QSize(655, 400));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/IMG/Imagens/Icone Sem Fundopng.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        abrirNota->setWindowIcon(icon);
        gridLayout = new QGridLayout(abrirNota);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");

        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(abrirNota);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        cbUrgencia = new QComboBox(abrirNota);
        cbUrgencia->addItem(QString());
        cbUrgencia->addItem(QString());
        cbUrgencia->addItem(QString());
        cbUrgencia->addItem(QString());
        cbUrgencia->setObjectName("cbUrgencia");
        cbUrgencia->setEnabled(true);
        cbUrgencia->setEditable(false);
        cbUrgencia->setSizeAdjustPolicy(QComboBox::SizeAdjustPolicy::AdjustToContentsOnFirstShow);
        cbUrgencia->setFrame(true);
        cbUrgencia->setLabelDrawingMode(QComboBox::LabelDrawingMode::UseStyle);

        horizontalLayout->addWidget(cbUrgencia);

        TxtAndamento = new QLabel(abrirNota);
        TxtAndamento->setObjectName("TxtAndamento");
        TxtAndamento->setMaximumSize(QSize(70, 16777215));

        horizontalLayout->addWidget(TxtAndamento);

        cbAndamento = new QComboBox(abrirNota);
        cbAndamento->addItem(QString());
        cbAndamento->addItem(QString());
        cbAndamento->addItem(QString());
        cbAndamento->setObjectName("cbAndamento");

        horizontalLayout->addWidget(cbAndamento);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        bloco = new QTextEdit(abrirNota);
        bloco->setObjectName("bloco");
        bloco->setReadOnly(true);

        gridLayout->addWidget(bloco, 2, 0, 1, 1);

        DiaeHora = new QLabel(abrirNota);
        DiaeHora->setObjectName("DiaeHora");

        gridLayout->addWidget(DiaeHora, 3, 0, 1, 1);


        retranslateUi(abrirNota);

        QMetaObject::connectSlotsByName(abrirNota);
    } // setupUi

    void retranslateUi(QDialog *abrirNota)
    {
        abrirNota->setWindowTitle(QCoreApplication::translate("abrirNota", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("abrirNota", "Prazo:", nullptr));
        cbUrgencia->setItemText(0, QCoreApplication::translate("abrirNota", "\360\237\237\242 Baixo", nullptr));
        cbUrgencia->setItemText(1, QCoreApplication::translate("abrirNota", "\360\237\237\241 M\303\251dio", nullptr));
        cbUrgencia->setItemText(2, QCoreApplication::translate("abrirNota", "\360\237\237\240 Alto", nullptr));
        cbUrgencia->setItemText(3, QCoreApplication::translate("abrirNota", "\360\237\224\264 Urgente", nullptr));

        TxtAndamento->setText(QCoreApplication::translate("abrirNota", "Andamento:", nullptr));
        cbAndamento->setItemText(0, QCoreApplication::translate("abrirNota", "\360\237\232\266 Em andamento", nullptr));
        cbAndamento->setItemText(1, QCoreApplication::translate("abrirNota", "\360\237\232\251 Finalizado", nullptr));
        cbAndamento->setItemText(2, QCoreApplication::translate("abrirNota", "\342\235\214 Cancelado", nullptr));

        DiaeHora->setText(QCoreApplication::translate("abrirNota", "Dia: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class abrirNota: public Ui_abrirNota {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABRIRNOTA_H
