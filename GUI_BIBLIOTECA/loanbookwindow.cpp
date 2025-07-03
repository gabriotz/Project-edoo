#include "loanbookwindow.h"
#include "ui_loanbookwindow.h"
#include <QMessageBox>

// O construtor agora é mais simples
loanBookWindow::loanBookWindow(Acervo* acervo, Usuario* currentUser, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loanBookWindow)
    , m_acervo(acervo)
    , m_currentUser(currentUser)
    , m_currentIndex(0)
{
    ui->setupUi(this);
    updateBookDisplay();
}

loanBookWindow::~loanBookWindow()
{
    delete ui;
}

void loanBookWindow::on_loanButton_clicked()
{
    Livro* livroAtual = m_acervo->buscarLivroPorIndice(m_currentIndex);
    if(livroAtual->getDisponibilidade()){
        if(m_currentUser->getQuantidadeLivros() < m_currentUser->getLimiteEmprestimo()){
            livroAtual->setUsado();
            m_currentUser->pegarLivroEmprestado(livroAtual);
            QMessageBox::information(this, "Sucesso!", "O livro foi emprestado!");
        } else {
            QMessageBox::warning(this, "Falha", "O usuário já atingiu seu limite de livros emprestados!");
        }
    } else {
        livroAtual->adicionarNaFila(m_currentUser);
        QMessageBox::information(this, "Livro Indisponível", "Este livro já está emprestado. Você foi adicionado à fila de espera.");
    }
    // Atualiza o display do livro atual
    updateBookDisplay();
}



void loanBookWindow::updateBookDisplay()
{
    if (m_acervo == nullptr || m_acervo->getTamanho() == 0) {
        ui->bookLabel->setText("Nenhum livro no acervo.");
        ui->nextButton->setEnabled(false);
        ui->previousButton->setEnabled(false);
        return;
    }
    ui->nextButton->setEnabled(true);
    ui->previousButton->setEnabled(true);
    const Livro* livroAtual = m_acervo->buscarLivroPorIndice(m_currentIndex);
    QString resumo = QString::fromStdString(livroAtual->getResumo());
    ui->bookLabel->setText(resumo);
}

void loanBookWindow::on_nextButton_clicked()
{
    if (m_acervo == nullptr || m_acervo->getTamanho() == 0) return;
    m_currentIndex++;
    if (m_currentIndex >= m_acervo->getTamanho()) {
        m_currentIndex = 0;
    }
    updateBookDisplay();
}

void loanBookWindow::on_previousButton_clicked()
{
    if (m_acervo == nullptr || m_acervo->getTamanho() == 0) return;
    m_currentIndex--;
    if (m_currentIndex < 0) {
        m_currentIndex = m_acervo->getTamanho() - 1;
    }
    updateBookDisplay();
}
