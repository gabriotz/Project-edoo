#ifndef USUARIO_H
#define USUARIO_H

#include "livros.h"
#include "acervo.h"
#include <string> 
#include <iostream>

class Usuario  {
private:
    std::string login;
    std::string senha;        
    std::vector<Livro*> livrosEmprestados;
public:
    
    Usuario(const std::string& uLogin, const std::string& uSenha);
    

    void pegarLivroEmprestado(Livro* livro);
    Livro* devolverLivro(const std::string& idLivro);    
    void listarLivrosDoUsuario() const;
    int getQuantidadeLivros() const;

    std::string getLogin() const;
    std::string getSenha() const;
    bool verificarLogin(const std::string& tentativaLogin, const std::string& tentativaSenha) const;
};

#endif