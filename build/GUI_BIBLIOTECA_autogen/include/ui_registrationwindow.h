/********************************************************************************
** Form generated from reading UI file 'registrationwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONWINDOW_H
#define UI_REGISTRATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegistrationWindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *loginLineEdit;
    QLabel *label_3;
    QLineEdit *passwordLineEdit;
    QComboBox *accountTypeComboBox;
    QPushButton *registerButton;
    QPushButton *loginButton;

    void setupUi(QDialog *RegistrationWindow)
    {
        if (RegistrationWindow->objectName().isEmpty())
            RegistrationWindow->setObjectName("RegistrationWindow");
        RegistrationWindow->resize(400, 300);
        label = new QLabel(RegistrationWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 20, 71, 16));
        label_2 = new QLabel(RegistrationWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(170, 50, 71, 16));
        loginLineEdit = new QLineEdit(RegistrationWindow);
        loginLineEdit->setObjectName("loginLineEdit");
        loginLineEdit->setGeometry(QRect(140, 70, 113, 22));
        label_3 = new QLabel(RegistrationWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(180, 110, 71, 16));
        passwordLineEdit = new QLineEdit(RegistrationWindow);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setGeometry(QRect(140, 130, 113, 22));
        accountTypeComboBox = new QComboBox(RegistrationWindow);
        accountTypeComboBox->addItem(QString());
        accountTypeComboBox->addItem(QString());
        accountTypeComboBox->setObjectName("accountTypeComboBox");
        accountTypeComboBox->setGeometry(QRect(160, 170, 101, 22));
        registerButton = new QPushButton(RegistrationWindow);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(274, 210, 81, 24));
        loginButton = new QPushButton(RegistrationWindow);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(50, 210, 111, 24));

        retranslateUi(RegistrationWindow);

        QMetaObject::connectSlotsByName(RegistrationWindow);
    } // setupUi

    void retranslateUi(QDialog *RegistrationWindow)
    {
        RegistrationWindow->setWindowTitle(QCoreApplication::translate("RegistrationWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("RegistrationWindow", "CADASTRO", nullptr));
        label_2->setText(QCoreApplication::translate("RegistrationWindow", "USUARIO", nullptr));
        label_3->setText(QCoreApplication::translate("RegistrationWindow", "SENHA", nullptr));
        accountTypeComboBox->setItemText(0, QCoreApplication::translate("RegistrationWindow", "PROFESSOR", nullptr));
        accountTypeComboBox->setItemText(1, QCoreApplication::translate("RegistrationWindow", "ALUNO", nullptr));

        registerButton->setText(QCoreApplication::translate("RegistrationWindow", "CADASTRAR", nullptr));
        loginButton->setText(QCoreApplication::translate("RegistrationWindow", "JA TENHO CONTA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistrationWindow: public Ui_RegistrationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONWINDOW_H
