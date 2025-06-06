#ifndef NO_PILHA
#define NO_PILHA

#include "Pacote.hpp"

class NoPilha {
    private:
    Pacote pacote;
    NoPilha* proximo;

    public:
    NoPilha();

    friend class Pilha;
};

#endif