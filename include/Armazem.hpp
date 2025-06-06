#ifndef ARMAZEM_HPP
#define ARMAZEM_HPP

#include "Pilha.hpp"
#include "ListaEncadeada.hpp"

class Armazem {
    private:
    int id;
    int numeroVizinhos;
    Pilha* secoes;
    ListaEncadeada* vizinhos;

    public:
    Armazem();
    ~Armazem();

    friend class Grafo;
};

#endif