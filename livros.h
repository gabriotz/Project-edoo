#ifndef LIVROS_H
#define LIVROS_H

#include <string> 
#include <iostream>
using namespace std;

class Livro{
    private:
        string id;
        string nome;
        string autor;
        string tema;
        int lancamento;
        bool disponivel;


    public:
        Livro(string id, string nome, string autor, string tema, int lancamento, bool disponivel);

        void resumo() const;       

        string getId() const;

        string getNome() const;
        
        string getTema() const;

        string getAutor() const;

        int getLancamento() const;
        
        bool getDisponibilidade() const;
        
        void setDisponivel(bool status); 

        void setUsado(); 
};

#endif 