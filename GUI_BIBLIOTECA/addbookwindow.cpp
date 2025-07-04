#include "addbookwindow.h"
#include "ui_addbookwindow.h"
#include <QMessageBox>
// Construtor da janela de adicionar livros.
addBookWindow::addBookWindow(Acervo* acervo, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addBookWindow),
    m_acervo(acervo)
{
    ui->setupUi(this);
}
// Destrutor, chamado quando a janela é fechada para liberar a memória da UI.
addBookWindow::~addBookWindow()
{
    delete ui;
}
// Função executada quando o botão "Adicionar" é clicado.
void addBookWindow::on_addBookButton_clicked()
{
    // Coleta os dados dos campos de texto da interface.
    QString name = ui->namelineEdit->text();
    QString topic = ui->topiclineEdit->text();
    QString author = ui->authorlineEdit->text();
    QString year = ui->yearlineEdit->text();

    bool conversaoOk;
    int yearInt = year.toInt(&conversaoOk);

    // Validação para garantir que nenhum campo está vazio.
    if (name.isEmpty() || topic.isEmpty() || author.isEmpty() || year.isEmpty()) {
        QMessageBox::warning(this, "Erro de doação de livro", "Os campos de dados não podem estar vazios.");
        return;
    }
    // Gera um ID simples para o novo livro.
    int tamanho = m_acervo->getTamanho();
    std::string id = "L" + std::to_string(tamanho);

    // Adiciona o novo livro ao acervo.
    m_acervo->adicionarLivro(new Livro(id,name.toStdString(),author.toStdString(),topic.toStdString(),yearInt,true));
    // Exibe uma mensagem de sucesso e fecha a janela.
    QMessageBox::information(this, "Sucesso", "Livro doado com sucesso!");
    accept();

};
