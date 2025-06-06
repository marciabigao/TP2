#include "../include/Evento.hpp"

Evento::Evento() {
    this->tempo = -1;
}

void Evento::setTempo(int tempo) {
    this->tempo = tempo;
}

int Evento::getTempo() {
    return this->tempo;
}

ChegadaPacote::ChegadaPacote(int tempo, Pacote pacote, int idArmazemDestino) {
    this->setTempo(tempo);
    this->pacote = pacote;
    this->idArmazemDestino = idArmazemDestino;
}

Pacote ChegadaPacote::getPacote() {
    return this->pacote;
}

int ChegadaPacote::getIDArmazemDestino() {
    return this->idArmazemDestino;
}

Transporte::Transporte(int tempo, int idArmazemOrigem, int idArmazemDestino) {
    this->setTempo(tempo);
    this->idArmazemOrigem = idArmazemOrigem;
    this->idArmazemDestino = idArmazemDestino;
}

int Transporte::getArmazemOrigem() {
    return this->idArmazemOrigem;
}

int Transporte::getArmazemDestino() {
    return this->idArmazemDestino;
}