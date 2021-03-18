#include <stdio.h>

#define TAM 10

void ex1()
{
    int a, b, total;
    int *p, *q, *r;

    p = &a;
    q = &b;
    r = &total;

    printf("Introduza o valor de a: ");
    scanf("%d", p);

    printf("Introduza o valor de b: ");
    scanf("%d", q);

    *r = *p + *q;
    
    printf("Resultado: %d + %d = %d \n", *p, *q, *r);
}

void troca_3_vars(float *x, float *y, float *z);

void ex2()
{
    float x, y, z;

    x = 1.0;
    y = 2.5;
    z = 3.7;

    troca_3_vars(&x, &y, &z);

    printf("x = %.2f \n", x); 
    printf("y = %.2f \n", y); 
    printf("z = %.2f \n", z); 

}

void troca_3_vars(float *x, float *y, float *z)
{
    float temp;

    temp = *z;

    *z = *y;
    *y = *x;
    *x = temp;
}

void caractArrayInt(int *array, int tam, int* pares, int* impares, int *maior, int *pos_maior);

void ex4()
{
    int pares, impares, maior, pos_maior;

    int array[TAM] = {1,3,7,5,2,10,9,7,7,1};


    caractArrayInt(array, TAM, &pares, &impares, &maior, &pos_maior);

    printf("Pares: %d \n", pares);
    printf("Impares: %d \n", impares);
    printf("Maior: %d \n", maior);
    printf("Posicao Maior: %d \n", pos_maior);

}

void caractArrayInt(int *array, int tam, int* pares, int* impares, int *maior, int *pos_maior)
{

    *maior = array[0];
    *pos_maior = 0;

    for (int i = 0; i < tam; i++)
    {
        if (array[i]%2 == 0)
            (*pares)++;
        
        if (*maior < array[i])
        {
            *maior = array[i];
            *pos_maior = i;
        }        
    }
    
    *impares = tam - *pares;

}

void doisMaiores(int *array, int tam, int *maior, int *segundoMaior);

void ex7()
{

    int maior, segundoMaior;

    int array[TAM] = {21,22,7,5,22,10,9,7,10,1};


    doisMaiores(array, TAM, &maior, &segundoMaior);

    printf("Maior: %d \n", maior);
    printf("Segundo Maior: %d \n", segundoMaior);

}

void doisMaiores(int *array, int tam, int *maior, int *segundoMaior)
{

    *maior = array[0];
    *segundoMaior = array[1];
    
    for (int i = 1; i < tam; i++)
    {
        
        if (array[i] > *maior)
        {
            *segundoMaior = *maior;
            *maior = array[i];

        } else if (array[i] > *segundoMaior && array[i] != *maior)
        {
            *segundoMaior = array[i];
        }
    }
}

int main(int argc, char const *argv[])
{
    
    //ex1();
    //ex2();
    //ex4();
    ex7();

    return 0;
}
