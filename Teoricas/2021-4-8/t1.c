#include <stdio.h>
#include <stdlib.h>

void inicializa(int array[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        array[i]=i*2;
    }
}

void mostra(int array[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

int main(int argc, char const *argv[])
{
    int tam, newTam;
    int *array, *aux;
    
    printf("Insira o tamanho do array: ");
    scanf("%d", &tam);

    array = malloc(sizeof(int)*tam);
    if (array == NULL)
    {
        printf("Erro de memoria!!! \n");
        return 0;
    }
    
    inicializa(array, tam);
    mostra(array, tam);

    printf("Insira o novo tamanho do array: ");
    scanf("%d", &newTam);

    aux = realloc(array,sizeof(int)*newTam);
    if (aux == NULL)
    {
        printf("Erro a aumentar a memoria!!! \n");
    }else
    {
        tam = newTam;
        array = aux;

        inicializa(array, tam);
    }

    mostra(array, tam);

    free(array);

    return 0;
}
