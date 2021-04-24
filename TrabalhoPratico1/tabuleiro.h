#ifndef TABULEIRO_H_INCLUDED
#define TABULEIRO_H_INCLUDED

struct Tabuleiro {

    char *tabuleiro;
    int nLinhas;
    int nColunas;
};

typedef struct Tabuleiro tabuleiro;

tabuleiro inicializarTabuleiro();
void mostraTabuleiro(tabuleiro tab);

#endif // TABULEIRO_H_INCLUDED
