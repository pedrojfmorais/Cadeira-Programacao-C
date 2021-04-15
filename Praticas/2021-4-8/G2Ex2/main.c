#include <stdio.h>
#include <stdlib.h>

#include "retangulo.h"
#include "ponto.h"

int main()
{
    Retangulo r = {4,5,{1,1}};

    ponto2D p = {2,2};
    printPonto(p);

    inicializa_retangulo(&r);
    imprime_retangulo(r);

    printf("A area do retangulo e: %d\n", area_retangulo(r));

    printf("O ponto ");

    switch(ponto_retangulo(r, p))
    {
        case 1: printf("encontra-se dentro do retangulo.");
                break;
        case 0: printf("encontra-se fora do retangulo.");
                break;
        default: printf("Ocorreu um erro!");
                 break;
    }

    printf("\n");

    move_retangulo(&r, 2, 3);

    imprime_retangulo(r);

    return 0;
}
