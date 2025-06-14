#ifndef PILHA_HPP
#define PILHA_HPP

#include "Nos.hpp"
#include "Pacote.hpp"

class Pilha {
    public:
    int id; //identificador da pilha (identificador do armazem ao qual o pacote sera destinado)
    NoPilha* topo; //ponteiro para o topo da pilha
    int tamanho; //tamanho atual da pilha

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