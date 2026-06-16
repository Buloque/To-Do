/********************************************************************************
** Form generated from reading UI file 'pagina_inicial.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGINA_INICIAL_H
#define UI_PAGINA_INICIAL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Pagina_Inicial
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *pbSair;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnCriar;
    QPushButton *btnEditar;
    QPushButton *btnApagar;
    QListWidget *lwTodosT;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *lblReg;

    void setupUi(QDialog *Pagina_Inicial)
    {
        if (Pagina_Inicial->objectName().isEmpty())
            Pagina_Inicial->setObjectName("Pagina_Inicial");
        Pagina_Inicial->resize(400, 600);
        Pagina_Inicial->setMinimumSize(QSize(400, 600));
        Pagina_Inicial->setMaximumSize(QSize(400, 600));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/IMG/Imagens/Icone Sem Fundopng.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Pagina_Inicial->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(Pagina_Inicial);
        gridLayout_2->setObjectName("gridLayout_2");
        pbSair = new QPushButton(Pagina_Inicial);
        pbSair->setObjectName("pbSair");
        pbSair->setEnabled(false);
        pbSair->setCheckable(true);
        pbSair->setAutoDefault(true);
        pbSair->setFlat(true);

        gridLayout_2->addWidget(pbSair, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnCriar = new QPushButton(Pagina_Inicial);
        btnCriar->setObjectName("btnCriar");

        horizontalLayout->addWidget(btnCriar);

        btnEditar = new QPushButton(Pagina_Inicial);
        btnEditar->setObjectName("btnEditar");
        btnEditar->setEnabled(true);

        horizontalLayout->addWidget(btnEditar);

        btnApagar = new QPushButton(Pagina_Inicial);
        btnApagar->setObjectName("btnApagar");

        horizontalLayout->addWidget(btnApagar);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        lwTodosT = new QListWidget(Pagina_Inicial);
        lwTodosT->setObjectName("lwTodosT");
        lwTodosT->setEditTriggers(QAbstractItemView::EditTrigger::CurrentChanged|QAbstractItemView::EditTrigger::DoubleClicked|QAbstractItemView::EditTrigger::EditKeyPressed);

        gridLayout->addWidget(lwTodosT, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(250, -1, -1, -1);
        pushButton = new QPushButton(Pagina_Inicial);
        pushButton->setObjectName("pushButton");
        pushButton->setMaximumSize(QSize(35, 35));

        horizontalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(Pagina_Inicial);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMaximumSize(QSize(35, 35));

        horizontalLayout_3->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(Pagina_Inicial);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMaximumSize(QSize(35, 35));

        horizontalLayout_3->addWidget(pushButton_3);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 2);

        lblReg = new QLabel(Pagina_Inicial);
        lblReg->setObjectName("lblReg");
        QFont font;
        font.setPointSize(8);
        font.setKerning(true);
        lblReg->setFont(font);

        gridLayout_2->addWidget(lblReg, 2, 0, 1, 1);


        retranslateUi(Pagina_Inicial);

        pbSair->setDefault(true);


        QMetaObject::connectSlotsByName(Pagina_Inicial);
    } // setupUi

    void retranslateUi(QDialog *Pagina_Inicial)
    {
        Pagina_Inicial->setWindowTitle(QCoreApplication::translate("Pagina_Inicial", "Tela Principal", nullptr));
        pbSair->setText(QCoreApplication::translate("Pagina_Inicial", "Sair", nullptr));
        btnCriar->setText(QCoreApplication::translate("Pagina_Inicial", "Criar", nullptr));
        btnEditar->setText(QCoreApplication::translate("Pagina_Inicial", "Editar", nullptr));
        btnApagar->setText(QCoreApplication::translate("Pagina_Inicial", "Apagar", nullptr));
        pushButton->setText(QCoreApplication::translate("Pagina_Inicial", "1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Pagina_Inicial", "2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Pagina_Inicial", "3", nullptr));
        lblReg->setText(QCoreApplication::translate("Pagina_Inicial", "Total de Registros:  ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Pagina_Inicial: public Ui_Pagina_Inicial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGINA_INICIAL_H
