#include <stdio.h>

#define L1 3
#define C1 2
#define L2 4
#define C2 3

void escreve(int n_linhas, int n_colunas, int matriz[][n_colunas])
{
    int *p;
    p = matriz[0];

    for (int i = 0; i < n_linhas*n_colunas; i++)
    {
        if (i%n_colunas == 0)
        {
            printf("\n");
        }
        printf(" %d", *(p+i));
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int mat1[L1][C1] = {{1,2},{3,4},{5,6}};
    int mat2[L2][C2] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};

    printf("\n Matriz 1: \n");
    escreve(L1, C1, mat1);

    printf("\n Matriz 2: \n");
    escreve(L2, C2, mat2);


    return 0;
}
