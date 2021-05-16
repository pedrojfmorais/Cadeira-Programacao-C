#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "registoJogadas.h"
#include "jogadores.h"
#include "tabuleiro.h"

ponteiroJogadas adicionarJogada(ponteiroJogadas listaJogadas, tabuleiro tab, char idJogador, int nJogada, int linha, int coluna, char infoJogada[])
{

    ponteiroJogadas nova, aux;

    nova = malloc(sizeof(jogada));

    if (nova == NULL)
    {
        printf("Erro na realocacao!\n");
        return listaJogadas;
    }

    nova->tab = copiarTabuleiro(tab);
    nova->jogador = idJogador;
    nova->nJogada = nJogada+1;
    nova->linhaAfetada = linha;
    nova->colunaAfetada = coluna;
    strcpy(nova->infoJogada,infoJogada);
    nova->next = NULL;

    if(listaJogadas == NULL)
    {
        listaJogadas = nova;
    } else
    {
        aux = listaJogadas;

        while(aux->next != NULL)
        {
            aux = aux->next;
        }

        aux->next = nova;
    }

    return listaJogadas;
}

void mostrarJogada(ponteiroJogadas listaJogadas)
{

    printf("-------------------- Jogada %d --------------------\n", listaJogadas->nJogada);
    mostraTabuleiro(listaJogadas->tab);
    printf("Jogador %c\n", listaJogadas->jogador);
    printf("Jogada numero %d\n", listaJogadas->nJogada);
    printf("Linha %d, Coluna %d\n", listaJogadas->linhaAfetada, listaJogadas->colunaAfetada);
    printf("%s", listaJogadas->infoJogada);
    printf("--------------------------------------------------\n\n");

}


int escreveJogadasFicheiro(char *nomeFicheiro, ponteiroJogadas listaJogadas)
{

    FILE *f = fopen(nomeFicheiro, "w");

    if(f == NULL)
    {
        fclose(f);
        return 1;
    }

    while(listaJogadas != NULL)
    {

        char linhaTabela[99], auxTexto[99];
        fprintf(f,"-------------------- Jogada %d --------------------\n", listaJogadas->nJogada);

        strcpy(linhaTabela, "  ");

        for(int i = 0; i < listaJogadas->tab.nColunas;i++)
        {
            sprintf(auxTexto, " %d", i+1);
            strcat(linhaTabela, auxTexto);
        }
        fprintf(f,"%s", linhaTabela);

        for(int i = 0; i < listaJogadas->tab.nLinhas; i++)
        {
            sprintf(auxTexto, "\n%d |", i+1);
            strcpy(linhaTabela, auxTexto);

            for(int j = 0; j < listaJogadas->tab.nColunas; j++)
            {
                sprintf(auxTexto, "%c|", listaJogadas->tab.tabuleiro[i][j]);
                strcat(linhaTabela, auxTexto);
            }
            fprintf(f,"%s", linhaTabela);
        }
        fprintf(f,"\n\n", linhaTabela);

        fprintf(f,"Jogador %c\n", listaJogadas->jogador);
        fprintf(f,"Jogada numero %d\n", listaJogadas->nJogada);
        fprintf(f,"Linha %d, Coluna %d\n", listaJogadas->linhaAfetada, listaJogadas->colunaAfetada);
        fprintf(f,"%s", listaJogadas->infoJogada);
        fprintf(f,"--------------------------------------------------\n\n");

        listaJogadas = listaJogadas->next;

    }

    fclose(f);

    return 0;
}
