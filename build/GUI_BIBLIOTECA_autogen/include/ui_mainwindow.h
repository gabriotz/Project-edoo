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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *welcomeLabel;
    QPushButton *addBookButton;
    QPushButton *loanBookButton;
    QPushButton *seeBookButton;
    QPushButton *seeAllBooksButton;
    QPushButton *logoutButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(450, 368);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        welcomeLabel = new QLabel(centralwidget);
        welcomeLabel->setObjectName("welcomeLabel");
        welcomeLabel->setGeometry(QRect(150, 50, 71, 16));
        addBookButton = new QPushButton(centralwidget);
        addBookButton->setObjectName("addBookButton");
        addBookButton->setGeometry(QRect(50, 80, 271, 24));
        loanBookButton = new QPushButton(centralwidget);
        loanBookButton->setObjectName("loanBookButton");
        loanBookButton->setGeometry(QRect(50, 160, 271, 24));
        seeBookButton = new QPushButton(centralwidget);
        seeBookButton->setObjectName("seeBookButton");
        seeBookButton->setGeometry(QRect(50, 200, 271, 24));
        seeAllBooksButton = new QPushButton(centralwidget);
        seeAllBooksButton->setObjectName("seeAllBooksButton");
        seeAllBooksButton->setGeometry(QRect(50, 120, 271, 24));
        logoutButton = new QPushButton(centralwidget);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setGeometry(QRect(330, 270, 75, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 450, 22));
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
        welcomeLabel->setText(QCoreApplication::translate("MainWindow", "Ol\303\241, usuario", nullptr));
        addBookButton->setText(QCoreApplication::translate("MainWindow", "DOAR UM LIVRO PARA A BIBLIOTECA", nullptr));
        loanBookButton->setText(QCoreApplication::translate("MainWindow", "REALIZAR EMPRESTIMO/DEVOLU\303\207\303\203O DE LIVRO", nullptr));
        seeBookButton->setText(QCoreApplication::translate("MainWindow", "VER MEUS LIVROS", nullptr));
        seeAllBooksButton->setText(QCoreApplication::translate("MainWindow", "VER LIVROS NA BIBLIOTECA", nullptr));
        logoutButton->setText(QCoreApplication::translate("MainWindow", "DESLOGAR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
