#include "usuario.h"
#include <string>

// Construtor da classe base Usuario.
Usuario::Usuario(const std::string& uLogin, const std::string& uSenha)
    : login(uLogin), senha(uSenha){
    
}
    
//Metodos para retornar dados do usuario
std::string Usuario::getLogin() const {
    return login;
}

std::string Usuario::getSenha() const {
    return senha;
}

std::vector<Livro*> Usuario::getVetor() const{
    return livrosEmprestados;
};

int Usuario::getQuantidadeLivros() const{
    return livrosEmprestados.size();
}

// Verifica as credenciais de login
bool Usuario::verificarLogin(const std::string& tentativaLogin, const std::string& tentativaSenha) const {
    return (tentativaLogin == login) && (tentativaSenha == senha); 
}

// Verifica se o usuario ja possui o livro no seu vetor de livros emprestados, para evitar entrar na fila de espera de um livro que ja possui.
bool Usuario::possuiLivro(const std::string& idLivro) const {
    for (const Livro* livro : livrosEmprestados) {
        if (livro->getId() == idLivro) {
            return true; // Encontrou o livro na lista do usuário
        }
    }
    return false; // Não encontrou o livro
}

//Altera senha do usuario, apenas para teste
bool Usuario::alterarSenha(const std::string& senhaAtual, const std::string& novaSenha) {
    if (this->senha == senhaAtual) {
        this->senha = novaSenha;
        std::cout << "  [SUCESSO] Senha alterada.\n";
        return true;
    } else {
        std::cout << "  [FALHA] A senha atual fornecida está incorreta.\n";
        return false;
    }
}

//Adiciona um livro no seu vetor de livros emprestados
void Usuario::pegarLivroEmprestado(Livro* livro){
    livrosEmprestados.push_back(livro);}



//Retira um livro do seu vetor de livros emprestados
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

//Lista os livros do usuario com seu resumo, apenas para teste
void Usuario::listarLivrosDoUsuario() const { 
    std::cout << "Livros com o usuário '" << this->login << "':" << std::endl;
    if (this->livrosEmprestados.empty()) {
        std::cout << "- Nenhum livro emprestado." << std::endl;
        return;
    }
    for (const Livro* livro : this->livrosEmprestados) {
        // Usa o método resumo() do livro para mostrar os detalhes
        if (livro) {
            livro->getResumo();
        }
    }
}

