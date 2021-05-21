#ifndef INTERROMPERJOGO_H_INCLUDED
#define INTERROMPERJOGO_H_INCLUDED

#include "jogadores.h"
#include "tabuleiro.h"
#include "registoJogadas.h"

int interromperJogo(int tipoJogo, int numJogadas, jogadores jogadorA, jogadores jogadorB, tabuleiro tab, ponteiroJogadas listaJogadas);
void lerJogoGuardado();

#endif // INTERROMPERJOGO_H_INCLUDED
