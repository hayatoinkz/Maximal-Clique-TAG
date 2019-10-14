#ifndef T1_H
#define T1_H

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void LimpaGrafo(); //funcao que limpa o grafo

int Read(string file);

void PrintMatrizAdjacencias(); //Imprime a matriz de adjacencias

void PrintAdjacencias(); //Imprime a lista de adjacencias

void PrintGraus(); //Imprime o grau de cada vetor

double CoeficienteAglomeracao(int num); //Funcao que calcula o coeficiente de aglomeracao

double mediaCoeficienteAglomeracao(); //Funcao que calcula a media de aglomeracao

void B_Kerbosch_cliques(vector<int> r, vector<int> p, vector<int> x); //aplicacao do algoritmo de Bron-Kerbosch

void cliquemaximal(); //funcao para impressao dos cliques maximais encontrados

#endif