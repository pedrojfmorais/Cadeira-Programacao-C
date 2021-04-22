#include <stdio.h>
#include <stdlib.h>

#include "retangulo.h"
#include "ponto.h"

int main()
{
    Retangulo array_r[MAX];

    int i, total=0;

    do
    {
        i=menu();
        switch(i)
        {
            case 1: adicionar_retangulo(array_r, &total);
                    break;
            case 2: mostra_retangulo(array_r,total);
                    break;
            case 3: elimina_retangulo_menor(array_r, &total);
                    break;
            case 4: elimina_retangulos_menores(array_r,&total,4);
                    break;
            case 5: //ordena_retangulos(array_r,total);
                    break;
            case 6: break;
        }
    }while(i>0 && i<6);

    return 0;
}
