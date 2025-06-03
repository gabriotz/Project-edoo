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

    bool removerLivro(const std::string& idLivro);

    int getTamanho() const;

    void listarLivros() const;

    


};

#endif
