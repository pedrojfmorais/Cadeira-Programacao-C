#include <stdio.h>
#include <stdlib.h>

#include "menus.h"
#include "jogadores.h"
#include "tabuleiro.h"

int main()
{
    jogadores jogadorA = inicializarJogador('A');
    jogadores jogadorB = inicializarJogador('B');

    int opcao;

    menuPrincipal();
    do{

        printf("Insira uma opcao: ");
        scanf(" %d", &opcao);

    }while(opcao < 0 || opcao > 2 && opcao != 9);

    printf("\n");

    switch(opcao)
    {
        case 0:
            //continuar jogo
            break;
        case 1:
            // 1 jogador
            break;
        case 2:
            // 2 jogadores
            break;
        case 9:
            printf("Obrigado por jogar.\n");
            return 0;
        default:
            printf("Ocorreu  um erro, tente novamente!\n");
            return 0;
    }

    return 0;
}
