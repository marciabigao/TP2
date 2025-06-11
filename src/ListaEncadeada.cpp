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

int ListaEncadeada::getIDpos(int pos) {
    NoLista* p;
    p = primeiro;
    
    for(int i = 0; i < pos; i++) {
        if(p != nullptr) {
            p = p->proximo;
        }
    }

    return p->id;
}

void ListaEncadeada::inserir(int id) {
    NoLista* novo;

    novo = new NoLista();
    novo->id = id;
    ultimo->proximo = novo;
    ultimo = novo;
    tamanho++;
}