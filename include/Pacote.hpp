#ifndef PACOTE_HPP
#define PACOTE_HPP

#include "ListaEncadeada.hpp"
#include <string>

//TAD representativo de um pacote 
class Pacote {
    private:
    int id; //identificador do pacote
    int momentoPostagem; //momento em que o pacote entrou no sistema
    int armazemOrigem; //armazem de postagem do pacote
    int armazemDestino; //armazem de destino final do pacote  
    int estado; //estado no qual o pacote se encontra
    int tempoArmazenado; //tempo em que o pacote ficou armazenado
    int tempoSendoTransportado; //tempo em que o pacote ficou em transporte

    public:
    ListaEncadeada* rota; //melhor rota do armazem de destino ao armazem de origem
    Pacote();

    int getID();
    int getMomentoPostagem();
    int getArmazemOrigem();
    int getArmazemDestino();
    int getEstado();
    int getTempoArmazenado();
    int getTempoSendoTransportado();

    void setID(int id);
    void setMomentoPostagem(int momentoPostagem);
    void setAmarzemDestino(int armazemDestino);
    void setArmazemOrigem(int armazemOrigem);
    void setEstado(int estado);
    void setRota(ListaEncadeada* rota);
};

#endif