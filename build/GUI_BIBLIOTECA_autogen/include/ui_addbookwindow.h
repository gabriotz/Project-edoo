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
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addBookWindow
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSplitter *splitter_5;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QLabel *label_4;
    QLineEdit *namelineEdit;
    QSplitter *splitter_2;
    QLabel *label_3;
    QLineEdit *authorlineEdit;
    QSplitter *splitter_3;
    QLabel *label_2;
    QLineEdit *topiclineEdit;
    QSplitter *splitter_4;
    QLabel *label_5;
    QLineEdit *yearlineEdit;
    QPushButton *addBookButton;

    void setupUi(QDialog *addBookWindow)
    {
        if (addBookWindow->objectName().isEmpty())
            addBookWindow->setObjectName("addBookWindow");
        addBookWindow->resize(800, 450);
        addBookWindow->setMinimumSize(QSize(800, 450));
        addBookWindow->setMaximumSize(QSize(800, 450));
        widget = new QWidget(addBookWindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(70, 70, 661, 311));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        splitter_5 = new QSplitter(widget);
        splitter_5->setObjectName("splitter_5");
        splitter_5->setOrientation(Qt::Orientation::Vertical);
        widget1 = new QWidget(splitter_5);
        widget1->setObjectName("widget1");
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(widget1);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Orientation::Horizontal);
        label_4 = new QLabel(splitter);
        label_4->setObjectName("label_4");
        splitter->addWidget(label_4);
        namelineEdit = new QLineEdit(splitter);
        namelineEdit->setObjectName("namelineEdit");
        namelineEdit->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 1px solid #CCCCCC;\n"
"padding: 8px;\n"
"border-radius: 8px;\n"
"color: #2D2D2D;\n"
"outline: none; /* Remove a borda de foco padr\303\243o do SO */\n"
"font: 700 10pt \"Segoe UI\";"));
        splitter->addWidget(namelineEdit);

        verticalLayout->addWidget(splitter);

        splitter_2 = new QSplitter(widget1);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setOrientation(Qt::Orientation::Horizontal);
        label_3 = new QLabel(splitter_2);
        label_3->setObjectName("label_3");
        splitter_2->addWidget(label_3);
        authorlineEdit = new QLineEdit(splitter_2);
        authorlineEdit->setObjectName("authorlineEdit");
        authorlineEdit->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 1px solid #CCCCCC;\n"
"padding: 8px;\n"
"border-radius: 8px;\n"
"color: #2D2D2D;\n"
"outline: none; /* Remove a borda de foco padr\303\243o do SO */\n"
"font: 700 10pt \"Segoe UI\";"));
        splitter_2->addWidget(authorlineEdit);

        verticalLayout->addWidget(splitter_2);

        splitter_3 = new QSplitter(widget1);
        splitter_3->setObjectName("splitter_3");
        splitter_3->setOrientation(Qt::Orientation::Horizontal);
        label_2 = new QLabel(splitter_3);
        label_2->setObjectName("label_2");
        splitter_3->addWidget(label_2);
        topiclineEdit = new QLineEdit(splitter_3);
        topiclineEdit->setObjectName("topiclineEdit");
        topiclineEdit->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 1px solid #CCCCCC;\n"
"padding: 8px;\n"
"border-radius: 8px;\n"
"color: #2D2D2D;\n"
"outline: none; /* Remove a borda de foco padr\303\243o do SO */\n"
"font: 700 10pt \"Segoe UI\";"));
        splitter_3->addWidget(topiclineEdit);

        verticalLayout->addWidget(splitter_3);

        splitter_4 = new QSplitter(widget1);
        splitter_4->setObjectName("splitter_4");
        splitter_4->setOrientation(Qt::Orientation::Horizontal);
        label_5 = new QLabel(splitter_4);
        label_5->setObjectName("label_5");
        splitter_4->addWidget(label_5);
        yearlineEdit = new QLineEdit(splitter_4);
        yearlineEdit->setObjectName("yearlineEdit");
        yearlineEdit->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 1px solid #CCCCCC;\n"
"padding: 8px;\n"
"border-radius: 8px;\n"
"color: #2D2D2D;\n"
"outline: none; /* Remove a borda de foco padr\303\243o do SO */\n"
"font: 700 10pt \"Segoe UI\";"));
        splitter_4->addWidget(yearlineEdit);

        verticalLayout->addWidget(splitter_4);

        splitter_5->addWidget(widget1);

        verticalLayout_2->addWidget(splitter_5);

        addBookButton = new QPushButton(widget);
        addBookButton->setObjectName("addBookButton");
        addBookButton->setStyleSheet(QString::fromUtf8("background: qlineargradient(\n"
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

        verticalLayout_2->addWidget(addBookButton);


        retranslateUi(addBookWindow);

        QMetaObject::connectSlotsByName(addBookWindow);
    } // setupUi

    void retranslateUi(QDialog *addBookWindow)
    {
        addBookWindow->setWindowTitle(QCoreApplication::translate("addBookWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("addBookWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:700; color:#2d2d2d;\">ADICIONAR UM LIVRO</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("addBookWindow", "<html><head/><body><p><span style=\" font-size:10pt; color:#2d2d2d;\">TEMA:</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("addBookWindow", "<html><head/><body><p><span style=\" font-size:10pt; color:#2d2d2d;\">AUTOR:</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("addBookWindow", "<html><head/><body><p><span style=\" font-size:10pt; color:#2d2d2d;\">NOME:</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("addBookWindow", "<html><head/><body><p><span style=\" font-size:10pt; color:#2d2d2d;\">ANO LAN\303\207AMENTO:</span></p></body></html>", nullptr));
        addBookButton->setText(QCoreApplication::translate("addBookWindow", "ADICIONAR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addBookWindow: public Ui_addBookWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBOOKWINDOW_H
