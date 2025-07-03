/********************************************************************************
** Form generated from reading UI file 'addbookwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBOOKWINDOW_H
#define UI_ADDBOOKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_addBookWindow
{
public:
    QLabel *label;
    QLineEdit *namelineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *authorlineEdit;
    QLabel *label_4;
    QLineEdit *topiclineEdit;
    QLabel *label_5;
    QLineEdit *yearlineEdit;
    QPushButton *addBookButton;

    void setupUi(QDialog *addBookWindow)
    {
        if (addBookWindow->objectName().isEmpty())
            addBookWindow->setObjectName("addBookWindow");
        addBookWindow->resize(400, 383);
        label = new QLabel(addBookWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 20, 121, 16));
        namelineEdit = new QLineEdit(addBookWindow);
        namelineEdit->setObjectName("namelineEdit");
        namelineEdit->setGeometry(QRect(180, 80, 113, 22));
        label_2 = new QLabel(addBookWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 80, 61, 16));
        label_3 = new QLabel(addBookWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 130, 61, 16));
        authorlineEdit = new QLineEdit(addBookWindow);
        authorlineEdit->setObjectName("authorlineEdit");
        authorlineEdit->setGeometry(QRect(180, 130, 113, 22));
        label_4 = new QLabel(addBookWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(80, 170, 61, 16));
        topiclineEdit = new QLineEdit(addBookWindow);
        topiclineEdit->setObjectName("topiclineEdit");
        topiclineEdit->setGeometry(QRect(180, 170, 113, 22));
        label_5 = new QLabel(addBookWindow);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(50, 210, 121, 41));
        yearlineEdit = new QLineEdit(addBookWindow);
        yearlineEdit->setObjectName("yearlineEdit");
        yearlineEdit->setGeometry(QRect(180, 220, 113, 22));
        addBookButton = new QPushButton(addBookWindow);
        addBookButton->setObjectName("addBookButton");
        addBookButton->setGeometry(QRect(140, 270, 75, 24));

        retranslateUi(addBookWindow);

        QMetaObject::connectSlotsByName(addBookWindow);
    } // setupUi

    void retranslateUi(QDialog *addBookWindow)
    {
        addBookWindow->setWindowTitle(QCoreApplication::translate("addBookWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("addBookWindow", "ADICIONAR UM LIVRO", nullptr));
        label_2->setText(QCoreApplication::translate("addBookWindow", "NOME:", nullptr));
        label_3->setText(QCoreApplication::translate("addBookWindow", "AUTOR:", nullptr));
        label_4->setText(QCoreApplication::translate("addBookWindow", "TEMA:", nullptr));
        label_5->setText(QCoreApplication::translate("addBookWindow", "ANO LAN\303\207AMENTO:", nullptr));
        addBookButton->setText(QCoreApplication::translate("addBookWindow", "Adicionar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addBookWindow: public Ui_addBookWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBOOKWINDOW_H
