# Projeto 1 Teoria e Aplicação de Grafos

## Turma A - 2/2019

Em 2003, no artigo “David Lusseau et al., The bottelenose dolphin community of Doubful Sound features a large proportion of long-lasting associations, Journal of Behavioral Ecology and Sociobiology 54:4, 396--405 (2003).” uma rede social de relações duradouras é identificada em uma comunidade de 62 golfinhos e apresentada como um grafo (não direcionado) para estudos. Os dados estão em arquivo anexo (`soc-dolphins.mtx`).

O projeto consiste em escrever um programa em C/C++ que lê o arquivo (`soc-dolphins.mtx`), monta com esses dados um grafo não direcionado, sem pesos, usando listas de adjacências, e então calcula e imprime como saída (tela) o seguinte:

1. O vértice, e seu respectivo grau **(para todos os vértices)**;
2. Todos os cliques maximais **(Indicando o número de vértices e quais)**;
3. O Coeficiente de Aglomeração de cada vértice;
4. O Coeficiente médio de Aglomeração do Grafo.

### Execução:

Compilação do programa

```bash
make all
```

Execução do programa

```bash
./main
```

Limpeza dos Arquivos Gerados

```bash
make clean
```
