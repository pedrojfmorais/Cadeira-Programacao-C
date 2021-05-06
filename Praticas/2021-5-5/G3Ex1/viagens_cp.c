#include <stdio.h>
#include <stdlib.h>

#include "viagens_cp.h"

void mostraPercurso(char *ficheiro)
{
    Paragem par;
    FILE *f = fopen(ficheiro, "rb");

    if(f == NULL)
    {
        printf("Erro a abrir o ficheiro\n");
        return;
    }

    fread(&par, sizeof(Paragem),1,f);
    while(feof(f) == 0)
    {
        printf("%s %d\n", par.nome,par.minutos);
        fread(&par, sizeof(Paragem),1,f);
    }

    fclose(f);
}

int tempo_percurso_completo(char *ficheiro)
{
    Paragem par;
    int totalMinutos = 0;
    FILE *f = fopen(ficheiro, "rb");

    if(f == NULL)
    {
        printf("Erro a abrir o ficheiro\n");
        return;
    }

    fread(&par, sizeof(Paragem),1,f);
    while(feof(f) == 0)
    {
        totalMinutos += par.minutos;
        fread(&par, sizeof(Paragem),1,f);
    }

    fclose(f);

    return totalMinutos;
}

int ligacao_cidades(char *ficheiro, char *cidadeA, char *cidadeB)
{

    Paragem par;
    int totalMinutos = 0;
    int contar = 0;
    FILE *f = fopen(ficheiro, "rb");

    if(f == NULL)
    {
        printf("Erro a abrir o ficheiro\n");
        return;
    }

    fread(&par, sizeof(Paragem),1,f);
    while(feof(f) == 0)
    {
        if(contar == 1)
            totalMinutos += par.minutos;

        if(strcmp(cidadeA, par.nome) == 0)
            contar = 1;

        if(strcmp(cidadeB, par.nome) == 0)
            contar = 2;

        fread(&par, sizeof(Paragem),1,f);
    }

    fclose(f);

    if(contar != 2)
        return -1;

    return totalMinutos;
}
