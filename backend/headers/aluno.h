#ifndef ALUNO_H
#define ALUNO_H

#include "usuario.h"
// A classe Aluno herda da classe Usuario, representando um tipo específico de usuário.
class Aluno : public Usuario {
public:
    // Construtor que inicializa um Aluno com login e senha.
    Aluno(const std::string& uLogin, const std::string& uSenha);

    // Sobrescreve os métodos virtuais puros da classe Usuario.
    int getLimiteEmprestimo() const override;
    std::string getTipoUsuario() const override;
    int getNivelPrioridade() const override; 
};

#endif