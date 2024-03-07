import pandas as pd
import matplotlib.pyplot as plt


def view_threads(excel_file):
    df = pd.read_excel(excel_file)

    plt.scatter(df["A"], df["B"])

    plt.xlabel("Numero de Threads")
    plt.ylabel("Tempo de Execusão")
    plt.title("Análise de Paralelismo com Threads")
    plt.show()


    

