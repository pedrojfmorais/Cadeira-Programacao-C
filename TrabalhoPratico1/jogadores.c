#include <stdio.h>
#include <stdlib.h>

#include "jogadores.h"

jogadores inicializarJogador(char identificacao)
{

    jogadores jogador;

    jogador.identificacao = identificacao;
    jogador.pedra = 1;
    jogador.aumentarTabuleiro = 2;

    return jogador;
}

void mostraJogador(jogadores jogador)
{

    printf("Este e o jogador %c: \n", jogador.identificacao);
    printf(" Pedras restantes: %d\n", jogador.pedra);
    printf(" Pode aumentar o tabuleiro %d vezes\n\n", jogador.aumentarTabuleiro);
}
