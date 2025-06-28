
#include "livros.h" 
#include "usuario.h"
#include <iostream>  


using namespace std;


Livro::Livro(string idLivro, string nomeLivro, string autorLivro, string temaLivro, int lancamentoLivro, bool disponivelInicial)
    : id(idLivro), nome(nomeLivro), autor(autorLivro), tema(temaLivro), lancamento(lancamentoLivro), disponivel(disponivelInicial) {
    
}


string Livro::getId() const {
    return id;
}

string Livro::getNome() const {
    return nome;
}

string Livro::getAutor() const {
    return autor;
}

string Livro::getTema() const {
    return tema;
}

int Livro::getLancamento() const {
    return lancamento;
}

bool Livro::getDisponibilidade() const {
    return disponivel;
}

void Livro::resumo() const {
    std::cout << "'" << nome << "' por " << autor
              << " | ID: " << id
              << " | Status: " << (disponivel ? "Disponivel" : "Emprestado") << std::endl;
}

void Livro::setDisponivel() {
    disponivel = true;
}

void Livro::setUsado() {
    disponivel = false; 
}

void Livro::adicionarNaFila(Usuario* novoUsuario) {
    auto it = filaDeEspera.begin();
    while (it != filaDeEspera.end()) {
        // Se a prioridade for menor (número maior), continua procurando:
        if (novoUsuario->getNivelPrioridade() > (*it)->getNivelPrioridade()) {
            ++it;
        }else{
            // Encontrou a posição correta (prioridade maior ou igual), insere antes e sai
            filaDeEspera.insert(it, novoUsuario);
            std::cout << "  [INFO] Usuario " << novoUsuario->getLogin() << " adicionado a fila de espera.\n";
            return;        
        }
    }

    // Se o loop terminar, o usuário tem a menor prioridade, então é inserido no final
    filaDeEspera.push_back(novoUsuario);
    std::cout << "  [INFO] Usuario " << novoUsuario->getLogin() << " adicionado ao final da fila de espera.\n";
}

Usuario* Livro::proximoDaFila(){
    if (filaDeEspera.empty()){
        return nullptr;
    }
    Usuario* proximo = filaDeEspera.front();
    filaDeEspera.pop_front(); // Remove da fila
    return proximo;
}

void Livro::verFilaDeEspera() const {
    std::cout << "  --- Fila de Espera para '" << this->nome << "' ---\n";
    if (filaDeEspera.empty()) {
        std::cout << "  A fila de espera esta vazia.\n";
    } else {
        int pos = 1;
        for (const auto& usuario : filaDeEspera) {
            std::cout << "  " << pos++ << ". " << usuario->getLogin() << " (Tipo: " << usuario->getTipoUsuario() << ")\n";
        }
    }
}
