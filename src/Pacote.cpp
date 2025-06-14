#include "../include/Pacote.hpp"

//construtor
Pacote::Pacote() {
    this->id = -1;
    this->momentoPostagem = -1;
    this->armazemOrigem = -1;
    this->armazemDestino = -1;
    this->estado = 1;
    this->tempoArmazenado = 0;
    this->tempoSendoTransportado = 0;
    this->rota = new ListaEncadeada();
    this->ultimoTempoChegada = 0;
}

//retorna o momento de postagem de um pacote
int Pacote::getMomentoPostagem() {
    return this->momentoPostagem;
}

//retorna o armazem de postagem de um pacote
int Pacote::getArmazemOrigem() {
    return this->armazemOrigem;
}

//retorna o destino final de um pacote
int Pacote::getArmazemDestino() {
    return this->armazemDestino;
}

//retorna o identificador de um pacote
int Pacote::getID() {
    return this->id;
}

//retorna o estado de um pacote
int Pacote::getEstado() {
    return this->estado;
}

//retorna o tempo que um pacote ficou armazenado
int Pacote::getTempoArmazenado() {
    return this->tempoArmazenado;
}

//retorna o tempo que um pacote ficou sendo transportado
int Pacote::getTempoSendoTransportado() {
    return this->tempoSendoTransportado;
}

//retorna ultimo tempo em que pacote chegou a um armazem
int Pacote::getUltimoTempoChegada() {
    return this->ultimoTempoChegada;
}

//atribui um id ao pacote
void Pacote::setID(int id) {
    this->id = id;
}

//atribuo o momento da postagem a um pacote
void Pacote::setMomentoPostagem(int momentoPostagem) {
    this->momentoPostagem = momentoPostagem;
}

//atribuo um armazem de postagem a um pacote
void Pacote::setArmazemOrigem(int armazemOrigem) {
    this->armazemOrigem = armazemOrigem;
}

//atribuo um armazem de destino a um pacote
void Pacote::setAmarzemDestino(int armazemDestino) {
    this->armazemDestino = armazemDestino;
}

//atribuo uma rota a um pacote
void Pacote::setRota(ListaEncadeada* rota) {
    this->rota = rota;
}

//atribuo um estado a um pacote
void Pacote::setEstado(int estado) {
    this->estado = estado;
}

//aumenta o tempo que o pacote ficou armazenado
void Pacote::incrementaTempoArmazenado(int tempo) {
    this->tempoArmazenado += tempo;
}

//aumenta o tempo em que pacote ficou em transporte
void Pacote::incrementaTempoTransporte(int tempo) {
    this->tempoSendoTransportado += tempo;
}

//atribui o ultimo tempo em que um pacote chegou a um armazem
void Pacote::setUltimoTempoChegada(int tempo) {
    this->ultimoTempoChegada = tempo;
}
