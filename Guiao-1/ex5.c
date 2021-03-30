#include <stdio.h>

#define TAM 5

int comuns(int *tabA, int tamA, int *tabB, int tamB)
{
    int j = 0;
    int comuns = 0;

    for (int i = 0; i < tamA; i++)
    {

        if (tabA[i] > tabB[tamB-1])
        {
            return comuns;
        }

        for (j; j < tamB; j++)
        {

            if (tabA[i] == tabB[j])
            {
                comuns++;
                break;

            } else if (tabA[i] < tabB[j])
            {
                break;
            }
        }
    }
    
    return comuns;
}

int main(int argc, char const *argv[])
{
    int array_1[TAM] = {1,4,7,12,22};
    int array_2[TAM] = {1,7,8,12,44};
    int nComuns;

    nComuns = comuns(array_1, TAM, array_2, TAM);

    printf("Existem %d numeros comuns. \n", nComuns);

    return 0;
}
