#include "mainwindow.h"
#include "seeallbookswindow.h"
#include "ui_mainwindow.h"
#include "addbookwindow.h"
#include "loanbookwindow.h"
#include "userbookswindow.h"

MainWindow::MainWindow(Acervo* acervo, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_currentUser(nullptr),
    m_acervo(acervo) // <-- O ponteiro é salvo aqui!
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_addBookButton_clicked()
{
    // Para compilar, a addBookWindow também precisa de ter o construtor correto
    addBookWindow dialog(m_acervo, this);
    dialog.exec();
}
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
void MainWindow::on_loanBookButton_clicked()
{

    std::cout << "Botao 'Emprestar Livro' clicado!" << std::endl;
    loanBookWindow dialog(m_acervo,m_currentUser, this);
    dialog.exec();
}


void MainWindow::on_seeBookButton_clicked()
{
    // Cria e exibe a janela de livros do usuário
    userBooksWindow dialog(m_currentUser, m_acervo, this);
    dialog.exec();
}
void MainWindow::on_seeAllBooksButton_clicked()
{
    seeAllBooksWindow dialog(m_acervo,this);
    dialog.exec();
}

void MainWindow::on_logoutButton_clicked()
{
    emit logoutRequest(); // emit sinal de logout
}

