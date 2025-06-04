#ifndef CADASTROS_H
#define CADASTROS_H
#include <iostream>
#include <vector>
#include <string>
#include "livros.h"
#include "usuario.h"


class Cadastros{
private:
    vector<Usuario*> cadastrosUsuarios;
public:
    Cadastros();

    void adicionarUsuario(Usuario* novoUsuario);

    void removerUsuario(const std::string& login);

    int getTamanho() const;

    void listarUsuarios() const;

    


};

#endif
