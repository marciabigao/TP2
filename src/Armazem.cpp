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