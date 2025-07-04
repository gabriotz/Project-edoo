#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>

// Construtor da janela de Login.
LoginWindow::LoginWindow(Cadastros* cadastros, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow),
    m_cadastros(cadastros) // Salva o ponteiro
{
    ui->setupUi(this);
}
// Destrutor
LoginWindow::~LoginWindow()
{
    delete ui;
}

// Quando o botão "CADASTRE-SE" é clicado, emite um sinal para a janela principal.
void LoginWindow::on_registerButton_clicked()
{
    emit showRegistrationWindow(); // A mainwindow ouvirá este sinal e trocará de tela.
}

// Quando o botão "ENTRAR" é clicado.
void LoginWindow::on_loginButton_clicked()
{
    // Pega os textos dos campos de login e senha.
    QString login = ui->loginLineEdit->text();
    QString senha = ui->passwordLineEdit->text();
    // Busca o usuário no sistema de backend.
    Usuario* usuario = m_cadastros->buscarUsuarioPorLogin(login.toStdString());

    // Verifica se o usuário existe e se a senha está correta.
    if (usuario != nullptr && usuario->verificarLogin(login.toStdString(), senha.toStdString()))
    {
        // Se o login for bem-sucedido, emite um sinal com os dados do usuário.
        emit loginSuccessful(usuario);

        close();
    }
    else
    {
        // Caso contrário, exibe uma mensagem de erro.
        QMessageBox::warning(this, "Falha no Login", "Login ou senha incorretos.");
    }
}
