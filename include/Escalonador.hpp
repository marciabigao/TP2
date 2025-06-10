#ifndef ESCALONADOR_HPP
#define ESCALONADOR_HPP

#include "Evento.hpp"

class Escalonador {
    private:
    int tamanho;
    Evento* dados;
    int capacidadeTransporte;
    int latenciaTransporte;
    int intervaloEntreTransportes;

    public:
    Escalonador(int tamanhoMax, int capacidadeTransporte, int latenciaTransporte, int intervaloEntreTransportes);
    ~Escalonador();

    void inserir(Evento* evento);
    Evento* remover();
    bool vazio();
};

#endif