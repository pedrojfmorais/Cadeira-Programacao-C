#include <stdio.h>

#define N 3

void transposta(int n, int array[][n])
{

    int array_temp[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            array_temp[i][j] = array[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            array[j][i] = array_temp[i][j];
        }
    }
}

int main(int argc, char const *argv[])
{
    
    int array[N][N] = {{1,2,3},{4,5,6},{7,8,9}};

    printf("Antes de transpor a matriz: \n");

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    
    transposta(N, array);

    printf("\nDepois de transpor a matriz: \n");

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}
