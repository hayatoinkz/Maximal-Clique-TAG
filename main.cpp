#include "t1.h"

int main(void)
{
    int V_source = Read("soc-dolphins.mtx");
    PrintGraus();
    cliquemaximal();
    cout << "Vertices e seus Coeficientes de Aglomeracao: " << endl;
    for (int i = 1; i < V_source + 1; i++)
    {
        printf("Vertice -> %d Coeficiente de Aglomeracao -> %lf\n", i, CoeficienteAglomeracao(i));
    }
    cout << endl;
    printf("Media dos Coeficientes: %lf\n", mediaCoeficienteAglomeracao());
    return 0;
}