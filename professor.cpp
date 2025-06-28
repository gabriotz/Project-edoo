#include "professor.h"

Professor::Professor(const std::string& uLogin, const std::string& uSenha)
    : Usuario(uLogin, uSenha) {
    std::cout << "--> Usuário do tipo 'Professor' criado: " << login << std::endl;
}

int Professor::getLimiteEmprestimo() const {
    return 10; 
}

std::string Professor::getTipoUsuario() const {
    return "Professor";
}

int Professor::getNivelPrioridade() const{
    return 1;
}
