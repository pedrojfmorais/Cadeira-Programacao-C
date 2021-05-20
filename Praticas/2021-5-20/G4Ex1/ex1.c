#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "ex1.h"

void preenche(pno p)
{
    printf("Nome: ");
    scanf(" %99[^\n]", p->nome);

    printf("ID: ");
    scanf("%d", &p->id);

    printf("Peso: ");
    scanf("%f", &p->peso);

    printf("Altura: ");
    scanf("%f", &p->altura);

    p->prox = NULL;
}

void mostra_info(pno p)
{
    float imc;
    while(p != NULL)
    {
        imc = p->peso/(p->altura*p->altura);
        printf("%s\t%d\t%.1f\t%.1f\t%.1f\n",
               p->nome, p->id, p->peso, p->altura, imc);

        p = p->prox;
    }
}

pno insere_final(pno p)
{
    pno novo, aux;

    novo = malloc(sizeof(no));
    if(novo == NULL)
    {
        printf("Erro na alocacao de memoria\n");
        return p;
    }

    preenche(novo);
    if(p == NULL)
    {
        p = novo;
    } else
    {
        aux = p;

        if(novo->id == aux->id)
        {
            printf("\n ID ja se encontra atribuido - elemento nao adicionado a lista\n");
            return p;
        }

        while(aux->prox != NULL){


            aux = aux->prox;

            if(novo->id == aux->id)
            {
                printf("\n ID ja se encontra atribuido - elemento nao adicionado a lista\n");
                return p;
            }
        }

        aux->prox = novo;
    }

    return p;
}


void liberta_lista(pno p)
{

    pno aux;

    while(p != NULL)
    {
        aux = p;
        p = p->prox;

        free(aux);
    }
}
