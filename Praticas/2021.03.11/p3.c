#include <stdio.h>
#include <math.h>
#include <string.h>

#define TAM 2
#define TAM_String 100

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

int mainEX8()
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
}

void inverteString(char string[])
{
    for (int i = strlen(string); i >= 0; i--)
    {
        printf("%c", string[i]);
    }
    
}

void mainEx11()
{

    char string[TAM_String] = "Hoje e Domingo!";

    inverteString(string);
}

void removeSpaces(char string[])
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == ' ' && string[i-1] != ' ' && i != 0)
        {
            printf("\n");
        } else if(string[i] != ' ')
        {
            printf("%c", string[i]);
        }
    }
}

void mainEx12()
{
    char string[TAM_String] = "Hoje e           Domingo!     ";

    removeSpaces(string);
}


int main(int argc, char const *argv[])
{
    //mainEX8();

    //mainEx11();

    mainEx12();
    
    return 0;
}
