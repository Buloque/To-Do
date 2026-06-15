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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_editar
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pbNegrito_2;
    QPushButton *pbItalic_2;
    QPushButton *pbStrikeOut_2;
    QPushButton *pbUnderline_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pbReset_2;
    QSpacerItem *horizontalSpacer_4;
    QDateEdit *dateEdit_2;
    QPushButton *pbDia_2;
    QTimeEdit *timeEdit_2;
    QPushButton *pbHora_2;
    QComboBox *cbUrgencia_2;
    QLineEdit *leTitulo;
    QTextEdit *texto;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pbSalvarLocal_2;
    QPushButton *pbSalvar_2;
    QPushButton *pbCancelar_2;
    QLabel *lblInfo;

    void setupUi(QDialog *editar)
    {
        if (editar->objectName().isEmpty())
            editar->setObjectName("editar");
        editar->resize(655, 400);
        editar->setMinimumSize(QSize(655, 400));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/IMG/Imagens/Icone Sem Fundopng.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        editar->setWindowIcon(icon);
        gridLayout = new QGridLayout(editar);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pbNegrito_2 = new QPushButton(editar);
        pbNegrito_2->setObjectName("pbNegrito_2");
        pbNegrito_2->setMaximumSize(QSize(30, 30));
        QFont font;
        font.setBold(true);
        pbNegrito_2->setFont(font);

        horizontalLayout_3->addWidget(pbNegrito_2);

        pbItalic_2 = new QPushButton(editar);
        pbItalic_2->setObjectName("pbItalic_2");
        pbItalic_2->setMaximumSize(QSize(30, 30));
        QFont font1;
        font1.setItalic(true);
        pbItalic_2->setFont(font1);

        horizontalLayout_3->addWidget(pbItalic_2);

        pbStrikeOut_2 = new QPushButton(editar);
        pbStrikeOut_2->setObjectName("pbStrikeOut_2");
        pbStrikeOut_2->setMaximumSize(QSize(30, 30));
        QFont font2;
        font2.setItalic(true);
        font2.setStrikeOut(true);
        font2.setKerning(true);
        pbStrikeOut_2->setFont(font2);

        horizontalLayout_3->addWidget(pbStrikeOut_2);

        pbUnderline_2 = new QPushButton(editar);
        pbUnderline_2->setObjectName("pbUnderline_2");
        pbUnderline_2->setMaximumSize(QSize(30, 30));
        QFont font3;
        font3.setItalic(false);
        font3.setUnderline(true);
        pbUnderline_2->setFont(font3);

        horizontalLayout_3->addWidget(pbUnderline_2);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pbReset_2 = new QPushButton(editar);
        pbReset_2->setObjectName("pbReset_2");
        pbReset_2->setMaximumSize(QSize(30, 30));

        horizontalLayout_3->addWidget(pbReset_2);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        dateEdit_2 = new QDateEdit(editar);
        dateEdit_2->setObjectName("dateEdit_2");
        dateEdit_2->setTimeSpec(Qt::TimeSpec::LocalTime);

        horizontalLayout_3->addWidget(dateEdit_2);

        pbDia_2 = new QPushButton(editar);
        pbDia_2->setObjectName("pbDia_2");
        pbDia_2->setMaximumSize(QSize(30, 30));

        horizontalLayout_3->addWidget(pbDia_2);

        timeEdit_2 = new QTimeEdit(editar);
        timeEdit_2->setObjectName("timeEdit_2");
        timeEdit_2->setWrapping(false);
        timeEdit_2->setFrame(true);
        timeEdit_2->setReadOnly(false);
        timeEdit_2->setTimeSpec(Qt::TimeSpec::LocalTime);

        horizontalLayout_3->addWidget(timeEdit_2);

        pbHora_2 = new QPushButton(editar);
        pbHora_2->setObjectName("pbHora_2");
        pbHora_2->setMaximumSize(QSize(30, 30));

        horizontalLayout_3->addWidget(pbHora_2);

        cbUrgencia_2 = new QComboBox(editar);
        cbUrgencia_2->addItem(QString());
        cbUrgencia_2->addItem(QString());
        cbUrgencia_2->addItem(QString());
        cbUrgencia_2->addItem(QString());
        cbUrgencia_2->setObjectName("cbUrgencia_2");

        horizontalLayout_3->addWidget(cbUrgencia_2);


        verticalLayout->addLayout(horizontalLayout_3);

        leTitulo = new QLineEdit(editar);
        leTitulo->setObjectName("leTitulo");

        verticalLayout->addWidget(leTitulo);

        texto = new QTextEdit(editar);
        texto->setObjectName("texto");

        verticalLayout->addWidget(texto);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        pbSalvarLocal_2 = new QPushButton(editar);
        pbSalvarLocal_2->setObjectName("pbSalvarLocal_2");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pbSalvarLocal_2->sizePolicy().hasHeightForWidth());
        pbSalvarLocal_2->setSizePolicy(sizePolicy);
        pbSalvarLocal_2->setMaximumSize(QSize(30, 30));

        horizontalLayout_4->addWidget(pbSalvarLocal_2);

        pbSalvar_2 = new QPushButton(editar);
        pbSalvar_2->setObjectName("pbSalvar_2");

        horizontalLayout_4->addWidget(pbSalvar_2);

        pbCancelar_2 = new QPushButton(editar);
        pbCancelar_2->setObjectName("pbCancelar_2");

        horizontalLayout_4->addWidget(pbCancelar_2);


        verticalLayout->addLayout(horizontalLayout_4);

        lblInfo = new QLabel(editar);
        lblInfo->setObjectName("lblInfo");

        verticalLayout->addWidget(lblInfo);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(editar);

        QMetaObject::connectSlotsByName(editar);
    } // setupUi

    void retranslateUi(QDialog *editar)
    {
        editar->setWindowTitle(QCoreApplication::translate("editar", "Editar", nullptr));
        pbNegrito_2->setText(QCoreApplication::translate("editar", "B", nullptr));
        pbItalic_2->setText(QCoreApplication::translate("editar", "i", nullptr));
        pbStrikeOut_2->setText(QCoreApplication::translate("editar", "S", nullptr));
        pbUnderline_2->setText(QCoreApplication::translate("editar", "u", nullptr));
        pbReset_2->setText(QCoreApplication::translate("editar", "R", nullptr));
        pbDia_2->setText(QCoreApplication::translate("editar", "D", nullptr));
        pbHora_2->setText(QCoreApplication::translate("editar", "H", nullptr));
        cbUrgencia_2->setItemText(0, QCoreApplication::translate("editar", "\360\237\237\242 Baixo", nullptr));
        cbUrgencia_2->setItemText(1, QCoreApplication::translate("editar", "\360\237\237\241 M\303\251dio", nullptr));
        cbUrgencia_2->setItemText(2, QCoreApplication::translate("editar", "\360\237\237\240 Alto", nullptr));
        cbUrgencia_2->setItemText(3, QCoreApplication::translate("editar", "\360\237\224\264 Urgente", nullptr));

        leTitulo->setText(QString());
        pbSalvarLocal_2->setText(QCoreApplication::translate("editar", "\360\237\222\276", nullptr));
        pbSalvar_2->setText(QCoreApplication::translate("editar", "Salvar", nullptr));
        pbCancelar_2->setText(QCoreApplication::translate("editar", "Cancelar", nullptr));
        lblInfo->setText(QCoreApplication::translate("editar", "Linha: 0  coluna: 0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editar: public Ui_editar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITAR_H
