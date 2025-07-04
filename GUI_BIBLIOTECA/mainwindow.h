// Em mainwindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "usuario.h"
#include "acervo.h"
#include "ui_mainwindow.h"

// ...
// Classe da janela principal, que aparece após o login.
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Construtor que recebe o acervo.
    explicit MainWindow(Acervo* acervo, QWidget *parent = nullptr);
    // Destrutor
    ~MainWindow();
    // Função para definir qual o usuario atual no sistema, possibilitando a funcionalidade de mudar de usuarios.
    void setCurrentUser(Usuario* user);
signals:
    void logoutRequest(); // sinal para logout
private:
    // Ponteiro para a interface gráfica.
    Ui::MainWindow *ui;
    // Ponteiro para o usuário atualmente logado.
    Usuario* m_currentUser;
    // Ponteiro para o acervo de livros.
    Acervo* m_acervo;
private slots:
    // Slots que respondem aos cliques nos botões do menu principal.
    void on_addBookButton_clicked();
    void on_loanBookButton_clicked();
    void on_seeBookButton_clicked();
    void on_seeAllBooksButton_clicked();
    void on_logoutButton_clicked();
};

#endif // MAINWINDOW_H
