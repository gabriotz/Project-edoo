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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_loanBookWindow
{
public:
    QLabel *label;
    QLabel *bookLabel;
    QPushButton *loanButton;
    QPushButton *previousButton;
    QPushButton *nextButton;

    void setupUi(QDialog *loanBookWindow)
    {
        if (loanBookWindow->objectName().isEmpty())
            loanBookWindow->setObjectName("loanBookWindow");
        loanBookWindow->resize(340, 385);
        label = new QLabel(loanBookWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 60, 121, 31));
        bookLabel = new QLabel(loanBookWindow);
        bookLabel->setObjectName("bookLabel");
        bookLabel->setGeometry(QRect(90, 140, 161, 51));
        loanButton = new QPushButton(loanBookWindow);
        loanButton->setObjectName("loanButton");
        loanButton->setGeometry(QRect(100, 290, 111, 24));
        previousButton = new QPushButton(loanBookWindow);
        previousButton->setObjectName("previousButton");
        previousButton->setGeometry(QRect(10, 230, 75, 24));
        nextButton = new QPushButton(loanBookWindow);
        nextButton->setObjectName("nextButton");
        nextButton->setGeometry(QRect(240, 230, 75, 24));

        retranslateUi(loanBookWindow);

        QMetaObject::connectSlotsByName(loanBookWindow);
    } // setupUi

    void retranslateUi(QDialog *loanBookWindow)
    {
        loanBookWindow->setWindowTitle(QCoreApplication::translate("loanBookWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("loanBookWindow", "Pegar livro Emprestado", nullptr));
        bookLabel->setText(QCoreApplication::translate("loanBookWindow", "TextLabel", nullptr));
        loanButton->setText(QCoreApplication::translate("loanBookWindow", "Pegar emprestado", nullptr));
        previousButton->setText(QCoreApplication::translate("loanBookWindow", "anterior", nullptr));
        nextButton->setText(QCoreApplication::translate("loanBookWindow", "proximo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loanBookWindow: public Ui_loanBookWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOANBOOKWINDOW_H
