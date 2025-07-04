#include "livros.h"
#include "acervo.h"
#include "cadastros.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Construtor
Cadastros::Cadastros() {
    cout << "A lista de usuarios foi criada" << endl;
}

// Adiciona um novo usuário ao sistema.
void Cadastros::adicionarUsuario(Usuario* novoUsuario){
    if (novoUsuario != nullptr) {
        cadastrosUsuarios.push_back(novoUsuario);
        std::cout << "Usuario '" << novoUsuario->getLogin() << "' adicionado." << std::endl;
    } else {
        std::cout << "Erro: Tentativa de adicionar um usuario nulo." << std::endl;
    }
   
}

// Remove um usuário do sistema a partir do seu login.
void Cadastros::removerUsuario(const std::string& login){
    
    for (auto it = cadastrosUsuarios.begin(); it != cadastrosUsuarios.end(); ++it) {
        if ((*it) != nullptr && (*it)->getLogin() == login) {
            std::cout << "Removendo usuario: " << (*it)->getLogin() << std::endl;
            delete *it; 
            cadastrosUsuarios.erase(it); // Remove o ponteiro do vetor
            return; // Usuário encontrado e removido
        }
    }
    std::cout << "Usuario com login '" << login << "' nao encontrado para remocao." << std::endl;
    

}

// Lista no console o login de todos os usuários cadastrados, usado apenas para testes
void Cadastros::listarUsuarios() const{
    if (cadastrosUsuarios.empty()) {
        std::cout << "Nenhum usuario cadastrado." << std::endl;
        return;
    }
    std::cout << "Usuarios cadastrados:" << std::endl;
    for (const Usuario* usuario : cadastrosUsuarios) {
        if (usuario != nullptr) {
            std::cout << "- Login: " << usuario->getLogin() << std::endl;
            // Se quiser listar os livros de cada usuário também:
            // std::cout << "  Livros do usuario:" << std::endl;
            // usuario->listarLivros(); // Isso funciona porque Usuario herda de Acervo
        }
    }
}
    
// Retorna a quantidade de usuários no sistema.
int Cadastros::getTamanho() const{
    return cadastrosUsuarios.size();
}

// Busca um usuário pelo seu login.
Usuario* Cadastros::buscarUsuarioPorLogin(const std::string& login) const {
    for (Usuario* usuario : cadastrosUsuarios) {
        if (usuario != nullptr && usuario->getLogin() == login) {
            return usuario; // Retorna o ponteiro para o usuário encontrado
        }
    }
    return nullptr; // Retorna nullptr se não encontrar o usuário
}

//destrutor
Cadastros::~Cadastros() {
    std::cout << "Destruindo a lista de cadastros e liberando a memória dos usuários..." << std::endl;
    for (Usuario* usuario : cadastrosUsuarios) {
        delete usuario; // Deleta cada objeto usuário alocado com 'new'
    }
}