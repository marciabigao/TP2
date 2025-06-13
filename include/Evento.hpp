#ifndef EVENTO_HPP
#define EVENTO_HPP

#include "Pacote.hpp"
#include <string>

class Evento {
    protected:
    std::string chave;
    int tipoEvento;
    int tempo;

    public:
    Evento();
    virtual ~Evento() {};
    void setTempo(int tempo);
    int getTempo();
    int getTipoEvento();
    std::string getChave();
};

class ChegadaPacote : public Evento {
    private:
    Pacote pacote;
    int idArmazemChegada;
    int idArmazemProximoDestino;

    public:
    ChegadaPacote(int tempo, Pacote pacote, int idArmazemChegada, int idArmazemProximoDestino);
    Pacote getPacote();
    int getIDArmazemChegada();
    int getIDArmazemProximoDestino();
    void setEstadoPacote(int estado);
};

class Transporte : public Evento {
    private:
    Pacote* pacotes;
    int idArmazemOrigem;
    int idArmazemDestino;
    int capacidadeTransporte;

    public:
    Transporte(int tempo, int idArmazemOrigem, int idArmazemDestino, int capacidadeTransporte);
    void setPacotes(Pacote* pacotes);
    int getArmazemOrigem();
    int getArmazemDestino();
    Pacote* getPacotes();
};

#endif