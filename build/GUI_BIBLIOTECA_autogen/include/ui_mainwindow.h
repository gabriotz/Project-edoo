/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *welcomeLabel;
    QPushButton *seeBookButton;
    QPushButton *seeAllBooksButton;
    QPushButton *loanBookButton;
    QPushButton *addBookButton;
    QPushButton *logoutButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 450);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(70, 50, 661, 363));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        welcomeLabel = new QLabel(layoutWidget);
        welcomeLabel->setObjectName("welcomeLabel");

        verticalLayout->addWidget(welcomeLabel);

        seeBookButton = new QPushButton(layoutWidget);
        seeBookButton->setObjectName("seeBookButton");
        seeBookButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: #ED1C24;\n"
"border: 2px solid #ED1C24;\n"
"padding: 15px 30px;\n"
"border-radius: 12px;\n"
"text-align: center;\n"
"\n"
"font: 700 14pt \"Segoe UI\";"));

        verticalLayout->addWidget(seeBookButton);

        seeAllBooksButton = new QPushButton(layoutWidget);
        seeAllBooksButton->setObjectName("seeAllBooksButton");
        seeAllBooksButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: #ED1C24;\n"
"border: 2px solid #ED1C24;\n"
"padding: 15px 30px;\n"
"border-radius: 12px;\n"
"text-align: center;\n"
"\n"
"font: 700 14pt \"Segoe UI\";"));

        verticalLayout->addWidget(seeAllBooksButton);

        loanBookButton = new QPushButton(layoutWidget);
        loanBookButton->setObjectName("loanBookButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(loanBookButton->sizePolicy().hasHeightForWidth());
        loanBookButton->setSizePolicy(sizePolicy1);
        loanBookButton->setStyleSheet(QString::fromUtf8("background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #8B0000, stop:1 #ED1C24);\n"
"color: white;\n"
"border: none;\n"
"padding: 20px 40px; /* Bot\303\265es maiores e mais proeminentes */\n"
"border-radius: 15px;\n"
"text-align: center;\n"
"\n"
"font: 700 16pt \"Segoe UI\";"));

        verticalLayout->addWidget(loanBookButton);

        addBookButton = new QPushButton(layoutWidget);
        addBookButton->setObjectName("addBookButton");
        addBookButton->setMouseTracking(false);
        addBookButton->setStyleSheet(QString::fromUtf8("background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #FFA500, stop:1 #FF6A00); /* Laranja */\n"
"color: white;\n"
"border: none;\n"
"padding: 20px 40px;\n"
"border-radius: 15px;\n"
"text-align: center;\n"
"font: 700 16pt \"Segoe UI\";"));

        verticalLayout->addWidget(addBookButton);

        logoutButton = new QPushButton(layoutWidget);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: white;\n"
"    color: #ED1C24;\n"
"    border: 2px solid #ED1C24;\n"
"    padding: 10px;\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    border-radius: 8px;\n"
"}\n"
"QPushButton#deslogarButton:hover {\n"
"    background-color: #FFE5E5;\n"
"}"));

        verticalLayout->addWidget(logoutButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:700; color:#2d2d2d;\">Ol\303\241, Usu\303\241rio!</span></p></body></html>", nullptr));
        seeBookButton->setText(QCoreApplication::translate("MainWindow", "MEUS LIVROS", nullptr));
        seeAllBooksButton->setText(QCoreApplication::translate("MainWindow", "CAT\303\201LOGO DA BIBLIOTECA", nullptr));
        loanBookButton->setText(QCoreApplication::translate("MainWindow", "EMPR\303\211STIMO DE LIVRO", nullptr));
#if QT_CONFIG(tooltip)
        addBookButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/>AA</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        addBookButton->setText(QCoreApplication::translate("MainWindow", "DOA\303\207\303\203O DE LIVRO", nullptr));
        logoutButton->setText(QCoreApplication::translate("MainWindow", "DESLOGAR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
