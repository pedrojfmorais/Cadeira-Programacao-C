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
void pedeCoordenadas(tabuleiro tab, int *linha, int *coluna);
int verificaPecaVerde(tabuleiro tab, int linha, int coluna);
tabuleiro copiarTabuleiro(tabuleiro tabRecebido);

int verificaVitoria(tabuleiro tab);
void declararVitoria(char idJogador);
#endif // TABULEIRO_H_INCLUDED
