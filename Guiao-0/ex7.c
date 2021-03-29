#include <stdio.h>
#include <math.h>

#define TAM 10

double desvioPadrao(int *tabela, int N)
{

    double desvioPadrao;
    double media = 0;

    for (int i = 0; i < N; i++)
    {
        media += tabela[i];
    }
    
    media /= N;

    for (int i = 0; i < N; i++)
    {
        desvioPadrao += pow(media-tabela[i], 2);
    }
    
    desvioPadrao = (1/(double)N) * desvioPadrao;
    
    return sqrt(desvioPadrao);


}

int main(int argc, char const *argv[])
{
    
    int tabela[TAM] = {18,16,45,82,512,1,233,23,54,55};
    double resultado;

    resultado = desvioPadrao(tabela, TAM);

    printf("O desvio padrao e: %lf \n", resultado);
    

    return 0;
}
