#ifndef LIVROS_H
#define LIVROS_H

#include <string> 
#include <iostream>
#include <list>
using namespace std;

// Declaração avançada (forward declaration) da classe Usuario.
// Isso informa ao compilador que a classe Usuario existe, sem precisar incluir o .h completo,
// evitando problemas de dependência circular.
class Usuario;

// A classe Livro representa um livro na biblioteca.
class Livro{
    private:
        // Atributos de um livro
        string id;
        string nome;
        string autor;
        string tema;
        int lancamento;
        bool disponivel;
        // Lista que funciona como fila de espera para usuários interessados no livro.
        std::list<Usuario*> filaDeEspera;        


    public:
        // Construtor para criar um novo objeto Livro.
        Livro(string id, string nome, string autor, string tema, int lancamento, bool disponivel);

        // Métodos para obter informações do livro.
        string getResumo() const;       
        string getId() const;
        string getNome() const;
        string getTema() const;
        string getAutor() const;
        int getLancamento() const;
        bool getDisponibilidade() const;

        // Métodos para alterar o estado do livro.
        void setDisponivel(); 
        void setUsado(); 

        // Métodos para gerenciar a fila de espera.
        void adicionarNaFila(Usuario* usuario);
        Usuario* proximoDaFila();
        void verFilaDeEspera() const;
        bool estaNaFila(const Usuario* usuario) const;
};

#endif 