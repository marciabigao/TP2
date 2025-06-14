#include "../include/Armazem.hpp"

Armazem::Armazem() {
    this->id = -1;
    this->numeroVizinhos = 0;
    this->vizinhos = new ListaEncadeada();
}

Armazem::~Armazem() {
    delete[] secoes;
    delete vizinhos;
}

void Armazem::alocarPilha() {
    this->secoes = new Pilha[numeroVizinhos];
}

int Armazem::getIndicePilha(int idPilhaDesejada) {
    for(int i = 0; i < numeroVizinhos; i++) {
        if(secoes[i].getID() == idPilhaDesejada) {
            return i;
        }
    }

    return -1;
}