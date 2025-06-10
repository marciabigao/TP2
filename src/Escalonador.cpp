#include "../include/Escalonador.hpp"

Escalonador::Escalonador(int tamanhoMax, int capacidadeTransporte, int latenciaTransporte, int intervaloEntreTransportes) {
    this->tamanho = 0;
    this->dados = new Evento[tamanhoMax];
    this->capacidadeTransporte = capacidadeTransporte;
    this->latenciaTransporte = latenciaTransporte;
    this->intervaloEntreTransportes = intervaloEntreTransportes;
}

Escalonador::~Escalonador() {
    delete[] dados;
}

void Escalonador::inserir(Evento* evento) {
    if(tamanho == 0)
    {
        dados[0] = *evento;
    }
    else 
    {
        this->dados[tamanho] = *evento;
        int i = tamanho;
        int ancestral = (i - 1) / 2;

        while(dados[i].getTempo() < dados[ancestral].getTempo()) {
            Evento* temp = new Evento();
            *temp = dados[ancestral];
            dados[ancestral] = dados[i];
            dados[i] = *temp;

            i = ancestral;
            ancestral = (i - 1) / 2;
        }
    }

    tamanho++;
    delete evento;
}

Evento* Escalonador::remover() {
    Evento* retorno = new Evento();
    *retorno = dados[0];
    dados[0] = dados[tamanho - 1];
    tamanho--;
    int i = 0;
    int s = 0;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < tamanho && dir < tamanho) {
        s = (dados[dir].getTempo() > dados[esq].getTempo()) ? esq : dir;
    } else if (esq < tamanho) {
        s = esq;
    } else if (dir < tamanho) {
            s = dir;
    } else {
        s = i;
    }

    while(dados[i].getTempo() > dados[s].getTempo()) {
        Evento* temp = new Evento();
        *temp = dados[s];
        dados[s] = dados[i];
        dados[i] = *temp;

        i = s;
        int esq = 2 * i + 1;
        int dir = 2 * i + 2;

        if (esq < tamanho && dir < tamanho) {
            s = (dados[dir].getTempo() > dados[esq].getTempo()) ? esq : dir;
        } else if (esq < tamanho) {
            s = esq;
        } else if (dir < tamanho) {
            s = dir;
        } else {
            s = i;
        }
    }

    return retorno;
}

bool Escalonador::vazio() {
    return (tamanho == 0);
}