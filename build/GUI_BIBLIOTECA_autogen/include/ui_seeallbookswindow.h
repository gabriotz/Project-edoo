/********************************************************************************
** Form generated from reading UI file 'seeallbookswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEEALLBOOKSWINDOW_H
#define UI_SEEALLBOOKSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_seeAllBooksWindow
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *bookLabel;
    QPushButton *nextButton;
    QPushButton *previousButton;

    void setupUi(QDialog *seeAllBooksWindow)
    {
        if (seeAllBooksWindow->objectName().isEmpty())
            seeAllBooksWindow->setObjectName("seeAllBooksWindow");
        seeAllBooksWindow->resize(800, 450);
        layoutWidget = new QWidget(seeAllBooksWindow);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(110, 70, 621, 311));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(label);

        bookLabel = new QLabel(layoutWidget);
        bookLabel->setObjectName("bookLabel");
        bookLabel->setStyleSheet(QString::fromUtf8("\n"
"    background-color: #ED1C24; /* Fundo vermelho CIn */\n"
"    color: white; /* Texto branco */\n"
"    padding: 5px;\n"
"    border: 1px solid #8B0000; /* Borda entre as se\303\247\303\265es */\n"
"    font-family: \"Segoe UI\";\n"
"    font-weight: bold;\n"
"    font-size: 10pt;\n"
"\n"
"QTableView { /* Estilo da tabela */\n"
"    background-color: white;\n"
"    gridline-color: #F0F0F0; /* Cor da grade */\n"
"    selection-background-color: #FFE5E5; /* Cor da sele\303\247\303\243o (levemente rosado) */\n"
"    selection-color: #2D2D2D; /* Cor do texto selecionado */\n"
"    border: 1px solid #CCCCCC;\n"
"    border-radius: 8px;\n"
"}\n"
"QTableView::item { /* Estilo de cada item/c\303\251lula */\n"
"    padding: 5px;\n"
"    font-family: \"Segoe UI\";\n"
"    font-size: 9pt;\n"
"    color: #2D2D2D;\n"
"}\n"
"QTableView::item:alternate { /* Linhas alternadas */\n"
"    background-color: #F8F8F8;\n"
"}"));
        bookLabel->setWordWrap(true);

        verticalLayout->addWidget(bookLabel);

        nextButton = new QPushButton(layoutWidget);
        nextButton->setObjectName("nextButton");
        nextButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: #ED1C24;\n"
"border: 2px solid #ED1C24;\n"
"padding: 8px 16px;\n"
"font-size: 14px;\n"
"font-weight: bold;\n"
"border-radius: 8px;"));

        verticalLayout->addWidget(nextButton);

        previousButton = new QPushButton(layoutWidget);
        previousButton->setObjectName("previousButton");
        previousButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: #ED1C24;\n"
"border: 2px solid #ED1C24;\n"
"padding: 8px 16px;\n"
"font-size: 14px;\n"
"font-weight: bold;\n"
"border-radius: 8px;"));

        verticalLayout->addWidget(previousButton);


        retranslateUi(seeAllBooksWindow);

        QMetaObject::connectSlotsByName(seeAllBooksWindow);
    } // setupUi

    void retranslateUi(QDialog *seeAllBooksWindow)
    {
        seeAllBooksWindow->setWindowTitle(QCoreApplication::translate("seeAllBooksWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("seeAllBooksWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:700; color:#2d2d2d;\">LIVROS DA BIBLIOTECA</span></p></body></html>", nullptr));
        bookLabel->setText(QCoreApplication::translate("seeAllBooksWindow", "<html><head/><body><p align=\"center\">TextLabel</p></body></html>", nullptr));
        nextButton->setText(QCoreApplication::translate("seeAllBooksWindow", "PR\303\223XIMO", nullptr));
        previousButton->setText(QCoreApplication::translate("seeAllBooksWindow", "ANTERIOR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class seeAllBooksWindow: public Ui_seeAllBooksWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEEALLBOOKSWINDOW_H
