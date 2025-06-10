#ifndef ARMAZEM_HPP
#define ARMAZEM_HPP

#include "Pilha.hpp"
#include "ListaEncadeada.hpp"

class Armazem {
    public:
    int id;
    int numeroVizinhos;
    Pilha* secoes;
    ListaEncadeada* vizinhos;

    public:
    Armazem();
    ~Armazem();
    void alocarPilha();

    friend class Grafo;
};

#endif