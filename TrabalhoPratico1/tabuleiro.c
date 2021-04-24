#include <stdio.h>
#include <stdlib.h>

#include "tabuleiro.h"
#include "utils.h"

tabuleiro inicializarTabuleiro()
{

    tabuleiro tab;
    int tam = intUniformRnd(3,5);

    tab.tabuleiro = malloc(sizeof(char)*tam*tam);

    if(tab.tabuleiro == NULL)
    {
        printf("Ocorreu um erro a alocar memória!");
        return;
    }

    tab.nLinhas = tam;
    tab.nColunas = tam;

    for(int i = 0; i < tam*tam; i++)
    {

        tab.tabuleiro[i] = ' ';
    }

    return tab;
}

void mostraTabuleiro(tabuleiro tab)
{
    for(int i = 0; i < tab.nLinhas*tab.nColunas; i++)
    {

        if(i%tab.nColunas == 0)
            printf("\n|");


        printf("%c|", tab.tabuleiro[i]);
    }
    printf("\n\n");
}
