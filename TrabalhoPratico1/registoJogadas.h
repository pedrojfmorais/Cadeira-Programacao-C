#ifndef REGISTOJOGADAS_H_INCLUDED
#define REGISTOJOGADAS_H_INCLUDED

#include "tabuleiro.h"

typedef struct Jogada jogada;

struct Jogada{

    tabuleiro tab;
    char jogador;
    int nJogada;
    int linhaAfetada;
    int colunaAfetada;
    char infoJogada[100];
    jogada *next;

};

jogada *adicionarJogada(jogada *arrayJogadas, tabuleiro tab, char idJogador, int nJogada, int linha, int coluna, char infoJogada[]);
void mostrarJogada(jogada *arrayJogadas, int index);

#endif // REGISTOJOGADAS_H_INCLUDED
