#ifndef CADASTROS_H
#define CADASTROS_H
#include <iostream>
#include <vector>
#include <string>
#include "livros.h"
#include "usuario.h"

// A classe Cadastros é responsável por gerenciar todos os usuários do sistema.
class Cadastros{
private:
    // Vetor que armazena ponteiros para todos os objetos Usuario (Alunos e Professores).
    vector<Usuario*> cadastrosUsuarios;
public:
    // Construtor e Destrutor.
    Cadastros();
    ~Cadastros();

    // Adiciona um novo usuário ao sistema.
    void adicionarUsuario(Usuario* novoUsuario);

    // Remove um usuário pelo seu login.
    void removerUsuario(const std::string& login);

    // Retorna a quantidade de usuários cadastrados.
    int getTamanho() const;

    // Imprime uma lista de todos os usuários no console.
    void listarUsuarios() const;

    // Busca um usuário pelo seu login e retorna um ponteiro para ele.
    Usuario* buscarUsuarioPorLogin(const std::string& login) const; // <-- ADICIONE ESTA LINHA
    


};

#endif
