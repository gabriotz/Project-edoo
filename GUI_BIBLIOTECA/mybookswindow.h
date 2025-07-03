#ifndef MYBOOKSWINDOW_H
#define MYBOOKSWINDOW_H

#include <QDialog>
#include "../usuario.h" // Precisa saber sobre o usuário
#include "../acervo.h"  // Precisa do acervo para atualizar o status dos livros

namespace Ui {
class MyBooksWindow;
}

class MyBooksWindow : public QDialog
{
    Q_OBJECT

public:
    // O construtor agora recebe o usuário e o acervo
    explicit MyBooksWindow(Usuario* currentUser, Acervo* acervo, QWidget *parent = nullptr);
    ~MyBooksWindow();

private:
    Ui::MyBooksWindow *ui;
    Usuario* m_currentUser;
    Acervo* m_acervo;

    void popularListaDeLivros(); // Função para carregar os livros na lista

private slots:
    void on_returnButton_clicked(); // Slot para o novo botão de devolver
};

#endif // MYBOOKSWINDOW_H
