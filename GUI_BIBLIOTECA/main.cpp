
#include "mainwindow.h"
#include "loginwindow.h"
#include "registrationwindow.h"
#include "seeallbookswindow.h"
#include <QApplication>
#include <QObject>

// Inclua o cabeçalho principal do seu backend
#include "cadastros.h"
#include "aluno.h"      // Inclua para poder criar Alunos
#include "professor.h"  // Inclua para poder criar Professores
#include "livros.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 1. Crie o "cérebro" do sistema de usuários.
    // Esta instância irá guardar todos os usuários cadastrados.
    Cadastros sistemaDeCadastros;
    Acervo biblioteca;
    MainWindow w(&biblioteca);
    int tamanho = biblioteca.getTamanho();
    std::string id = "L" + std::to_string(tamanho);
    // --- Popular com dados de teste ---
    sistemaDeCadastros.adicionarUsuario(new Aluno("aluno", "123"));
    sistemaDeCadastros.adicionarUsuario(new Professor("prof", "admin"));
    biblioteca.adicionarLivro(new Livro(id,"Matematica Discreta","Rosen", "Matemática", 2009, true));
    tamanho = biblioteca.getTamanho();
    id = "L" + std::to_string(tamanho);

    biblioteca.adicionarLivro(new Livro(id,"Memorias póstumas de Brás Cubas","Machado de Assis", "Literatura", 1881, true));

    // ---------------------------------------------

    // 2. Crie as janelas e passe o sistema de cadastros para elas

    LoginWindow login(&sistemaDeCadastros); // Passe o ponteiro
    RegistrationWindow registration(&sistemaDeCadastros); // Passe o ponteiro

    // Conexão 1: Da tela de login -> para a de cadastro
    QObject::connect(&login, &LoginWindow::showRegistrationWindow, [&]() {
        login.hide();
        registration.show();
    });

    // Conexão 2: Da tela de cadastro -> de volta para a de login
    QObject::connect(&registration, &RegistrationWindow::showLoginWindow, [&]() {
        registration.hide();
        login.show();
    });

    // Conexão 3: Se o login for bem-sucedido...
    QObject::connect(&login, &LoginWindow::loginSuccessful, [&](Usuario* user) {
        w.setCurrentUser(user); // ...passe o utilizador para a janela principal...
        w.show();               // ...e mostre a janela principal.
    });

    // Conexão 4: Logout do usuário
    QObject::connect(&w, &MainWindow::logoutRequest, [&]() {
        w.close();      // Fecha a janela principal
        login.show();   // Mostra a janela de login novamente
    });


    // Inicie mostrando a janela de login
    login.show();

    return a.exec();
}
