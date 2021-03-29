#include <stdio.h>

#define TAM 10

int calculaSoma(int *tabela, int tam, int valor)
{

    for (int i = 0; i < tam; i++)
    {
        for (int j = i+1; j < tam; j++)
        {
            for (int k = j+1; k < tam; k++)
            {
                if (tabela[i]+tabela[j]+tabela[k] == valor)
                {
                    printf("%d %d %d \n", tabela[i], tabela[j], tabela[k]);
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    
    int tabela[TAM] = {1,4,6,5,7,4,2,2,1,3};
    int valor = 15;

    calculaSoma(tabela, TAM, valor);
    

    return 0;
}
