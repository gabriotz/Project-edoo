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

QT_BEGIN_NAMESPACE

class Ui_seeAllBooksWindow
{
public:
    QLabel *label;
    QLabel *bookLabel;
    QPushButton *previousButton;
    QPushButton *nextButton;

    void setupUi(QDialog *seeAllBooksWindow)
    {
        if (seeAllBooksWindow->objectName().isEmpty())
            seeAllBooksWindow->setObjectName("seeAllBooksWindow");
        seeAllBooksWindow->resize(400, 300);
        label = new QLabel(seeAllBooksWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 20, 101, 20));
        bookLabel = new QLabel(seeAllBooksWindow);
        bookLabel->setObjectName("bookLabel");
        bookLabel->setGeometry(QRect(90, 60, 201, 61));
        bookLabel->setWordWrap(true);
        previousButton = new QPushButton(seeAllBooksWindow);
        previousButton->setObjectName("previousButton");
        previousButton->setGeometry(QRect(40, 140, 75, 24));
        nextButton = new QPushButton(seeAllBooksWindow);
        nextButton->setObjectName("nextButton");
        nextButton->setGeometry(QRect(270, 140, 75, 24));

        retranslateUi(seeAllBooksWindow);

        QMetaObject::connectSlotsByName(seeAllBooksWindow);
    } // setupUi

    void retranslateUi(QDialog *seeAllBooksWindow)
    {
        seeAllBooksWindow->setWindowTitle(QCoreApplication::translate("seeAllBooksWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("seeAllBooksWindow", "Livros na Biblioteca", nullptr));
        bookLabel->setText(QCoreApplication::translate("seeAllBooksWindow", "TextLabel", nullptr));
        previousButton->setText(QCoreApplication::translate("seeAllBooksWindow", "Anterior", nullptr));
        nextButton->setText(QCoreApplication::translate("seeAllBooksWindow", "Proximo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class seeAllBooksWindow: public Ui_seeAllBooksWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEEALLBOOKSWINDOW_H
