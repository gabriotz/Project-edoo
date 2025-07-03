#include "mybookswindow.h"
#include "ui_mybookswindow.h" // Certifique-se que o include reflete o novo nome do .ui
#include <QMessageBox>

MyBooksWindow::MyBooksWindow(Usuario* currentUser, Acervo* acervo, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyBooksWindow),
    m_currentUser(currentUser),
    m_acervo(acervo)
{
    ui->setupUi(this);
    setWindowTitle("Meus Livros Emprestados");
    popularListaDeLivros();
}

MyBooksWindow::~MyBooksWindow()
{
    delete ui;
}

void MyBooksWindow::popularListaDeLivros()
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

    ui->returnButton->setEnabled(true);
    for (Livro* livro : livrosDoUsuario) {
        if (livro) {
            QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(livro->getNome()));
            item->setData(Qt::UserRole, QString::fromStdString(livro->getId()));
            ui->myBooksListWidget->addItem(item);
        }
    }
}

void MyBooksWindow::on_returnButton_clicked()
{
    QListWidgetItem* selectedItem = ui->myBooksListWidget->currentItem();
    if (!selectedItem || !selectedItem->data(Qt::UserRole).isValid()) {
        QMessageBox::warning(this, "Atenção", "Por favor, selecione um livro da lista para devolver.");
        return;
    }

    QString livroId = selectedItem->data(Qt::UserRole).toString();
    Livro* livroDevolvido = m_currentUser->devolverLivro(livroId.toStdString());

    if (livroDevolvido) {
        Usuario* proximoDaFila = livroDevolvido->proximoDaFila();
        if (proximoDaFila) {
            proximoDaFila->pegarLivroEmprestado(livroDevolvido);
            QMessageBox::information(this, "Sucesso", QString("Livro devolvido e emprestado para: %1").arg(QString::fromStdString(proximoDaFila->getLogin())));
        } else {
            livroDevolvido->setDisponivel();
            QMessageBox::information(this, "Sucesso", "Livro devolvido e disponível no acervo!");
        }
    } else {
        QMessageBox::critical(this, "Erro", "Não foi possível processar a devolução.");
    }

    // Atualiza a lista para refletir a devolução
    popularListaDeLivros();
}
