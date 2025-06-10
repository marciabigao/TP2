#include "../include/Pacote.hpp"

Pacote::Pacote() {
    this->id = -1;
    this->momentoPostagem = -1;
    this->armazemOrigem = -1;
    this->armazemDestino = -1;
    this->estado = 0;
    this->rota = new ListaEncadeada();
}

Pacote::Pacote(int id, int dataHora, int origem, int destino, int estado) {
    this->id = id;
    this->momentoPostagem = dataHora;
    this->armazemOrigem = origem;
    this->armazemDestino = destino;
    this->estado = estado;
}

int Pacote::getMomentoPostagem() {
    return this->momentoPostagem;
}

int Pacote::getArmazemOrigem() {
    return this->armazemOrigem;
}

int Pacote::getArmazemDestino() {
    return this->armazemDestino;
}