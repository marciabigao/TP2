#ifndef NOFILA_HPP
#define NOFILA_HPP

class NoFila {
    public:
    int id;
    NoFila* proximo;

    public:
    NoFila();

    friend class Fila;
};

#endif