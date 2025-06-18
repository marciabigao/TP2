import pandas as pd
import matplotlib.pyplot as plt
import re

# Lê o CSV
df = pd.read_csv('resultados.csv')

# Verifica as colunas
print("Colunas disponíveis no CSV:", df.columns)
print("Primeiras linhas do CSV:")
print(df.head())

# Função segura para extrair número do nome do arquivo
def extrair_numero(arquivo):
    match = re.search(r'\d+', str(arquivo))  # usa str() para garantir segurança
    return int(match.group()) if match else None

# Função segura para extrair tipo do nome do arquivo
def extrair_tipo(arquivo):
    match = re.search(r'(pacotes|armazens|capacidade)', str(arquivo).lower())
    return match.group() if match else None

# Aplica as funções seguras
df['numero'] = df['arquivo'].apply(extrair_numero)
df['tipo'] = df['arquivo'].apply(extrair_tipo)

# Remove linhas com dados ausentes
df = df.dropna(subset=['numero', 'tipo'])

# Verifica se o dataframe tem dados úteis
print("Dados após processamento:")
print(df.head())

# Função para plotar gráfico e salvar como imagem
def plot_tipo(tipo, cor, titulo):
    df_tipo = df[df['tipo'] == tipo].sort_values(by='numero')
    
    if df_tipo.empty:
        print(f"[AVISO] Nenhum dado para tipo: {tipo}")
        return

    plt.figure(figsize=(10, 6))
    plt.plot(df_tipo['numero'], df_tipo['tempo_execucao_segundos'], marker='o', color=cor)
    plt.title(titulo)
    plt.xlabel('Quantidade')
    plt.ylabel('Custo de Tempo (segundos)')
    plt.grid(True)
    plt.tight_layout()
    
    nome_arquivo = f"{tipo}_grafico.png"
    plt.savefig(nome_arquivo)
    print(f"[OK] Gráfico salvo como: {nome_arquivo}")
    plt.close()

# Geração dos gráficos
plot_tipo('pacotes', 'red', 'Quantidade (Pacotes) vs. Custo de Tempo de Execução')
plot_tipo('armazens', 'blue', 'Quantidade (Armazéns) vs. Custo de Tempo de Execução')
plot_tipo('capacidade', 'green', 'Quantidade (Capacidade) vs. Custo de Tempo de Execução')

#comando de execucao no windows: C:\python05\python.exe plotar_resultados.py

