#include "../include/Fila.hpp"

//construtor
Fila::Fila() {
    frente = new NoFila();
    tras = frente;
    tamanho = 0;
}

//retira todos os nos da fila, mantendo apenas a cabeca
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

//destrutor
Fila::~Fila() {
    this->limpa();
    delete frente;
}

//adiciona elemento ao final da fila
void Fila::enfileira(int id) {
    NoFila* nova;

    nova = new NoFila();
    nova->id = id;
    tras->proximo = nova;
    tras = nova;
    tamanho++;
}

//pega o primeiro elemento da fila
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

//retorna se a fila esta vazia ou nao
bool Fila::vazia() {
    return (tamanho == 0);
}