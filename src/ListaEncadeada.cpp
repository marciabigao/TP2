#include "../include/ListaEncadeada.hpp"

ListaEncadeada::ListaEncadeada() {
    primeiro = new NoLista();
    ultimo = primeiro;
    tamanho = 0;
}

void ListaEncadeada::limpar() {
    NoLista* p;
    
    p = primeiro->proximo;

    while(p != nullptr) {
        primeiro->proximo = p->proximo;
        delete p;
        p = primeiro->proximo;
    }

    ultimo = primeiro;
    tamanho = 0;
}

ListaEncadeada::~ListaEncadeada() {
    this->limpar();
    delete primeiro;
}

NoLista* ListaEncadeada::getPrimeiro() {
    return primeiro;
}

void ListaEncadeada::inserir(int id) {
    NoLista* novo;

    novo = new NoLista();
    novo->id = id;
    ultimo->proximo = novo;
    ultimo = novo;
    tamanho++;
}