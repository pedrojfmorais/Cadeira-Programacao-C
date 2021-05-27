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
void atualiza_peso(pno p, int id, int novo_peso)
{

    if(p == NULL)
    {
        printf("Lista vazia");
        return;
    }

    while(p != NULL && p->id != id)
    {
        p = p->prox;
    }

    if(p != NULL)
        p->peso = novo_peso;
    else
        printf("O id nao existe");

}

pno elimina(pno p, int id)
{

    pno ant, aux;

    aux = p;

    if(aux == NULL)
    {
        printf("Lista vazia");
        return NULL;
    }

    if(aux->id == id)
    {
        p = aux->prox;
        free(aux);
        return p;
    }

    while(aux != NULL && aux->id != id)
    {
        ant = aux;
        aux = aux->prox;
    }

    if(aux->id == id)
    {
        ant->prox = aux->prox;
        free(aux);
    }
    else
        printf("Id nao existe");

    return p;
}
pno elimina_lista_imc_superior(pno p, float imc)
{
    pno aux = p;
    while(aux != NULL)
    {

        if((aux->peso/(aux->altura*aux->altura)) > imc)
        {
            p = elimina(p,aux->id);
        }
        aux = aux->prox;

    }
    return p;
}

void grava_lista_imc(char *nomeFich, pno p)
{
    FILE *f = fopen(nomeFich,"wt");
    if (!f)
    {
        printf ("Não foi possível abrir o ficheiro de dados");
       // fclose(f);
        return;
    }
    while(p != NULL)
    {
        fprintf(f,"%s %d %f %f\n",
               p->nome, p->id, p->peso, p->altura);
        p = p->prox;
    }
    fclose(f);
}
void grava_lista_imc_bin(char *nomeFich, pno p)
{
    FILE *f = fopen(nomeFich,"wb");
    if (!f)
    {
        printf ("Não foi possível abrir o ficheiro de dados");
        //fclose(f);
        return;
    }
    while(p != NULL)
    {
         fwrite(p, sizeof(no), 1, f);
         p = p->prox;
    }
    fclose(f);
}

pno le_lista_imc_ficheiro(char *nomeFich, pno p)
{
    pno novo, aux;
    FILE *f = fopen(nomeFich,"rt");
    if (!f)
    {
        printf ("Não foi possível abrir o ficheiro de dados");
        //fclose(f);
        return p;
    }
    novo = malloc(sizeof(no));
    if(novo == NULL)
    {
        printf("Erro na alocacao de memoria\n");
        return p;
    }
    while (fscanf(f,"%s %d %f %f\n",
               novo->nome,&novo->id, &novo->peso, &novo->altura)==4)
    {
        novo->prox = NULL;
        if(p == NULL) //inserir primeiro elemento da lista
            p = novo;
        else //inserir no final da lista
        {
            aux = p;
            while(aux->prox != NULL)
                aux = aux->prox;
            aux->prox = novo;
        }
        novo = malloc(sizeof(no));
        if(novo == NULL)
        {
            printf("Erro na alocacao de memoria\n");
            return p;
        }
    }
        free(novo);
        fclose(f);
        return p;
}
