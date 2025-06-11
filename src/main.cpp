#include "../include/Grafo.hpp"
#include "../include/Escalonador.hpp"
#include "../include/Pacote.hpp"
#include "../include/ListaEncadeada.hpp"
#include "../include/Fila.hpp"
#include <fstream>
#include <iostream>

#include "../include/NoLista.hpp"
#include "../include/NoPilha.hpp"

const int M_MAXTAM = 200;

int main(int argc, char** argv) {
    //lendo e configurando armazens
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
    Pacote* pacotesSistema = new Pacote[numeroPacotes];
    for(int i = 0; i < numeroPacotes; i++) {
        int tempoChegada, id, armazemOrigem, armazemDestino;
        std::string infos;
        arquivo >> tempoChegada >> infos >> id >> infos >> armazemOrigem >> infos >> armazemDestino;

        pacotesSistema[i].setMomentoPostagem(tempoChegada);
        pacotesSistema[i].setID(id);
        pacotesSistema[i].setArmazemOrigem(armazemOrigem);
        pacotesSistema[i].setAmarzemDestino(armazemDestino);

        //determinando rota do pacote com pesquisa em largura pelo grafo
        Fila filaPesquisaLargura;
        bool visitados[quantidadeArmazens];
        int pai[quantidadeArmazens];
        for (int i = 0; i < quantidadeArmazens; i++) {
            visitados[i] = false;
            pai[i] = -1;
        }

        visitados[armazemOrigem] = true;
        filaPesquisaLargura.enfileira(armazemOrigem);

        while(!filaPesquisaLargura.vazia()) {
            int armazemAtual = filaPesquisaLargura.desenfileira();
            if(armazemAtual == armazemDestino) {break;}

            int adjacentes[grafo.armazens[armazemAtual].numeroVizinhos];
            int contador = 0;
            NoLista* p = grafo.armazens[armazemAtual].vizinhos->primeiro->proximo;
            while(p != nullptr) {
                adjacentes[contador] = p->id;
                p = p->proximo;
                contador++;
            }

            for(int j = 0; j < grafo.armazens[armazemAtual].numeroVizinhos; j++) {
                if(!visitados[adjacentes[j]]) {
                    visitados[adjacentes[j]] = true;
                    pai[adjacentes[j]] = armazemAtual;
                    filaPesquisaLargura.enfileira(adjacentes[j]);
                }
            }
        }

        int caminho[quantidadeArmazens];
        int tam = 0;

        for (int v = armazemDestino; v != -1; v = pai[v]) {
            caminho[tam++] = v;
        }

        ListaEncadeada* aux;
        aux = new ListaEncadeada();
        for (int i = tam - 1; i >= 0; i--) {
            aux->inserir(caminho[i]);
        }

        pacotesSistema[i].setRota(aux);
    }

    /*
    for(int i = 0; i < numeroPacotes; i++) {
        std::cout << "ID pacote: " << pacotesSistema[i].getID() << " Postagem: " << pacotesSistema[i].getMomentoPostagem() 
        << " Origem: " << pacotesSistema[i].getArmazemOrigem() << " Destino: " << pacotesSistema[i].getArmazemDestino()
        << " Estado: " << pacotesSistema[i].getEstado() << " Temp Arm: " << pacotesSistema[i].getTempoArmazenado()
        << " Tempo Transp: " << pacotesSistema[i].getTempoSendoTransportado() << " Rota: ";

        NoLista* p = pacotesSistema[i].rota->primeiro->proximo;
        while(p != nullptr) {
            std::cout << p->id << " ";
            p = p->proximo;
        }
        std::cout << std::endl;
    }
    */

    //adicionando pacotes nas pilhas iniciais
    for(int i = 0; i < numeroPacotes; i++) {
        grafo.inserePacoteSecao(pacotesSistema[i].getArmazemOrigem(), pacotesSistema[i].rota->getIDpos(2), pacotesSistema[i]);
    }

    /*
    for(int i = 0; i < quantidadeArmazens; i++) {
        std::cout << "Pilhas Armazem " << grafo.armazens[i].id << std::endl;
        for(int j = 0; j < grafo.armazens[i].numeroVizinhos; j++) {
            std::cout << "Pilha Destino: " << grafo.armazens[i].secoes[j].id << std::endl;
            NoPilha* p = grafo.armazens[i].secoes[j].topo;
            while(p != nullptr) {
                std::cout << p->pacote.getID() << " ";
                p = p->proximo;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    */
    
    return 0;
}