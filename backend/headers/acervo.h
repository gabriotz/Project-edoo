#ifndef ACERVO_H
#define ACERVO_H

#include <iostream>
#include <vector>
#include <string>
#include "livros.h"

using namespace std;

// A classe Acervo gerencia toda a coleção de livros da biblioteca.
class Acervo{
private:
    // Vetor de ponteiros para objetos Livro. É aqui que todos os livros são armazenados.
    vector<Livro*> AcervoLivros;
public:
    // Construtor da classe
    Acervo();
    
    // Procura por um livro no acervo usando seu ID.
    Livro* buscarLivroPorId(const std::string& idLivro) const;
    
    // Adiciona um novo livro ao acervo.
    void adicionarLivro(Livro* novoLivro);

    // Remove um livro do acervo a partir do seu ID.
    bool removerLivro(const std::string& idLivro);

    // Retorna o número total de livros no acervo.
    int getTamanho() const;

    // Imprime uma lista de todos os livros no console.
    void listarLivros() const;

    // Busca um livro pela sua posição (índice) no vetor.
    Livro* buscarLivroPorIndice(int indice) const;
    


};

#endif
