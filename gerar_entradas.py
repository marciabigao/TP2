import random
import os

def gerar_linha_pacote(tempo_max, id_base, n_armazens):
    tempo = random.randint(0, tempo_max)
    id_pacote = random.randint(1000, 9999)
    org = random.randint(0, n_armazens - 1)
    dst = random.randint(0, n_armazens - 1)
    while dst == org:
        dst = random.randint(0, n_armazens - 1)
    return f"{tempo} pac {id_pacote} org {org} dst {dst}"

def gerar_matriz_adjacencia(n_armazens, conexao_prob=0.3):
    matriz = []
    for i in range(n_armazens):
        linha = []
        for j in range(n_armazens):
            if i == j:
                linha.append(0)
            else:
                linha.append(1 if random.random() < conexao_prob else 0)
        matriz.append(linha)
    return matriz

def salvar_entrada(nome_arquivo, capacidade, latencia=20, intervalo=110, custo=1,
                   n_armazens=4, matriz=None, pacotes=[]):
    with open(nome_arquivo, "w") as f:
        f.write(f"{capacidade}\n{latencia}\n{intervalo}\n{custo}\n{n_armazens}\n")
        if matriz is not None:
            for linha in matriz:
                f.write(" ".join(map(str, linha)) + "\n")
        f.write(f"{len(pacotes)}\n")
        for pacote in pacotes:
            f.write(pacote + "\n")

def gerar_varios_arquivos_variando_pacotes(n_pacotes_base, n_armazens, capacidade):
    os.makedirs("entradas", exist_ok=True)
    for i in range(50):
        n_pacotes = n_pacotes_base + i * 5  # Variação de 5 em 5
        pacotes = [gerar_linha_pacote(tempo_max=200, id_base=i, n_armazens=n_armazens)
                   for _ in range(n_pacotes)]
        matriz = gerar_matriz_adjacencia(n_armazens)
        salvar_entrada(f"entradas/{n_pacotes}_pacotes.txt", capacidade,
                       n_armazens=n_armazens, matriz=matriz, pacotes=pacotes)

def gerar_varios_arquivos_variando_armazens(n_pacotes, n_armazens_base, capacidade):
    os.makedirs("entradas", exist_ok=True)
    for i in range(50):
        n_armazens = n_armazens_base + i * 5  # Variação de 5 em 5
        pacotes = [gerar_linha_pacote(tempo_max=200, id_base=i, n_armazens=n_armazens)
                   for _ in range(n_pacotes)]
        matriz = gerar_matriz_adjacencia(n_armazens)
        salvar_entrada(f"entradas/{n_armazens}_armazens.txt", capacidade,
                       n_armazens=n_armazens, matriz=matriz, pacotes=pacotes)

def gerar_varios_arquivos_variando_capacidade(n_pacotes, n_armazens, capacidade_base):
    os.makedirs("entradas", exist_ok=True)
    for i in range(50):
        capacidade = capacidade_base + i * 2  # Variação de 2 em 2
        pacotes = [gerar_linha_pacote(tempo_max=200, id_base=i, n_armazens=n_armazens)
                   for _ in range(n_pacotes)]
        matriz = gerar_matriz_adjacencia(n_armazens)
        salvar_entrada(f"entradas/{capacidade}_capacidade.txt", capacidade,
                       n_armazens=n_armazens, matriz=matriz, pacotes=pacotes)

if __name__ == "__main__":
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument("--modo", choices=["pacotes", "armazens", "capacidade"], required=True)
    parser.add_argument("--n_pacotes", type=int, required=True)
    parser.add_argument("--n_armazens", type=int, required=True)
    parser.add_argument("--capacidade", type=int, required=True)

    args = parser.parse_args()

    if args.modo == "pacotes":
        print("Gerando arquivos variando número de pacotes...")
        gerar_varios_arquivos_variando_pacotes(args.n_pacotes, args.n_armazens, args.capacidade)
    elif args.modo == "armazens":
        print("Gerando arquivos variando número de armazéns...")
        gerar_varios_arquivos_variando_armazens(args.n_pacotes, args.n_armazens, args.capacidade)
    elif args.modo == "capacidade":
        print("Gerando arquivos variando capacidade do transporte...")
        gerar_varios_arquivos_variando_capacidade(args.n_pacotes, args.n_armazens, args.capacidade)



'''
COMO EXECUTAR:
python gerar_entradas.py --modo pacotes --n_pacotes 10 --n_armazens 10 --capacidade 5
python gerar_entradas.py --modo armazens --n_pacotes 10 --n_armazens 10 --capacidade 2
python gerar_entradas.py --modo capacidade --n_pacotes 50 --n_armazens 10 --capacidade 1
'''