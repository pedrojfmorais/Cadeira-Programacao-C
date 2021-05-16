#ifndef REGISTOJOGADAS_H_INCLUDED
#define REGISTOJOGADAS_H_INCLUDED

#include "tabuleiro.h"

typedef struct Jogada jogada, *ponteiroJogadas;

struct Jogada{

    tabuleiro tab;
    char jogador;
    int nJogada;
    int linhaAfetada;
    int colunaAfetada;
    char infoJogada[100];
    jogada *next;

};

ponteiroJogadas adicionarJogada(ponteiroJogadas listaJogadas, tabuleiro tab, char idJogador, int nJogada, int linha, int coluna, char infoJogada[]);
void mostrarJogada(ponteiroJogadas listaJogadas);
int escreveJogadasFicheiro(char *nomeFicheiro, ponteiroJogadas listaJogadas);

#endif // REGISTOJOGADAS_H_INCLUDED
