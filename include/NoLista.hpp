#ifndef NOLISTA_HPP
#define NOLISTA_HPP

class NoLista {
    private:
    int id;
    NoLista* proximo;

    public:
    NoLista();

    friend class ListaEncadeada;
};

#endif