#ifndef PACOTE_HPP
#define PACOTE_HPP

#include "ListaEncadeada.hpp"
#include <string>

class Pacote {
    private:
    int momentoPostagem;
    std::string nomeRemetente;
    std::string nomeDestinatario;
    int armazemOrigem;
    int armazemDestino;
    ListaEncadeada* rota;

    public:
    Pacote();
    Pacote(int dataHora, std::string remetente, std::string destinatario, int origem, int destino);

    int getMomentoPostagem();
    std::string getNomeRemetente();
    std::string getNomeDestinatario();
    int getArmazemOrigem();
    int getArmazemDestino();

    void calcularRota();
};

#endif