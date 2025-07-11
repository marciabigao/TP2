//inclusao das bibliotecas e dos arquivos necessarios
#include "../include/Grafo.hpp"
#include "../include/Escalonador.hpp"
#include "../include/Pacote.hpp"
#include "../include/ListaEncadeada.hpp"
#include "../include/Fila.hpp"
#include "../include/Pilha.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>

//determinando uma constante para o valor maximo do heap, que e alocado estaticamente
const int M_MAXTAM = 200;

//funcao acessorio para capturar informacoes da chave do evento
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

    if (argc < 2) {
        std::cerr << "Arquivo de entrada não foi passado." << std::endl;
        return 1;
    }

    std::ifstream arquivo(argv[1]);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << argv[1] << std::endl;
        return 1;
    }
    else {
        arquivo >> capacidadeTransporte >> latenciaTransporte >> intervaloEntreTransportes >> custoRemocao;
        arquivo >> quantidadeArmazens;
    }

    if (quantidadeArmazens <= 0) { //testa se o numero de armazens e valido para evitar alocacoes de memoria erradas
        std::cerr << "Erro: tamanho do vetor inválido: " << quantidadeArmazens << std::endl;
        return 1;
    }

    //criando as principais estruturas
    Escalonador escalonador(M_MAXTAM, capacidadeTransporte, latenciaTransporte, intervaloEntreTransportes);
    Grafo grafo(quantidadeArmazens, custoRemocao);

    try {
        //lendo os vizinhos de cada armazem
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

        //leitura dos pacotes e cálculo da sua rota
        int numeroPacotes;
        arquivo >> numeroPacotes;
        Pacote* pacotesSistema = new Pacote[numeroPacotes];
        int contador = 0;
        for(int i = 0; i < numeroPacotes; i++) {

            if (contador > numeroPacotes) { //testa se o total passado e compativel com o numero de pacotes do arquivo
                std::cerr << "Aviso: mais pacotes no arquivo do que o total informado (" << contador << ")." << std::endl;
                break;
            }

            int tempoChegada, id, armazemOrigem, armazemDestino;
            std::string infos;
            arquivo >> tempoChegada >> infos >> id >> infos >> armazemOrigem >> infos >> armazemDestino;

            pacotesSistema[i].setMomentoPostagem(tempoChegada);

            if(i == 0) {relogio = tempoChegada;}
            else {
                if(tempoChegada < relogio) {relogio = tempoChegada;}
            }

            pacotesSistema[i].setID(i);
            pacotesSistema[i].setArmazemOrigem(armazemOrigem);
            pacotesSistema[i].setAmarzemDestino(armazemDestino);

            //determinando rota do pacote com pesquisa em largura pelo grafo
            Fila filaPesquisaLargura; //estrutura auxiliar para a pesquisa em largura
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

            contador++;
        }

        if (contador < numeroPacotes) { //testa se o numero de pacotes lidos e igual ao passado
            std::cerr << "Erro: número de pacotes lidos (" << contador << ") é menor que o total informado (" << numeroPacotes << ")." << std::endl;
            return 1;
        }

        arquivo.close();

        //começar a simulação de eventos

        //escalonando eventos de transporte
        for(int i = 0; i < quantidadeArmazens; i++) {
            for(int j = 0; j < quantidadeArmazens; j++) {
                if(matrizAdjacencia[i][j]) {
                    Transporte* novoTransporte = new Transporte(relogio + intervaloEntreTransportes, i, j, capacidadeTransporte);
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

        int pacotesEntregues = 0;
        while(!escalonador.vazio() && pacotesEntregues < numeroPacotes) { //enquanto houverem eventos e pacotes nao entregues
            //retiro o proximo evento de maior prioridade do heap
            Evento* evento = escalonador.remover();
            if(evento == nullptr) {break;}
            relogio = evento->getTempo(); //configuro o relogio para o instante do proximo evento
            std::string chave = evento->getChave();

            if(evento->getTipoEvento() == 2) { //se o evento e transporte
                int tempoInicioTransporte = relogio;
                int armazemOrigem = std::stoi(extrairString(6, 8, chave));
                int armazemDestino = std::stoi(extrairString(9, 11, chave));
                int indicePilhaOrigem = grafo.armazens[armazemOrigem].getIndicePilha(armazemDestino);

                if(!grafo.armazens[armazemOrigem].secoes[indicePilhaOrigem].vazia()) {
                    Pilha auxiliar;

                    //removo os pacotes da secao e os adiciono em uma pilha auxiliar (priorizando o transporte dos mais antigos)
                    while(!grafo.armazens[armazemOrigem].secoes[indicePilhaOrigem].vazia()) {
                        Pacote* pacote = grafo.armazens[armazemOrigem].secoes[indicePilhaOrigem].desempilha();
                        relogio += custoRemocao;
                        std::cout <<  std::setw(7) << std::setfill('0') << relogio << " pacote ";
                        std::cout << std::setw(3) << std::setfill('0') << pacote->getID() << " removido de ";
                        std::cout << std::setw(3) << std::setfill('0') << armazemOrigem << " na secao ";
                        std::cout << std::setw(3) << std::setfill('0') << armazemDestino << std::endl;

                        auxiliar.empilha(pacote);
                    }

                    //carrego no transporte tantos pacotes quantos forem suportador por ele
                    for(int i = 0; i < capacidadeTransporte; i++) {
                        Pacote* pacote = auxiliar.desempilha();
                        pacote->setEstado(4);
                        pacote->incrementaTempoArmazenado(relogio - pacote->getUltimoTempoChegada());
                        int novoProxDestino = pacote->rota->getSucessor(armazemDestino);

                        //escalono a chegada dos pacotes no proximo armazem
                        ChegadaPacote* novaChegada = new ChegadaPacote(relogio + latenciaTransporte, pacote, 
                            armazemDestino, novoProxDestino);
                        novaChegada->getPacote()->setEstado(2);
                        escalonador.inserir(novaChegada);
                        
                        std::cout <<  std::setw(7) << std::setfill('0') << relogio << " pacote ";
                        std::cout << std::setw(3) << std::setfill('0') << pacote->getID() << " em transito de ";
                        std::cout << std::setw(3) << std::setfill('0') << armazemOrigem << " para ";
                        std::cout << std::setw(3) << std::setfill('0') << armazemDestino << std::endl;

                        if(auxiliar.vazia()) {
                            break;
                        }
                    }

                    //retorno os pacotes restantes para a secao
                    while(!auxiliar.vazia()) {
                        Pacote* pacote = auxiliar.desempilha();
                        grafo.armazens[armazemOrigem].secoes[indicePilhaOrigem].empilha(pacote);

                        std::cout <<  std::setw(7) << std::setfill('0') << relogio << " pacote ";
                        std::cout << std::setw(3) << std::setfill('0') << pacote->getID() << " rearmazenado em ";
                        std::cout << std::setw(3) << std::setfill('0') << armazemOrigem << " na secao ";
                        std::cout << std::setw(3) << std::setfill('0') << armazemDestino << std::endl;
                    }
                }

                //escalono proximo evento de transporte
                Transporte* novoTransporte = new Transporte(tempoInicioTransporte + intervaloEntreTransportes, armazemOrigem, 
                armazemDestino, capacidadeTransporte);
                escalonador.inserir(novoTransporte);
            }

            if(evento->getTipoEvento() == 1) { //se evento e chegada de pacote
                ChegadaPacote* chegada = dynamic_cast<ChegadaPacote*>(evento);

                //incremento as estatisticas de tempo
                chegada->getPacote()->incrementaTempoArmazenado(latenciaTransporte);
                chegada->getPacote()->setUltimoTempoChegada(relogio);

                //se o pacote chegou ao seu destino final
                if(chegada->getPacote()->getArmazemDestino() == chegada->getIDArmazemChegada() || chegada->getIDArmazemProximoDestino() == -1) {
                    //registro a entrega do pacote
                    std::cout <<  std::setw(7) << std::setfill('0') << relogio << " pacote ";
                    std::cout << std::setw(3) << std::setfill('0') << chegada->getPacote()->getID() << " entregue em ";
                    std::cout << std::setw(3) << std::setfill('0') << chegada->getPacote()->getArmazemDestino() << std::endl;
                    chegada->getPacote()->setEstado(5);
                    pacotesEntregues++;
                }
                else { //se nao chegou ao destino final
                    int armazemChegada = chegada->getIDArmazemChegada();
                    int armazemProximoDestino = chegada->getIDArmazemProximoDestino();
                    int indicePilha = grafo.armazens[armazemChegada].getIndicePilha(armazemProximoDestino);

                    chegada->getPacote()->setEstado(3);
                    //armazeno pacote na secao correspondente ao proximo destino
                    grafo.armazens[armazemChegada].secoes[indicePilha].empilha(chegada->getPacote());

                    std::cout <<  std::setw(7) << std::setfill('0') << relogio << " pacote ";
                    std::cout << std::setw(3) << std::setfill('0') << chegada->getPacote()->getID() << " armazenado em ";
                    std::cout << std::setw(3) << std::setfill('0') << armazemChegada << " na secao ";
                    std::cout << std::setw(3) << std::setfill('0') << armazemProximoDestino << std::endl;
                }
            }
        }
    } catch (const std::exception& e) { //captura quaisquer erros de execução e informa o que aconteceu
        std::cerr << "Erro durante o processamento: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}