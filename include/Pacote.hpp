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
    ListaEncadeada* rota;

    public:
    Pacote();
    Pacote(int id, int dataHora, int origem, int destino, int estado);

    int getMomentoPostagem();
    int getArmazemOrigem();
    int getArmazemDestino();

    void calcularRota();
};

#endif