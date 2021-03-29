#include <stdio.h>

#define TAM 10

int maisReps(int *tabela, int tam)
{

    int maisComum = tabela[0];
    int maisReps = 1;
    int reps = 1;

    for (int i = 1; i < tam; i++)
    {
        reps = 1;

        for (int j = i+1; j < tam; j++)
        {
            if (tabela[i] == tabela[j])
                reps++;
            
        }
        
        if (reps > maisReps)
        {
            maisComum = tabela[i];
            maisReps = reps;

        } else if (reps == maisReps && tabela[i] > maisComum)
        {
            maisComum = tabela[i];
        }
    }
    
    return maisComum;

}

int main(int argc, char const *argv[])
{
    
    int tabela[TAM] = {1,4,6,45,76,44,2,2,45,23};
    int resultado;

    resultado = maisReps(tabela, TAM);

    printf("O valor que mais se repete na tabela e: %d \n", resultado);
    

    return 0;
}
