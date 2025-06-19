#include "livros.h"
#include "acervo.h"
#include "cadastros.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Cadastros::Cadastros() {
    cout << "A lista de usuarios foi criada" << endl;
}

void Cadastros::adicionarUsuario(Usuario* novoUsuario){
    if (novoUsuario != nullptr) {
        cadastrosUsuarios.push_back(novoUsuario);
        std::cout << "Usuario '" << novoUsuario->getLogin() << "' adicionado." << std::endl;
    } else {
        std::cout << "Erro: Tentativa de adicionar um usuario nulo." << std::endl;
    }
   
}

void Cadastros::removerUsuario(const std::string& login){
     // TODO: Implementar a lógica para encontrar e remover o usuário
    // Exemplo de lógica (você precisará adaptar e testar):
    
    for (auto it = cadastrosUsuarios.begin(); it != cadastrosUsuarios.end(); ++it) {
        if ((*it) != nullptr && (*it)->getLogin() == login) {
            std::cout << "Removendo usuario: " << (*it)->getLogin() << std::endl;
            delete *it; // Importante: liberar a memória se Usuario foi criado com 'new'
            cadastrosUsuarios.erase(it); // Remove o ponteiro do vetor
            return; // Usuário encontrado e removido
        }
    }
    std::cout << "Usuario com login '" << login << "' nao encontrado para remocao." << std::endl;
    

}

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
    

int Cadastros::getTamanho() const{
    return cadastrosUsuarios.size();
}

