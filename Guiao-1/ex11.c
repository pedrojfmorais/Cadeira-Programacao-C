#include <stdio.h>

#define TAM1 5
#define TAM2 5

int comparaVetores(int *vetor_1, int tam1, int *vetor_2, int tam2)
{

    if (tam1 != tam2)
    {
        return 0;
    }
    
    for (int i = 0; i < tam1; i++)
    {
        if (vetor_1[i] != vetor_2[i])
        {
            return 0;
        }
    }
    
    return 1;
}

int main(int argc, char const *argv[])
{
    int array_1[TAM1] = {1,2,3,4,5};
    int array_2[TAM2] = {1,2,3,4,5};
    int resultado;

    resultado = comparaVetores(array_1, TAM1, array_2, TAM2);

    printf("Os dois arrays ");

    if (resultado == 0)
    {
        printf("nao ");
    }
    
    printf("sao iguais.");

    return 0;
}
