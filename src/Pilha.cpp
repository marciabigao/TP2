#include "../include/Pilha.hpp"

Pilha::Pilha() {
    this->id = -1;
    this->topo = nullptr;
    this->tamanho = 0;
}

void Pilha::limpar() {
    while(tamanho != 0) {desempilha();}
}

Pilha::~Pilha() {
    this->limpar();
}

void Pilha::setID(int id) {
    this->id = id;
}

int Pilha::getID() {
    return this->id;
}

void Pilha::empilha(Pacote* pacote) {
    NoPilha* novo;

    novo = new NoPilha();
    novo->pacote = pacote;
    novo->proximo = topo;
    topo = novo;
    tamanho++;
}

Pacote* Pilha::desempilha() {
    Pacote* aux;
    NoPilha* p;

    if(tamanho == 0) {
        throw("A pilha está vaiza!");
    }

    aux = topo->pacote;
    p = topo;
    topo = topo->proximo;
    delete p;
    tamanho--;

    return aux;
}

bool Pilha::vazia(){
    return (tamanho == 0);
}