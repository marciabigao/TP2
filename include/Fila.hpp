#ifndef FILA_HPP
#define FILA_HPP

#include "NoFila.hpp"

class Fila {
    private:
    int tamanho;
    NoFila* frente;
    NoFila* tras;

    public:
    Fila();
    ~Fila();

    void enfileira(int id);
    int desenfileira();
    void limpa();
    bool vazia();
};

#endif