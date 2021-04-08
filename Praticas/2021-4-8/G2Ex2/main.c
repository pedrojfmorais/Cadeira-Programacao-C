#include <stdio.h>
#include <stdlib.h>

#include "retangulo.h"
#include "ponto.h"

int main()
{
    Retangulo r = {4,5,{1,1}};

    ponto2D p = {1,1};
    printPonto(p);

    imprime_retangulo(r);

    return 0;
}
