
#include <stdio.h>
#include <string.h>

#define N 7


void escreve_sin(char *sin[][2], int tot_lin)
{
	for (int i = 0; i < tot_lin; i++)
        printf("%s : %s\n", *(*(sin + i)), *(*(sin + i) + 1));
    printf("\nE A MESMA COISA\n");
    for (int i = 0; i < tot_lin; i++)
        printf("%s : %s\n", sin[i][0], sin[i][1]);
}

char *pesquisa_sinonimo(char *sin[][2], int tot_lin, char *p)
{
	 for (int i = 0; i < tot_lin; i++)
     {
        if (strcmp(sin[i][0], p) == 0)
            //return (*(*(sin + i)+1));
            return sin[i][1];

        else if (strcmp(*(*(sin + i) + 1), p) == 0)
            return *(*(sin + i));
     }

    return NULL;
}

void pesquisa_sin_em_frase(char *sin[][2], int tot_lin)
{
    char frase[1024];

    printf("\nEscreva uma frase: ");
    scanf(" %[^\n]", frase);

    char * palavraNaFrase = strtok(frase, " ,;.");
    char * sinonimoDePalavra;

    while (palavraNaFrase != NULL)
    {
        sinonimoDePalavra = pesquisa_sinonimo(sin, tot_lin, palavraNaFrase);

        if (sinonimoDePalavra != NULL)
            printf("A palavra %s e sinonimo de %s\n", sinonimoDePalavra, palavraNaFrase);

        palavraNaFrase = strtok(NULL, " ,;.");

    }
}



int encontra_palavras_repetidas(char *sin[][2], int tot_lin)
{
    int conta_repetidos = 0;

    for (int i = 0; i < tot_lin; i++)
    {
        for (int z = i + 1; z < tot_lin; z++)
        {
            /*if (strcmp(*(*(sin + i)), *(*(sin + z))) == 0
                || strcmp(*(*(sin + i)), *(*(sin + z) + 1)) == 0
                || strcmp(*(*(sin + i) + 1), *(*(sin + z))) == 0
                || strcmp(*(*(sin + i) + 1), *(*(sin + z) + 1)) == 0)*/

            if ( strcmp(sin[i][0], sin[z][0]) == 0
                || strcmp(sin[i][0], sin[z][1]) == 0
                || strcmp(sin[i][1], sin[z][0]) == 0
                || strcmp(sin[i][1], sin[z][1]) == 0)
                conta_repetidos++;


        }
    }

    return conta_repetidos;
}

int encontra_palavras_repetidas1(char *sin[][2], int tot_lin)
{
    int conta_repetidos = 0;
    int flag[N*2];
    for (int j=0;j<N*2;j++)//inicialização das flags todas a zero
        flag[j] = 0;

    for (int i = 0; i < tot_lin; i++)
    {
        for (int z = i + 1; z < tot_lin; z++)
        {
            if ( strcmp(sin[i][0], sin[z][0]) == 0) // compara o elemento sin[i][0] com todos os elementos da coluna 0 a partir dessa linha

            {
                if(!flag[i])
                {
                    conta_repetidos++;
                    flag[i]=1;
                }
                flag[z]=1;


            }
            if (strcmp(sin[i][0], sin[z][1]) == 0) // compara o elemento sin[i][0] com todos os elementos da coluna 1 a partir dessa linha
            {
                if(!flag[i])
                {
                    conta_repetidos++;
                    flag[i]=1;
                }
                flag[z+N]=1;
            }
            if ( strcmp(sin[i][1], sin[z][0]) == 0) //compara o elemento sin[i][1] com todos os elementos da coluna 0 a partir dessa linha

            {
                if(!flag[i+N])
                {
                    conta_repetidos++;
                    flag[i+N]=1;
                }
                flag[z]=1;


            }
            if (strcmp(sin[i][1], sin[z][1]) == 0) //compara o elemento sin[i][1] com todos os elementos da coluna 0 a partir dessa linha
            {
                if(!flag[i+N])
                {
                    conta_repetidos++;
                    flag[i+N]=1;
                }
                flag[z+N]=1;
            }
        }
    }
     for (int j=0;j<N*2;j++)
       printf("\nflag[%d] = %d", j, flag[j]);

    return conta_repetidos;
}



int main()
{
	char palavra[50], *p;

	char *s[N][2] = {{"estranho", "bizarro"},
					 {"desconfiar", "suspeitar"},
					 {"vermelho", "encarnado"},
					 {"duvidar", "desconfiar"},
					 {"carro", "automovel"},
					 {"desconfiar", "duvidar"},
					 {"desconfiar", "bizarro"}};



	escreve_sin(s, N);		// alinea 22.1

	printf("Palavra a pesquisar: ");
	scanf(" %s", palavra);

	p = pesquisa_sinonimo(s, N, palavra); // alinea 22.2

	if(p == NULL)
		printf("A palavra %s nao tem sinonimo conhecido\n", palavra);
	else
		printf("A palavra %s e sinonimo de %s\n", p, palavra);


	pesquisa_sin_em_frase(s, N); // alinea 22.3
    printf("\nPalavras repetidas: %d", encontra_palavras_repetidas1(s, N)); // alinea 22.4
    //printf("\nPalavras repetidas: %d", palavras_repetidas1(s, N)); // alinea 22.4

	return 0;
}
