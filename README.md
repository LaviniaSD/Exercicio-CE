# Análise de texto em multi-threads

Repositório da atividade de Computação Escalável do quinto período do curso de Ciência de Dados e Inteligência Artificial.

Projeto desenvolvido por [Isabela Yabe](https://github.com/IsabelaYabe), [LavíniaDias](https://github.com/LaviniaSD), [George Dutra](https://github.com/georgedutra), [Luan Rodrigues](https://github.com/Luan-vht3).

# Resumo

Nessa atividade exploramos um pouco a biblioteca padrão de multi-threads, do C++. Fizemos uma busca e contagem de palavras em textos de grande magnitude, comparando a eficiência do código conforme aumentamos o número de threads para o processo de paralelização.

# Estrutura e uso

A atividade se baseia principalmente na análise do arquivo `shakespeare.txt` através do código `search.cpp`. Utilizamos o script `modify_data.py` para aumentar o tamanho do arquivo e torná-lo significativo para análise de tempo de processamento. Utilizamos o arquivo `view_threads.py` para criar visualizações dos dados obtidos, e reunimos nossas conclusões no arquivo `relatorio.ipynb`.

Para compilar o arquivo principal, rode em seu terminal:

```
g++ search.cpp
```

e execute o arquivo `a.exe` gerado.