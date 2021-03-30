#include <stdio.h>

#define TAM 10

void caractArray(int *t, int tam, int *np, int *ni, int *maior, int *pos)
{

    *maior = t[0];
    *pos = 0;

    for (int i = 0; i < tam; i++)
    {
        if (t[i] % 2 == 0)
        {
            (*np)++;
        } else
        {
            (*ni)++;
        }
        
        if (*maior < t[i])
        {
            *maior = t[i];
            *pos = i;
        }
    }
    
    (*pos)++;
}

int main(int argc, char const *argv[])
{
    
    int array[TAM] = {12,23,43,123,56,2,23,44,24,23};
    int pares;
    int impares;
    int maior;
    int posMaior;

    caractArray(array, TAM, &pares, &impares, &maior, &posMaior);

    printf("Pares: %d \n", pares);
    printf("Impares: %d \n", impares);
    printf("Maior: %d \t Posicao: %d \n", maior, posMaior);

    return 0;
}
