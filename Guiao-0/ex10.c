#include <stdio.h>

int verificaQuadradoMagico(int tabela[][3])
{

    int soma = tabela[0][0]+tabela[0][1]+tabela[0][2];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tabela[i][j] < 1 || tabela[i][j] > 9)
            {
                return 0;
            }

            for (int k = i+1; k < 3; k++)
            {
                for (int l = j+1; l < 3; l++)
                {
                    if (tabela[i][j] == tabela[k][l])
                    {
                        return 0;
                    }
                }
            }
        }
    }
    
    for (int i = 1; i < 3; i++)
    {
        if (tabela[i][0]+tabela[i][1]+tabela[i][2] != soma)
        {
            return 0;
        }

        if (tabela[0][i]+tabela[1][i]+tabela[2][i] != soma)
        {
            return 0;
        }
    }

    if (tabela[0][0]+tabela[1][1]+tabela[2][2] != soma)
    {
        return 0;
    }

    if (tabela[2][0]+tabela[1][1]+tabela[0][2] != soma)
    {
        return 0;
    }
    
    return 1;
    
}

int main(int argc, char const *argv[])
{
    int tabela[3][3] = {{6,1,8},{7,5,3},{2,9,4}};

    int resultado = verificaQuadradoMagico(tabela);

    printf("O quadrado ");

    if (!resultado)
        printf("nao ");
    
    printf("e magico. \n");

    return 0;
}
