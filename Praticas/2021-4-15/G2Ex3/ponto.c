
#include <stdio.h>
#include "ponto.h"

// alinea b)
void printPonto(ponto2D a){
    printf("Ponto: (%d,%d)\n", a.x, a.y);
}

// alinea c)
void initPonto(ponto2D *p){

    int x,y;

    printf("Insira as duas coordenadas do ponto: \n");
    printf("Coordenada X: ");
    scanf(" %d", &p->x);

    printf("Coordenada Y: ");
    scanf(" %d", &p->y);

}

// alinea d)
void movePonto(ponto2D* p, int dx, int dy){

    p->x += dx;
    p->y += dy;

}
