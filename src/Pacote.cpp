#include "../include/Pacote.hpp"

Pacote::Pacote() {
    this->id = -1;
    this->momentoPostagem = -1;
    this->armazemOrigem = -1;
    this->armazemDestino = -1;
    this->estado = 1;
    this->tempoArmazenado = 0;
    this->tempoSendoTransportado = 0;
    this->rota = new ListaEncadeada();
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

int Pacote::getID() {
    return this->id;
}

int Pacote::getEstado() {
    return this->estado;
}

int Pacote::getTempoArmazenado() {
    return this->tempoArmazenado;
}

int Pacote::getTempoSendoTransportado() {
    return this->tempoSendoTransportado;
}

void Pacote::setID(int id) {
    this->id = id;
}

void Pacote::setMomentoPostagem(int momentoPostagem) {
    this->momentoPostagem = momentoPostagem;
}

void Pacote::setArmazemOrigem(int armazemOrigem) {
    this->armazemOrigem = armazemOrigem;
}

void Pacote::setAmarzemDestino(int armazemDestino) {
    this->armazemDestino = armazemDestino;
}

void Pacote::setRota(ListaEncadeada* rota) {
    this->rota = rota;
}