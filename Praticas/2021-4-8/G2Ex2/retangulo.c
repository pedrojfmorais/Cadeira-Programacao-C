#include <stdio.h>
#include "retangulo.h"

void imprime_retangulo(Retangulo r){

    printf("Canto superior esquerdo: (%d,%d) \n", r.p_cse.x, r.p_cse.y);
    printf("Canto superior direito: (%d,%d) \n", r.p_cse.x+r.largura, r.p_cse.y);
    printf("Canto inferior esquerdo: (%d,%d) \n", r.p_cse.x, r.p_cse.y-r.altura);
    printf("Canto inferior direito: (%d,%d) \n", r.p_cse.x+r.largura, r.p_cse.y-r.altura);

}
