#include "mainwindow.h"
#include "seeallbookswindow.h"
#include "ui_mainwindow.h"
#include "addbookwindow.h"

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
}


void MainWindow::on_seeBookButton_clicked()
{
    // A lógica para ver os livros virá aqui no futuro.
    // Por agora, deixamos a função vazia para que o programa compile.
    std::cout << "Botao 'Ver Livros' clicado!" << std::endl;
}
void MainWindow::on_seeAllBooksButton_clicked()
{
    seeAllBooksWindow dialog(m_acervo,this);
    dialog.exec();
}
