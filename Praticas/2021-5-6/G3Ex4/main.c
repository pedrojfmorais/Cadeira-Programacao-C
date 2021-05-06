
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

//Linha comprida para teste: 01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890


void mostra_fich(char *nome) {
    char linha[TAM];
    FILE *f=fopen(nome,"rt");
    if (!f) {
        fprintf(stderr,"Erro a abrir o ficheiro: %s\n",nome);
        return;
    }

    //fgets(linha, TAM, stdin);
    //puts(linha);
    while (fgets(linha,TAM,f))
    {
        fputs(linha,stdout);
        printf("\n");
        //puts(linha);
    }


    fclose(f);
}

void mostra_fich1(char *nome) {
    char linha[TAM+1];
    FILE *f=fopen(nome,"rt");
    if (!f) {
        fprintf(stderr,"Erro a abrir o ficheiro: %s\n",nome);
        return;
    }

    while (fgets(linha,20,f))
        {//printf("%s\n",linha);
        puts(linha);}

    fclose(f);
}
void mostra_fich2(char *nome) {
    char c;
    FILE *f=fopen(nome,"rt");
    if (!f) {
        fprintf(stderr,"Erro a abrir o ficheiro: %s\n",nome);
        return;}

    while ((c=fgetc(f)) != EOF)
        putchar(c);

    fclose(f);
}

int main(int argc, char** argv) {
    mostra_fich("ex4.txt");
    //puts("\nsegundo------------------------------------------------------------------------\n");
    //mostra_fich1("ex4.txt");
    puts("\nterceiro------------------------------------------------------------------------\n");
    mostra_fich2("ex4.txt");
    return (EXIT_SUCCESS);
}

