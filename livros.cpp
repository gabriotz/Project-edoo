
#include "livros.h" 
#include <iostream>  


using namespace std;


Livro::Livro(string idLivro, string nomeLivro, string autorLivro, string temaLivro, int lancamentoLivro, bool disponivelInicial)
    : id(idLivro), nome(nomeLivro), autor(autorLivro), tema(temaLivro), lancamento(lancamentoLivro), disponivel(disponivelInicial) {
    
}


string Livro::getId() const {
    return id;
}

string Livro::getNome() const {
    return nome;
}

string Livro::getAutor() const {
    return autor;
}

string Livro::getTema() const {
    return tema;
}

int Livro::getLancamento() const {
    return lancamento;
}

bool Livro::getDisponibilidade() const {
    return disponivel;
}

// Implementação do método resumo() (com 'const' para corresponder à declaração)
void Livro::resumo() const {
    cout << "O livro '" << nome << "' sobre '" << tema
         << "' foi lancado em " << lancamento << " pelo autor " << autor
         << ". Status: " << (disponivel ? "Disponivel" : "Emprestado") << endl; // Adicionei status
}

// Implementação dos Métodos Setters
void Livro::setDisponivel() {
    disponivel = true;
}

void Livro::setUsado() {
    disponivel = false; // Reutiliza o método setDisponivel
}