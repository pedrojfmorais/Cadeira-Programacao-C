#include <stdio.h>

void rodarVariaveis(float *a, float *b, float *c)
{

    float temp;

    temp = *a;
    *a = *c;
    *c = *b;
    *b = temp;

}

int main()
{
    float a, b, c;
    
    printf("Insira o primeiro valor: ");
    scanf("%f", &a);
    
    printf("Insira o segundo valor: ");
    scanf("%f", &b);
    
    printf("Insira o terceiro valor: ");
    scanf("%f", &c);

    printf("Antes rotacao: \n");
    printf("a = %.2f \t b = %.2f \t c = %.2f \n\n", a, b, c);

    rodarVariaveis(&a, &b, &c);

    printf("Antes rotacao: \n");
    printf("a = %.2f \t b = %.2f \t c = %.2f \n\n", a, b, c);
    
    return 0;
}