#ifndef LISTAENC_HPP
#define LISTAENC_HPP

#include "Nos.hpp"

//TAD representativo de uma lista encadeada 
class ListaEncadeada {
    public:
    NoLista* primeiro; //ponteiro para primeiro elemento da lista
    NoLista* ultimo; //ponteiro para ultimo elemento da lista
    int tamanho; //tamanho atual da lista

    public:
    ListaEncadeada();
    ~ListaEncadeada();

    NoLista* getPrimeiro();
    int getIDpos(int pos);
    int getSucessor(int id);

    void inserir(int id);
    void limpar();

    friend class Grafo;
};

#endif