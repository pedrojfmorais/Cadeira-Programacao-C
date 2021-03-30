#include <stdio.h>

#define TAM 8

void reduzMatriz(int tam, int matrizOriginal[][tam], float matrizReduzida[][tam/2])
{

    int linha = 0;

    for (int i = 0; i < TAM; i+=2)
    {
        
        int coluna = 0;

        for (int j = 0; j < TAM; j+=2)
        {
            matrizReduzida[linha][coluna] = matrizOriginal[i][j] + matrizOriginal[i][j+1] + matrizOriginal[i+1][j] + matrizOriginal[i+1][j+1];
            matrizReduzida[linha][coluna] /= 4;
            coluna++;
        }
        linha++;
    }
}

int main(int argc, char const *argv[])
{
    
    int matrizOriginal[TAM][TAM] = 
    {
        {0,4,9,3,6,7,2,9},
        {9,4,7,8,3,4,7,2},
        {5,1,2,6,3,8,6,2},
        {7,1,4,8,7,2,0,7},
        {4,9,3,5,2,1,5,7},
        {5,3,4,7,8,9,1,0},
        {2,3,5,6,7,9,2,4},
        {2,3,4,5,6,7,8,9}
    };

    float matrizReduzida[TAM/2][TAM/2];

    reduzMatriz(TAM, matrizOriginal, matrizReduzida);

    printf("Matriz Original: \n");
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
        {
            printf("%d ", matrizOriginal[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz reduzida: \n");
    for (int i = 0; i < TAM/2; i++)
    {
        for (int j = 0; j < TAM/2; j++)
        {
            printf("%.2f ", matrizReduzida[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}
