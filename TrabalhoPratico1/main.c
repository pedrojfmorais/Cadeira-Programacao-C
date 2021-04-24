#include <stdio.h>
#include <stdlib.h>

#include "menus.h"
#include "jogadores.h"
#include "tabuleiro.h"

void umJogador()
{

}

void doisJogadores()
{
    int numJogadas = 0;
    int checkJogada = 0;
    char opcao;

    jogadores jogadorA = inicializarJogador('A');
    jogadores jogadorB = inicializarJogador('B');

    jogadores arrayJogadores[2] = {jogadorA,jogadorB};

    tabuleiro tab = inicializarTabuleiro();

    int linha, coluna;

    while(numJogadas < 10)
    {
        printf("\n\n--------------------------------------------------\n");
        printf("Jogador %c.\n\n", arrayJogadores[numJogadas%2].identificacao);

        mostraTabuleiro(tab);
        menuJogadas();
        printf("--------------------------------------------------\n");
        do{

            printf("Escolha uma jogada: ");
            scanf("%d", &opcao);
        }while(opcao < 0 || opcao > 7 && opcao != 9);

        switch(opcao)
        {
            case 1:
                pedeCoordenadas(tab,&linha,&coluna);
                checkJogada = verificaPeca(tab,arrayJogadores[numJogadas%2],linha,coluna,'G');
                break;

            case 2:
                pedeCoordenadas(tab,&linha,&coluna);
                checkJogada = verificaPeca(tab,arrayJogadores[numJogadas%2],linha,coluna,'Y');
                break;

            case 3:
                pedeCoordenadas(tab,&linha,&coluna);
                checkJogada = verificaPeca(tab,arrayJogadores[numJogadas%2],linha,coluna,'R');
                break;

            case 4:
                if(arrayJogadores[numJogadas%2].pedra == 0)
                {
                    printf("\nEste jogador esgotou as Pedras.\n");
                    checkJogada = 1;
                    break;
                }
                pedeCoordenadas(tab,&linha,&coluna);
                checkJogada = verificaPeca(tab,&arrayJogadores[numJogadas%2],linha,coluna,'P');
                break;

            case 5:
                break;

            case 6:
                break;

            case 7:
                break;

            case 9:
                break;

            case 0:
                break;

            default:
                printf("Ocorreu  um erro, tente novamente!\n");
                break;

        }
        if(checkJogada == 0)
            numJogadas++;

    }
}

int main()
{

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
            doisJogadores();
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
