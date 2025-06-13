#include "../include/Evento.hpp"

#include <sstream>
#include <iomanip>

Evento::Evento() {
    this->tempo = -1;
    this->chave = "";
    this->tipoEvento = 0;
}

void Evento::setTempo(int tempo) {
    this->tempo = tempo;
}

int Evento::getTempo() {
    return this->tempo;
}

int Evento::getTipoEvento() {
    return this->tipoEvento;
}

std::string Evento::getChave() {
    return this->chave;
}

std::string formataComZeros(int numeroDigitos, int inteiro) {
    std::ostringstream oss;
    oss << std::setw(numeroDigitos) << std::setfill('0') << inteiro;
    return oss.str();
}

ChegadaPacote::ChegadaPacote(int tempo, Pacote pacote, int idArmazemChegada, int idArmazemProximoDestino) {
    this->setTempo(tempo);
    this->pacote = pacote;
    this->idArmazemChegada = idArmazemChegada;
    this->chave = formataComZeros(6, tempo) + formataComZeros(6, pacote.getID()) + "1";
    this->tipoEvento = 1;
}

Pacote ChegadaPacote::getPacote() {
    return this->pacote;
}

int ChegadaPacote::getIDArmazemChegada() {
    return this->idArmazemChegada;
}

int ChegadaPacote::getIDArmazemProximoDestino() {
    return this->idArmazemProximoDestino;
}

void ChegadaPacote::setEstadoPacote(int estado) {
    this->pacote.setEstado(estado);
}

Transporte::Transporte(int tempo, int idArmazemOrigem, int idArmazemDestino, int capacidadeTransporte) {
    this->setTempo(tempo);
    this->idArmazemOrigem = idArmazemOrigem;
    this->idArmazemDestino = idArmazemDestino;
    this->pacotes = new Pacote[capacidadeTransporte];
    this->capacidadeTransporte = capacidadeTransporte;
    this->chave = formataComZeros(6, tempo) + formataComZeros(3, idArmazemOrigem) 
    + formataComZeros(3, idArmazemDestino) + "1";
    this->tipoEvento = 2;
}

int Transporte::getArmazemOrigem() {
    return this->idArmazemOrigem;
}

int Transporte::getArmazemDestino() {
    return this->idArmazemDestino;
}

Pacote* Transporte::getPacotes() {
    return this->pacotes;
}

void Transporte::setPacotes(Pacote* pacotes) {
    this->pacotes = pacotes;
}