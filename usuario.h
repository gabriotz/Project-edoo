#ifndef USUARIO_H
#define USUARIO_H

#include "livros.h"
#include "acervo.h"
#include <string> 
#include <iostream>

class Usuario  {
protected:
    std::string login;
    std::string senha;        
    std::vector<Livro*> livrosEmprestados;
public:
    virtual ~Usuario() = default;    

    Usuario(const std::string& uLogin, const std::string& uSenha);
    

    void pegarLivroEmprestado(Livro* livro);
    Livro* devolverLivro(const std::string& idLivro);    
    void listarLivrosDoUsuario() const;
    int getQuantidadeLivros() const;

    std::string getLogin() const;
    std::string getSenha() const;
    std::vector<Livro*> getVetor()const;
    bool verificarLogin(const std::string& tentativaLogin, const std::string& tentativaSenha) const;
    bool alterarSenha(const std::string& senhaAtual, const std::string& novaSenha);


    virtual int getLimiteEmprestimo() const = 0;
    virtual std::string getTipoUsuario() const = 0;

    virtual int getNivelPrioridade() const = 0; // 1 = alta prioridade, 2 = baixa, etc.
};

#endif
