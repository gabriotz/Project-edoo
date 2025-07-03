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

QT_BEGIN_NAMESPACE

class Ui_userBooksWindow
{
public:
    QLabel *label;
    QListWidget *myBooksListWidget;
    QPushButton *returnButton;

    void setupUi(QDialog *userBooksWindow)
    {
        if (userBooksWindow->objectName().isEmpty())
            userBooksWindow->setObjectName("userBooksWindow");
        userBooksWindow->resize(400, 300);
        label = new QLabel(userBooksWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 20, 71, 16));
        myBooksListWidget = new QListWidget(userBooksWindow);
        myBooksListWidget->setObjectName("myBooksListWidget");
        myBooksListWidget->setGeometry(QRect(60, 60, 261, 91));
        returnButton = new QPushButton(userBooksWindow);
        returnButton->setObjectName("returnButton");
        returnButton->setGeometry(QRect(220, 180, 75, 24));

        retranslateUi(userBooksWindow);

        QMetaObject::connectSlotsByName(userBooksWindow);
    } // setupUi

    void retranslateUi(QDialog *userBooksWindow)
    {
        userBooksWindow->setWindowTitle(QCoreApplication::translate("userBooksWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("userBooksWindow", "MEUS LIVROS", nullptr));
        returnButton->setText(QCoreApplication::translate("userBooksWindow", "DEVOLVER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userBooksWindow: public Ui_userBooksWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERBOOKSWINDOW_H
