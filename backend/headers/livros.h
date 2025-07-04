#ifndef LIVROS_H
#define LIVROS_H

#include <string> 
#include <iostream>
#include <list>
using namespace std;

class Usuario;

class Livro{
    private:
        string id;
        string nome;
        string autor;
        string tema;
        int lancamento;
        bool disponivel;
        std::list<Usuario*> filaDeEspera;        


    public:
        Livro(string id, string nome, string autor, string tema, int lancamento, bool disponivel);

        string getResumo() const;       

        string getId() const;

        string getNome() const;
        
        string getTema() const;

        string getAutor() const;

        int getLancamento() const;
        
        bool getDisponibilidade() const;
        
        void setDisponivel(); 

        void setUsado(); 

        void adicionarNaFila(Usuario* usuario);

        Usuario* proximoDaFila();
        
        void verFilaDeEspera() const;

        bool estaNaFila(const Usuario* usuario) const;
};

#endif 