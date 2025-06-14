#ifndef NOS_HPP
#define NOS_HPP

class Pacote;

class NoFila {
    public:
    int id;
    NoFila* proximo;

    public:
    NoFila();

    friend class Fila;
};

class NoLista {
    public:
    int id;
    NoLista* proximo;

    public:
    NoLista();

    friend class ListaEncadeada;
    friend class Grafo;
};

class NoPilha {
    public:
    Pacote* pacote;
    NoPilha* proximo;

    public:
    NoPilha();

    friend class Pilha;
};

#endif