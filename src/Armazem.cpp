#include "../include/Armazem.hpp"
#include <iostream>

//construtor
Armazem::Armazem() {
    this->id = -1;
    this->numeroVizinhos = 0;

    try {
        this->vizinhos = new ListaEncadeada();
    } catch (const std::bad_alloc& e) {
        std::cerr << "Erro ao alocar memória para o vetor: " << e.what() << std::endl;
    }
}

//destrutor
Armazem::~Armazem() {
    delete[] secoes;
    delete vizinhos;
}

//cria as pilhas das secoes do armazem
void Armazem::alocarPilha() {
    this->secoes = new Pilha[numeroVizinhos];
}

//retorna em qual indice do vetor de pilha a pilha com um determinado identificador se encontra
int Armazem::getIndicePilha(int idPilhaDesejada) {
    for(int i = 0; i < numeroVizinhos; i++) {
        if(secoes[i].getID() == idPilhaDesejada) {
            return i;
        }
    }

    return -1;
}