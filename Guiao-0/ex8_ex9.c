#include <stdio.h>

#define TAM 10

void preencheMatriz(int tabela[][3], int tam)
{

    int num;

    for (int i = 0; i < tam; i++)
    {
        printf("Insira um numero: ");
        scanf(" %d", &num);

        while (1)
        {
            int error = 0;
            for (int j = 0; j < tam; j++)
            {
                if (num == tabela[j][0])
                {
                    printf("\nInsira outro valor: ");
                    scanf(" %d", &num);
                    error = 1;
                    break;
                }
            }
            if (!error)
            {
                break;
            }
            
        }
        
        tabela[i][0] = num;
        tabela[i][1] = num*num;
        tabela[i][2] = num*num*num;
        
    }
}

void mostraMatriz(int tabela[][3], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d %d %d \n", tabela[i][0], tabela[i][1], tabela[i][2]);
    }
}

int main(int argc, char const *argv[])
{
    
    int tabela[TAM][3];
    
    preencheMatriz(tabela, TAM);
    mostraMatriz(tabela, TAM);
    
    return 0;
}
