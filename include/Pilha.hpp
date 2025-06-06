#ifndef PILHA_HPP
#define PILHA_HPP

#include "NoPilha.hpp"
#include "Pacote.hpp"

class Pilha {
    private:
    int id;
    NoPilha* topo;
    int tamanho;

    public:
    Pilha();
    ~Pilha();

    void setID(int id);
    int getID();

    void empilha(Pacote pacote);
    Pacote desempilha();
    void limpar();
    bool vazia();
};

#endif