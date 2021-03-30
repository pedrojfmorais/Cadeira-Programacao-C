#include <stdio.h>

#define TAM 5

void removeMenoresMedia(int *array, int tam)
{

    float media = 0;

    for (int i = 0; i < tam; i++)
    {
        media += array[i];
    }

    media /= tam;

    printf("\n\n Media: %.2f \n\n", media);

    for (int i = 0; i < tam; i++)
    {
        if (array[i] < media)
        {
            array[i] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    
    int array[TAM] = {1,4,6,8,2};

    printf("Antes funcao: ");
    for (int i = 0; i < TAM; i++)
    {
        printf("%d ", array[i]);
    }

    removeMenoresMedia(array, TAM);

    printf("Apos funcao: ");
    for (int i = 0; i < TAM; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}
