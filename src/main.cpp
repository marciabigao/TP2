#include "../include/Grafo.hpp"
#include "../include/Escalonador.hpp"
#include "../include/Pacote.hpp"
#include <fstream>
#include <iostream>

#include "../include/NoLista.hpp"

const int M_MAXTAM = 200;

int main(int argc, char** argv) {
    int capacidadeTransporte, latenciaTransporte, intervaloEntreTransportes, custoRemocao, quantidadeArmazens;

    std::ifstream arquivo(argv[1]);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << argv[1] << std::endl;
        return 1;
    }
    else {
        arquivo >> capacidadeTransporte >> latenciaTransporte >> intervaloEntreTransportes >> custoRemocao;
        arquivo >> quantidadeArmazens;
    }

    Escalonador escalonador(M_MAXTAM, capacidadeTransporte, latenciaTransporte, intervaloEntreTransportes);
    Grafo grafo(quantidadeArmazens, custoRemocao);

    bool adjacencia;
    int numeroVizinhos = 0;
    for(int i = 0; i < quantidadeArmazens; i++) {
        for(int j = 0; j < quantidadeArmazens; j++) {
            arquivo >> adjacencia;
            if(adjacencia) {
                grafo.insereVizinho(i, j);
                numeroVizinhos++;
            }
        }

        grafo.setNumeroVizinhos(i, numeroVizinhos);
        numeroVizinhos = 0;

        grafo.criaSecoes(i);
    }
    
    /*
    for(int i = 0; i < quantidadeArmazens; i++) {
        std::cout << "ID armazem: " << grafo.armazens[i].id << " Numero vz: " << grafo.armazens[i].numeroVizinhos << std::endl;
        std::cout << "Vizinhos: ";
        NoLista* p = grafo.armazens[i].vizinhos->primeiro->proximo;
        while(p != nullptr) {
            std::cout << p->id << " ";
            p = p->proximo;
        }
        std::cout << std::endl;
        std::cout << "Pilhas: ";
        for(int j = 0; j < grafo.armazens[i].numeroVizinhos; j++) {
            std::cout << grafo.armazens[i].secoes[j].id << " ";
        }
        std::cout << std::endl << std::endl;
    }
    */

    //leitura dos pacotes
    int numeroPacotes;
    arquivo >> numeroPacotes;
    Pacote aux;
    for(int i = 0; i < numeroPacotes; i++) {
        
    }

    return 0;
}