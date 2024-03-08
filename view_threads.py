import pandas as pd
import matplotlib.pyplot as plt


def view_threads_all(csv_file):
    df = pd.read_csv(csv_file)

    plt.scatter(df["A"], df["B"])


    plt.ylabel("Tempo de Execução")

    plt.ylabel("Tempo de Execução")

    plt.title("Análise de Paralelismo com Threads")
    plt.show()

def view_threads_searches(csv_file):
    df = pd.read_csv(csv_file)

    plt.scatter(df["A"], df["B"])

    plt.xlabel("Número de Threads")
    plt.ylabel("Tempo de Execução da Pesquisa")
    plt.title("Análise de Paralelismo com Threads")
    plt.show()

def view_threads(csv_file_1, csv_file_2):
    df_1 = pd.read_csv(csv_file_1)
    df_2 = pd.read_csv(csv_file_2)

    fig, axs = plt.subplots(1, 2, figsize=(12, 6)) 

    axs[0].scatter(df_1["A"], df_1["B"]) 

    axs[0].set_xlabel("Número de Threads") 
    axs[0].set_ylabel("Tempo de Execução")  
    axs[0].set_title("Análise de Paralelismo com Threads")  

    axs[1].scatter(df_2["A"], df_2["B"]) 

    axs[1].set_xlabel("Número de Threads")  
    axs[1].set_ylabel("Tempo de Execução da Pesquisa")  
    axs[1].set_title("Análise de Paralelismo com Threads")  

    plt.tight_layout()
    plt.show()