#include <stdio.h>

#define LIN1 2
#define COL1 5

#define LIN2 2
#define COL2 5

void somaMatrizes(int lin1, int col1, int a[][col1], int lin2, int col2, int b[][col2])
{

    for (int i = 0; i < LIN1*COL1; i++)
    {
        *(*(a)+i) = *(*(a)+i) + *(*(b)+i);
    }
}

int main(int argc, char const *argv[])
{
    int a[LIN1][COL1] = {{1,2,3,4,5},{6,7,8,9,0}};
    int b[LIN2][COL2] = {{1,2,3,4,5},{6,7,8,9,0}};

    somaMatrizes(LIN1, COL1, a, LIN2, COL2, b);

    printf("Matriz Final: \n");

    for (int i = 0; i < LIN1*COL1; i++)
    {
        if (i % COL1 == 0 && i != 0)
        {
            printf("\n");
        }
        
        printf("%d\t", *(*(a)+i));
    }

    return 0;
}
