#include "aluno.h"

Aluno::Aluno(const std::string& uLogin, const std::string& uSenha)
    : Usuario(uLogin, uSenha) {
    std::cout << "--> Usuário do tipo 'Aluno' criado: " << login << std::endl;
}

int Aluno::getLimiteEmprestimo() const {
    return 3; 
}

std::string Aluno::getTipoUsuario() const {
    return "Aluno";
}