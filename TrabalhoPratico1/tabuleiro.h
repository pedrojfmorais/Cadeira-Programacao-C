#ifndef TABULEIRO_H_INCLUDED
#define TABULEIRO_H_INCLUDED

#include "jogadores.h"

struct Tabuleiro {

    char **tabuleiro;
    int nLinhas;
    int nColunas;
};

typedef struct Tabuleiro tabuleiro;

tabuleiro inicializarTabuleiro();
void mostraTabuleiro(tabuleiro tab);
void pedeCoordenadas(tabuleiro tab, int *linha, int *coluna);

int verificaPeca(tabuleiro tab, jogadores *jogador, int linha, int coluna, char pecaColocar);
tabuleiro aumentaLinhas(tabuleiro tab, jogadores *jogador, int *checkJogada);
tabuleiro aumentaColunas(tabuleiro tab, jogadores *jogador, int *checkJogada);

tabuleiro copiarTabuleiro(tabuleiro tabRecebido);

int verificaVitoria(tabuleiro tab);
void declararVitoria(char idJogador);
#endif // TABULEIRO_H_INCLUDED
