#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "usuario.h"

class Professor : public Usuario {
public:
    Professor(const std::string& uLogin, const std::string& uSenha);

    int getLimiteEmprestimo() const override;
    std::string getTipoUsuario() const override;
};

#endif