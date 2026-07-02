/********************************************************************************
** Form generated from reading UI file 'diferenca.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIFERENCA_H
#define UI_DIFERENCA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_diferenca
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QTextEdit *txtOriginal;
    QTextEdit *txtDiff;
    QWidget *horizontalLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *leOriginal;
    QLineEdit *leDiff;

    void setupUi(QDialog *diferenca)
    {
        if (diferenca->objectName().isEmpty())
            diferenca->setObjectName("diferenca");
        diferenca->resize(655, 400);
        diferenca->setMaximumSize(QSize(655, 400));
        horizontalLayoutWidget = new QWidget(diferenca);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(9, 50, 641, 341));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        txtOriginal = new QTextEdit(horizontalLayoutWidget);
        txtOriginal->setObjectName("txtOriginal");

        horizontalLayout->addWidget(txtOriginal);

        txtDiff = new QTextEdit(horizontalLayoutWidget);
        txtDiff->setObjectName("txtDiff");

        horizontalLayout->addWidget(txtDiff);

        horizontalLayoutWidget_2 = new QWidget(diferenca);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(9, 9, 641, 32));
        gridLayout_2 = new QGridLayout(horizontalLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        leOriginal = new QLineEdit(horizontalLayoutWidget_2);
        leOriginal->setObjectName("leOriginal");

        gridLayout_2->addWidget(leOriginal, 0, 0, 1, 1);

        leDiff = new QLineEdit(horizontalLayoutWidget_2);
        leDiff->setObjectName("leDiff");

        gridLayout_2->addWidget(leDiff, 0, 1, 1, 1);


        retranslateUi(diferenca);

        QMetaObject::connectSlotsByName(diferenca);
    } // setupUi

    void retranslateUi(QDialog *diferenca)
    {
        diferenca->setWindowTitle(QCoreApplication::translate("diferenca", "Dialog", nullptr));
        txtOriginal->setHtml(QCoreApplication::translate("diferenca", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        txtDiff->setHtml(QCoreApplication::translate("diferenca", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        leOriginal->setText(QString());
        leDiff->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class diferenca: public Ui_diferenca {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIFERENCA_H
