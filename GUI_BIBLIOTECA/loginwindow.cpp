#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>

LoginWindow::LoginWindow(Cadastros* cadastros, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow),
    m_cadastros(cadastros) // Salva o ponteiro
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_registerButton_clicked()
{
    emit showRegistrationWindow();
}


void LoginWindow::on_loginButton_clicked()
{
    QString login = ui->loginLineEdit->text();
    QString senha = ui->passwordLineEdit->text();

    Usuario* usuario = m_cadastros->buscarUsuarioPorLogin(login.toStdString());

    if (usuario != nullptr && usuario->verificarLogin(login.toStdString(), senha.toStdString()))
    {

        emit loginSuccessful(usuario);

        close();
    }
    else
    {
        QMessageBox::warning(this, "Falha no Login", "Login ou senha incorretos.");
    }
}
