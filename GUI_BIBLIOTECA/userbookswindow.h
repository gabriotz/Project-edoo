#ifndef USERBOOKSWINDOW_H
#define USERBOOKSWINDOW_H


#include <QDialog>
#include "usuario.h"
#include "acervo.h"


namespace Ui {
class userBooksWindow;
}
// Classe da janela que mostra os livros emprestados por um usuário específico.
class userBooksWindow : public QDialog
{
    Q_OBJECT

public:
    // Construtor que recebe o usuário logado e o acervo.
    explicit userBooksWindow(Usuario* currentUser, Acervo* acervo, QWidget *parent = nullptr);
    // Destrutor
    ~userBooksWindow();

private:
    // Ponteiro para a interface gráfica.
    Ui::userBooksWindow *ui;
    // Ponteiro para o usuário logado.
    Usuario* m_currentUser;
    // Ponteiro para o acervo.
    Acervo* m_acervo;
    // Função para preencher a lista de livros do usuário
    void popularListaDeLivros();

private slots:
    // Slot para o botão de devolver o livro selecionado.
    void on_returnButton_clicked();

};

#endif // USERBOOKSWINDOW_H
