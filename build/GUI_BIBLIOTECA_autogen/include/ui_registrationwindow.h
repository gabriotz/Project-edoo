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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegistrationWindow
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
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
        RegistrationWindow->resize(800, 450);
        RegistrationWindow->setMinimumSize(QSize(600, 450));
        RegistrationWindow->setMaximumSize(QSize(1200, 900));
        layoutWidget = new QWidget(RegistrationWindow);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(70, 70, 661, 311));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        loginLineEdit = new QLineEdit(layoutWidget);
        loginLineEdit->setObjectName("loginLineEdit");
        loginLineEdit->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 1px solid #CCCCCC;\n"
"padding: 8px;\n"
"border-radius: 8px;\n"
"color: #2D2D2D;\n"
"outline: none; /* Remove a borda de foco padr\303\243o do SO */"));

        verticalLayout->addWidget(loginLineEdit);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        passwordLineEdit = new QLineEdit(layoutWidget);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 1px solid #CCCCCC;\n"
"padding: 8px;\n"
"border-radius: 8px;\n"
"color: #2D2D2D;\n"
"outline: none; /* Remove a borda de foco padr\303\243o do SO */"));

        verticalLayout->addWidget(passwordLineEdit);

        accountTypeComboBox = new QComboBox(layoutWidget);
        accountTypeComboBox->addItem(QString());
        accountTypeComboBox->addItem(QString());
        accountTypeComboBox->setObjectName("accountTypeComboBox");
        accountTypeComboBox->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 1px solid #CCCCCC;\n"
"padding: 8px;\n"
"border-radius: 8px;\n"
"color: #2D2D2D;\n"
"outline: none;\n"
"\n"
"/* Opcional: estilo da seta para baixo */\n"
"QComboBox::drop-down {\n"
"    border-left: 1px solid #CCCCCC;\n"
"    width: 20px; /* Largura da \303\241rea da seta */\n"
"}\n"
"QComboBox::down-arrow {\n"
"    image: url(Caminho/Para/Sua/Seta.png); /* Se quiser um \303\255cone personalizado */\n"
"}"));

        verticalLayout->addWidget(accountTypeComboBox);

        registerButton = new QPushButton(layoutWidget);
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
""));

        verticalLayout->addWidget(registerButton);

        loginButton = new QPushButton(layoutWidget);
        loginButton->setObjectName("loginButton");
        loginButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: #ED1C24;\n"
"border: 2px solid #ED1C24;\n"
"padding: 8px 16px;\n"
"font-size: 14px;\n"
"font-weight: bold;\n"
"border-radius: 8px;"));

        verticalLayout->addWidget(loginButton);


        retranslateUi(RegistrationWindow);

        QMetaObject::connectSlotsByName(RegistrationWindow);
    } // setupUi

    void retranslateUi(QDialog *RegistrationWindow)
    {
        RegistrationWindow->setWindowTitle(QCoreApplication::translate("RegistrationWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("RegistrationWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:700;\">CADASTRO</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("RegistrationWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#2d2d2d;\">USUARIO</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("RegistrationWindow", "<html><head/><body><p><span style=\" font-weight:700; color:#2d2d2d;\">SENHA</span></p></body></html>", nullptr));
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
