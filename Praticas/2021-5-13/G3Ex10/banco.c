#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banco.h"

void mostra_ficheiro(char *nome)
{
    FILE *in;
    Cliente tmp;

    if((in = fopen(nome, "rb")) != NULL)
	{
        while (fread(&tmp, sizeof(Cliente), 1, in) == 1)
            printf("Nome: %s\nConta: %d\tMontante: %d\n", tmp.nome, tmp.conta, tmp.montante);
        fclose(in);
    }
	else printf("Erro ao abrir o ficheiro %s para leitura\n", nome);
}

void conta_bytes_clientes(char *nome)
{
    int n;
    FILE *in;

    if ((in=fopen(nome,"rb"))==NULL){
                printf("Ficheiro nao existe\n");
               // exit(1); //exit(EXIT_FAILURE);
                exit(EXIT_FAILURE);
    }
    fseek(in, 0, SEEK_END);     /* vai para o fim */
    n = ftell(in);
    printf("Bytes: %d; Clientes: %d\n", n, n/sizeof(Cliente));
    fclose(in);
}

void mostra_ficheiro_invertido(char* nome){
    FILE *in;
    Cliente tmp;
    int n, i;

    if((in = fopen(nome,"rb"))!= NULL){

    fseek(in, 0, SEEK_END); //vai para o fim
    n=ftell(in)/sizeof(Cliente); //determina o número de clientes

    for(i=0; i<n; i++){

        fseek(in, -sizeof(Cliente), SEEK_CUR); //posiciona no início do cliente que vai ser lido
        if (fread(&tmp,sizeof(Cliente), 1, in) == 1) //posiciona no final do último cliente
            printf("Nome %s\t Conta %d\tMontante: %d\n",tmp.nome,tmp.conta,tmp.montante); //mostra
            fseek(in, -sizeof(Cliente), SEEK_CUR);//reposiciona no início do último cliente
    }
     fclose(in);
    }
}

int atualizaSaldo(char *nome, char *nome_cliente, int valor)
{
    FILE *f;
    Cliente c;
    f = fopen(nome, "rb+");
    if(f == NULL)
        return 0;
    while(fread(&c, sizeof(Cliente), 1, f) == 1)
    {
        if(strcmp(c.nome, nome_cliente) == 0)
        {
            c.montante += valor;
            if(c.montante < 0)
                return 0;
            fseek(f, -sizeof(Cliente), SEEK_CUR); //o fread posicionou no final do cliente pretendido, por isso tenho de reposicionar no início
            fwrite(&c, sizeof(Cliente), 1, f);
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}

int transfere(char *nomeF, char *or, char *dest, int valor)
{
    FILE *f;

    f = fopen(nomeF, "rb+");
    if(f == NULL)
        return 0;
    if(atualizaSaldo(nomeF, or, -valor))
    {
        if(atualizaSaldo(nomeF, dest, valor))
        {
            fclose(f);
            return 1;
        }

        else
            atualizaSaldo(nomeF, or, valor);
    }

    fclose(f);
    return 0;
}


void elimina_cliente(char *nomeF, char *nomeC)
{
    FILE *in, *out;
    Cliente tmp;

    if((in = fopen(nomeF, "rb")) != NULL)
	{
        if((out= fopen("temporario", "wb")) != NULL)
		{
			while(fread(&tmp, sizeof(Cliente), 1, in))
			{
				if(strcmp(tmp.nome, nomeC) != 0)
                    fwrite(&tmp, sizeof(Cliente), 1, out);
			}

            fclose(in);
            fclose(out);
           	remove(nomeF);
			rename("temporario", nomeF);
        }
		else
		{
			fclose(in);
			printf("Erro ao abrir o ficheiro temporario para escrita\n");
        }
    }
	else printf("Erro ao abrir o ficheiro %s para leitura\n", nomeF);
}

void adiciona_cliente(char *nome, Cliente novo)
{
    FILE *in, *out;
    Cliente tmp;
	int done = 0;

    if((in = fopen(nome, "rb")) != NULL)
	{
        if((out= fopen("temporario", "wb")) != NULL)
		{
			while(fread(&tmp, sizeof(Cliente), 1, in))
			{
				if(done==0 && strcmp(tmp.nome, novo.nome) >= 0)
				{
					fwrite(&novo, sizeof(Cliente), 1, out);
					done = 1;
				}
				fwrite(&tmp, sizeof(Cliente), 1, out);
			}
			if(done==0)
				fwrite(&novo, sizeof(Cliente), 1, out); //caso seja para inserir no final (nunca cumpriu strcmp(tmp.nome, novo.nome) >= 0)
            fclose(in);
            fclose(out);
           	remove(nome);
			rename("temporario", nome);
        }
		else
		{
			fclose(in);
			printf("Erro ao abrir o ficheiro temporario para escrita\n");
        }
    }
	else printf("Erro ao abrir o ficheiro %s para leitura\n", nome);
}

void junta_tudo(char *nome1, char *nome2, char *dest)
{
    FILE *in1, *in2, *out;
    Cliente tmp1, tmp2;
	int v1, v2;

    if((in1 = fopen(nome1, "rb")))
	{
        if((in2 = fopen(nome2, "rb")))
		{
            if ((out = fopen(dest, "wb")))
			{
                v1=fread(&tmp1, sizeof(Cliente), 1, in1);
                v2=fread(&tmp2, sizeof(Cliente), 1, in2);

                while (v1==1 && v2==1)
				{
                    if (strcmp(tmp1.nome, tmp2.nome) < 0)
					{
                        fwrite(&tmp1, sizeof(Cliente), 1, out);
                        v1=fread(&tmp1, sizeof(Cliente), 1, in1);
                    }
					else if(strcmp(tmp1.nome, tmp2.nome) > 0)
					{
                        fwrite(&tmp2, sizeof(Cliente), 1, out);
                        v2=fread(&tmp2, sizeof(Cliente), 1, in2);
                    }
					else
					{
                        tmp1.montante += tmp2.montante;
                        fwrite(&tmp1, sizeof(Cliente), 1, out);
                        v1=fread(&tmp1, sizeof(Cliente), 1, in1);
                        v2=fread(&tmp2, sizeof(Cliente), 1, in2);
                    }
                }
                while (v1==1)
				{
                    fwrite(&tmp1, sizeof(Cliente), 1, out);
                    v1=fread(&tmp1, sizeof(Cliente), 1, in1);
                }
                while (v2==1)
				{
                    fwrite(&tmp2, sizeof(Cliente), 1, out);
                    v2=fread(&tmp2, sizeof(Cliente), 1, in2);
                }
                fclose(in1);
                fclose(in2);
                fclose(out);
            }
			else
			{
				fclose(in1);
                fclose(in2);
                printf("Erro ao abrir o ficheiro %s para escrita\n", dest);
            }
        }
		else
		{
			fclose(in1);
			printf("Erro ao abrir o ficheiro %s para leitura\n", nome2);
        }
    }
	else
		printf("Erro ao abrir o ficheiro %s para leitura\n", nome1);
}


