#ifndef JOGADORES_H_INCLUDED
#define JOGADORES_H_INCLUDED

struct dadosJogadores{

    char identificacao;
    int pedra;
    int aumentarTabuleiro;

};

typedef struct dadosJogadores jogadores;

jogadores inicializarJogador(char identificacao);
void mostraJogador(jogadores jogador);

#endif // JOGADORES_H_INCLUDED
