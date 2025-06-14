#ifndef FILA_HPP
#define FILA_HPP

#include "Nos.hpp"

//TAD representativo de uma fila
class Fila {
    private:
    int tamanho; //tamanho atual da fila
    NoFila* frente; //ponteiro para o primeiro elemento da fila
    NoFila* tras; //ponteiro para o ultimo elemento da fila

    public:
    Fila();
    ~Fila();

    void enfileira(int id);
    int desenfileira();
    void limpa();
    bool vazia();
};

#endif