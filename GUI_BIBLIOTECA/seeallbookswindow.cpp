#include "seeallbookswindow.h"
#include "ui_seeallbookswindow.h"
#include <vector>
#include "../livros.h"


seeAllBooksWindow::seeAllBooksWindow(Acervo* acervo, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::seeAllBooksWindow)
    ,m_acervo(acervo)
    ,m_currentIndex(0)
{
    ui->setupUi(this);
    updateBookDisplay();
}

seeAllBooksWindow::~seeAllBooksWindow()
{
    delete ui;
}

void seeAllBooksWindow::updateBookDisplay()
{
    if (m_acervo == nullptr || m_acervo->getTamanho() == 0) {
        ui->bookLabel->setText("Nenhum livro no acervo.");

        ui->nextButton->setEnabled(false);
        ui->previousButton->setEnabled(false);
        return;
    }

    ui->nextButton->setEnabled(true);
    ui->previousButton->setEnabled(true);

    // Pega o livro na posição atual
    const Livro* livroAtual = m_acervo->buscarLivroPorIndice(m_currentIndex);

    // Usa a função getResumo() que criámos no backend
    QString resumo = QString::fromStdString(livroAtual->getResumo());

    // Atualiza a QLabel
    ui->bookLabel->setText(resumo);
}

// Slot para o botão "Próximo >"
void seeAllBooksWindow::on_nextButton_clicked()
{
    if (m_acervo == nullptr || m_acervo->getTamanho() == 0) return;

    // Avança o índice
    m_currentIndex++;

    // Se passarmos do último livro, voltamos ao primeiro (efeito carrossel)
    if (m_currentIndex >= m_acervo->getTamanho()) {
        m_currentIndex = 0;
    }

    // Chama a função para atualizar a tela com o novo livro
    updateBookDisplay();
}

// Slot para o botão "< Anterior"
void seeAllBooksWindow::on_previousButton_clicked()
{
    if (m_acervo == nullptr || m_acervo->getTamanho() == 0) return;

    // Recua o índice
    m_currentIndex--;

    // Se passarmos do primeiro livro, vamos para o último
    if (m_currentIndex < 0) {
        m_currentIndex = m_acervo->getTamanho() - 1;
    }

    // Chama a função para atualizar a tela com o novo livro
    updateBookDisplay();
}
