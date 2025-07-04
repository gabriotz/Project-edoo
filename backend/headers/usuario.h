#ifndef USUARIO_H
#define USUARIO_H

#include "livros.h"
#include "acervo.h"
#include <string> 
#include <iostream>

// A classe Usuario é uma classe base abstrata para Alunos e Professores.
// Ela não pode ser instanciada diretamente porque possui métodos virtuais puros.
class Usuario  {
protected: // Atributos protegidos são acessíveis por esta classe e por suas classes derivadas (Aluno, Professor).
    std::string login;
    std::string senha;        
    std::vector<Livro*> livrosEmprestados; // vetor de livros que o usuário pegou emprestado.
public:
    // Destrutor virtual, essencial para classes base com herança polimórfica.
    virtual ~Usuario() = default;    

    // Construtor da classe base.
    Usuario(const std::string& uLogin, const std::string& uSenha);
    
    // Métodos relacionados a operações com livros.
    bool possuiLivro(const std::string& idLivro) const;
    void pegarLivroEmprestado(Livro* livro);
    Livro* devolverLivro(const std::string& idLivro);    
    void listarLivrosDoUsuario() const;
    int getQuantidadeLivros() const;

    // Métodos para obter informações do usuário.
    std::string getLogin() const;
    std::string getSenha() const;
    std::vector<Livro*> getVetor()const;


    // Métodos de autenticação e gerenciamento da conta.
    bool verificarLogin(const std::string& tentativaLogin, const std::string& tentativaSenha) const;
    bool alterarSenha(const std::string& senhaAtual, const std::string& novaSenha);

    //Metodos virtuais, para a implementação do polimorfismo com as classes aluno e professor.
    virtual int getLimiteEmprestimo() const = 0;
    virtual std::string getTipoUsuario() const = 0;
    virtual int getNivelPrioridade() const = 0; // 1 = alta prioridade, 2 = baixa, etc.
};

#endif
