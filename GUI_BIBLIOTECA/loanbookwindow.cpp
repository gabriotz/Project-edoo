#include "loanbookwindow.h"
#include "ui_loanbookwindow.h"
#include <QMessageBox>

// Construtor da janela de empréstimo de livros.
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
// Destrutor.
loanBookWindow::~loanBookWindow()
{
    delete ui;
}
// Função executada quando o botão "Pegar emprestado" é clicado.
void loanBookWindow::on_loanButton_clicked()
{
    Livro* livroAtual = m_acervo->buscarLivroPorIndice(m_currentIndex);
    // Verifica se o livro está disponível.
    if(livroAtual->getDisponibilidade()){
        // Verifica se o usuário não atingiu seu limite de empréstimos.
        if(m_currentUser->getQuantidadeLivros() < m_currentUser->getLimiteEmprestimo()){
            livroAtual->setUsado(); // Marca o livro como emprestado.
            m_currentUser->pegarLivroEmprestado(livroAtual); // Adiciona o livro ao vetor do usuário.
            QMessageBox::information(this, "Sucesso!", "O livro foi emprestado!");
        } else {
            QMessageBox::warning(this, "Falha", "O usuário já atingiu seu limite de livros emprestados!");
        }
    } else { // Se o livro não está disponível, tenta entrar na fila de espera.
        // VERIFICAÇÃO 1: O usuário já tem o livro
        if (m_currentUser->possuiLivro(livroAtual->getId())) {
            QMessageBox::warning(this, "Aviso", "Você já está com este livro emprestado.");
            return; // Impede que continue
        }

        // VERIFICAÇÃO 2: O usuário já está na fila
        if (livroAtual->estaNaFila(m_currentUser)) {
            QMessageBox::information(this, "Aviso", "Você já está na fila de espera para este livro.");
            return; // Impede que continue
        }

        // Se passar nas duas verificações, adiciona à fila.
        livroAtual->adicionarNaFila(m_currentUser);
        QMessageBox::information(this, "Livro Indisponível", "Você foi adicionado à fila de espera.");

    }
    // Atualiza o display do livro atual
    updateBookDisplay();
}

// Atualiza o resumo do livro exibido na tela.
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

// Navega para o próximo livro da lista (efeito carrossel)
void loanBookWindow::on_nextButton_clicked()
{
    if (m_acervo == nullptr || m_acervo->getTamanho() == 0) return;
    m_currentIndex++;
    if (m_currentIndex >= m_acervo->getTamanho()) {
        m_currentIndex = 0;
    }
    updateBookDisplay();
}

// Navega para o livro anterior da lista (efeito carrossel).
void loanBookWindow::on_previousButton_clicked()
{
    if (m_acervo == nullptr || m_acervo->getTamanho() == 0) return;
    m_currentIndex--;
    if (m_currentIndex < 0) {
        m_currentIndex = m_acervo->getTamanho() - 1;
    }
    updateBookDisplay();
}
