#include <stdio.h>

#define TAM 10

int maior(int *tabela, int tam)
{

    int maior = tabela[0];

    for (int i = 1; i < tam; i++)
    {
        if(maior < tabela[i])
            maior = tabela[i];
    }
    
    return maior;

}

int main(int argc, char const *argv[])
{
    
    int tabela[TAM] = {1,4,6,45,76,44,2,2,1,23};
    int resultado;

    resultado = maior(tabela, TAM);

    printf("O maior valor da tabela e: %d \n", resultado);
    

    return 0;
}
