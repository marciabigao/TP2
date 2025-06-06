#ifndef ESCALONADOR_HPP
#define ESCALONADOR_HPP

#include "Evento.hpp"

class Escalonador {
    private:
    int tamanho;
    Evento* dados;

    public:
    Escalonador(int tamanhoMax);
    ~Escalonador();

    void inserir(Evento* evento);
    Evento* remover();
    bool vazio();
};

#endif