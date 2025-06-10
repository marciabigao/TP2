#include "../include/Fila.hpp"

Fila::Fila() {
    frente = new NoFila();
    tras = frente;
    tamanho = 0;
}

void Fila::limpa() {
    NoFila* p;

    p = frente->proximo;
    while(p != nullptr) {
        frente->proximo = p->proximo;
        delete p;
        p = frente->proximo;
    }

    tamanho = 0;
    tras = frente;
}

Fila::~Fila() {
    this->limpa();
    delete frente;
}

void Fila::enfileira(int id) {
    NoFila* nova;

    nova = new NoFila();
    nova->id = id;
    tras->proximo = nova;
    tras = nova;
    tamanho++;
}

int Fila::desenfileira() {
    NoFila* p;
    int retorno;

    if(tamanho == 0) {
        throw ("A fila está vazia!");
    }

    retorno = frente->proximo->id;
    p = frente;
    frente = frente->proximo;
    delete p;
    tamanho--;

    return retorno;
}

bool Fila::vazia() {
    return (tamanho == 0);
}