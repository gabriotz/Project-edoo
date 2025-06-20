#include "usuario.h"
#include <string>

Usuario::Usuario(const std::string& uLogin, const std::string& uSenha)
    : login(uLogin), senha(uSenha){
    
    std::cout << "Usuário '" << login << "' criado." << std::endl;
}
    

std::string Usuario::getLogin() const {
    return login;
}

std::string Usuario::getSenha() const {
    return senha;
}

bool Usuario::verificarLogin(const std::string& tentativaLogin, const std::string& tentativaSenha) const {
    return (tentativaLogin == login) && (tentativaSenha == senha); 
}

void Usuario::pegarLivroEmprestado(Livro* livro){
    livrosEmprestados.push_back(livro);}

Livro* Usuario::devolverLivro(const std::string& idLivro) {
    for (auto it = livrosEmprestados.begin(); it != livrosEmprestados.end(); ++it) {
        if ((*it)->getId() == idLivro) {
            // Parte 1: Identificar o livro e prepará-lo para a devolução
            Livro* livroDevolvido = *it; 

            // Parte 2: Cumprir a responsabilidade do usuário (remover da sua lista)
            livrosEmprestados.erase(it); 

            // Parte 3: Cumprir a responsabilidade da função (entregar o livro de volta ao sistema)
            return livroDevolvido; 
        }
    }
    return nullptr; 
}
void Usuario::listarLivrosDoUsuario() const { // <-- O 'const' ESTÁ AQUI
    std::cout << "Livros com o usuário '" << this->login << "':" << std::endl;
    if (this->livrosEmprestados.empty()) {
        std::cout << "- Nenhum livro emprestado." << std::endl;
        return;
    }
    for (const Livro* livro : this->livrosEmprestados) {
        // Usa o método resumo() do livro para mostrar os detalhes
        if (livro) {
            livro->resumo();
        }
    }
}

int Usuario::getQuantidadeLivros() const{
    return livrosEmprestados.size();
}