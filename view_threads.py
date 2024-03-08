import pandas as pd
import matplotlib.pyplot as plt


def view_threads(csv_file):
    df = pd.read_csv(csv_file)

    plt.scatter(df["A"], df["B"])

    plt.xlabel("Numero de Threads")
    plt.ylabel("Tempo de Execusão")
    plt.title("Análise de Paralelismo com Threads")
    plt.show()


excel_file = "excel_teste.xlsx"
df = pd.read_excel(excel_file)

csv_file = "csv_teste.csv"
df.to_csv(csv_file, index=False)   

