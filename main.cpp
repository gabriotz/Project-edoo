// main.cpp - SUGESTÃO DE ESTRUTURA
#include "acervo.h"   // Inclui Livro indiretamente se acervo.h incluir livros.h
#include "livros.h"   // Boa prática incluir explicitamente se for usar Livro aqui
#include <iostream>

// using namespace std; // Recomendo std::cout, std::endl etc.

int main() {
    // Criar alguns livros
    Livro* livro1 = new Livro("1", "O Senhor dos Aneis", "J.R.R. Tolkien", "Fantasia", 1954, true);
    Livro* livro2 = new Livro("2", "1984", "George Orwell", "Distopia", 1949, true);
    Livro* livro3 = new Livro("3", "O Guia do Mochileiro das Galaxias", "Douglas Adams", "Ficcao Cientifica", 1979, false);

    livro1->setUsado();
    
    // Criar um acervo
    Acervo meuAcervo;
    std::cout << "\n"; // Para separar as mensagens

    // Adicionar livros ao acervo
    meuAcervo.adicionarLivro(livro1);
    meuAcervo.adicionarLivro(livro2);
    meuAcervo.adicionarLivro(livro3);
    meuAcervo.adicionarLivro(new Livro("4", "A Revolucao dos Bichos", "George Orwell", "Satira Politica", 1945, true)); // Outra forma
    std::cout << "\n";

    // Listar livros
    std::cout << "--- Listando Livros Apos Adicao ---" << std::endl;
    meuAcervo.listarLivros();
    std::cout << "Tamanho do acervo: " << meuAcervo.getTamanho() << std::endl;
    std::cout << "\n";

    // Usar resumo de um livro
    if (livro1) { // Sempre bom checar ponteiros antes de usar
        livro1->resumo();
    }
    std::cout << "\n";

    // Remover um livro
    std::cout << "--- Removendo Livro ID 2 ---" << std::endl;
    meuAcervo.removerLivro("2"); // livro2 será deletado aqui
    livro2 = nullptr; // Boa prática: anular ponteiro após delete
    std::cout << "\n";

    // Listar livros novamente
    std::cout << "--- Listando Livros Apos Remocao ---" << std::endl;
    meuAcervo.listarLivros();
    std::cout << "Tamanho do acervo: " << meuAcervo.getTamanho() << std::endl;
    std::cout << "\n";

    // Testar adicionar livro nulo
    meuAcervo.adicionarLivro(nullptr);
    std::cout << "\n";

    // Testar remover livro inexistente
    meuAcervo.removerLivro("99");
    std::cout << "\n";


    // IMPORTANTE: Gerenciamento de memória para os livros restantes no acervo
    // Se você criou livros com 'new' e os adicionou ao acervo,
    // e o acervo não tem um destrutor para limpar esses livros,
    // você teria um vazamento de memória aqui.
    // A classe Acervo deveria ter um destrutor para deletar os Livro* que ela armazena.
    // Ex:
    // Acervo::~Acervo() {
    //     for (Livro* livro : AcervoLivros) {
    //         delete livro;
    //     }
    //     AcervoLivros.clear();
    // }
    // Se o destrutor estiver implementado em Acervo, os livros restantes (livro1, livro3, livro4)
    // serão deletados quando 'meuAcervo' sair de escopo no final do main.
    // Se não, você precisaria deletá-los manualmente ANTES de meuAcervo ser destruído,
    // ou implementar o destrutor.

    // Se você não implementou o destrutor em Acervo e não removeu todos os livros manualmente:
    // delete livro1; // Se não foi removido e deletado pelo acervo
    // delete livro3; // Se não foi removido e deletado pelo acervo
    // O livro com ID "4" também precisaria ser gerenciado.

    return 0;
}