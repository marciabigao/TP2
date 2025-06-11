#ifndef GRAFO_HPP
#define GRAFO_HPP

#include "Armazem.hpp"
#include "Pilha.hpp"

class Grafo {
    public:
    int numeroVertices;
    Armazem* armazens;
    int custoRemocao;

    public:
    Grafo(int numeroVertices, int custoRemocao);
    ~Grafo();

    void setNumeroVizinhos(int IDArmazemAlvo, int numVizinhos);
    void insereVizinho(int IDArmazemAlvo, int IDArmazemVizinho);
    void criaSecoes(int IDArmazemAlvo);
    void inserePacoteSecao(int IDArmazemAlvo, int secaoDestino, Pacote pacote);
};

#endif