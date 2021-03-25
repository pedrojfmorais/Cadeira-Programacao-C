
#include <stdio.h>
#include <string.h>

#define N	5


void escreve_sin(char *sin[][2], int tot_lin)
{
	for (int i = 0; i < tot_lin; i++)
	{
		printf("%s -> %s \n", *(*(sin+i)), *(*(sin+i)+1));
	}
	printf("\n");
}

char *pesquisa_sinonimo(char *sin[][2], int tot_lin, char *p)
{

	for (int i = 0; i < tot_lin; i++)
	{
		
		if(!stricmp(p, sin[i][0]))
		{
			return sin[i][1];

		} else if(!stricmp(p, sin[i][1]))
		{
			return sin[i][0];

		}
	}

	return NULL;
}

void detetarSinonimosFrase(char *sin[][2], int tot_lin){

	char frase[500], *p;

	printf("\nFrase a pesquisar: ");
	scanf(" %[^\n]", frase);

	char delim[] = " ";

	char *palavra = strtok(frase, delim);

	while (palavra != NULL)
	{
		p = pesquisa_sinonimo(sin, N, palavra);

		if(p != NULL)
			printf("A palavra %s e sinonimo de %s\n", p, palavra);

		palavra = strtok(NULL, delim);
	}
	printf("\n");
}

int contarPalavrasRepetidas(char *sin[][2], int tot_lin)
{

	int repetidas = 0;
	
	for (int i = 0; i < tot_lin*2; i++)
	{
		for (int j = i+1; j < (tot_lin*2); j++)
		{
			if (!strcmp(*(*(sin)+i), *(*(sin)+j)))
			{
				repetidas++;
			}
		}
	}
	return repetidas;
}

int main()
{
	char palavra[50], *p;
	int repetidas = 0;
	
	char *s[N][2] = {{"estranho", "bizarro"},
					 {"desconfiar", "suspeitar"},
					 {"vermelho", "encarnado"},
					 {"duvidar", "desconfiar"},
					 {"carro", "automovel"}};	

	
	escreve_sin(s, N);		// alinea 22.1
	
	printf("Palavra a pesquisar: ");
	scanf(" %s", palavra);
	
	p = pesquisa_sinonimo(s, N, palavra); // alinea 22.2
	
	if(p == NULL)
		printf("A palavra %s nao tem sinonimo conhecido\n", palavra);
	else
		printf("A palavra %s e sinonimo de %s\n", p, palavra);
	
	detetarSinonimosFrase(s, N);

	repetidas = contarPalavrasRepetidas(s, N);

	printf("Repetem-se %d palavras.\n", repetidas);

	return 0;
}