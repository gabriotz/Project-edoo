#include "livros.h"
#include "acervo.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Acervo::Acervo() {
    cout << "Acervo de livros criado." << endl;
}

void adicionarLivro(Livro* novoLivro){
    if (novoLivro != nullptr){
        Acervo.push_back(novoLivro);
        cout << "Livro '" << novoLivro->getNome() << "' adicionado ao acervo." << endl;
    }
    else{
        cout << "Erro: Tentativa de adicionar um livro nulo." << endl;
    }
}

bool Acervo::removerLivro(const std::string& idLivro) {
    // Para remover, você precisa encontrar o livro pelo ID no vector
    for (size_t i = 0; i < Acervo.size(); ++i) {
        if (Acervo[i]->getId() == idLivro) {
            // Libera a memória do objeto Livro antes de removê-lo do vector
            delete Acervo[i];
            // Remove o elemento do vector
            Acervo.erase(Acervo.begin() + i);
            cout << "Livro com ID '" << idLivro << "' removido do acervo." << endl;
            return true;
        }
    }
    cout << "Livro com ID '" << idLivro << "' nao encontrado para remocao." << endl;
    return false;
}
