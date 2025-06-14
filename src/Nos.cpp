#include "../include/Nos.hpp"

//construtor do no da fila
NoFila::NoFila() {
    id = -1;
    proximo = nullptr;
}

//construtor do no da lista
NoLista::NoLista() {
    id = -1;
    proximo = nullptr;
}

//construtor do no da pilha
NoPilha::NoPilha() {
    proximo = nullptr;
    pacote = nullptr;
}