#include "../include/Armazem.hpp"

//construtor
Armazem::Armazem() {
    this->id = -1;
    this->numeroVizinhos = 0;
    this->vizinhos = new ListaEncadeada();
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