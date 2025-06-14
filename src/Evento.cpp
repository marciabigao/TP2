#include "../include/Evento.hpp"

#include <sstream>
#include <iomanip>

//construtor
Evento::Evento() {
    this->tempo = -1;
    this->chave = "";
    this->tipoEvento = 0;
}

//atribui um tempo ao evento
void Evento::setTempo(int tempo) {
    this->tempo = tempo;
}

//recupera o tempo do evento
int Evento::getTempo() {
    return this->tempo;
}

//recupera o tipo de evento
int Evento::getTipoEvento() {
    return this->tipoEvento;
}

//recupera a chave do evento
std::string Evento::getChave() {
    return this->chave;
}

//funcao acessorio para a geracao da chave do evento
std::string formataComZeros(int numeroDigitos, int inteiro) {
    std::ostringstream oss;
    oss << std::setw(numeroDigitos) << std::setfill('0') << inteiro;
    return oss.str();
}

//construtor default
ChegadaPacote::ChegadaPacote() {
    this->setTempo(-1);
    this->idArmazemChegada = -1;
    this->chave = "";
    this->tipoEvento = 1;
}

//construtor com parametros
ChegadaPacote::ChegadaPacote(int tempo, Pacote* pacote, int idArmazemChegada, int idArmazemProximoDestino) {
    this->setTempo(tempo);
    this->pacote = pacote;
    this->idArmazemChegada = idArmazemChegada;
    this->idArmazemProximoDestino = idArmazemProximoDestino;
    this->chave = formataComZeros(6, tempo) + formataComZeros(6, pacote->getID()) + "1";
    this->tipoEvento = 1;
}

//recupera o pacote do evento de chegada
Pacote* ChegadaPacote::getPacote() {
    return this->pacote;
}

//recupera o identificador do armazem de chegada
int ChegadaPacote::getIDArmazemChegada() {
    return this->idArmazemChegada;
}

//recupera o identificador do proximo destino do pacote
int ChegadaPacote::getIDArmazemProximoDestino() {
    return this->idArmazemProximoDestino;
}

//atribui um estado ao pacote
void ChegadaPacote::setEstadoPacote(int estado) {
    this->pacote->setEstado(estado);
}

//construtor da classe
Transporte::Transporte(int tempo, int idArmazemOrigem, int idArmazemDestino, int capacidadeTransporte) {
    this->setTempo(tempo);
    this->idArmazemOrigem = idArmazemOrigem;
    this->idArmazemDestino = idArmazemDestino;
    this->capacidadeTransporte = capacidadeTransporte;
    this->chave = formataComZeros(6, tempo) + formataComZeros(3, idArmazemOrigem) 
    + formataComZeros(3, idArmazemDestino) + "1";
    this->tipoEvento = 2;
}

//retorna o armazem de origem do transporte
int Transporte::getArmazemOrigem() {
    return this->idArmazemOrigem;
}

//retorna o armazem de destino do pacote
int Transporte::getArmazemDestino() {
    return this->idArmazemDestino;
}