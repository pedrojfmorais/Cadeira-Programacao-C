#ifndef TIPOJOGO_H_INCLUDED
#define TIPOJOGO_H_INCLUDED

#include "menus.h"
#include "jogadores.h"
#include "tabuleiro.h"
#include "registoJogadas.h"
#include "interromperJogo.h"

void umJogador();
void doisJogadores(int numJogadas, jogadores jogadorA, jogadores jogadorB, tabuleiro tab, ponteiroJogadas listaJogadas);
void terminarJogo(ponteiroJogadas listaJogadas, tabuleiro *tab);
void libertarMemoria(ponteiroJogadas listaJogadas, tabuleiro *tab);

#endif // TIPOJOGO_H_INCLUDED
