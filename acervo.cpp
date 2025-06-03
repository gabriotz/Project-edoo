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
        cout << "Livro '" << novoLivro->getNome() << "' adicionado ao acervo." << endl;
    }
    else{
        cout << "Erro: Tentativa de adicionar um livro nulo." << endl;
    }
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

void Acervo::listarLivros() const{
    if (AcervoLivros.empty()){
        cout << "O acervo de livros está vazio!" << endl;
        return;
    }
    else{
        cout<< "Os livros no acervo são: ";
        for (Livro* livro : AcervoLivros){
            std::cout << "- " << livro->getNome() << " (ID: " << livro->getId() << ")" << std::endl;
        }
    }
}

int Acervo::getTamanho() const { // Se a intenção for o tamanho total. Removi o parâmetro idLivro.
    return AcervoLivros.size();
}
