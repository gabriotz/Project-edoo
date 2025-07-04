#include "aluno.h"

// Construtor da classe Aluno.
// Chama o construtor da classe base 'Usuario' para inicializar.
Aluno::Aluno(const std::string& uLogin, const std::string& uSenha)
    : Usuario(uLogin, uSenha) {
    std::cout << "--> Usuário do tipo 'Aluno' criado: " << login << std::endl;
}

// Retorna o limite de empréstimos para um Aluno.
int Aluno::getLimiteEmprestimo() const {
    return 3; 
}

// Retorna a string que identifica este tipo de usuário.
std::string Aluno::getTipoUsuario() const {
    return "Aluno";
}

// Retorna o nível de prioridade na fila de espera.
int Aluno::getNivelPrioridade() const{
    return 2; //prioridade menor que professor
}
