#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menus.h"
#include "jogadores.h"
#include "tabuleiro.h"
#include "tipoJogo.h"


int main()
{

    int opcao;

    initRandom();

    printf("\n\n --------- Bem vindo ao Jogo do Semaforo ---------\n\n\n");
    printf("Escolha um tipo de jogo: \n\n");
    menuPrincipal();

    do{

        printf("Insira uma opcao: ");
        scanf(" %d", &opcao);

    }while(opcao < 0 || opcao > 2 && opcao != 9);

    printf("\n");

    switch(opcao)
    {
        case 0:
            lerJogoGuardado();
            //continuar jogo
            break;
        case 1:
            // 1 jogador
            break;
        case 2:
            doisJogadores(0, inicializarJogador('A'), inicializarJogador('B'), inicializarTabuleiro(), NULL);
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
