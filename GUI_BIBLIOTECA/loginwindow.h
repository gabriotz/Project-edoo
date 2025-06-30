#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include "../cadastros.h" // <<< ADICIONE/VERIFIQUE ESTE INCLUDE

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(Cadastros* cadastros, QWidget *parent = nullptr);
    ~LoginWindow();

signals:
    void showRegistrationWindow();
    void loginSuccessful(Usuario* user);

private slots:
    void on_registerButton_clicked();
    void on_loginButton_clicked();

private:
    Ui::LoginWindow *ui;
    Cadastros* m_cadastros;
};

#endif // LOGINWINDOW_H
