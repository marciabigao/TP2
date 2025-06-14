#ifndef PILHA_HPP
#define PILHA_HPP

#include "Nos.hpp"
#include "Pacote.hpp"

class Pilha {
    public:
    int id;
    NoPilha* topo;
    int tamanho;

    public:
    Pilha();
    ~Pilha();

    void setID(int id);
    int getID();

    void empilha(Pacote* pacote);
    Pacote* desempilha();
    void limpar();
    bool vazia();
};

#endif