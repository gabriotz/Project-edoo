#ifndef ALUNO_H
#define ALUNO_H

#include "usuario.h"

class Aluno : public Usuario {
public:
    Aluno(const std::string& uLogin, const std::string& uSenha);

    int getLimiteEmprestimo() const override;
    std::string getTipoUsuario() const override;
};

#endif