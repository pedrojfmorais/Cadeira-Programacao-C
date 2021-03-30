#include <stdio.h>

#define N 5

double produto_escalar (double *a, double *b, int n)
{
    double resultado = 0;
    
    for (int i = 0; i < n; i++)
    {
        resultado += a[i]*b[i];
    }

    return resultado;
}

int main(int argc, char const *argv[])
{
    
    double a[N] = {1.5, 2.2, 3.5, 4.1, 7.5}; 
    double b[N] = {0.5, 1.2, 2.5, 2.1, 3.5}; 
    
    double resultado = produto_escalar(a, b, N);

    printf("O produto escalar entre o vetor 'a' e 'b' e: %.2f \n", resultado);

    return 0;
}
