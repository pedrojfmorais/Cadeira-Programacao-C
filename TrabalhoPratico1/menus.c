#include <stdio.h>
#include "jogadores.h"

//função que mostra o menu principal
void menuPrincipal()
{
    //verifica se o ficheiro "jogo.bin" existe
    FILE *f;

    f = fopen("jogo.bin", "rb");

    //se este existir mostra a opção de continuar jogo
    if (f != NULL)
    {
        printf(" '0' - Continuar Jogo\n");
    }
    fclose(f);

    //mostra as restantes opções
    printf(" '1' - 1 Jogador\n");
    printf(" '2' - 2 Jogadores\n");
    printf(" '9' - Sair\n\n");
}

//mostra as opções do utilizador durante o decorrer do jogo
//recebe uma estrutura jogador para mostrar nas opções quantas pedras este tem restantes e quantas linhas e colunas pode adicionar
void menuJogadas(jogadores jogador)
{

    printf(" '1' - Colocar peca Verde (G)\n");
    printf(" '2' - Colocar peca Amarela (Y)\n");
    printf(" '3' - Colocar peca Vermelha (R)\n");
    printf(" '4' - Colocar Pedra (P) (Restantes: %d)\n", jogador.pedra);
    printf(" '5' - Adicionar Linha ao tabuleiro (Restantes: %d)\n", jogador.aumentarTabuleiro);
    printf(" '6' - Adicionar Coluna ao tabuleiro (Restantes: %d)\n", jogador.aumentarTabuleiro);
    printf(" '7' - Ver jogadas anteriores\n");
    printf(" '9' - Interromper Jogo\n");
    printf(" '0' - Desistir\n\n");
}
