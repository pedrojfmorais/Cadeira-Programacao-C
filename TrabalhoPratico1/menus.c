#include <stdio.h>

void menuPrincipal()
{
    FILE *f;

    f = fopen("jogo.bin", "rb");
    if (f != NULL)
    {
        printf(" '0' - Continuar Jogo\n");
    }
    fclose(f);

    printf(" '1' - 1 Jogador\n");
    printf(" '2' - 2 Jogadores\n");
    printf(" '9' - Sair\n\n");
}

void menuJogadas()
{

    printf(" '1' - Colocar peca Verde (G)\n");
    printf(" '2' - Colocar peca Amarela (Y)\n");
    printf(" '3' - Colocar peca Vermelha (R)\n");
    printf(" '4' - Colocar Pedra (P)\n");
    printf(" '5' - Adicionar Linha ao tabuleiro\n");
    printf(" '6' - Adicionar Coluna ao tabuleiro\n");
    printf(" '7' - Ver jogadas anteriores\n");
    printf(" '9' - Interromper Jogo\n");
    printf(" '0' - Desistir\n\n");
}
