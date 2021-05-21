#include <stdio.h>
#include <stdlib.h>

#include "jogadores.h"
#include "tabuleiro.h"
#include "registoJogadas.h"

int interromperJogo(int tipoJogo, int numJogadas, jogadores jogadorA, jogadores jogadorB, tabuleiro tab, ponteiroJogadas listaJogadas)
{

    ponteiroJogadas aux = listaJogadas;
    FILE *f = fopen("jogo.bin", "wb");

    if (f == NULL)
    {
        printf("Erro ao aceder ao ficheiro! \n");
        return 1;
    }

    fwrite(&tipoJogo, sizeof(int), 1, f);
    fwrite(&numJogadas, sizeof(int), 1, f);

    //jogadores
    fwrite(&jogadorA, sizeof(jogadores), 1, f);
    fwrite(&jogadorB, sizeof(jogadores), 1, f);

    //escreve tabuleiro

    fwrite(&tab.nLinhas, sizeof(int), 1, f);
    fwrite(&tab.nColunas, sizeof(int), 1, f);

    for(int i = 0; i < tab.nLinhas; i++)
    {
        fwrite(tab.tabuleiro[i], sizeof(char)*tab.nColunas, 1, f);
    }

    for(int i = 0; i < numJogadas; i++)
    {
        fwrite(&aux->jogador, sizeof(char), 1, f);
        fwrite(&aux->nJogada, sizeof(int), 1, f);
        fwrite(&aux->linhaAfetada, sizeof(int), 1, f);
        fwrite(&aux->colunaAfetada, sizeof(int), 1, f);
        fwrite(&aux->infoJogada, sizeof(char), 100, f);

        fwrite(&aux->tab.nLinhas, sizeof(int), 1, f);
        fwrite(&aux->tab.nColunas, sizeof(int), 1, f);

        for(int j = 0; j < aux->tab.nLinhas; j++)
        {
            fwrite(aux->tab.tabuleiro[j], sizeof(char)*aux->tab.nColunas, 1, f);
        }

        aux = aux->next;

    }

    fclose(f);

    printf("\n\n O seu jogo foi guardado, volte mais tarde para continuar. \n\n");

    libertarMemoria(listaJogadas, &tab);

    exit(0);
}

void lerJogoGuardado()
{
    int tipoJogo;
    int numJogadas;
    jogadores jogadorA;
    jogadores jogadorB;
    tabuleiro tab;
    ponteiroJogadas listaJogadas = NULL;

    FILE *f;
    f = fopen("jogo.bin", "rb");

    if (f == NULL)
    {
        printf("Erro ao aceder ao ficheiro! \n");
        return 1;
    }

    fread(&tipoJogo, sizeof(int), 1, f);
    fread(&numJogadas, sizeof(int), 1, f);

    //jogadores
    fread(&jogadorA, sizeof(jogadores), 1, f);
    fread(&jogadorB, sizeof(jogadores), 1, f);

    //tabuleiro
    fread(&tab.nLinhas, sizeof(int), 1, f);
    fread(&tab.nColunas, sizeof(int), 1, f);

    tab.tabuleiro = (char**)malloc(sizeof(char*)*tab.nLinhas);

    if(tab.tabuleiro == NULL)
    {
        printf("Ocorreu um erro a alocar memória!");
        return;
    }

    for(int i = 0; i < tab.nLinhas; i++)
    {
        tab.tabuleiro[i] = (char*)malloc(sizeof(char)* tab.nColunas);

        if(tab.tabuleiro[i] == NULL)
        {
            printf("Ocorreu um erro a alocar memória!");
            return;
        }

        fread(tab.tabuleiro[i], sizeof(char)*tab.nColunas, 1, f);
    }

    for(int i = 0; i < numJogadas; i++)
    {

        jogada aux;

        fread(&aux.jogador, sizeof(char), 1, f);
        fread(&aux.nJogada, sizeof(int), 1, f);
        fread(&aux.linhaAfetada, sizeof(int), 1, f);
        fread(&aux.colunaAfetada, sizeof(int), 1, f);
        fread(&aux.infoJogada, sizeof(char), 100, f);

        fread(&aux.tab.nLinhas, sizeof(int), 1, f);
        fread(&aux.tab.nColunas, sizeof(int), 1, f);

        aux.tab.tabuleiro = (char**)malloc(sizeof(char*)*aux.tab.nLinhas);

        if(aux.tab.tabuleiro == NULL)
        {
            printf("Ocorreu um erro a alocar memória!");
            return;
        }

        for(int j = 0; j < aux.tab.nLinhas; j++)
        {
            aux.tab.tabuleiro[j] = (char*)malloc(sizeof(char)* aux.tab.nColunas);

            if(aux.tab.tabuleiro[j] == NULL)
            {
                printf("Ocorreu um erro a alocar memória!");
                return;
            }

            fread(aux.tab.tabuleiro[j], sizeof(char)*aux.tab.nColunas, 1, f);
        }

        aux.next = NULL;

        listaJogadas = adicionarJogada(listaJogadas, aux.tab, aux.jogador, aux.nJogada-1, aux.linhaAfetada, aux.colunaAfetada, aux.infoJogada);
    }

    fclose(f);
    remove("jogo.bin");

    if(tipoJogo == 1)
    {
        printf("\n\n\n\n------------- A retomar UM JOGADORES -------------\n\n\n\n");
        //umJogador(numJogadas, jogadorA, jogadorB, tab, listaJogadas);
    }
    else if(tipoJogo == 2)
    {
        printf("\n\n\n\n------------ A retomar DOIS JOGADORES ------------\n\n\n\n");
        doisJogadores(numJogadas, jogadorA, jogadorB, tab, listaJogadas);
    }
}
