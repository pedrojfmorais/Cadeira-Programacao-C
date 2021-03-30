#include <stdio.h>

int main()
{
    int a, b, total, *p = &a, *q = &b, *r = &total;
    
    printf("Insira o primeiro valor: ");
    scanf("%d", p);
    
    printf("Insira o segundo valor: ");
    scanf("%d", q);

    *r = *p + *q;

    printf("a= %d \t b= %d \t total= %d\n", a, b, total);
    
    return 0;
}