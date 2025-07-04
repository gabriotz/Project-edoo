/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *loginLineEdit;
    QLabel *label_3;
    QLineEdit *passwordLineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *loginButton;
    QPushButton *registerButton;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(800, 450);
        LoginWindow->setAutoFillBackground(false);
        LoginWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 248, 248);"));
        widget = new QWidget(LoginWindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(70, 70, 661, 311));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(45, 45, 45);\n"
"font: 9pt \"Segoe UI\";"));

        verticalLayout->addWidget(label_2);

        loginLineEdit = new QLineEdit(widget);
        loginLineEdit->setObjectName("loginLineEdit");
        loginLineEdit->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 1px solid #CCCCCC;\n"
"padding: 8px;\n"
"border-radius: 8px;\n"
"color: #2D2D2D;\n"
"outline: none; /* Remove a borda de foco padr\303\243o do SO */\n"
"\n"
""));

        verticalLayout->addWidget(loginLineEdit);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        passwordLineEdit = new QLineEdit(widget);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 1px solid #CCCCCC;\n"
"padding: 8px;\n"
"border-radius: 8px;\n"
"color: #2D2D2D;\n"
"outline: none; /* Remove a borda de foco padr\303\243o do SO */"));

        verticalLayout->addWidget(passwordLineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        loginButton = new QPushButton(widget);
        loginButton->setObjectName("loginButton");
        loginButton->setStyleSheet(QString::fromUtf8("background: qlineargradient(\n"
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
"\n"
""));

        horizontalLayout->addWidget(loginButton);

        registerButton = new QPushButton(widget);
        registerButton->setObjectName("registerButton");
        registerButton->setStyleSheet(QString::fromUtf8("background: qlineargradient(\n"
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
"\n"
"hover {\n"
"    background: qlineargradient(\n"
"        x1:0, y1:0, x2:1, y2:0,\n"
"        stop:0 #A00000, stop:1 #FF3030\n"
"    );\n"
"}\n"
""));

        horizontalLayout->addWidget(registerButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:700; color:#2D2D2D;\">LOGIN</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700; color:#2d2d2d;\">USUARIO</span></p></body></html>", nullptr));
        loginLineEdit->setText(QString());
        label_3->setText(QCoreApplication::translate("LoginWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:700; color:#2d2d2d;\">SENHA</span></p></body></html>", nullptr));
        passwordLineEdit->setText(QString());
        loginButton->setText(QCoreApplication::translate("LoginWindow", "ENTRAR", nullptr));
        registerButton->setText(QCoreApplication::translate("LoginWindow", "CADASTRE-SE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
