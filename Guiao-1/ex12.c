#include <stdio.h>

#define LINHAS1 2
#define COLUNAS1 5

#define LINHAS2 2
#define COLUNAS2 5

int comparaVetores(int linhas1, int colunas1, int matriz_1[][colunas1], int linhas2, int colunas2, int matriz_2[][colunas2])
{

    if (linhas1 != linhas1 || colunas1 != colunas2)
    {
        return 0;
    }
    
    for (int i = 0; i < linhas1; i++)
    {   
        for (int j = 0; j < colunas1; j++)
        {
            if (matriz_1[i][j] != matriz_2[i][j])
            {
                return 0;
            }
        }
    }
    
    return 1;
}

int main(int argc, char const *argv[])
{
    int matrix_1[LINHAS1][COLUNAS1] = {{1,2,3,4,5}, {6,7,8,9,0}};
    int matrix_2[LINHAS2][COLUNAS2] = {{1,2,3,4,5}, {6,7,8,9,0}};
    int resultado;

    resultado = comparaVetores(LINHAS1, COLUNAS1,matrix_1, LINHAS2, COLUNAS2, matrix_2);

    printf("As duas matrizes ");

    if (resultado == 0)
    {
        printf("nao ");
    }
    
    printf("sao iguais.");

    return 0;
}
