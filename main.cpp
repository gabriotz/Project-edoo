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
    setlocale(LC_ALL, "Portuguese_Brazil.1252");

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
                sistemaUsuarios.listarUsuarios();
                break;
            }
            case 5: { // Rodar Simulação de Empréstimo e Devolução
                std::string loginTeste, idLivroTeste;
                char acao;

                std::cout << "\n--- Simulacao ---";
                std::cout << "\nDigite o login do usuario: ";
                std::getline(std::cin, loginTeste);
                std::cout << "Digite o ID do livro: ";
                std::getline(std::cin, idLivroTeste);

                // Etapa 1: Validar se o usuário e o livro existem
                Usuario* u = sistemaUsuarios.buscarUsuarioPorLogin(loginTeste);
                if (!u) {
                    std::cout << "FALHA: Usuario '" << loginTeste << "' nao encontrado.\n";
                    break;
                }
                Livro* l = biblioteca.buscarLivroPorId(idLivroTeste);
                if (!l) {
                    std::cout << "FALHA: Livro com ID '" << idLivroTeste << "' nao encontrado.\n";
                    break;
                }

                // Etapa 2: Perguntar a ação desejada
                std::cout << "O que deseja fazer com o livro '" << l->getNome() << "'? (E para Emprestar, D para Devolver): ";
                std::cin >> acao;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                // Etapa 3: Executar a lógica baseada na ação
                if (acao == 'E' || acao == 'e') {
                    // --- LÓGICA DE EMPRÉSTIMO ---
                    std::cout << "\n>>> TENTANDO EMPRESTAR '" << l->getNome() << "' PARA '" << u->getLogin() << "'...\n";
                    
                    if (l->getDisponibilidade()) {
                        // Caminho 1: O livro está disponível
                        if (u->getQuantidadeLivros() < u->getLimiteEmprestimo()) {
                            l->setUsado();
                            u->pegarLivroEmprestado(l);
                            std::cout << "SUCESSO! Emprestimo realizado.\n";
                        } else {
                            std::cout << "FALHA! O usuario ja atingiu seu limite de " << u->getLimiteEmprestimo() << " emprestimos.\n";
                        }
                    } else {
                        // Caminho 2: O livro está emprestado, oferecer fila de espera
                        std::cout << "FALHA! O livro ja esta emprestado.\n";
                        l->verFilaDeEspera();
                        char entrarNaFila;
                        std::cout << "Deseja entrar na fila de espera? (S/N): ";
                        std::cin >> entrarNaFila;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        if (entrarNaFila == 'S' || entrarNaFila == 's') {
                            l->adicionarNaFila(u);
                        }
                    }
                } else if (acao == 'D' || acao == 'd') {
                    // --- LÓGICA DE DEVOLUÇÃO ---
                    std::cout << "\n>>> TENTANDO DEVOLVER '" << l->getNome() << "'...\n";
                    
                    Livro* livroDevolvido = u->devolverLivro(l->getId());
                    if (livroDevolvido) {
                        // Verifica se há alguém na fila de espera PELO LIVRO devolvido
                        Usuario* proximoDaFila = livroDevolvido->proximoDaFila();
                        
                        if (proximoDaFila) {
                            // Se houver, o livro é automaticamente emprestado para essa pessoa
                            proximoDaFila->pegarLivroEmprestado(livroDevolvido);
                            // O livro continua com o status 'usado'
                            std::cout << "SUCESSO! Livro devolvido e automaticamente emprestado para o proximo da fila: " << proximoDaFila->getLogin() << ".\n";
                        } else {
                            // Se não houver ninguém na fila, o livro fica disponível
                            livroDevolvido->setDisponivel();
                            std::cout << "SUCESSO! Livro devolvido e agora esta disponivel no acervo.\n";
                        }
                    } else {
                        std::cout << "FALHA! O usuario '" << u->getLogin() << "' nao possuia este livro para devolver.\n";
                    }
                } else {
                    std::cout << "ERRO: Acao invalida. Escolha 'E' ou 'D'.\n";
                }
                break;
            }
            case 0: { // Sair
                std::cout << "\nEncerrando o programa...\n";
                return 0; 
            }
            default: {
                std::cout << "Opcao invalida. Tente novamente.\n";
                break;
            }
        }
    }

    return 0;
}