/********************************************************************************
** Form generated from reading UI file 'userbookswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERBOOKSWINDOW_H
#define UI_USERBOOKSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userBooksWindow
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QListWidget *myBooksListWidget;
    QPushButton *returnButton;

    void setupUi(QDialog *userBooksWindow)
    {
        if (userBooksWindow->objectName().isEmpty())
            userBooksWindow->setObjectName("userBooksWindow");
        userBooksWindow->resize(800, 450);
        userBooksWindow->setStyleSheet(QString::fromUtf8(""));
        widget = new QWidget(userBooksWindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(70, 70, 661, 311));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 58, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        label = new QLabel(widget);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        myBooksListWidget = new QListWidget(widget);
        myBooksListWidget->setObjectName("myBooksListWidget");
        myBooksListWidget->setStyleSheet(QString::fromUtf8("    background-color: #ED1C24; /* Fundo vermelho CIn */\n"
"    color: white; /* Texto branco */\n"
"    padding: 5px;\n"
"    border: 1px solid #8B0000; /* Borda entre as se\303\247\303\265es */\n"
"    font-family: \"Segoe UI\";\n"
"    font-weight: bold;\n"
"    font-size: 10pt;"));

        verticalLayout_2->addWidget(myBooksListWidget);

        returnButton = new QPushButton(widget);
        returnButton->setObjectName("returnButton");
        returnButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: #ED1C24;\n"
"border: 2px solid #ED1C24;\n"
"padding: 8px 16px;\n"
"font-size: 14px;\n"
"font-weight: bold;\n"
"border-radius: 8px;"));

        verticalLayout_2->addWidget(returnButton);


        retranslateUi(userBooksWindow);

        QMetaObject::connectSlotsByName(userBooksWindow);
    } // setupUi

    void retranslateUi(QDialog *userBooksWindow)
    {
        userBooksWindow->setWindowTitle(QCoreApplication::translate("userBooksWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("userBooksWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:700;\">MEUS LIVROS</span></p></body></html>", nullptr));
        returnButton->setText(QCoreApplication::translate("userBooksWindow", "DEVOLVER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userBooksWindow: public Ui_userBooksWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERBOOKSWINDOW_H
