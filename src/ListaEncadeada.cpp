#include "../include/ListaEncadeada.hpp"
#include "../include/Nos.hpp"
#include <iostream>

//construtor
ListaEncadeada::ListaEncadeada() {

    try {
        primeiro = new NoLista();
    } catch (const std::bad_alloc& e) {
        std::cerr << "Erro ao alocar memória para o vetor: " << e.what() << std::endl;
    }

    ultimo = primeiro;
    tamanho = 0;
}

//retira todos os nos, menos a cabeca
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

//destrutor
ListaEncadeada::~ListaEncadeada() {
    this->limpar();
    delete primeiro;
}

//retorna o primeiro elemento da lista
NoLista* ListaEncadeada::getPrimeiro() {
    return primeiro;
}

//retorna o identificador associado a uma determinada posicao da lista
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

//retorna o identificador do sucessor de um determinado id da lista
int ListaEncadeada::getSucessor(int id) {
    NoLista* p;
    p = primeiro;

    while(p->id != id && p != nullptr) {
        p = p->proximo;
    }

    if(p->proximo == nullptr || p == nullptr) {return -1;}

    p = p->proximo;

    return p->id;
}

//insere um novo elemento ao final da lista
void ListaEncadeada::inserir(int id) {
    NoLista* novo;

    try {
        novo = new NoLista();
    } catch (const std::bad_alloc& e) {
        std::cerr << "Erro ao alocar memória para a variavel: " << e.what() << std::endl;
    }

    novo->id = id;
    ultimo->proximo = novo;
    ultimo = novo;
    tamanho++;
}