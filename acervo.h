#ifndef ACERVO_H
#define ACERVO_H

#include <iostream>
#include <vector>
#include <string>
#include "livros.h"

using namespace std;

class Acervo{
private:
    vector<Livro*> AcervoLivros;
public:
    Acervo();

    void adicionarLivro(Livro* novoLivro);

    void removerLivro(Livro* novoLivro);

    int getTamanho(const std::string& idLivro);

    void listarLivros() const;


};

#endif
