#ifndef ARMAZEM_HPP
#define ARMAZEM_HPP

#include "Pilha.hpp"
#include "ListaEncadeada.hpp"

//TAD representativo do armazem, que também sera o no do grafo de armazens
class Armazem {
    public:
    int id; //identificador do armazem
    int numeroVizinhos; //numero de outros armazens ao qual esta conectado
    Pilha* secoes; //pilhas que armazenam os pacotes destinados aos seus vizinhos
    ListaEncadeada* vizinhos; //lista encadeada representativa dos vizinhos (estrutura do grafo)

    public:
    Armazem();
    ~Armazem();

    void alocarPilha();
    int getIndicePilha(int idPilhaDesejada);

    friend class Grafo;
};

#endif