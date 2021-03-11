#include <stdio.h>
#include <math.h>

#define TAM 2

void ex8(int array[][3], int tam)
{
    int scanNum;

    for (int i = 0; i < tam; i++)
    {
        printf("Insira um numero: ");
        scanf(" %d", &scanNum);

        while (1)
        {
            if (scanNum < 1 || scanNum > 100)
            {
                printf("Numero incorreto, insira novamente: ");
                scanf(" %d", &scanNum);
            } else 
            {
                break;
            }
        }
        
        array[i][0] = scanNum;
        array[i][1] = pow(scanNum, 2);
        array[i][2] = pow(scanNum, 3);
    }
    
}

int main(int argc, char const *argv[])
{
    
    int array[TAM][3];

    printf("\n");

    ex8(array, TAM);

    printf("\n");

    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }   
    

    return 0;
}
