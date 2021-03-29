#include <stdio.h>

#define TAM 10

int encontra(int *tabela, int tam, int valor)
{
    int inicio = 0;
    int fim = tam/2;
    if (tabela[tam/2] < valor)
    {
        inicio = tam/2;
        fim = tam;
    }
    
    for (inicio; inicio < fim; inicio++)
    {
        if (tabela[inicio] == valor)
        {
            return 1;
        }   
    }
    return 0;

}

int main(int argc, char const *argv[])
{
    
    int tabela[TAM] = {1,4,6,45,76,84,102,122,144,223};
    int resultado;

    resultado = encontra(tabela, TAM, 122);

    printf("O valor ");

    if (!resultado)
        printf("nao ");
    
    printf("encontra-se na tabela. \n");
    
    return 0;
}
