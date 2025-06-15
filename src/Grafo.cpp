#include "../include/Grafo.hpp"
#include "../include/Nos.hpp"
#include <iostream>

//construtor
Grafo::Grafo(int numeroVertices, int custoRemocao) {
    this->numeroVertices = numeroVertices;

    try {
        this->armazens = new Armazem[numeroVertices];
    } catch (const std::bad_alloc& e) {
        std::cerr << "Erro ao alocar memória para o vetor: " << e.what() << std::endl;
    }

    this->custoRemocao = custoRemocao;

    for(int i = 0; i < numeroVertices; i++) {
        armazens[i].id = i;
    }
}

//destrutor
Grafo::~Grafo() {
    delete[] armazens;
}

//atribui o numero de vizinhos de um determinado armazem
void Grafo::setNumeroVizinhos(int IDArmazemAlvo, int numVizinhos) {
    armazens[IDArmazemAlvo].numeroVizinhos = numVizinhos;
}

//adiciona um vizinho a lista de vizinhos de um determinado armazem
void Grafo::insereVizinho(int IDArmazemAlvo, int IDArmazemVizinho) {
    armazens[IDArmazemAlvo].vizinhos->inserir(IDArmazemVizinho);
}

//cria as secoes (pilhas) de um determinado armazem
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

//adiciona um pacote a uma determinada secao
void Grafo::inserePacoteSecao(int IDArmazemAlvo, int secaoDestino, Pacote* pacote) {
    int indice = armazens[IDArmazemAlvo].getIndicePilha(secaoDestino);
    armazens[IDArmazemAlvo].secoes[indice].empilha(pacote);
}