#ifndef GRAFO_HPP
#define GRAFO_HPP

#include "Armazem.hpp"

class Grafo {
    private:
    int numeroVertices;
    Armazem* armazens;

    public:
    Grafo(int numeroVertices);
    ~Grafo();

    void setNumeroVizinhos(int IDArmazemAlvo, int numVizinhos);
    void insereVizinho(int IDArmazemAlvo, int IDArmazemDestino);
};

#endif