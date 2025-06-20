#include <iostream>
#include <string>

// Inclua os cabeçalhos do seu projeto (sem as classes de polimorfismo)
#include "acervo.h"
#include "usuario.h"
#include "livros.h"

// Função auxiliar para organizar a saída no terminal
void imprimirLinhaDivisoria() {
    std::cout << "========================================================" << std::endl;
}

int main() {
    Acervo biblioteca;
    imprimirLinhaDivisoria();
    std::cout << "INICIANDO SIMULACAO COM AUTENTICACAO OBRIGATORIA" << std::endl;
    
    for(int i = 0 ; i<3; i++){
        string nome;
        string autor;
        string tema;
        int ano;
        cout << "vamos criar usuarios" << endl;
        getline (cin,nome);
        getline (cin,autor);
        getline (cin,tema);
        cin >> ano;
        cin.ignore();
        int tamanho = biblioteca.getTamanho();
        string id = "l" + std::to_string(tamanho);        
        biblioteca.adicionarLivro(new Livro(id, nome, autor, tema, ano, true));
    }
    biblioteca.listarLivros();
    
    
    
    
    
    
    
    imprimirLinhaDivisoria();









    // 1. CRIAÇÃO DO CENÁRIO
    
    biblioteca.adicionarLivro(new Livro("L01", "A Guerra dos Tronos", "George R. R. Martin", "Fantasia", 1996, true));
    biblioteca.adicionarLivro(new Livro("L02", "Duna", "Frank Herbert", "Ficcao Cientifica", 1965, true));
    
    // Usuário com credenciais que usaremos para testar
    Usuario usuario("ana.silva", "pass123");

    std::cout << "\n--- ESTADO INICIAL DO ACERVO DA BIBLIOTECA ---\n" << std::endl;
    biblioteca.listarLivros();
    imprimirLinhaDivisoria();

    // =================================================================
    // TESTE 1: TENTATIVA DE EMPRÉSTIMO COM LOGIN INCORRETO
    // =================================================================
    std::cout << ">>> TENTATIVA 1: Emprestar 'Duna' (L02) com SENHA ERRADA." << std::endl;

    // A. O "portão": a verificação de login
    if (usuario.verificarLogin("ana.silva", "senha_errada")) {
        // Este bloco não deve ser executado
        std::cout << "   [ERRO INESPERADO] Login passou com credenciais erradas." << std::endl;
    } else {
        // Este bloco DEVE ser executado
        std::cout << "   [SUCESSO NO TESTE] Falha na autenticacao. O emprestimo foi bloqueado, como esperado." << std::endl;
    }
    imprimirLinhaDivisoria();

    // =================================================================
    // TESTE 2: TENTATIVA DE EMPRÉSTIMO COM LOGIN CORRETO
    // =================================================================
    std::cout << ">>> TENTATIVA 2: Emprestar 'Duna' (L02) com CREDENCIAIS CORRETAS." << std::endl;
    
    // A. Verificação do login novamente, agora com os dados corretos
    if (usuario.verificarLogin("ana.silva", "pass123")) {
        std::cout << "   [INFO] Autenticacao bem-sucedida. Prosseguindo com a logica de emprestimo..." << std::endl;
        
        // B. LÓGICA DE EMPRÉSTIMO (SÓ EXECUTA APÓS LOGIN VÁLIDO)
        Livro* livroParaEmprestar = biblioteca.buscarLivroPorId("L02");

        if (livroParaEmprestar && livroParaEmprestar->getDisponibilidade()) {
            std::cout << "   [SUCESSO] Livro encontrado e disponivel. Emprestimo realizado." << std::endl;
            livroParaEmprestar->setUsado();
            usuario.pegarLivroEmprestado(livroParaEmprestar);
        } else if (livroParaEmprestar) {
            std::cout << "   [FALHA] O livro foi encontrado, mas ja esta emprestado." << std::endl;
        } else {
            std::cout << "   [FALHA] Livro nao encontrado no acervo." << std::endl;
        }

    } else {
        // Este bloco não deve ser executado
        std::cout << "   [ERRO INESPERADO] Falha na autenticacao com credenciais corretas." << std::endl;
    }

    std::cout << "\n--- ESTADO APOS TENTATIVAS DE EMPRESTIMO ---\n" << std::endl;
    std::cout << "Acervo completo da biblioteca:" << std::endl;
    biblioteca.listarLivros();
    std::cout << std::endl;
    usuario.listarLivrosDoUsuario();
    imprimirLinhaDivisoria();

    // =================================================================
    // TESTE 3: DEVOLUÇÃO DO LIVRO
    // =================================================================
    std::cout << ">>> ACAO: Devolver o livro 'Duna' (ID: L02)..." << std::endl;

    Livro* livroDevolvido = usuario.devolverLivro("L02");

    if (livroDevolvido) {
        livroDevolvido->setDisponivel();
        std::cout << "   [SUCESSO] Livro '" << livroDevolvido->getNome() << "' foi devolvido e seu status atualizado para disponivel." << std::endl;
    } else {
        std::cout << "   [FALHA] Usuario nao tinha este livro para devolver." << std::endl;
    }

    std::cout << "\n--- ESTADO FINAL DO SISTEMA ---\n" << std::endl;
    biblioteca.listarLivros();
    imprimirLinhaDivisoria();

    // Lembrete sobre o gerenciamento de memória...
    // A classe Acervo deve ter um destrutor para deletar os ponteiros de Livro.

    return 0;
}