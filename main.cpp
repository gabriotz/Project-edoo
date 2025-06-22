#include <iostream>
#include <string>
#include <vector>
#include <locale.h>
#include <limits> 

#include "acervo.h"
#include "cadastros.h"
#include "aluno.h"
#include "professor.h"
#include "livros.h"


void imprimirLinhaDivisoria() {
    std::cout << "========================================================" << std::endl;
}

int main() {

    Acervo biblioteca;
    Cadastros sistemaUsuarios;
    int escolha;

    while (true) {
        imprimirLinhaDivisoria();
        std::cout << "SISTEMA DE GERENCIAMENTO DA BIBLIOTECA\n";
        std::cout << "1. Adicionar novo Livro\n";
        std::cout << "2. Adicionar novo Usuario\n";
        std::cout << "3. Listar todos os Livros no Acervo\n";
        std::cout << "4. Listar todos os Usuarios Cadastrados\n";
        std::cout << "5. Rodar Simulacao de Emprestimo e Devolucao\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> escolha;

        // Limpa o buffer do teclado. Essencial após usar 'cin >>' para que 'getline' funcione corretamente depois.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (escolha) {
            case 1: { // Adicionar Livro
                std::string nome, autor, tema;
                int ano;
                int tamanho;
                std::string id;

                std::cout << "\n--- Cadastro de Novo Livro ---\n";
                std::cout << "Digite o nome: ";
                std::getline(std::cin, nome);

                if (nome.empty()) {
                    std::cout << "ERRO: Nome do livro nao pode ser vazio.\n";
                    break;
                }

                std::cout << "Digite o autor: ";
                std::getline(std::cin, autor);
                std::cout << "Digite o tema: ";
                std::getline(std::cin, tema);
                std::cout << "Digite o ano de lancamento: ";
                std::cin >> ano;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpa o buffer de novo

                tamanho = biblioteca.getTamanho();
                id = "L" + std::to_string(tamanho + 10); // Lógica de ID para não colidir com os de teste
                biblioteca.adicionarLivro(new Livro(id, nome, autor, tema, ano, true));
                break;
            }
            case 2: { // Adicionar Usuario
                int tipoUsuario;
                std::string login, senha;

                std::cout << "\n--- Cadastro de Novo Usuario ---\n";
                std::cout << "Digite o tipo (1 para Aluno, 2 para Professor): ";
                std::cin >> tipoUsuario;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Digite o login: ";
                std::getline(std::cin, login);
                std::cout << "Digite a senha: ";
                std::getline(std::cin, senha);

                if (tipoUsuario == 1) {
                    sistemaUsuarios.adicionarUsuario(new Aluno(login, senha));
                } else if (tipoUsuario == 2) {
                    sistemaUsuarios.adicionarUsuario(new Professor(login, senha));
                } else {
                    std::cout << "ERRO: Tipo de usuario invalido.\n";
                }
                break;
            }
            case 3: { // Listar Livros
                std::cout << "\n";
                biblioteca.listarLivros();
                break;
            }
            case 4: { // Listar Usuarios
                std::cout << "\n";
                sistemaUsuarios.listarUsuarios(); // Supondo que você tenha um método para listar usuários
                break;
            }
            case 5: { // Rodar Simulação
                std::string loginTeste, idLivroTeste;
                std::cout << "\n--- Simulacao de Emprestimo ---\n";
                std::cout << "Digite o login do usuario que fara o emprestimo: ";
                std::getline(std::cin, loginTeste);
                std::cout << "Digite o ID do livro a ser emprestado: ";
                std::getline(std::cin, idLivroTeste);

                Usuario* u = sistemaUsuarios.buscarUsuarioPorLogin(loginTeste);
                Livro* l = biblioteca.buscarLivroPorId(idLivroTeste);

                if (!u) {
                    std::cout << "FALHA: Usuario '" << loginTeste << "' nao encontrado.\n";
                    break;
                }
                if (!l) {
                    std::cout << "FALHA: Livro com ID '" << idLivroTeste << "' nao encontrado.\n";
                    break;
                }

                std::cout << "\n>>> TENTANDO EMPRESTAR '" << l->getNome() << "' PARA '" << u->getLogin() << "'...\n";
                if (u->getQuantidadeLivros() < u->getLimiteEmprestimo()) {
                    if (l->getDisponibilidade()) {
                        l->setUsado();
                        u->pegarLivroEmprestado(l);
                        std::cout << "SUCESSO! Emprestimo realizado.\n";
                    } else {
                        std::cout << "FALHA! O livro ja esta emprestado.\n";
                    }
                } else {
                    std::cout << "FALHA! O usuario ja atingiu seu limite de emprestimos.\n";
                }
                
                imprimirLinhaDivisoria();
                std::cout << "Estado atual do usuario:\n";
                u->listarLivrosDoUsuario(); // Apenas esta chamada é necessária.
                // l->resumo(); // ESTA LINHA FOI REMOVIDA PARA CORRIGIR A DUPLICIDADE
                imprimirLinhaDivisoria();

                std::cout << "\n>>> DEVOLVENDO O LIVRO AGORA...\n";
                Livro* livroDevolvido = u->devolverLivro(idLivroTeste);
                if (livroDevolvido) {
                    livroDevolvido->setDisponivel();
                    std::cout << "SUCESSO! Livro devolvido ao acervo.\n";
                } else {
                    std::cout << "FALHA! O usuario nao possuia este livro.\n";
                }

                break;
            }
            case 0: { // Sair
                std::cout << "\nEncerrando o programa...\n";
                return 0; // Sai do loop e da função main
            }
            default: {
                std::cout << "Opcao invalida. Tente novamente.\n";
                break;
            }
        }
    }

    return 0;
}