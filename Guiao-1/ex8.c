#include <stdio.h>

#define TAM 5

int maior_subida(int *tab, int dim)
{

    int maiorSubida = tab[1]-tab[0];
    int posMaiorSubida = 1;

    for (int i = 2; i < dim; i++)
    {
        if (tab[i]-tab[i-1] > maiorSubida)
        {
            maiorSubida = tab[i]-tab[i-1];
            posMaiorSubida = i;
        }
    }
    return posMaiorSubida+1;
}

int main(int argc, char const *argv[])
{
    int array[TAM] = {1,4,5,66,77};
    int posMaiorSubida;

    posMaiorSubida = maior_subida(array, TAM);

    printf("A maior subida encontra-se na posicao: %d. \n", posMaiorSubida);

    return 0;
}
