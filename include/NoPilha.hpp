#ifndef NO_PILHA
#define NO_PILHA

#include "Pacote.hpp"

class NoPilha {
    public:
    Pacote pacote;
    NoPilha* proximo;

    public:
    NoPilha();

    friend class Pilha;
};

#endif