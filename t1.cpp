#include "t1.h"

vector<int> grafo[100];
map<int, vector<int>> vertices;
int V_source, V_destiny, interactions;
vector<vector<int>> cliquesmax;

void LimpaGrafo()
{ //funcao que limpa o grafo
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            grafo[i].push_back(0);
        }
    }
}

int Read(string file)
{

    LimpaGrafo(); //Seta o grafo pra 0
    fstream FileReader;
    FileReader.open(file.c_str());
    if (FileReader.is_open())
    {
        FileReader >> V_source >> V_destiny >> interactions;
        for (int i = 0; i < interactions; i++)
        {
            int s, d;
            FileReader >> s >> d;
            //Preenche matriz de adjacencias do grafo
            grafo[s][d - 1] = 1;
            grafo[d][s - 1] = 1;
            //Preenche adjacencias de cada vertice
            auto it = find(vertices[s].begin(), vertices[s].end(), d);
            if (s == d)
            { //se for o mesmo vertice so insere-se 1
                vertices[s].push_back(d);
            }
            else if (it == vertices[s].end())
            { //caso nao ache o vertice, ha uma insercao visto que ele nao existe
                vertices[s].push_back(d);
                vertices[d].push_back(s);
            }
        }
    }

    else
    {
        cout << "Error reading File: " << file << endl; //Printa um erro caso nao consiga dar load na file
    }

    FileReader.close();
    return V_source;
}

void PrintMatrizAdjacencias()
{ //Imprime a matriz de adjacencias
    for (int i = 1; i < vertices.size() + 1; i++)
    {
        cout << i << " - ";
        for (int j = 0; j < vertices.size(); j++)
        {
            cout << grafo[i][j] << " ";
        }
        cout << endl;
    }
}

void PrintAdjacencias()
{ //Imprime a lista de adjacencias
    cout << "Lista de Adjacencias: " << endl;
    for (int i = 1; i <= vertices.size(); i++)
    {
        cout << "Vertice: " << i << endl;
        cout << "  ";
        for (int j = 0; j < vertices[i].size(); j++)
        {
            cout << vertices[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void PrintGraus()
{ //Imprime o grau de cada vetor
    cout << "Vertices e seus Graus: " << endl;
    for (int i = 1; i <= vertices.size(); i++)
    {
        cout << "Vertice: " << i;
        cout << "  Grau: ";
        int grau = 0;
        for (int j = 0; j < vertices[i].size(); j++)
        {
            grau++;
        }
        cout << grau << endl;
    }
    cout << endl;
}

double CoeficienteAglomeracao(int num)
{ //Funcao que calcula o coeficiente de aglomeracao
    double coeficente;
    int quantidadedevizinho = 0;
    double triangulo = 0;
    vector<int> v = vertices[num];
    //iguala flag com o numero de adjacencia (vizinhos de num)
    quantidadedevizinho = v.size();
    //dois loops para achar 2 numeros adjacentes no mesmo vertice e ver se eles possuem uma ligacao entre si
    for (int i = 0; i < quantidadedevizinho; i++)
    {
        int v1 = v[i];
        for (int j = 0; j < quantidadedevizinho; j++)
        {
            //Se i for igual a j, quer dizer q sao o mesmo vertice entao j eh iterado.
            int v2 = v[j];

            //for para percorrer o vertice adjacente e ver se ele possui um adjacente em comum c num
            for (int x = 0; x < vertices[v1].size(); x++)
            {
                //verifica se o triangulo foi formado
                if (v2 == vertices[v1][x])
                {
                    //note que o mesmo triangulo sempre eh contado 2 vezes e isso sera compensado no final
                    triangulo += 0.5;
                }
            }
        }
    }
    //equacao do coeficente eh 2 vezes o numero de triangulos dividido por o numero de adjacentes vezes o numero de adjacentes menos 1, se o numero de vizinhos for maior q 1
    if (quantidadedevizinho > 1)
    {
        coeficente = (2 * triangulo) / (quantidadedevizinho * (quantidadedevizinho - 1));
    }
    else
    {
        coeficente = 0.0;
    }
    //se ele so tiver um vizinho nao pode fazer divisao por 0
    return coeficente;
}

double mediaCoeficienteAglomeracao()
{ //Funcao que calcula a media de aglomeracao
    double total = 0.0;
    double media;
    for (int i = 1; i < V_source + 1; i++)
    {
        total += CoeficienteAglomeracao(i);
    }

    cout << "Total dos coeficente ";
    cout << total << '\n';

    media = total / V_source;

    return media;
}

void B_Kerbosch_cliques(vector<int> r, vector<int> p, vector<int> x)
{ //aplicacao do algoritmo de Bron-Kerbosch
    if (p.empty() && x.empty())
    { //se p e x estiverem vazios insere R na lista de cliques
        cliquesmax.push_back(r);
    }
    if ((p.empty()) && (!x.empty()))
    { //se p estiver vazio mas x não, realiza backtracking
        return;
    }

    map<int, bool> pmem, xmem;
    for (int i = 0; i <= vertices.size(); i++)
    {                    //inicia uma copia da lista de p e x no formato de map
        pmem[i] = false; //pois não se pode modificar a que estamos percorrendo
        pmem[i] = false;
    }
    for (int i = 0; i < p.size(); i++)
    {
        pmem[p[i]] = true;
    }
    for (int i = 0; i < x.size(); i++)
    {
        xmem[x[i]] = true;
    }

    for (int i = 0; i < p.size(); i++)
    {
        r.push_back(p[i]); //insere o novo vertice em R

        vector<int> pprox, xprox;

        for (int j = 0; j < vertices[p[i]].size(); j++)
        {
            if (pmem[vertices[p[i]][j]])
            { //insere a interceção dos vizinhos do vertice com p em p
                pprox.push_back(vertices[p[i]][j]);
            }
            if (xmem[vertices[p[i]][j]])
            { //insere a interceção dos vizinhos do vertice com x em x
                xprox.push_back(vertices[p[i]][j]);
            }
        }

        B_Kerbosch_cliques(r, pprox, xprox); //faz uma chamada recursiva com os novos dados

        r.pop_back(); //remove o vertice que ja foi checado

        pmem[p[i]] = false; // remove o vertice de P e o insere em X

        xmem[p[i]] = true;
    }
}

void cliquemaximal()
{ //funcao para impressao dos cliques maximais encontrados
    vector<int> verticesR;
    vector<int> verticesP;
    vector<int> verticesX;

    for (int i = 1; i <= vertices.size(); i++)
    { //adiciona todos os vertices em p
        verticesP.push_back(i);
    }
    B_Kerbosch_cliques(verticesR, verticesP, verticesX); //chama a função do algoritmo bron-kerbosch

    cout << "Lista dos cliques maximais: " << endl;
    for (int i = 0; i < cliquesmax.size(); i++)
    { //imprime a lista de cliques maximais
        cout << i + 1 << " - ";
        for (int j = 0; j < cliquesmax[i].size(); j++)
        {
            cout << cliquesmax[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}