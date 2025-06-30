#include "registrationwindow.h"
#include "ui_registrationwindow.h"
#include "../aluno.h"
#include "../professor.h"
#include <QMessageBox> // Para mostrar mensagens de erro/sucesso

// Modifique o construtor para receber e guardar o ponteiro
RegistrationWindow::RegistrationWindow(Cadastros* cadastros, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrationWindow),
    m_cadastros(cadastros) // Guarde o ponteiro
{
    ui->setupUi(this);
}

RegistrationWindow::~RegistrationWindow()
{
    delete ui;
}

// Lógica CADASTRO
void RegistrationWindow::on_registerButton_clicked()
{
    QString login = ui->loginLineEdit->text();
    QString senha = ui->passwordLineEdit->text();

    if (login.isEmpty() || senha.isEmpty()) {
        QMessageBox::warning(this, "Erro de Cadastro", "Os campos de Login e Senha não podem estar vazios.");
        return;
    }

    if (m_cadastros->buscarUsuarioPorLogin(login.toStdString())) {
        QMessageBox::warning(this, "Erro de Cadastro", "Este nome de usuário já está em uso.");
        return;
    }


    // Pega o texto do item atualmente selecionado no ComboBox
    QString accountType = ui->accountTypeComboBox->currentText();

    if (accountType == "ALUNO"){
        m_cadastros->adicionarUsuario(new Aluno(login.toStdString(), senha.toStdString()));
    } else if (accountType == "PROFESSOR") {
        m_cadastros->adicionarUsuario(new Professor(login.toStdString(), senha.toStdString()));
    } else {
        // Caso o usuário não tenha selecionado uma opção válida
        QMessageBox::warning(this, "Erro de Cadastro", "Por favor, selecione um tipo de conta (Aluno ou Professor).");
        return;
    }

    QMessageBox::information(this, "Sucesso", "Usuário cadastrado com sucesso!");
    emit showLoginWindow(); // Volta para a tela de login
}

// Voltar diretamente para a tela de login
void RegistrationWindow::on_loginButton_clicked()
{
    emit showLoginWindow();
}
