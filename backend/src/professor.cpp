#include "professor.h"

// Construtor da classe Professor.
// Chama o construtor da classe base 'Usuario' para inicializar.
Professor::Professor(const std::string& uLogin, const std::string& uSenha)
    : Usuario(uLogin, uSenha) {
    std::cout << "--> Usuário do tipo 'Professor' criado: " << login << std::endl;
}

// Retorna o limite de empréstimos para um Professor.
int Professor::getLimiteEmprestimo() const {
    return 10; 
}

// Retorna a string que identifica este tipo de usuário.
std::string Professor::getTipoUsuario() const {
    return "Professor";
}

// Retorna o nível de prioridade na fila de espera.
int Professor::getNivelPrioridade() const{
    return 1;
}
