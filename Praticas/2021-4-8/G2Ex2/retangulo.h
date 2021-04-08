#ifndef RETANGULO_H_INCLUDED
#define RETANGULO_H_INCLUDED
#include "ponto.h"

typedef struct rect Retangulo;
struct rect{

    int largura;
    int altura;
    ponto2D p_cse;

};

void imprime_retangulo(Retangulo r);

#endif // RETANGULO_H_INCLUDED
