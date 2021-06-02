#ifndef TIPOJOGO_H_INCLUDED
#define TIPOJOGO_H_INCLUDED

#include "menus.h"
#include "jogadores.h"
#include "tabuleiro.h"
#include "registoJogadas.h"
#include "interromperJogo.h"

//declara as funções criadas no ficheiro "tipoJogo.c"
void umJogador(int numJogadas, jogadores jogadorA, jogadores jogadorB, tabuleiro tab, ponteiroJogadas listaJogadas);
void doisJogadores(int numJogadas, jogadores jogadorA, jogadores jogadorB, tabuleiro tab, ponteiroJogadas listaJogadas);
void switchJogadorHumano(int numJogadas, jogadores *arrayJogadores, tabuleiro *tab, ponteiroJogadas *listaJogadas, int opcao, int *checkJogada, int tipoJogo);
void terminarJogo(ponteiroJogadas listaJogadas, tabuleiro *tab);
void vitoriaJogo(int numJogadas, jogadores jogador, tabuleiro tab, ponteiroJogadas listaJogadas);
void libertarMemoria(ponteiroJogadas listaJogadas, tabuleiro *tab);

#endif // TIPOJOGO_H_INCLUDED
