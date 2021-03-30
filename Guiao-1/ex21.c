#include <stdio.h>
#include <string.h>

#define LINHAS 5
#define COLUNAS 6

void encontraPalavra(int linhas, int colunas, char quebraCabecas[][colunas], char *palavra)
{

    if (linhas > colunas && strlen(palavra) > linhas)
    {
        printf("A palavra e demasiado grande.\n");
        return;

    }else if (linhas < colunas && strlen(palavra) > colunas)
    {
        printf("A palavra e demasiado grande.\n");
        return;
    }
    
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            if (quebraCabecas[i][j] == palavra[0])
            {
                if (i+(strlen(palavra)-1) < linhas)
                {
                    int l = 0;
                    for (int k = i; k < linhas; k++)
                    {
                        if (palavra[l] != quebraCabecas[k][j])
                        {
                            break;
                        }
                        l++;
                    }

                    if (l == strlen(palavra))
                    {
                        printf("A palavra \"%s\" surge ao longo da coluna %d e inicio na linha %d. \n", palavra, j, i);
                    }
                }

                if (j+(strlen(palavra)-1) < colunas)
                {
                    int l = 0;
                    for (int k = j; k < colunas; k++)
                    {
                        if (palavra[l] != quebraCabecas[i][k])
                        {
                            break;
                        }
                        l++;
                    }

                    if (l == strlen(palavra))
                    {
                        printf("A palavra \"%s\" surge ao longo da linha %d e inicio na coluna %d. \n", palavra, i, j);
                    }
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    char palavra[20];
    
    char quebraCabeca[LINHAS][COLUNAS] = 
    {
        {'e', 'B', 'a', 'u', 'l', 'q'},
        {'l', 'e', 'r', 'r', 's', 's'},
        {'u', 'w', 'u', 'q', 'g', 'r'},
        {'a', 'a', 'l', 'l', 'u', 'a'},
        {'p', 'm', 'h', 'u', 'd', 'j'}
    };

    printf("Insira a palavra a pesquisar: ");
    scanf("%s", palavra);

    encontraPalavra(LINHAS, COLUNAS, quebraCabeca, palavra);

    return 0;
}