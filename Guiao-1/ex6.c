#include <stdio.h>

#define TAM 5

void vizinhos(int *tab, int dim, int *igual)
{

    int media = 0;

    for (int i = 0; i < dim; i++)
    {
        if (i == 0)
        {
            if (tab[i] == tab[i+1])
            {
                (*igual)++;
            }

        } else if (i == dim-1)
        {
            if (tab[i] == tab[i-1])
            {
                (*igual)++;
            }

        } else
        {
            media = tab[i-1] + tab[i+1];
            media /= 2;

            if (tab[i] == media)
            {
                (*igual)++;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int array[TAM] = {1,1,5,7,7};
    int iguais = 0;

    vizinhos(array, TAM, &iguais);

    printf("Existem %d elementos iguais a media dos seus vizinhos\n", iguais);

    return 0;
}
