#include <stdio.h>

void escreveDados(char *nome, int num[])
{

    printf("%s: ", nome);

    for (int i = 0; i < 7; i++)
    {
        printf("%d, ", num[i]);
    }
    printf("\n");
}

void processaDados(char *nomeFicheiro)
{

    char nome[100];
    int num[7];
    FILE *f;

    f = fopen(nomeFicheiro, "r");
    if (f == NULL)
    {
        printf("Erro a abrir o ficheiro! \n");
        return;
    }
    
    while (fscanf(f," %99[^\n]",nome) != EOF)
    {

        for (int i = 0; i < 7; i++)
        {
            fscanf(f,"%d",&num[i]);
        }
        
        escreveDados(nome, num);
    }
    
    fclose(f);

}

int main(int argc, char const *argv[])
{
    processaDados("dados.txt");
    return 0;
}
