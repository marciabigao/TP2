#ifndef LISTAENC_HPP
#define LISTAENC_HPP

#include "NoLista.hpp"

class ListaEncadeada {
    public:
    NoLista* primeiro;
    NoLista* ultimo;
    int tamanho;

    public:
    ListaEncadeada();
    ~ListaEncadeada();

    NoLista* getPrimeiro();
    int getIDpos(int pos);

    void inserir(int id);
    void limpar();

    friend class Grafo;
};

#endif