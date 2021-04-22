#ifndef RETANGULO_H_INCLUDED
#define RETANGULO_H_INCLUDED
#include "ponto.h"

#define MAX 10

typedef struct rect Retangulo;
struct rect{

    int largura;
    int altura;
    ponto2D p_cse;

};

void imprime_retangulo(Retangulo r);
void inicializa_retangulo(Retangulo *r);
int area_retangulo(Retangulo r);
int ponto_retangulo(Retangulo r, ponto2D p);
void move_retangulo(Retangulo *r, int dx, int dy);
int menu();
void adicionar_retangulo(Retangulo array_r[], int *total);
void mostra_retangulo(Retangulo array_r[], int total);
void elimina_retangulo_menor(Retangulo array_r[], int *total);
void elimina_retangulos_menores(Retangulo array_r[], int *total, int area);
#endif // RETANGULO_H_INCLUDED
