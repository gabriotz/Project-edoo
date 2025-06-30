#include "addbookwindow.h"
#include "ui_addbookwindow.h"
#include <QMessageBox>
addBookWindow::addBookWindow(Acervo* acervo, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addBookWindow),
    m_acervo(acervo)
{
    ui->setupUi(this);
}

addBookWindow::~addBookWindow()
{
    delete ui;
}
void addBookWindow::on_addBookButton_clicked()
{
    QString name = ui->namelineEdit->text();
    QString topic = ui->topiclineEdit->text();
    QString author = ui->authorlineEdit->text();
    QString year = ui->yearlineEdit->text();

    bool conversaoOk;
    int yearInt = year.toInt(&conversaoOk);

    if (name.isEmpty() || topic.isEmpty() || author.isEmpty() || year.isEmpty()) {
        QMessageBox::warning(this, "Erro de doação de livro", "Os campos de dados não podem estar vazios.");
        return;
    }
    int tamanho = m_acervo->getTamanho();
    std::string id = "L" + std::to_string(tamanho);


    m_acervo->adicionarLivro(new Livro(id,name.toStdString(),author.toStdString(),topic.toStdString(),yearInt,true));
    QMessageBox::information(this, "Sucesso", "Livro doado com sucesso!");
    accept();

};
