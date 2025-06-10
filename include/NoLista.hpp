#ifndef NOLISTA_HPP
#define NOLISTA_HPP

class NoLista {
    public:
    int id;
    NoLista* proximo;

    public:
    NoLista();

    friend class ListaEncadeada;
    friend class Grafo;
};

#endif