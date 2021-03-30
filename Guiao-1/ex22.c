#include <stdio.h>
#include <string.h>

#define N 5

void imprimeSinonimos(int linhas, char *sinonimos[][2])
{
    printf("\n Lista de sinonimos: \n");
    for (int i = 0; i < linhas; i++)
    {
        printf("  %s - %s \n", sinonimos[i][0], sinonimos[i][1]);
    }
    
    printf("\n");

}

char *pesquisaPalavra(int linhas, char *sinonimos[][2], char *palavra)
{

    for (int i = 0; i < linhas; i++)
    {
        if (!strcmp(sinonimos[i][0], palavra))
        {
            return sinonimos[i][1];
        }

        if (!strcmp(sinonimos[i][1], palavra))
        {
            return sinonimos[i][0];
        }
    }
    
    return NULL;
}

void pesquisarFrase(int linhas, char *sinonimos[][2])
{
    printf("\n");

    char frase[500];
    char *sinonimo;

    printf("Insira uma palavra a pesquisar: ");
    scanf(" %[^\n]", frase);

    char delim[] = " ";

    char *palavra = strtok(frase, delim);

    while (palavra != NULL)
    {
        
        sinonimo = pesquisaPalavra(linhas, sinonimos, palavra);
                
        if (sinonimo != NULL)
        {
            printf("O sinonimo de \"%s\" e: %s.\n", palavra, sinonimo);
        }
        palavra = strtok(NULL, delim);
    }
    printf("\n");
}

int verificaRepetidas(int linhas, char *sinonimos[][2]){

    int repetidas = 0;
    char arrayRepetidas[linhas*2];

    for (int i = 0; i < linhas*2; i++)
    {
        for (int j = i+1; j < linhas*2; j++)
        {
            if (!strcmp(*(*(sinonimos)+i), *(*(sinonimos)+j)))
            {
                repetidas++;
            }
        }
    }

    return repetidas;
}

int main(int argc, char const *argv[])
{
    char *s[N][2] = 
    {
        {"estranho", "bizarro"},
		{"desconfiar", "suspeitar"},
		{"vermelho", "encarnado"},
		{"duvidar", "desconfiar"},
		{"carro", "automovel"}
    };	

    char palavra[20];
    char *sinonimo;

    int repetidas;

    imprimeSinonimos(N, s);

    printf("Insira uma palavra a pesquisar: ");
    scanf("%s", palavra);

    sinonimo = pesquisaPalavra(N, s, palavra);

    if (sinonimo != NULL)
    {
        printf("O sinonimo de \"%s\" e: %s.\n", palavra, sinonimo);
    } else {
        printf("Nao existe sinonimo para \"%s\".\n", palavra);
    }

    pesquisarFrase(N, s);

    repetidas = verificaRepetidas(N, s);
    
    printf("\nExistem %d palavras repetidas.\n", repetidas);

    return 0;
}
