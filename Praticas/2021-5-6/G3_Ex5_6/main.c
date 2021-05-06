#include <stdio.h>
#include <stdlib.h>

#define TAM 100
void duplicaConteudo(char *origem, char *destino)
{
    char ler[100];
    char c;
    FILE *f = fopen(origem,"rt");
    if (!f)
    {
        printf ("Não foi possível abrir o ficheiro origem");
        return;
    }
    FILE *g = fopen(destino,"wt");
    if (!g)
    {
        printf ("Não foi possível abrir o ficheiro destino");
        fclose(f);
        return;
    }
   // while (fgets(ler,TAM,f))
     //   fputs(ler, g);
    while((c=fgetc(f))!= EOF)
		fputc(c, g);
fclose(f);
fclose(g);

}
void mostra_fich2(char *nome) {
    char c;
    FILE *f=fopen(nome,"rt");
    if (!f) {
        fprintf(stderr,"Erro a abrir o ficheiro: %s\n",nome);
        return;
    }

    while ((c=fgetc(f)) != EOF)
        putchar(c);

    fclose(f);
}

void duplicaConteudoNumerado(char *origem, char *destino)
{
    char c;
    char ler[TAM];
    int conta=1;
    FILE *f = fopen(origem,"rt");
    if (!f)
    {
        printf ("Não foi possível abrir o ficheiro origem");
        return;
    }

    FILE *g = fopen(destino,"wt");
    if (!g)
    {
        printf ("Não foi possível abrir o ficheiro destino");
        fclose(f);
        return;
    }

    //fprintf(g, "%d. ", conta++); //imprime 1 conta = 2
	/*while ((c=fgetc(f)) != EOF)
	{
		fputc(c, g);
		if(c == '\n')
			fprintf(g, "%d. ", conta++);

	}*/

	while (fgets(ler,TAM,f))
	{
		fprintf(g, "%d. ", conta++);
		fputs(ler, g);
	}

fclose(f);
fclose(g);

}

int main()
{
    printf("\n-----------Duplica ficheiro-------------\n");
    duplicaConteudo("ex4.txt", "ex5.txt");
    printf("\n-----------Mostra ficheiro duplicado-------------\n");
    mostra_fich2("ex5.txt");

    printf("\n-----------Duplica ficheiro numerado-------------\n");
    duplicaConteudoNumerado("ex6.txt", "ex6_numerado.txt");
    printf("\n-----------Mostra ficheiro original-------------\n");
    mostra_fich2("ex6.txt");

    printf("\n-----------Mostra ficheiro duplicado-------------\n");
    mostra_fich2("ex6_numerado.txt");


    return 0;
}
