#ifndef EVENTO_HPP
#define EVENTO_HPP

#include "Pacote.hpp"
#include <string>

class Evento {
    private:
    std::string chave;
    int tempo;

    public:
    Evento();
    void setTempo(int tempo);
    int getTempo();
};

class ChegadaPacote : public Evento {
    private:
    Pacote pacote;
    int idArmazemDestino;

    public:
    ChegadaPacote(int tempo, Pacote pacote, int idArmazemDestino);
    Pacote getPacote();
    int getIDArmazemDestino();
};

class Transporte : public Evento {
    private:
    Pacote pacote;
    int idArmazemOrigem;
    int idArmazemDestino;

    public:
    Transporte(int tempo, int idArmazemOrigem, int idArmazemDestino, Pacote pacote);
    int getArmazemOrigem();
    int getArmazemDestino();
    Pacote getPacote();
};

#endif