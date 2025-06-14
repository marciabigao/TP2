#ifndef EVENTO_HPP
#define EVENTO_HPP

#include "Pacote.hpp"
#include <string>

//TAD representativo do evento na simulacao discreta de eventos
class Evento {
    protected:
    std::string chave; //chave de comparacao entre eventos no heap
    int tipoEvento; //indicador do tipo de herdeiro que esse evento e
    int tempo; //momento em que o evento ocorre na simulacao

    public:
    Evento();
    virtual ~Evento() {};
    void setTempo(int tempo);
    int getTempo();
    int getTipoEvento();
    std::string getChave();
};

//TAD herdeiro de Evento, representativo da chegada de um pacote em um armazem
class ChegadaPacote : public Evento {
    private:
    Pacote* pacote; //pacote que esta chegando
    int idArmazemChegada; //onde esse pacote esta chegando
    int idArmazemProximoDestino; //em qual sessao do armazem atual esse pacote deve ser armazenado

    public:
    ChegadaPacote();
    ChegadaPacote(int tempo, Pacote* pacote, int idArmazemChegada, int idArmazemProximoDestino);
    Pacote* getPacote();
    int getIDArmazemChegada();
    int getIDArmazemProximoDestino();
    void setEstadoPacote(int estado);
};

//TAD herdeiro de Evento, representativo do transporte de pacotes entre armazens
class Transporte : public Evento {
    private:
    int idArmazemOrigem; //origem do transporte 
    int idArmazemDestino; //destino do transporte
    int capacidadeTransporte; //quantos pacotes um mesmo transporte transporta, no maximo

    public:
    Transporte(int tempo, int idArmazemOrigem, int idArmazemDestino, int capacidadeTransporte);
    int getArmazemOrigem();
    int getArmazemDestino();
    Pacote* getPacotes();
};

#endif