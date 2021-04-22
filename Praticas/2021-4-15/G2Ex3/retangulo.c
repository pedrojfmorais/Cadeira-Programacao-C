#include <stdio.h>
#include "ponto.h"
#include "retangulo.h"

void imprime_retangulo(Retangulo r){

    printf("Canto superior esquerdo: (%d,%d) \n", r.p_cse.x, r.p_cse.y);
    printf("Canto superior direito: (%d,%d) \n", r.p_cse.x+r.largura, r.p_cse.y);
    printf("Canto inferior esquerdo: (%d,%d) \n", r.p_cse.x, r.p_cse.y-r.altura);
    printf("Canto inferior direito: (%d,%d) \n", r.p_cse.x+r.largura, r.p_cse.y-r.altura);

}

void inicializa_retangulo(Retangulo *r)
{
    printf("Indique a altura do retangulo: ");
    scanf("%d", &r->altura);
    printf("Indique a largura do retangulo: ");
    scanf("%d", &r->largura);
    printf("Indique as coordenadas do canto superior esquerdo do retangulo: \n");
    initPonto(&r->p_cse);
}

int area_retangulo(Retangulo r)
{
    return r.altura*r.largura;
}

int ponto_retangulo(Retangulo r, ponto2D p)
{
    if(p.x > r.p_cse.x && p.x < r.p_cse.x+r.largura && p.y < r.p_cse.y && p.y > r.p_cse.y-r.altura)
        return 1;

    return 0;
}

void move_retangulo(Retangulo *r, int dx, int dy)
{
    movePonto(&r->p_cse,dx,dy);
}

int menu()
{
    int i;
    puts("1 - Adiciona Retangulo");
    puts("2 - Mostra Retangulos");
    puts("3 - Elimina Retangulo Mais Pequeno");
    puts("4 - Elimina Retangulos com area inferior a um limite");
    puts("5 - Ordena retangulos pela ordem crescente da distancia Euclidiana");
    puts("6 - Terminar");
    puts("Escolha uma opcao: ");
    do
    {
        scanf("%d", &i);
    }
    while(i<1 || i>6);
    return i;
}

Retangulo obtem_info()
{
    Retangulo r;

    inicializa_retangulo(&r);

    return r;
}

void adicionar_retangulo(Retangulo array_r[], int *total)
{
    if(*total >= MAX)
    {
        printf("\nTabela Completa\n");
        return;
    }

    array_r[*total] = obtem_info();
    (*total)++;
}

void mostra_retangulo(Retangulo array_r[], int total)
{
    for(int i = 0; i < total; i++)
    {
        printf("\n\nRetangulo %d: \n", i+1);
        imprime_retangulo(array_r[i]);
    }
}

void elimina_retangulo_menor(Retangulo array_r[], int *total)
{
    if(*total == 0)
    {
        printf("\nNao existem retangulos!\n\n");
        return;
    }

    int area_menor = area_retangulo(array_r[0]);
    int idx_eliminar = 0;
    for(int i = 1; i < *total; i++)
    {
        int nova_area = area_retangulo(array_r[i]);

        if(nova_area < area_menor)
        {
            area_menor = nova_area;
            idx_eliminar = i;
        }
    }

    array_r[idx_eliminar] = array_r[(*total)-1];
    (*total)--;

}

void elimina_retangulos_menores(Retangulo array_r[], int *total, int area)
{
    int count = 0;

    if(*total == 0)
    {
        printf("\nNao existem retangulos!\n\n");
        return;
    }

    for(int i = 0; i < *total; i++)
    {
        if(area_retangulo(array_r[i]) < area)
            count++;
    }

    for(int i = 0; i < count; i++)
        elimina_retangulo_menor(array_r, total);
}
