#include "../include/Pacote.hpp"

Pacote::Pacote() {
    this->momentoPostagem = -1;
    this->nomeRemetente = "";
    this->nomeDestinatario = "";
    this->armazemOrigem = -1;
    this->armazemDestino = -1;
    this->rota = new ListaEncadeada();
}

Pacote::Pacote(int dataHora, std::string remetente, std::string destinatario, int origem, int destino) {
    this->momentoPostagem = dataHora;
    this->nomeRemetente = remetente;
    this->nomeDestinatario = destinatario;
    this->armazemOrigem = origem;
    this->armazemDestino = destino;
}

int Pacote::getMomentoPostagem() {
    return this->momentoPostagem;
}

std::string Pacote::getNomeRemetente() {
    return this->nomeRemetente;
}

std::string Pacote::getNomeDestinatario() {
    return this->nomeDestinatario;
}

int Pacote::getArmazemOrigem() {
    return this->armazemOrigem;
}

int Pacote::getArmazemDestino() {
    return this->armazemDestino;
}