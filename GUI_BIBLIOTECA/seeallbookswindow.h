#ifndef SEEALLBOOKSWINDOW_H
#define SEEALLBOOKSWINDOW_H

#include <QDialog>
#include "acervo.h"

namespace Ui {
class seeAllBooksWindow;
}
// Classe da janela que exibe todos os livros da biblioteca em um carrossel.
class seeAllBooksWindow : public QDialog
{
    Q_OBJECT

public:
    // Construtor que recebe o acervo para poder listar os livros.
    explicit seeAllBooksWindow(Acervo *acervo, QWidget *parent = nullptr);
    // Destrutor.
    ~seeAllBooksWindow();

private:
    // Guarda o índice do livro que está sendo mostrado na tela.
    int m_currentIndex;
    // Ponteiro para a interface gráfica.
    Ui::seeAllBooksWindow *ui;
    // Ponteiro para o acervo.
    Acervo *m_acervo;
    // Função privada que atualiza o texto na tela com os dados do livro atual.
    void updateBookDisplay();
private slots:
    // Slots para os botões de navegação do carrossel.
    void on_nextButton_clicked();
    void on_previousButton_clicked();
};

#endif // SEEALLBOOKSWINDOW_H
