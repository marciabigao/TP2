#include "../include/Grafo.hpp"
#include "../include/Nos.hpp"
#include <iostream>

Grafo::Grafo(int numeroVertices, int custoRemocao) {
    this->numeroVertices = numeroVertices;
    this->armazens = new Armazem[numeroVertices];
    this->custoRemocao = custoRemocao;

    for(int i = 0; i < numeroVertices; i++) {
        armazens[i].id = i;
    }
}

Grafo::~Grafo() {
    delete[] armazens;
}

void Grafo::setNumeroVizinhos(int IDArmazemAlvo, int numVizinhos) {
    armazens[IDArmazemAlvo].numeroVizinhos = numVizinhos;
}

void Grafo::insereVizinho(int IDArmazemAlvo, int IDArmazemVizinho) {
    armazens[IDArmazemAlvo].vizinhos->inserir(IDArmazemVizinho);
}

void Grafo::criaSecoes(int IDArmazemAlvo) {
    armazens[IDArmazemAlvo].alocarPilha();

    NoLista* p = armazens[IDArmazemAlvo].vizinhos->getPrimeiro();
    p = p->proximo;
    int IDpilhas[armazens[IDArmazemAlvo].numeroVizinhos];
    int posicao = 0;
    
    while(p != nullptr) {
        IDpilhas[posicao] = p->id;
        posicao++;
        p = p->proximo;
    }

    for(int i = 0; i < armazens[IDArmazemAlvo].numeroVizinhos; i++) {
        armazens[IDArmazemAlvo].secoes[i].setID(IDpilhas[i]);
    }
}

void Grafo::inserePacoteSecao(int IDArmazemAlvo, int secaoDestino, Pacote* pacote) {
    int indice = armazens[IDArmazemAlvo].getIndicePilha(secaoDestino);
    armazens[IDArmazemAlvo].secoes[indice].empilha(pacote);
}