#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ex1_2.h"
#include "ex3.h"

pno insere_ord(pno p)
{
    pno novo, aux;
    float imc_novo;
    float imc_atual = 0;
    novo = malloc(sizeof(no));
    if(novo == NULL)
    {
        printf("Erro na alocacao de memoria\n");
        return p;
    }
    preenche(novo);
    imc_novo = novo->peso/(novo->altura*novo->altura);
    if(p!=NULL)
        imc_atual = p->peso/(p->altura*p->altura);

    if(p == NULL || imc_novo < imc_atual) //inserir elemento à cabeça de lista
    {
        novo->prox = p;
        p = novo;
    }
    else
    {
        aux = p;

        while(aux->prox != NULL && imc_novo > aux->prox->peso/(aux->prox->altura*aux->prox->altura))
        {

            //printf("IMCAtual: %.1f IMCNovo: %.1f", aux->peso/(aux->altura*aux->altura), imc_novo);
            aux = aux->prox;

        }
        novo->prox = aux->prox;
        aux->prox = novo;
    }
    return p;
}


pno le_lista_imc_ficheiro_ordenado(char *nomeFich, pno p)
{
    pno novo, aux;
    float imc_novo, imc_atual;

    FILE *f = fopen(nomeFich,"rt");
    if (!f)
    {
        printf ("Não foi possível abrir o ficheiro de dados");
        fclose(f);
        return;
    }
    /*novo = malloc(sizeof(no));
    if(novo == NULL)
    {
        printf("Erro na alocacao de memoria\n");
        return p;
    }*/
    while (!feof(f))
    {

        novo = malloc(sizeof(no));
        if(novo == NULL)
        {
            printf("Erro na alocacao de memoria\n");
            fclose(f);
            return p;
        }

        fscanf(f,"%s %d %f %f\n",novo->nome,&novo->id, &novo->peso, &novo->altura);
        novo->prox = NULL;

        imc_novo = novo->peso/(novo->altura*novo->altura);
        if(p!=NULL)
            imc_atual = p->peso/(p->altura*p->altura);

        if(p == NULL || imc_novo < imc_atual)
            p = novo;
        else
        {
            aux = p;
            while(aux->prox != NULL && imc_novo > aux->prox->peso/(aux->prox->altura*aux->prox->altura))
                aux = aux->prox;
            novo->prox = aux->prox;
            aux->prox = novo;
        }
       /* novo = malloc(sizeof(no));
        if(novo == NULL)
        {
            printf("Erro na alocacao de memoria\n");
            return p;
        }*/
    }
    //free(novo);
    fclose(f);
    return p;
}
