#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "usuario.h"
// A classe Professor herda de Usuario, representando um tipo de usuário com privilégios.
class Professor : public Usuario { 
public:
    //Construtor que inicializa um Professor com login e senha.
    Professor(const std::string& uLogin, const std::string& uSenha);

    // Sobrescreve os métodos virtuais puros da classe Usuario.
    int getLimiteEmprestimo() const override;
    std::string getTipoUsuario() const override;
    int getNivelPrioridade() const override; 

};

#endif