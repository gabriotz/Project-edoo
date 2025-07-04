#include "mainwindow.h"
#include "seeallbookswindow.h"
#include "ui_mainwindow.h"
#include "addbookwindow.h"
#include "loanbookwindow.h"
#include "userbookswindow.h"
// Construtor da janela principal.
MainWindow::MainWindow(Acervo* acervo, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_currentUser(nullptr),
    m_acervo(acervo)
{
    ui->setupUi(this);
}
// Destrutor
MainWindow::~MainWindow()
{
    delete ui;
}
// Chamado quando o usuário clica para doar um livro.
void MainWindow::on_addBookButton_clicked()
{
    // Para compilar, a addBookWindow também precisa de ter o construtor correto
    addBookWindow dialog(m_acervo, this);
    dialog.exec();
}
// Define o usuário que acabou de fazer login.
void MainWindow::setCurrentUser(Usuario* user)
{
    m_currentUser = user; // Salva o ponteiro do utilizador atual

    // Verifica se o utilizador é válido antes de o usar
    if (m_currentUser) {
        // Pega o nome de login do utilizador
        QString nomeUsuario = QString::fromStdString(m_currentUser->getLogin());
        setWindowTitle("Biblioteca - Bem-vindo(a) " + nomeUsuario);
        ui->welcomeLabel->setText("Olá, " + nomeUsuario);
    }
}
// Chamado quando o usuário clica para emprestar um livro.
void MainWindow::on_loanBookButton_clicked()
{

    std::cout << "Botao 'Emprestar Livro' clicado!" << std::endl;
    loanBookWindow dialog(m_acervo,m_currentUser, this);
    dialog.exec();
}

// Chamado quando o usuário clica para ver seus livros.
void MainWindow::on_seeBookButton_clicked()
{
    // Cria e exibe a janela de livros do usuário
    userBooksWindow dialog(m_currentUser, m_acervo, this);
    dialog.exec();
}
// Chamado quando o usuário clica para ver todos os livros da biblioteca.
void MainWindow::on_seeAllBooksButton_clicked()
{
    seeAllBooksWindow dialog(m_acervo,this); // Cria a janela que lista todos os livros.
    dialog.exec();
}
// Chamado quando o usuário clica no botão de deslogar.
void MainWindow::on_logoutButton_clicked()
{
    emit logoutRequest(); // emite sinal de logout
}

