#include "userbookswindow.h"
#include "ui_userbookswindow.h"
#include <QMessageBox>

// Construtor da janela "Livros do usuario".
userBooksWindow::userBooksWindow(Usuario* currentUser, Acervo* acervo, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::userBooksWindow),
    m_currentUser(currentUser),
    m_acervo(acervo)
{
    ui->setupUi(this);
    setWindowTitle("Meus Livros Emprestados");
    popularListaDeLivros();
}

// Destrutor.
userBooksWindow::~userBooksWindow()
{
    delete ui;
}
// Preenche o widget de lista com os livros emprestados pelo usuário.
void userBooksWindow::popularListaDeLivros()
{
    ui->myBooksListWidget->clear();
    vector<Livro*> livrosDoUsuario = m_currentUser->getVetor();

    if (livrosDoUsuario.empty()) {
        // Adiciona uma mensagem se o usuário não tiver livros
        QListWidgetItem* item = new QListWidgetItem("Você não possui livros emprestados.");
        item->setFlags(item->flags() & ~Qt::ItemIsSelectable); // Impede que o item seja selecionado
        ui->myBooksListWidget->addItem(item);
        ui->returnButton->setEnabled(false); // Desabilita o botão
        return;
    }
    // Adiciona cada livro do usuário à lista na interface.
    ui->returnButton->setEnabled(true);
    for (Livro* livro : livrosDoUsuario) {
        if (livro) {
            QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(livro->getNome()));
            item->setData(Qt::UserRole, QString::fromStdString(livro->getId()));
            ui->myBooksListWidget->addItem(item);
        }
    }
}
// Chamado quando o botão "DEVOLVER" é clicado.
void userBooksWindow::on_returnButton_clicked()
{
    // Pega o item atualmente selecionado na lista.
    QListWidgetItem* selectedItem = ui->myBooksListWidget->currentItem();
    if (!selectedItem || !selectedItem->data(Qt::UserRole).isValid()) {
        QMessageBox::warning(this, "Atenção", "Por favor, selecione um livro da lista para devolver.");
        return;
    }
    // Recupera o ID do livro guardado no item.
    QString livroId = selectedItem->data(Qt::UserRole).toString();
    Livro* livroDevolvido = m_currentUser->devolverLivro(livroId.toStdString());

    if (livroDevolvido) {
        // Verifica se há alguém na fila de espera por este livro.
        Usuario* proximoDaFila = livroDevolvido->proximoDaFila();
        if (proximoDaFila) {
            // Se houver, o livro é automaticamente emprestado para o próximo.
            proximoDaFila->pegarLivroEmprestado(livroDevolvido);
            QMessageBox::information(this, "Sucesso", QString("Livro devolvido e emprestado para: %1").arg(QString::fromStdString(proximoDaFila->getLogin())));
        } else {
            // Se não, o livro apenas se torna disponível no acervo.
            livroDevolvido->setDisponivel();
            QMessageBox::information(this, "Sucesso", "Livro devolvido e disponível no acervo!");
        }
    } else {
        QMessageBox::critical(this, "Erro", "Não foi possível processar a devolução.");
    }

    // Atualiza a lista para refletir a devolução
    popularListaDeLivros();
}
