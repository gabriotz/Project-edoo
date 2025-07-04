/********************************************************************************
** Form generated from reading UI file 'loanbookwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOANBOOKWINDOW_H
#define UI_LOANBOOKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loanBookWindow
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *bookLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *nextButton;
    QPushButton *previousButton;
    QPushButton *loanButton;

    void setupUi(QDialog *loanBookWindow)
    {
        if (loanBookWindow->objectName().isEmpty())
            loanBookWindow->setObjectName("loanBookWindow");
        loanBookWindow->resize(800, 450);
        layoutWidget = new QWidget(loanBookWindow);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(70, 70, 661, 311));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        bookLabel = new QLabel(layoutWidget);
        bookLabel->setObjectName("bookLabel");
        bookLabel->setStyleSheet(QString::fromUtf8("    background-color: #ED1C24; /* Fundo vermelho CIn */\n"
"    color: white; /* Texto branco */\n"
"    padding: 5px;\n"
"    border: 1px solid #8B0000; /* Borda entre as se\303\247\303\265es */\n"
"    font-family: \"Segoe UI\";\n"
"    font-weight: bold;\n"
"    font-size: 10pt;"));

        verticalLayout->addWidget(bookLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        nextButton = new QPushButton(layoutWidget);
        nextButton->setObjectName("nextButton");
        nextButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: #ED1C24;\n"
"border: 2px solid #ED1C24;\n"
"padding: 8px 16px;\n"
"font-size: 14px;\n"
"font-weight: bold;\n"
"border-radius: 8px;\n"
"font: 700 12pt \"Segoe UI\";"));

        horizontalLayout->addWidget(nextButton);

        previousButton = new QPushButton(layoutWidget);
        previousButton->setObjectName("previousButton");
        previousButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: #ED1C24;\n"
"border: 2px solid #ED1C24;\n"
"padding: 8px 16px;\n"
"font-size: 14px;\n"
"font-weight: bold;\n"
"border-radius: 8px;\n"
"font: 700 12pt \"Segoe UI\";"));

        horizontalLayout->addWidget(previousButton);


        verticalLayout->addLayout(horizontalLayout);

        loanButton = new QPushButton(layoutWidget);
        loanButton->setObjectName("loanButton");
        loanButton->setStyleSheet(QString::fromUtf8("background: qlineargradient(\n"
"    x1:0, y1:0, x2:1, y2:0,\n"
"    stop:0 #8B0000, stop:1 #ED1C24\n"
");\n"
"color: white;\n"
"border: none;\n"
"padding: 12px 20px;\n"
"font-size: 15px;\n"
"font-weight: bold;\n"
"border-radius: 10px;\n"
"text-align: center;\n"
""));

        verticalLayout->addWidget(loanButton);


        retranslateUi(loanBookWindow);

        QMetaObject::connectSlotsByName(loanBookWindow);
    } // setupUi

    void retranslateUi(QDialog *loanBookWindow)
    {
        loanBookWindow->setWindowTitle(QCoreApplication::translate("loanBookWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("loanBookWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:700;\">EMPR\303\211STIMO DE LIVRO</span></p></body></html>", nullptr));
        bookLabel->setText(QCoreApplication::translate("loanBookWindow", "TextLabel", nullptr));
        nextButton->setText(QCoreApplication::translate("loanBookWindow", "PR\303\223XIMO", nullptr));
        previousButton->setText(QCoreApplication::translate("loanBookWindow", "ANTERIOR", nullptr));
        loanButton->setText(QCoreApplication::translate("loanBookWindow", "PEGAR EMPRESTADO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loanBookWindow: public Ui_loanBookWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOANBOOKWINDOW_H
