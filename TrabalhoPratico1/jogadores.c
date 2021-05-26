#include <stdio.h>
#include <stdlib.h>

#include "jogadores.h"

//função que recebe a identificação de um jogador e o inicializa
jogadores inicializarJogador(char identificacao)
{
    //cria um novo objeto do tipo "jogadores"
    jogadores jogador;

    //guarda os dados do jogador na estrutura
    jogador.identificacao = identificacao;
    jogador.pedra = 1;
    jogador.aumentarTabuleiro = 2;

    //e devolve a estrutura
    return jogador;
}

//função que mostra os dados de um jogador
void mostraJogador(jogadores jogador)
{

    printf("Este e o jogador %c: \n", jogador.identificacao);
    printf(" Pedras restantes: %d\n", jogador.pedra);
    printf(" Pode aumentar o tabuleiro %d vezes\n\n", jogador.aumentarTabuleiro);
}
