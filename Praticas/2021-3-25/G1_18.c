
#include <stdio.h>


// Escrever a função

void calcularMediaColuna(int n_linhas, int n_colunas, float matriz[][n_colunas], int *min, int *max)
{

    float mediaMin = 0;
    float mediaMax = 0;


    for (int i = 0; i < n_colunas; i++)
    {
        float mediaAtual = 0;
        for (int j = 0; j < n_linhas; j++)
        {
            mediaAtual += matriz[j][i];
        }

        mediaAtual /= n_linhas;
        
        printf("Colunas %d, media: %.2f \n", i, mediaAtual);

        if (i == 0)
        {
            mediaMin = mediaAtual;
            mediaMax = mediaAtual;

        }
        if (mediaMin > mediaAtual)
        {
            mediaMin = mediaAtual;
            *min = i;

        }
        if (mediaMax < mediaAtual)
        {
            mediaMax = mediaAtual;
            *max = i;
        }
    }
    printf("\n");
}

int main(int argc, char** argv) {

    float m1[3][2] = {{1.0, 4.5},{-2.5, 8.9},{0.3, 1.4}};
    float m2[2][6] = {{1.0, 1.6, 4.2, 1.4, 0.5, -3.4},{2.5, 8.1, 0.9, -0.1, 0.8, 3.5}};
    int min1=0, max1=0, min2=0, max2=0;

    calcularMediaColuna( 3, 2, m1, &min1, &max1);
    calcularMediaColuna( 2, 6, m2, &min2, &max2);
    
    printf("\nMatriz 1: min: %d, max: %d\n", min1, max1);
    printf("\nMatriz 2: min: %d, max: %d\n", min2, max2);

    return 0;
}
