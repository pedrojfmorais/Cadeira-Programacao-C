#include <stdio.h>

#define M 2
#define N 5

int unicaMat(int nLin, int nCol, int mat[][nCol])
{

    for (int i = 0; i < nLin*nCol; i++)
    {
        for (int j = i+1; j < nLin*nCol; j++)
        {
            if (*(*(mat)+i) == *(*(mat)+j))
            {
                return 0;
            }  
        }  
    }

    return 1;
}

int main(int argc, char const *argv[])
{
    
    int array[M][N] = {{1,2,3,4,5},{6,7,8,9,0}};
    int resultado;

    resultado = unicaMat(M, N, array);

    printf("Os elementos da matriz ");

    if (!resultado)
    {
        printf("nao ");
    }

    printf("sao unicos. \n");

    return 0;
}
