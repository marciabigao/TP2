#include "../include/Pilha.hpp"
#include <iostream>

//construtor
Pilha::Pilha() {
    this->id = -1;
    this->topo = nullptr;
    this->tamanho = 0;
}

//retira todos os nos da pilha
void Pilha::limpar() {
    while(tamanho != 0) {desempilha();}
}

//destrutor
Pilha::~Pilha() {
    this->limpar();
}

//atribui um identificador a pilha
void Pilha::setID(int id) {
    this->id = id;
}

//retorna o identificador da pilha
int Pilha::getID() {
    return this->id;
}

//empilha um novo pacote
void Pilha::empilha(Pacote* pacote) {
    NoPilha* novo;

    try {
        novo = new NoPilha();
    } catch (const std::bad_alloc& e) {
        std::cerr << "Erro ao alocar memória para a variavel: " << e.what() << std::endl;
    }

    novo->pacote = pacote;
    novo->proximo = topo;
    topo = novo;
    tamanho++;
}

//desempilha o pacote ao topo
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

//retorna se a pilha esta vazia ou nao
bool Pilha::vazia(){
    return (tamanho == 0);
}