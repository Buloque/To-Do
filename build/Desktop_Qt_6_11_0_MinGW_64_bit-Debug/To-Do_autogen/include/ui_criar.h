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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
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
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pbReset;
    QSpacerItem *horizontalSpacer;
    QDateEdit *dateEdit;
    QPushButton *pbDia;
    QTimeEdit *timeEdit;
    QPushButton *pbHora;
    QComboBox *cbUrgencia;
    QTextEdit *texto;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbSalvarLocal;
    QPushButton *pbSalvar;
    QPushButton *pbCancelar;
    QLabel *lblInfo;

    void setupUi(QDialog *criar)
    {
        if (criar->objectName().isEmpty())
            criar->setObjectName("criar");
        criar->resize(665, 400);
        criar->setMinimumSize(QSize(665, 400));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/IMG/Imagens/Icone Sem Fundopng.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        criar->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(criar);
        verticalLayout->setObjectName("verticalLayout");
        leTitulo = new QLineEdit(criar);
        leTitulo->setObjectName("leTitulo");

        verticalLayout->addWidget(leTitulo);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pbNegrito = new QPushButton(criar);
        pbNegrito->setObjectName("pbNegrito");
        pbNegrito->setMaximumSize(QSize(30, 30));
        QFont font;
        font.setBold(true);
        pbNegrito->setFont(font);

        horizontalLayout_2->addWidget(pbNegrito);

        pbItalic = new QPushButton(criar);
        pbItalic->setObjectName("pbItalic");
        pbItalic->setMaximumSize(QSize(30, 30));
        QFont font1;
        font1.setItalic(true);
        pbItalic->setFont(font1);

        horizontalLayout_2->addWidget(pbItalic);

        pbStrikeOut = new QPushButton(criar);
        pbStrikeOut->setObjectName("pbStrikeOut");
        pbStrikeOut->setMaximumSize(QSize(30, 30));
        QFont font2;
        font2.setItalic(true);
        font2.setStrikeOut(true);
        font2.setKerning(true);
        pbStrikeOut->setFont(font2);

        horizontalLayout_2->addWidget(pbStrikeOut);

        pbUnderline = new QPushButton(criar);
        pbUnderline->setObjectName("pbUnderline");
        pbUnderline->setMaximumSize(QSize(30, 30));
        QFont font3;
        font3.setItalic(false);
        font3.setUnderline(true);
        pbUnderline->setFont(font3);

        horizontalLayout_2->addWidget(pbUnderline);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pbReset = new QPushButton(criar);
        pbReset->setObjectName("pbReset");
        pbReset->setMaximumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(pbReset);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        dateEdit = new QDateEdit(criar);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setTimeSpec(Qt::TimeSpec::LocalTime);

        horizontalLayout_2->addWidget(dateEdit);

        pbDia = new QPushButton(criar);
        pbDia->setObjectName("pbDia");
        pbDia->setMaximumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(pbDia);

        timeEdit = new QTimeEdit(criar);
        timeEdit->setObjectName("timeEdit");
        timeEdit->setWrapping(false);
        timeEdit->setFrame(true);
        timeEdit->setReadOnly(false);
        timeEdit->setTimeSpec(Qt::TimeSpec::LocalTime);

        horizontalLayout_2->addWidget(timeEdit);

        pbHora = new QPushButton(criar);
        pbHora->setObjectName("pbHora");
        pbHora->setMaximumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(pbHora);

        cbUrgencia = new QComboBox(criar);
        cbUrgencia->addItem(QString());
        cbUrgencia->addItem(QString());
        cbUrgencia->addItem(QString());
        cbUrgencia->addItem(QString());
        cbUrgencia->setObjectName("cbUrgencia");

        horizontalLayout_2->addWidget(cbUrgencia);


        verticalLayout->addLayout(horizontalLayout_2);

        texto = new QTextEdit(criar);
        texto->setObjectName("texto");

        verticalLayout->addWidget(texto);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pbSalvarLocal = new QPushButton(criar);
        pbSalvarLocal->setObjectName("pbSalvarLocal");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pbSalvarLocal->sizePolicy().hasHeightForWidth());
        pbSalvarLocal->setSizePolicy(sizePolicy);
        pbSalvarLocal->setMaximumSize(QSize(30, 30));

        horizontalLayout->addWidget(pbSalvarLocal);

        pbSalvar = new QPushButton(criar);
        pbSalvar->setObjectName("pbSalvar");

        horizontalLayout->addWidget(pbSalvar);

        pbCancelar = new QPushButton(criar);
        pbCancelar->setObjectName("pbCancelar");

        horizontalLayout->addWidget(pbCancelar);


        verticalLayout->addLayout(horizontalLayout);

        lblInfo = new QLabel(criar);
        lblInfo->setObjectName("lblInfo");

        verticalLayout->addWidget(lblInfo);


        retranslateUi(criar);

        QMetaObject::connectSlotsByName(criar);
    } // setupUi

    void retranslateUi(QDialog *criar)
    {
        criar->setWindowTitle(QCoreApplication::translate("criar", "Criar", nullptr));
        leTitulo->setText(QString());
        pbNegrito->setText(QCoreApplication::translate("criar", "B", nullptr));
        pbItalic->setText(QCoreApplication::translate("criar", "i", nullptr));
        pbStrikeOut->setText(QCoreApplication::translate("criar", "S", nullptr));
        pbUnderline->setText(QCoreApplication::translate("criar", "u", nullptr));
        pbReset->setText(QCoreApplication::translate("criar", "R", nullptr));
        pbDia->setText(QCoreApplication::translate("criar", "D", nullptr));
        pbHora->setText(QCoreApplication::translate("criar", "H", nullptr));
        cbUrgencia->setItemText(0, QCoreApplication::translate("criar", "\360\237\237\242 Baixo", nullptr));
        cbUrgencia->setItemText(1, QCoreApplication::translate("criar", "\360\237\237\241 M\303\251dio", nullptr));
        cbUrgencia->setItemText(2, QCoreApplication::translate("criar", "\360\237\237\240 Alto", nullptr));
        cbUrgencia->setItemText(3, QCoreApplication::translate("criar", "\360\237\224\264 Urgente", nullptr));

        pbSalvarLocal->setText(QCoreApplication::translate("criar", "\360\237\222\276", nullptr));
        pbSalvar->setText(QCoreApplication::translate("criar", "Salvar", nullptr));
        pbCancelar->setText(QCoreApplication::translate("criar", "Cancelar", nullptr));
        lblInfo->setText(QCoreApplication::translate("criar", "Linha: 0  coluna: 0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class criar: public Ui_criar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRIAR_H
