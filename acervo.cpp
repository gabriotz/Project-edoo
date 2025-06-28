#include "livros.h"
#include "acervo.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Acervo::Acervo() {
    cout << "Acervo de livros criado." << endl;
}

void Acervo::adicionarLivro(Livro* novoLivro){
    if (novoLivro != nullptr){
        AcervoLivros.push_back(novoLivro);
        std::cout << "Livro '" << novoLivro->getNome() << "' (ID: " << novoLivro->getId() << ") adicionado ao acervo." << std::endl;
    } else {
        std::cout << "Erro: Tentativa de adicionar um livro nulo." << std::endl;
    }
}

Livro* Acervo::buscarLivroPorId(const std::string& idLivro) const {
    for (Livro* livro : AcervoLivros) {
        if (livro != nullptr && livro->getId() == idLivro) {
            return livro; 
        }
    }
    return nullptr; 
}


bool Acervo::removerLivro(const std::string& idLivro) { 
    for (size_t i = 0; i < AcervoLivros.size(); ++i) {    
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

void Acervo::listarLivros() const {
    if (AcervoLivros.empty()) {
        cout << "O acervo de livros está vazio!" << endl;
        return;
    }
    cout << "--- Acervo Completo da Biblioteca ---" << endl;
    for (const Livro* livro : AcervoLivros) {
        if (livro) {
            cout << "- ";
            livro->resumo(); // Mude para usar o resumo completo!
        }
    }
}

int Acervo::getTamanho() const { // Se a intenção for o tamanho total. Removi o parâmetro idLivro.
    return AcervoLivros.size();
}

