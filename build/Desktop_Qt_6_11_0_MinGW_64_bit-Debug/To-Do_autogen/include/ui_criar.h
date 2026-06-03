/********************************************************************************
** Form generated from reading UI file 'criar.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CRIAR_H
#define UI_CRIAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_criar
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *leTitulo;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pbNegrito;
    QPushButton *pbItalic;
    QPushButton *pbStrikeOut;
    QPushButton *pbUnderline;
    QDateEdit *dateEdit;
    QTimeEdit *timeEdit;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbSalvar;
    QPushButton *pbCancelar;
    QLabel *label;

    void setupUi(QDialog *criar)
    {
        if (criar->objectName().isEmpty())
            criar->setObjectName("criar");
        criar->resize(665, 400);
        criar->setMinimumSize(QSize(665, 400));
        verticalLayout = new QVBoxLayout(criar);
        verticalLayout->setObjectName("verticalLayout");
        leTitulo = new QLineEdit(criar);
        leTitulo->setObjectName("leTitulo");

        verticalLayout->addWidget(leTitulo);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pbNegrito = new QPushButton(criar);
        pbNegrito->setObjectName("pbNegrito");
        QFont font;
        font.setBold(true);
        pbNegrito->setFont(font);

        horizontalLayout_2->addWidget(pbNegrito);

        pbItalic = new QPushButton(criar);
        pbItalic->setObjectName("pbItalic");
        QFont font1;
        font1.setItalic(true);
        pbItalic->setFont(font1);

        horizontalLayout_2->addWidget(pbItalic);

        pbStrikeOut = new QPushButton(criar);
        pbStrikeOut->setObjectName("pbStrikeOut");
        QFont font2;
        font2.setItalic(true);
        font2.setStrikeOut(true);
        font2.setKerning(true);
        pbStrikeOut->setFont(font2);

        horizontalLayout_2->addWidget(pbStrikeOut);

        pbUnderline = new QPushButton(criar);
        pbUnderline->setObjectName("pbUnderline");
        QFont font3;
        font3.setItalic(false);
        font3.setUnderline(true);
        pbUnderline->setFont(font3);

        horizontalLayout_2->addWidget(pbUnderline);

        dateEdit = new QDateEdit(criar);
        dateEdit->setObjectName("dateEdit");

        horizontalLayout_2->addWidget(dateEdit);

        timeEdit = new QTimeEdit(criar);
        timeEdit->setObjectName("timeEdit");
        timeEdit->setWrapping(false);
        timeEdit->setFrame(true);
        timeEdit->setReadOnly(false);

        horizontalLayout_2->addWidget(timeEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        plainTextEdit = new QPlainTextEdit(criar);
        plainTextEdit->setObjectName("plainTextEdit");

        verticalLayout->addWidget(plainTextEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pbSalvar = new QPushButton(criar);
        pbSalvar->setObjectName("pbSalvar");

        horizontalLayout->addWidget(pbSalvar);

        pbCancelar = new QPushButton(criar);
        pbCancelar->setObjectName("pbCancelar");

        horizontalLayout->addWidget(pbCancelar);


        verticalLayout->addLayout(horizontalLayout);

        label = new QLabel(criar);
        label->setObjectName("label");

        verticalLayout->addWidget(label);


        retranslateUi(criar);

        QMetaObject::connectSlotsByName(criar);
    } // setupUi

    void retranslateUi(QDialog *criar)
    {
        criar->setWindowTitle(QCoreApplication::translate("criar", "Dialog", nullptr));
        leTitulo->setText(QCoreApplication::translate("criar", "Titulo", nullptr));
        pbNegrito->setText(QCoreApplication::translate("criar", "B", nullptr));
        pbItalic->setText(QCoreApplication::translate("criar", "i", nullptr));
        pbStrikeOut->setText(QCoreApplication::translate("criar", "S", nullptr));
        pbUnderline->setText(QCoreApplication::translate("criar", "u", nullptr));
        pbSalvar->setText(QCoreApplication::translate("criar", "Salvar", nullptr));
        pbCancelar->setText(QCoreApplication::translate("criar", "Cancelar", nullptr));
        label->setText(QCoreApplication::translate("criar", "Info adicionais", nullptr));
    } // retranslateUi

};

namespace Ui {
    class criar: public Ui_criar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRIAR_H
