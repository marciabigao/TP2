#ifndef LISTAENC_HPP
#define LISTAENC_HPP

#include "NoLista.hpp"

class ListaEncadeada {
    private:
    NoLista* primeiro;
    NoLista* ultimo;
    int tamanho;

    public:
    ListaEncadeada();
    ~ListaEncadeada();

    void inserir(int id);
    void limpar();
};

#endif