#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"


char menu()
{
    char n;
    printf("\nIntroduza o numero da opcao pretendida: ");
    printf("\n1 - Adiciona Contacto");
    printf("\n2 - Elimina Contacto");
    printf("\n3 - Lista todos Contactos");
    printf("\n4 - Procura Contacto");
    printf("\n5 - Atualiza Contacto");
    printf("\n6 - Ordena Contactos");
    printf("\n7 - Sair");
    printf("\nOPCAO: ");
    fflush(stdin);
    n = getchar();

    return n;
}

contactos obtem_info()
{
    contactos novoContacto;

    printf("Insira o nome do novo contacto: ");
    scanf(" %99[^\n]", novoContacto.nome);

    printf("Insira o numero de telemovel do novo contacto: ");
    scanf(" %9[^\n]", novoContacto.numero);

    return novoContacto;
}

contactos *adiciona_contacto(contactos *array_contactos, int *total)
{
    if((*total) == 0)
    {

        array_contactos = malloc(sizeof(contactos));

        if(array_contactos == NULL)
        {
            printf("Ocorreu um erro a alocar memória!");
            return NULL;
        }

        contactos novo = obtem_info();

        array_contactos[*total] = novo;
        (*total)++;

    } else
    {
        contactos *aux;
        int existe_contacto = 0;
        int i;

        aux = realloc(array_contactos,sizeof(contactos)*(*total+1));

        if(aux == NULL)
        {
            printf("Ocorreu um erro a alocar memória!");
            return NULL;
        }

        array_contactos = aux;
        contactos novo;
        do{

            existe_contacto = 0;
            novo = obtem_info();

            for(i = 0; i < *total && strcmp(novo.nome, array_contactos[i].nome) != 0; i++);

            if(i < *total)
            {
                existe_contacto = 1;
                printf("\n\t Contacto ja existe! \n\n");
            }

        }while(existe_contacto);

        array_contactos[*total] = novo;
        (*total)++;
    }

    return array_contactos;

}

void escreve_info(contactos cont)
{
    printf("\nNome: %s.\n", cont.nome);
    printf("Telemovel: %s.\n", cont.numero);
}

void escreve_contactos(contactos *array_contactos, int total)
{

    for(int i = 0; i < total; i++)
    {
        escreve_info(array_contactos[i]);
    }
}


void procura_contacto(contactos *array_contactos, int total,char *nome)
{
    for(int i = 0; i < total; i++)
    {
        if(!strcmp(array_contactos[i].nome, nome))
        {
            printf("O numero do contacto %s e: %s.\n", array_contactos[i].nome, array_contactos[i].numero);
            return;
        }
    }
    printf("O contacto \"%s\" nao existe!\n", nome);
}

contactos *atualiza_contacto(contactos *array_contactos, int total, char nome[100])
{

    int i = 0;
    for(i; i<total && strcmp(nome, array_contactos[i].nome)!=0;i++);

    if(i==total)
    {
        printf("Contactos nao existe\n");
    } else
    {
        printf("Introduza o novo contacto de %s: ", array_contactos[i].nome);
        scanf(" %9[^\n]", &array_contactos[i].numero);
    }
    return array_contactos;
}

contactos *elimina_contacto(contactos *array_contactos, int *total, char nome[100])
{
    int i = 0;
    contactos *aux;
    contactos temp;

    for(i; i<*total && strcmp(nome, array_contactos[i].nome)!=0;i++);

    if(i==*total)
    {
        printf("Contactos nao existe\n");
        return array_contactos;

    }else if(*total==1)
    {
        free(array_contactos);
        *total = 0;
        return NULL;

    }else
    {
        temp = array_contactos[i];

        array_contactos[i] = array_contactos[*total-1];
        aux = realloc(array_contactos, sizeof(contactos)*(*total)-1);

        if(aux == NULL)
        {
            printf("Ocorreu um erro a alocar memória!");
            array_contactos[i] = temp;
            return array_contactos;
        }

        array_contactos = aux;
        (*total)--;

    }
    return array_contactos;
}

contactos *ordena_contactos(contactos *array_contactos, int total)
{
    int i, ordena;
    contactos aux;

    do{

        ordena = 0;
        for(i = 0; i < total-1;i++)
        {
            if(strcmp(array_contactos[i].nome,array_contactos[i+1].nome)>0)
            {
                aux = array_contactos[i];
                array_contactos[i] = array_contactos[i+1];
                array_contactos[i+1] = aux;
                ordena = 1;
            }
        }

    }while(ordena);

    return array_contactos;
}
