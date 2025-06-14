#ifndef NOS_HPP
#define NOS_HPP

class Pacote;

//TAD representativo de um no da fila
class NoFila {
    public:
    int id; //identificador do elemento (identificador do armazem na busca por largura)
    NoFila* proximo; //ponteiro para o proximo elemento da fila

    public:
    NoFila();

    friend class Fila;
};

//TAD representativo de um no da lista encadeada
class NoLista {
    public:
    int id; //identificador do no (identificador do armazem vizinho ou da rota)
    NoLista* proximo; //ponteiro para o proximo elemento da lista

    public:
    NoLista();

    friend class ListaEncadeada;
    friend class Grafo;
};

//TAD representativo de um no da pilha
class NoPilha {
    public:
    Pacote* pacote; //ponteiro para o pacote armazenado na pilha
    NoPilha* proximo; //ponteiro para o proximo elemento da pilha

    public:
    NoPilha();

    friend class Pilha;
};

#endif