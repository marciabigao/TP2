#ifndef PACOTE_HPP
#define PACOTE_HPP

#include "ListaEncadeada.hpp"
#include <string>

class Pacote {
    private:
    int id;
    int momentoPostagem;
    int armazemOrigem;
    int armazemDestino;
    int estado;
    int tempoArmazenado;
    int tempoSendoTransportado;
    int parteCaminho;

    public:
    ListaEncadeada* rota;
    Pacote();

    int getID();
    int getMomentoPostagem();
    int getArmazemOrigem();
    int getArmazemDestino();
    int getEstado();
    int getTempoArmazenado();
    int getTempoSendoTransportado();
    int getParteCaminho();

    void setID(int id);
    void setMomentoPostagem(int momentoPostagem);
    void setAmarzemDestino(int armazemDestino);
    void setArmazemOrigem(int armazemOrigem);
    void setEstado(int estado);
    void setRota(ListaEncadeada* rota);
};

#endif