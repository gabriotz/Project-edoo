// Em mainwindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../usuario.h"
#include "../acervo.h"
#include "ui_mainwindow.h"

// ...

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Acervo* acervo, QWidget *parent = nullptr);
    ~MainWindow();

    void setCurrentUser(Usuario* user);
signals:
    void logoutRequest(); // sinal para logout
private:
    Ui::MainWindow *ui;
    Usuario* m_currentUser;
    Acervo* m_acervo;
private slots:
    void on_addBookButton_clicked();
    void on_loanBookButton_clicked();
    void on_seeBookButton_clicked();
    void on_seeAllBooksButton_clicked();
    void on_logoutButton_clicked();
};

#endif // MAINWINDOW_H
