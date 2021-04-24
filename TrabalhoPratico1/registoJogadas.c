#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "registoJogadas.h"
#include "jogadores.h"
#include "tabuleiro.h"

jogada *adicionarJogada(jogada *arrayJogadas, tabuleiro tab, char idJogador, int nJogada, int linha, int coluna, char infoJogada[])
{

    jogada *aux;

    aux = realloc(arrayJogadas, sizeof(jogada)*(nJogada+1));

    if (aux == NULL)
    {
        printf("Erro na realocacao!\n");
        return arrayJogadas;
    }

    arrayJogadas = aux;

    arrayJogadas[nJogada].tab = copiarTabuleiro(tab);
    arrayJogadas[nJogada].jogador = idJogador;
    arrayJogadas[nJogada].nJogada = nJogada+1;
    arrayJogadas[nJogada].linhaAfetada = linha;
    arrayJogadas[nJogada].colunaAfetada = coluna;
    strcpy(arrayJogadas[nJogada].infoJogada,infoJogada);

    return arrayJogadas;
}

void mostrarJogada(jogada *arrayJogadas, int index)
{

    printf("-------------------- Jogada %d --------------------\n", arrayJogadas[index].nJogada);
    mostraTabuleiro(arrayJogadas[index].tab);
    printf("Jogador %c\n", arrayJogadas[index].jogador);
    printf("Jogada numero %d\n", arrayJogadas[index].nJogada);
    printf("Linha %d, Coluna %d\n", arrayJogadas[index].linhaAfetada, arrayJogadas[index].colunaAfetada);
    printf("%s", arrayJogadas[index].infoJogada);
    printf("--------------------------------------------------\n\n");

}
