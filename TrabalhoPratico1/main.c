#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menus.h"
#include "jogadores.h"
#include "tabuleiro.h"
#include "registoJogadas.h"

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

    jogada *arrayJogadas = NULL;
    char infoJogada[100];
    int nJogadasAnteriores = 0;

    int vitoria = 0;

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

                //registo de jogadas
                sprintf(infoJogada, "Peca Verde na linha %d, coluna %d pelo jogador %c.\n", linha, coluna, arrayJogadores[numJogadas%2].identificacao);
                arrayJogadas = adicionarJogada(arrayJogadas, tab, arrayJogadores[numJogadas%2].identificacao, numJogadas, linha, coluna, infoJogada);

                vitoria = verificaVitoria(tab);

                if(vitoria == 1)
                {
                    declararVitoria(arrayJogadores[(numJogadas)%2].identificacao);

                    //registo de jogadas
                    sprintf(infoJogada, "O jogador %c ganhou o jogo.\n", arrayJogadores[numJogadas%2].identificacao);
                    arrayJogadas = adicionarJogada(arrayJogadas, tab, arrayJogadores[numJogadas%2].identificacao, numJogadas+1, 0, 0, infoJogada);

                    //terminar jogo
                    terminarJogo(arrayJogadas, tab);
                }

                break;

            case 2:
                pedeCoordenadas(tab,&linha,&coluna);
                checkJogada = verificaPeca(tab,arrayJogadores[numJogadas%2],linha,coluna,'Y');

                //registo de jogadas
                sprintf(infoJogada, "Peca Amarela na linha %d, coluna %d pelo jogador %c.\n", linha, coluna, arrayJogadores[numJogadas%2].identificacao);
                arrayJogadas = adicionarJogada(arrayJogadas, tab, arrayJogadores[numJogadas%2].identificacao, numJogadas, linha, coluna, infoJogada);

                break;

            case 3:
                pedeCoordenadas(tab,&linha,&coluna);
                checkJogada = verificaPeca(tab,arrayJogadores[numJogadas%2],linha,coluna,'R');

                //registo de jogadas
                sprintf(infoJogada, "Peca Vermelha na linha %d, coluna %d pelo jogador %c.\n", linha, coluna, arrayJogadores[numJogadas%2].identificacao);
                arrayJogadas = adicionarJogada(arrayJogadas, tab, arrayJogadores[numJogadas%2].identificacao, numJogadas, linha, coluna, infoJogada);

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

                //registo de jogadas
                sprintf(infoJogada, "Pedra na linha %d, coluna %d pelo jogador %c.\n", linha, coluna, arrayJogadores[numJogadas%2].identificacao);
                arrayJogadas = adicionarJogada(arrayJogadas, tab, arrayJogadores[numJogadas%2].identificacao, numJogadas, linha, coluna, infoJogada);

                break;

            case 5:
                break;

            case 6:
                break;

            case 7:

                printf("\nOcorreram ate agora %d jogadas.\n", numJogadas);
                do{

                    printf("Ver ultimas 'x' jogadas: ");
                    scanf("%d", &nJogadasAnteriores);
                }while(nJogadasAnteriores < 0 || nJogadasAnteriores > numJogadas);

                printf("\n");

                for(int i = numJogadas-1; i >= (numJogadas-nJogadasAnteriores); i--)
                {

                    mostrarJogada(arrayJogadas, i);
                }
                checkJogada = 1;
                break;

            case 9:
                break;

            case 0:
                printf("\nPretende mesmo desistir(y/n): ");
                scanf(" %c", &opcao);

                if(opcao == 'y' || opcao == 'Y')
                {
                    declararVitoria(arrayJogadores[(numJogadas+1)%2].identificacao);

                    //registo de jogadas
                    sprintf(infoJogada, "O jogador %c desistiu.\n", arrayJogadores[numJogadas%2].identificacao);
                    arrayJogadas = adicionarJogada(arrayJogadas, tab, arrayJogadores[numJogadas%2].identificacao, numJogadas, 0, 0, infoJogada);

                    //terminar jogo
                    terminarJogo(arrayJogadas, tab);
                } else{
                    checkJogada = 1;
                }

                break;

            default:
                printf("Ocorreu  um erro, tente novamente!\n");
                break;

        }
        if(checkJogada == 0)
            numJogadas++;

    }
}

void terminarJogo(jogada *arrayJogadas, tabuleiro tab)
{
    //guardar registo jogo em ficheiro
    //free tabuleiro
    //free registoJogadas
    //terminar

    exit(0);

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
