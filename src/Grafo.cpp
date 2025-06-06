#include "../include/Grafo.hpp"

Grafo::Grafo(int numeroVertices) {
    this->numeroVertices = numeroVertices;
    this->armazens = new Armazem[numeroVertices];

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

void Grafo::insereVizinho(int IDArmazemAlvo, int IDArmazemDestino) {
    armazens[IDArmazemAlvo].vizinhos->inserir(IDArmazemDestino);

    for(int i = 0; i < armazens[IDArmazemAlvo].numeroVizinhos; i++) {
        if(armazens[IDArmazemAlvo].secoes[i].getID() == -1) {
            armazens[IDArmazemAlvo].secoes[i].setID(IDArmazemDestino);
        }
    }
}