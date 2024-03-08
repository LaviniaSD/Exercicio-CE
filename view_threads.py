import pandas as pd
import matplotlib.pyplot as plt


def view_threads_all(csv_file):
    df = pd.read_csv(csv_file)

    plt.scatter(df["A"], df["B"])

    plt.xlabel("Número de Threads")
<<<<<<< Updated upstream
    plt.ylabel("Tempo de Execução")
=======
    plt.ylabel("Tempo de Execusão")
>>>>>>> Stashed changes
    plt.title("Análise de Paralelismo com Threads")
    plt.show()

def view_threads_searches(csv_file):
    df = pd.read_csv(csv_file)

    plt.scatter(df["A"], df["B"])

    plt.xlabel("Número de Threads")
    plt.ylabel("Tempo de Execusão da Pesquisa")
    plt.title("Análise de Paralelismo com Threads")
    plt.show()

def view_threads(csv_file):
    df = pd.read_csv(csv_file)

    fig, axs = plt.subplots(1,2, figsize=(10,4))

    axs[0].plt.scatter(df["A"], df["B"])

    axs[0].plt.xlabel("Número de Threads")
    axs[0].plt.ylabel("Tempo de Execusão")
    axs[0].plt.title("Análise de Paralelismo com Threads")
    
    axs[1].plt.scatter(df["A"], df["B"])

    axs[1].plt.xlabel("Número de Threads")
    axs[1].plt.ylabel("Tempo de Execusão da Pesquisa")
    axs[1].plt.title("Análise de Paralelismo com Threads")
    axs[1].plt.show()

    plt.tight_layout()
    plt.show()