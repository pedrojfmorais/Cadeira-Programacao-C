#ifndef REGISTOJOGADAS_H_INCLUDED
#define REGISTOJOGADAS_H_INCLUDED

#include "tabuleiro.h"

struct Jogada{

    tabuleiro tab;
    char jogador;
    int nJogada;
    int linhaAfetada;
    int colunaAfetada;
    char infoJogada[100];

};

typedef struct Jogada jogada;

jogada *adicionarJogada(jogada *arrayJogadas, tabuleiro tab, char idJogador, int nJogada, int linha, int coluna, char infoJogada[]);
void mostrarJogada(jogada *arrayJogadas, int index);

#endif // REGISTOJOGADAS_H_INCLUDED
