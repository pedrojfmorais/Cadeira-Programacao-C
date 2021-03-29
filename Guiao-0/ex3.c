#include <stdio.h>

#define TAM 10

int repsMaior(int *tabela, int tam)
{

    int maior = tabela[0];
    int reps = 1;

    for (int i = 1; i < tam; i++)
    {
        if(maior < tabela[i])
        {
            maior = tabela[i];
            reps = 1;
        } else if (maior == tabela[i])
        {
            reps++;
        }
        
            
    }
    
    return reps;

}

int main(int argc, char const *argv[])
{
    
    int tabela[TAM] = {1,4,79,45,76,44,2,79,79,23};
    int resultado;

    resultado = repsMaior(tabela, TAM);

    printf("O maior valor aparece %d vezes na tabela. \n", resultado);
    

    return 0;
}
