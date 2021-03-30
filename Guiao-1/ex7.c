#include <stdio.h>

#define TAM 5

void procura_dupla(int *tab, int tam, int *prim, int *seg)
{

    *prim = tab[0];
    *seg = tab[0];

    for (int i = 1; i < tam; i++)
    {
        
        if (tab[i] > *prim)
        {
            *seg = *prim;
            *prim = tab[i];
            
        } else if (tab[i] > *seg)
        {
            *seg = tab[i];
        }
    }
}

int main(int argc, char const *argv[])
{
    int array[TAM] = {1,44,5,22,27};
    int maior;
    int segundoMaior;

    procura_dupla(array, TAM, &maior, &segundoMaior);

    printf("Maior: %d. \n", maior);
    printf("Segundo Maior: %d. \n", segundoMaior);

    return 0;
}
