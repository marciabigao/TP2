#ifndef ESCALONADOR_HPP
#define ESCALONADOR_HPP

#include "Evento.hpp"

//TAD representativo da fila de prioridade da simulacao discreta de eventos
class Escalonador {
    private:
    int tamanho; //quantidade de eventos escalonados
    Evento** dados; //vetor de eventos escalonados
    int capacidadeTransporte; //capacidade de cada transporte
    int latenciaTransporte; //tempo de duração do transporte
    int intervaloEntreTransportes; //intervalo entre transportes entre dois armazens

    public:
    Escalonador(int tamanhoMax, int capacidadeTransporte, int latenciaTransporte, int intervaloEntreTransportes);
    ~Escalonador();

    void inserir(Evento* evento);
    Evento* remover();
    bool vazio();
};

#endif