#ifndef LOANBOOKWINDOW_H
#define LOANBOOKWINDOW_H

#include <QDialog>
#include "usuario.h"
#include "acervo.h"

namespace Ui {
class loanBookWindow;
}
// Classe da janela responsável por emprestar e colocar na fila de espera.
class loanBookWindow : public QDialog
{
    Q_OBJECT

public:
    // Construtor que recebe o acervo, o usuário logado e um widget "pai".
    explicit loanBookWindow(Acervo* acervo, Usuario* currentUser, QWidget *parent = nullptr);
    // Destrutor.
    ~loanBookWindow();

private:
    // Mantém o controle de qual livro está sendo exibido na tela.
    int m_currentIndex;
    // Ponteiro para a interface gráfica.
    Ui::loanBookWindow *ui;
    // Ponteiro para o acervo
    Acervo* m_acervo;
    // Ponteiro para o usuario atual
    Usuario* m_currentUser;

    //Função para atualizar os livros na tela
    void updateBookDisplay();

private slots:
    // Funções que respondem aos cliques nos botões da interface.
    void on_loanButton_clicked();
    void on_nextButton_clicked();
    void on_previousButton_clicked();

};

#endif // LOANBOOKWINDOW_H
