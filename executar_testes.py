import subprocess
import time
import csv
import os

# Caminho para o executável (no mesmo diretório onde o script será executado)
EXECUTAVEL = "./tp2.out"

# Pasta onde estão os arquivos de entrada (assumindo execução dentro de "entradas/")
PASTA_ENTRADA = "."  # diretório atual

# Nome do CSV de saída
ARQUIVO_SAIDA = "resultados.csv"

def medir_tempo_execucao(caminho_arquivo):
    inicio = time.perf_counter()
    try:
        resultado = subprocess.run([EXECUTAVEL, caminho_arquivo], capture_output=True, text=True)
        if resultado.returncode != 0:
            print(f"Erro ao executar {caminho_arquivo}:")
            print(resultado.stderr)
            return None
    except Exception as e:
        print(f"Exceção ao executar {caminho_arquivo}: {e}")
        return None
    fim = time.perf_counter()
    return fim - inicio

def rodar_testes():
    resultados = []

    for arquivo in os.listdir(PASTA_ENTRADA):
        if arquivo.endswith(".txt"):
            caminho_completo = os.path.join(PASTA_ENTRADA, arquivo)
            tempo = medir_tempo_execucao(caminho_completo)
            if tempo is not None:
                print(f"Executado {arquivo} em {tempo:.4f} segundos")
                resultados.append([arquivo, f"{tempo:.4f}"])
            else:
                print(f"Falha ao executar {arquivo}")
                resultados.append([arquivo, "erro"])

    with open(ARQUIVO_SAIDA, mode="w", newline="") as f:
        writer = csv.writer(f)
        writer.writerow(["arquivo", "tempo_execucao_segundos"])
        writer.writerows(resultados)

if __name__ == "__main__":
    rodar_testes()

#ADICIONAR O EXECUTÁVEL NESSE DIRETÓRIO