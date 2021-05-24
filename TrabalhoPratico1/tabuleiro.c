#include <stdio.h>
#include <stdlib.h>

#include "tabuleiro.h"

#include "utils.h"

tabuleiro inicializarTabuleiro()
{

    tabuleiro tab;
    int tam = intUniformRnd(3,5);

    //cria array dinamico com 'tam' numero de linhas
    tab.tabuleiro = (char**)malloc(sizeof(char*)*tam);

    if(tab.tabuleiro == NULL)
    {
        printf("Ocorreu um erro a alocar memória!");
        return;
    }

    //para cada linha cria 'tam' numero de colunas
    for (int i=0; i<tam; i++)
    {
        tab.tabuleiro[i] = (char*)malloc(sizeof(char)* tam );
        if(tab.tabuleiro[i] == NULL)
        {
            printf("Erro na alocacao de memoria");
            free(tab.tabuleiro);
            return;
        }

        //inicializar o tabuleiro
        for (int j = 0; j < tam; j++)
        {
            tab.tabuleiro[i][j] = ' ';
        }

    }

    tab.nLinhas = tam;
    tab.nColunas = tam;

    return tab;
}

void mostraTabuleiro(tabuleiro tab)
{
    printf("  ");
    for(int i = 0; i < tab.nColunas;i++)
        printf(" %d", i+1);

    for(int i = 0; i < tab.nLinhas; i++)
    {
        printf("\n%d |", i+1);

        for(int j = 0; j < tab.nColunas; j++)
        {
            printf("%c|", tab.tabuleiro[i][j]);
        }
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

int verificaPeca(tabuleiro tab, int linha, int coluna, char pecaColocar)
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

    if(tab.tabuleiro[linha][coluna] != pecaRequerida)
    {
        return 1;
    }

    tab.tabuleiro[linha][coluna] = pecaColocar;

    return 0;
}

tabuleiro aumentaLinhas(tabuleiro tab, int *checkJogada)
{
    tabuleiro aux;

    aux.nLinhas = tab.nLinhas+1;
    aux.nColunas = tab.nColunas;

    aux.tabuleiro = (char**)realloc(tab.tabuleiro, sizeof(char*)*aux.nLinhas);

    if(aux.tabuleiro == NULL)
    {
        printf("Ocorreu um erro a alocar memória!");
        *checkJogada = 1;
        return tab;
    }

    aux.tabuleiro[aux.nLinhas-1] = (char*)malloc(sizeof(char)* aux.nColunas);

    if(aux.tabuleiro[aux.nLinhas-1] == NULL)
    {
        printf("Erro na alocacao de memoria");
        *checkJogada = 1;
        return tab;
    }

    for (int j = 0; j < aux.nColunas; j++)
    {
        aux.tabuleiro[aux.nLinhas-1][j] = ' ';
    }

    *checkJogada = 0;
    return aux;
}

tabuleiro aumentaColunas(tabuleiro tab, int *checkJogada)
{
    tabuleiro aux;

    aux.nLinhas = tab.nLinhas;
    aux.nColunas = tab.nColunas+1;

    aux.tabuleiro = (char**)realloc(tab.tabuleiro, sizeof(char*)*aux.nLinhas);

    if(aux.tabuleiro == NULL)
    {
        printf("Ocorreu um erro a alocar memória!");
        *checkJogada = 1;
        return tab;
    }

    for(int i = 0; i < aux.nLinhas; i++)
    {
        aux.tabuleiro[i] = (char*)realloc(aux.tabuleiro[i], sizeof(char)* aux.nColunas);

        if(aux.tabuleiro[i] == NULL)
        {
            printf("Erro na alocacao de memoria");
            *checkJogada = 1;
            return tab;
        }

        aux.tabuleiro[i][aux.nColunas-1] = ' ';
    }

    *checkJogada = 0;
    return aux;
}

tabuleiro copiarTabuleiro(tabuleiro tabRecebido)
{

    tabuleiro tab;

    tab.tabuleiro = (char**)malloc(sizeof(char*)*tabRecebido.nLinhas);

    if(tab.tabuleiro == NULL)
    {
        printf("Ocorreu um erro a alocar memória!");
        return;
    }

    for (int i=0; i<tabRecebido.nLinhas; i++)
    {
        tab.tabuleiro[i] = (char*)malloc(sizeof(char)*tabRecebido.nColunas);
        if(tab.tabuleiro[i] == NULL)
        {
            printf("Erro na alocacao de memoria");
            free(tab.tabuleiro);
            return;
        }

        for (int j = 0; j < tabRecebido.nColunas; j++)
        {
            tab.tabuleiro[i][j] = tabRecebido.tabuleiro[i][j];
        }

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

        if(tab.tabuleiro[i][0] == ' ')
            continue;

        for(int j = 0; j < tab.nColunas; j++)
        {
            if(tab.tabuleiro[i][j] == tab.tabuleiro[i][0] && tab.tabuleiro[i][j] != ' ')
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

        if(tab.tabuleiro[0][i] == ' ')
            continue;

        for(int j = 0; j < tab.nLinhas; j++)
        {

            if(tab.tabuleiro[j][i] == tab.tabuleiro[0][i] && tab.tabuleiro[j][i] != ' ')
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
    if(tab.nLinhas == tab.nColunas)
    {

        verifica = 0;

        for(int i = 0; i < tab.nLinhas; i++)
        {

            if(tab.tabuleiro[i][i] == tab.tabuleiro[0][0] && tab.tabuleiro[i][i] != ' ')
            {
                verifica++;
            }else
            {
                break;
            }
        }

        if(verifica == tab.nLinhas)
            return 1;

        verifica = 0;

        for(int i = 0, j = tab.nLinhas-1; i < tab.nLinhas; i++, j--)
        {

            if(tab.tabuleiro[i][j] == tab.tabuleiro[tab.nLinhas-1][0] && tab.tabuleiro[i][j] != ' ')
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

    return 0;
}

void declararVitoria(char idJogador)
{

    printf("\n\n\n\n\nO jogador %c ganhou o jogo.\n\n\n", idJogador);
}
