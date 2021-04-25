#include <stdio.h>
#include <stdlib.h>

#include "tabuleiro.h"
#include "jogadores.h"

#include "utils.h"

tabuleiro inicializarTabuleiro()
{

    tabuleiro tab;
    int tam = intUniformRnd(3,5);

    tab.tabuleiro = malloc(sizeof(char)*tam*tam);

    if(tab.tabuleiro == NULL)
    {
        printf("Ocorreu um erro a alocar memória!");
        return;
    }

    tab.nLinhas = tam;
    tab.nColunas = tam;

    for(int i = 0; i < tam*tam; i++)
    {

        tab.tabuleiro[i] = ' ';
    }

    return tab;
}

void mostraTabuleiro(tabuleiro tab)
{
    printf("  ");
    for(int i = 0; i < tab.nColunas;i++)
        printf(" %d", i+1);

    for(int i = 0; i < tab.nLinhas*tab.nColunas; i++)
    {

        if(i%tab.nColunas == 0)
            printf("\n%d |", (i/tab.nColunas)+1);


        printf("%c|", tab.tabuleiro[i]);
    }
    printf("\n\n");
}

void pedeCoordenadas(tabuleiro tab, int *linha, int *coluna)
{

    do{
        printf("Linha: ");
        scanf("%d", linha);
    }while((*linha) < 1 || (*linha) > tab.nLinhas);


    do{
        printf("Coluna: ");
        scanf("%d", coluna);
    }while((*coluna) < 1 || (*coluna) > tab.nColunas);

}

int verificaPeca(tabuleiro tab, jogadores *jogador, int linha, int coluna, char pecaColocar)
{
    linha = linha-1;
    coluna = coluna-1;

    char pecaRequerida = ' ';

    switch(pecaColocar)
    {
        case 'P':
            //a peca requerida a estar no local para a Pedra e igual a da peca Verde
        case 'G':
            pecaRequerida = ' ';
            break;
        case 'Y':
            pecaRequerida = 'G';
            break;
        case 'R':
            pecaRequerida = 'Y';
            break;
        default:
            printf("Peca invalida, tente novamente!\n");
            return 1;
    }

    if(tab.tabuleiro[linha*tab.nColunas+coluna] != pecaRequerida)
    {
        printf("\n\nJogada Invalida!\n");
        return 1;
    }

    tab.tabuleiro[linha*tab.nColunas+coluna] = pecaColocar;

    if(pecaColocar = 'P')
        jogador->pedra--;

    return 0;
}

tabuleiro copiarTabuleiro(tabuleiro tabRecebido)
{

    tabuleiro tab;

    tab.tabuleiro = malloc(sizeof(char)*tabRecebido.nLinhas*tabRecebido.nColunas);

    if(tab.tabuleiro == NULL)
    {
        printf("Ocorreu um erro a alocar memória!");
        return;
    }

    for(int i = 0; i < tabRecebido.nLinhas*tabRecebido.nColunas; i++)
    {

        tab.tabuleiro[i] = tabRecebido.tabuleiro[i];
    }

    tab.nLinhas = tabRecebido.nLinhas;
    tab.nColunas = tabRecebido.nColunas;

    return tab;
}

int verificaVitoria(tabuleiro tab)
{
    int verifica;

    //verificação das linhas
    for(int i = 0; i < tab.nLinhas; i++)
    {
        verifica = 0;

        if(tab.tabuleiro[i*tab.nColunas] == ' ')
            continue;

        for(int j = i*tab.nColunas; j < i*tab.nColunas+tab.nColunas; j++)
        {
            if(tab.tabuleiro[i*tab.nColunas] == tab.tabuleiro[j] && tab.tabuleiro[i*tab.nColunas] != ' ')
            {
                verifica++;
            }else
            {
                break;
            }
        }
        if(verifica == tab.nColunas)
            return 1;
    }

    //verificação das colunas
    for(int i = 0; i < tab.nColunas; i++)
    {
        verifica = 0;

        if(tab.tabuleiro[i] == ' ')
            continue;

        for(int j = i; j <= i+((tab.nLinhas-1)*tab.nColunas); j+=tab.nColunas)
        {

            if(tab.tabuleiro[i] == tab.tabuleiro[j] && tab.tabuleiro[i] != ' ')
            {
                verifica++;
            }else
            {
                break;
            }
        }
        if(verifica == tab.nLinhas)
            return 1;
    }

    //verificação diagonais
    return 0;
}

void declararVitoria(char idJogador)
{

    printf("\n\n\n\n\nO jogador %c ganhou o jogo.\n\n\n\n\n", idJogador);
}
