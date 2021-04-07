#include <stdio.h>

#define LINHAS 4
#define COLUNAS 5

void mediaColunas(int linhas, int colunas, float array[][colunas], int *idxMediaBaixa, int *idxMediaAlta)
{

    float mediaBaixa;
    float mediaAlta;

    for (int j = 0; j < colunas; j++)
    {           
        float media = 0;

        for (int i = 0; i < linhas; i++)
        {
            media += array[i][j];
        }
        
        media /= linhas;

        printf("A media dos valores na coluna %d e de: %.2f \n", j, media);

        if (j == 0)
        {
            mediaBaixa = media;
            mediaAlta = media;

            *idxMediaAlta = 0;
            *idxMediaBaixa = 0;
        }

        if (media > mediaAlta)
        {
            mediaAlta = media;
            *idxMediaAlta = j;
        }

        if (media < mediaBaixa)
        {
            mediaBaixa = media;
            *idxMediaBaixa = j;
        }
    }

    printf("\n");
}

int main(int argc, char const *argv[])
{
    float array[LINHAS][COLUNAS] = {{1,2,3,4,5},{6,7,8,9,0},{11,22,33,44,55},{66,77,88,99,00}};
    int idxMediaBaixa;
    int idxMediaAlta; 

    mediaColunas(LINHAS, COLUNAS, array, &idxMediaBaixa, &idxMediaAlta);

    printf("A media mais alta encontra-se na coluna com indice %d. \n", idxMediaAlta);
    printf("A media mais baixa encontra-se na coluna com indice %d. \n", idxMediaBaixa);

    return 0;
}
