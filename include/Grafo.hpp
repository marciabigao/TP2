#ifndef GRAFO_HPP
#define GRAFO_HPP

#include "Armazem.hpp"
#include "Pilha.hpp"

//TAD representativo de um grafo
class Grafo {
    public:
    int numeroVertices; //numero de vertices do grafo
    Armazem* armazens; //nos do grafo (que serao armazens)
    int custoRemocao; //custo para remover um pacote de uma pilha

    public:
    Grafo(int numeroVertices, int custoRemocao);
    ~Grafo();

    void setNumeroVizinhos(int IDArmazemAlvo, int numVizinhos);
    void insereVizinho(int IDArmazemAlvo, int IDArmazemVizinho);
    void criaSecoes(int IDArmazemAlvo);
    void inserePacoteSecao(int IDArmazemAlvo, int secaoDestino, Pacote* pacote);
};

#endif