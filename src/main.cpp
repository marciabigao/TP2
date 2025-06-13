#include "../include/Grafo.hpp"
#include "../include/Escalonador.hpp"
#include "../include/Pacote.hpp"
#include "../include/ListaEncadeada.hpp"
#include "../include/Fila.hpp"
#include "../include/Pilha.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>

#include "../include/NoLista.hpp"
#include "../include/NoPilha.hpp"

const int M_MAXTAM = 200;

std::string extrairString(int inicio, int fim, const std::string& texto) {
    if (inicio < 0 || fim >= static_cast<int>(texto.size()) || inicio > fim) {
        return "";
    }
    return texto.substr(inicio, fim - inicio + 1);
}

int main(int argc, char** argv) {
    //lendo e configurando armazens
    int relogio = 0;
    int capacidadeTransporte, latenciaTransporte, intervaloEntreTransportes, custoRemocao, quantidadeArmazens;
    int numeroArestas = 0;

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

    int matrizAdjacencia[quantidadeArmazens][quantidadeArmazens];
    bool adjacencia;
    int numeroVizinhos = 0;
    for(int i = 0; i < quantidadeArmazens; i++) {
        for(int j = 0; j < quantidadeArmazens; j++) {
            arquivo >> adjacencia;
            matrizAdjacencia[i][j] = adjacencia;

            if(adjacencia) {
                grafo.insereVizinho(i, j);
                numeroVizinhos++;
                numeroArestas++;
            }
        }

        grafo.setNumeroVizinhos(i, numeroVizinhos);
        numeroVizinhos = 0;

        grafo.criaSecoes(i);
    }

    numeroArestas = numeroArestas / 2;
    
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

    //leitura dos pacotes e cálculo da sua rota
    int numeroPacotes;
    arquivo >> numeroPacotes;
    Pacote* pacotesSistema = new Pacote[numeroPacotes];
    for(int i = 0; i < numeroPacotes; i++) {
        int tempoChegada, id, armazemOrigem, armazemDestino;
        std::string infos;
        arquivo >> tempoChegada >> infos >> id >> infos >> armazemOrigem >> infos >> armazemDestino;

        pacotesSistema[i].setMomentoPostagem(tempoChegada);

        if(i == 0) {relogio = tempoChegada;}
        else {
            if(tempoChegada < relogio) {relogio = tempoChegada;}
        }

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

    //começar a simulação de eventos

    //escalonando eventos de transporte
    for(int i = 0; i < quantidadeArmazens; i++) {
        for(int j = 0; j < quantidadeArmazens; j++) {
            if(matrizAdjacencia[i][j]) {
                Transporte* novoTransporte = new Transporte(relogio + 100, i, j, capacidadeTransporte);
                escalonador.inserir(novoTransporte);
            }
        }
    }

    //escalonando chegada pacotes no primeiro armazem
    for(int i = 0; i < numeroPacotes; i++) {
        ChegadaPacote* novaChegada = new ChegadaPacote(pacotesSistema[i].getMomentoPostagem(), &pacotesSistema[i], 
        pacotesSistema[i].getArmazemOrigem(), pacotesSistema[i].rota->getIDpos(2));
        escalonador.inserir(novaChegada);
        novaChegada->setEstadoPacote(2);
    }


    while(!escalonador.vazio()) {
        Evento* evento = escalonador.remover();
        relogio = evento->getTempo();
        std::string chave = evento->getChave();

        if(evento->getTipoEvento() == 2) {
            int tempoInicioTransporte = relogio;
            int armazemOrigem = std::stoi(extrairString(6, 8, chave));
            int armazemDestino = std::stoi(extrairString(9, 11, chave));
            int indicePilhaOrigem = grafo.armazens[armazemOrigem].getIndicePilha(armazemDestino);

            if(!grafo.armazens[armazemOrigem].secoes[indicePilhaOrigem].vazia()) {
                Pilha auxiliar;

                while(!grafo.armazens[armazemOrigem].secoes[indicePilhaOrigem].vazia()) {
                    Pacote* pacote = grafo.armazens[armazemOrigem].secoes[indicePilhaOrigem].desempilha();
                    relogio += custoRemocao;
                    std::cout <<  std::setw(6) << std::setfill('0') << relogio << " pacote ";
                    std::cout << std::setw(3) << std::setfill('0') << pacote->getID() << " removido de ";
                    std::cout << std::setw(3) << std::setfill('0') << armazemOrigem << " na secao ";
                    std::cout << std::setw(3) << std::setfill('0') << armazemDestino << std::endl;

                    auxiliar.empilha(pacote);
                }

                for(int i = 0; i < capacidadeTransporte; i++) {
                    Pacote* pacote = auxiliar.desempilha();
                    pacote->setEstado(4);
                    int novoProxDestino = pacote->rota->getSucessor(armazemDestino);

                    ChegadaPacote* novaChegada = new ChegadaPacote(relogio + latenciaTransporte, pacote, 
                        armazemDestino, novoProxDestino);
                    novaChegada->getPacote()->setEstado(2);
                    escalonador.inserir(novaChegada);
                    
                    std::cout <<  std::setw(6) << std::setfill('0') << relogio << " pacote ";
                    std::cout << std::setw(3) << std::setfill('0') << pacote->getID() << " em transito de ";
                    std::cout << std::setw(3) << std::setfill('0') << armazemOrigem << " para ";
                    std::cout << std::setw(3) << std::setfill('0') << armazemDestino << std::endl;

                    if(auxiliar.vazia()) {
                        break;
                    }
                }

                while(!auxiliar.vazia()) {
                    Pacote* pacote = auxiliar.desempilha();
                    grafo.armazens[armazemOrigem].secoes[indicePilhaOrigem].empilha(pacote);

                    std::cout <<  std::setw(6) << std::setfill('0') << relogio << " pacote ";
                    std::cout << std::setw(3) << std::setfill('0') << pacote->getID() << " rearmazenado em ";
                    std::cout << std::setw(3) << std::setfill('0') << armazemOrigem << " na secao ";
                    std::cout << std::setw(3) << std::setfill('0') << armazemDestino << std::endl;
                }
            }

            Transporte* novoTransporte = new Transporte(tempoInicioTransporte + 100, armazemOrigem, 
                armazemDestino, capacidadeTransporte);
            escalonador.inserir(novoTransporte);
        }

        if(evento->getTipoEvento() == 1) {
            ChegadaPacote* chegada = dynamic_cast<ChegadaPacote*>(evento);

            if(chegada->getPacote()->getArmazemDestino() == chegada->getIDArmazemChegada() || chegada->getIDArmazemProximoDestino() == -1) {
                std::cout <<  std::setw(6) << std::setfill('0') << relogio << " pacote ";
                std::cout << std::setw(3) << std::setfill('0') << chegada->getPacote()->getID() << " entregue em ";
                std::cout << std::setw(3) << std::setfill('0') << chegada->getPacote()->getArmazemDestino() << std::endl;
                chegada->getPacote()->setEstado(5);
            }
            else {
                int armazemChegada = chegada->getIDArmazemChegada();
                int armazemProximoDestino = chegada->getIDArmazemProximoDestino();
                int indicePilha = grafo.armazens[armazemChegada].getIndicePilha(armazemProximoDestino);
                chegada->getPacote()->setEstado(3);
                grafo.armazens[armazemChegada].secoes[indicePilha].empilha(chegada->getPacote());

                std::cout <<  std::setw(6) << std::setfill('0') << relogio << " pacote ";
                std::cout << std::setw(3) << std::setfill('0') << chegada->getPacote()->getID() << " armazenado em ";
                std::cout << std::setw(3) << std::setfill('0') << armazemChegada << " na secao ";
                std::cout << std::setw(3) << std::setfill('0') << armazemProximoDestino << std::endl;
            }
        }

        if(relogio > 400) {
            break;
        }
    }
    
    return 0;
}