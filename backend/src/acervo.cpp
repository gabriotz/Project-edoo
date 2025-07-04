#include "livros.h"
#include "acervo.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//construtor
Acervo::Acervo() {
    cout << "Acervo de livros criado." << endl;
}

// Adiciona um novo livro ao vetor de livros do acervo.
void Acervo::adicionarLivro(Livro* novoLivro){
    // Garante que o ponteiro recebido não é nulo.
    if (novoLivro != nullptr){
        AcervoLivros.push_back(novoLivro);
        std::cout << "Livro '" << novoLivro->getNome() << "' (ID: " << novoLivro->getId() << ") adicionado ao acervo." << std::endl;
    } else {
        std::cout << "Erro: Tentativa de adicionar um livro nulo." << std::endl;
    }
}

// Procura por um livro no acervo pelo seu ID.
Livro* Acervo::buscarLivroPorId(const std::string& idLivro) const {
    // Percorre todos os livros do acervo.
    for (Livro* livro : AcervoLivros) {
        // Se encontrar o livro com o ID correspondente, retorna o ponteiro para ele.
        if (livro != nullptr && livro->getId() == idLivro) {
            return livro; 
        }
    }
    // Se não encontrar, retorna nulo.
    return nullptr; 
}

// Encontra um livro pelo ID e o remove do acervo.
bool Acervo::removerLivro(const std::string& idLivro) { 
    for (size_t i = 0; i < AcervoLivros.size(); ++i) {    
        // Percorre o vetor usando um índice para poder remover o elemento.
        if (AcervoLivros[i] != nullptr && AcervoLivros[i]->getId() == idLivro) { 
            delete AcervoLivros[i];                      
            AcervoLivros[i] = nullptr; 
            AcervoLivros.erase(AcervoLivros.begin() + i); 
            std::cout << "Livro com ID '" << idLivro << "' removido do acervo." << std::endl;
            return true;
        }
    }
    std::cout << "Livro com ID '" << idLivro << "' nao encontrado para remocao." << std::endl;
    return false;
}

// Imprime no console a lista de todos os livros do acervo.
void Acervo::listarLivros() const {
    if (AcervoLivros.empty()) {
        cout << "O acervo de livros está vazio!" << endl;
        return;
    }
    cout << "--- Acervo Completo da Biblioteca ---" << endl;
    for (const Livro* livro : AcervoLivros) {
        if (livro) {
            cout << "- ";
            livro->getResumo(); 
        }
    }
}

// Retorna um ponteiro para o livro em uma posição específica do vetor.
Livro* Acervo::buscarLivroPorIndice(int indice) const {
    return AcervoLivros[indice];
}

// Retorna o número total de livros no acervo.
int Acervo::getTamanho() const { 
    return AcervoLivros.size();
}

