#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menus.h"
#include "jogadores.h"
#include "tabuleiro.h"
#include "registoJogadas.h"
#include "interromperJogo.h"

void umJogador(int numJogadas, jogadores jogadorA, jogadores jogadorB, tabuleiro tab, ponteiroJogadas listaJogadas)
{

    int linha, coluna;
    int opcao;

    int checkJogada = 0;

    jogadores arrayJogadores[2] = {jogadorA,jogadorB};

    char infoJogada[100];
    int nJogadasAnteriores = 0;

    int vitoria = 0;

    while(1)
    {

        if(arrayJogadores[numJogadas%2].identificacao == 'B')
        {

            linha = intUniformRnd(1,tab.nLinhas);
            coluna = intUniformRnd(1,tab.nColunas);

            printf("\n\n--------------------------------------------------\n");
            printf("Jogador %c.\n\n", arrayJogadores[numJogadas%2].identificacao);

            mostraTabuleiro(tab);

            do{
                if(tab.tabuleiro[linha-1][coluna-1] == 'P')
                {
                    linha = intUniformRnd(1,tab.nLinhas);
                    coluna = intUniformRnd(1,tab.nColunas);
                    continue;
                }

                opcao = intUniformRnd(1,4);

                switch(opcao)
                {
                    case 1:
                        if(tab.tabuleiro[linha-1][coluna-1] == ' ')
                        {
                            checkJogada = verificaPeca(tab,linha,coluna,'G');
                            sprintf(infoJogada, "Peca Verde na linha %d, coluna %d pelo jogador %c.\n", linha, coluna, arrayJogadores[numJogadas%2].identificacao);

                        } else if(tab.tabuleiro[linha-1][coluna-1] == 'G')
                        {
                            checkJogada = verificaPeca(tab,linha,coluna,'Y');
                            sprintf(infoJogada, "Peca Amarela na linha %d, coluna %d pelo jogador %c.\n", linha, coluna, arrayJogadores[numJogadas%2].identificacao);

                        }else if(tab.tabuleiro[linha-1][coluna-1] == 'Y')
                        {
                            checkJogada = verificaPeca(tab,linha,coluna,'R');
                            sprintf(infoJogada, "Peca Vermelha na linha %d, coluna %d pelo jogador %c.\n", linha, coluna, arrayJogadores[numJogadas%2].identificacao);

                        }else{
                            checkJogada = 1;
                        }

                        if(checkJogada == 1)
                            break;

                        //registo de jogadas

                        listaJogadas = adicionarJogada(listaJogadas, tab, arrayJogadores[numJogadas%2].identificacao, numJogadas, linha, coluna, infoJogada);

                        if(verificaVitoria(tab) == 1)
                        {
                            vitoriaJogo(numJogadas, arrayJogadores[numJogadas%2], tab, listaJogadas);
                        }
                        break;

                    case 2:

                        if(arrayJogadores[numJogadas%2].pedra == 0)
                        {
                            checkJogada = 1;
                            break;
                        }

                        checkJogada = verificaPeca(tab,linha,coluna,'P');

                        if(checkJogada == 0)
                            arrayJogadores[numJogadas%2].pedra = 0;

                        //registo de jogadas
                        sprintf(infoJogada, "Pedra na linha %d, coluna %d pelo jogador %c.\n", linha, coluna, arrayJogadores[numJogadas%2].identificacao);
                        listaJogadas = adicionarJogada(listaJogadas, tab, arrayJogadores[numJogadas%2].identificacao, numJogadas, linha, coluna, infoJogada);

                        break;

                    case 3:

                        if(arrayJogadores[numJogadas%2].aumentarTabuleiro == 0)
                        {
                            checkJogada = 1;
                            break;
                        }

                        tab = aumentaLinhas(tab, &checkJogada);

                        if(checkJogada == 0)
                            arrayJogadores[numJogadas%2].aumentarTabuleiro -= 1;

                        //registo de jogadas
                        sprintf(infoJogada, "Aumento de uma linha ao tabuleiro pelo jogador %c.\n", arrayJogadores[numJogadas%2].identificacao);
                        listaJogadas = adicionarJogada(listaJogadas, tab, arrayJogadores[numJogadas%2].identificacao, numJogadas, tab.nLinhas, 0, infoJogada);

                        break;

                    case 4:

                        if(arrayJogadores[numJogadas%2].aumentarTabuleiro == 0)
                        {
                            checkJogada = 1;
                            break;
                        }

                        tab = aumentaColunas(tab, &checkJogada);

                        if(checkJogada == 0)
                            arrayJogadores[numJogadas%2].aumentarTabuleiro -= 1;

                        //registo de jogadas
                        sprintf(infoJogada, "Aumento de uma coluna ao tabuleiro pelo jogador %c.\n", arrayJogadores[numJogadas%2].identificacao);
                        listaJogadas = adicionarJogada(listaJogadas, tab, arrayJogadores[numJogadas%2].identificacao, numJogadas, 0, tab.nColunas, infoJogada);

                        break;

                }

                if(checkJogada == 0)
                {
                    numJogadas++;
                    break;
                }

            }while(checkJogada == 1);


            printf("%s\n", infoJogada);

            printf("--------------------------------------------------\n");
        }
        else
        {
            while(1)
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

                switchJogadorHumano(numJogadas, &arrayJogadores, &tab, &listaJogadas, opcao, &checkJogada, 1);

                if(checkJogada == 0)
                {
                    numJogadas++;
                    break;
                }

            }
        }
    }
}

void doisJogadores(int numJogadas, jogadores jogadorA, jogadores jogadorB, tabuleiro tab, ponteiroJogadas listaJogadas)
{
    int checkJogada = 0;
    int opcao;

    jogadores arrayJogadores[2] = {jogadorA,jogadorB};

    while(1)
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

        switchJogadorHumano(numJogadas, &arrayJogadores, &tab, &listaJogadas, opcao, &checkJogada,2);

        if(checkJogada == 0)
            numJogadas++;

    }
}

void switchJogadorHumano(int numJogadas, jogadores *arrayJogadores, tabuleiro *tab, ponteiroJogadas *listaJogadas, int opcao, int *checkJogada, int tipoJogo)
{

    int linha, coluna;
    int nJogadasAnteriores = 0;

    char infoJogada[100];

    switch(opcao)
        {
            case 1:
                pedeCoordenadas(*tab,&linha,&coluna);
                *checkJogada = verificaPeca(*tab,linha,coluna,'G');

                if(*checkJogada == 1)
                {
                    printf("\n\nJogada Invalida!\n");
                    break;
                }

                //registo de jogadas
                sprintf(infoJogada, "Peca Verde na linha %d, coluna %d pelo jogador %c.\n", linha, coluna, arrayJogadores[numJogadas%2].identificacao);
                *listaJogadas = adicionarJogada(*listaJogadas, *tab, arrayJogadores[numJogadas%2].identificacao, numJogadas, linha, coluna, infoJogada);

                if(verificaVitoria(*tab) == 1)
                {
                    vitoriaJogo(numJogadas, arrayJogadores[numJogadas%2], *tab, *listaJogadas);
                }

                break;

            case 2:
                pedeCoordenadas(*tab,&linha,&coluna);
                *checkJogada = verificaPeca(*tab,linha,coluna,'Y');

                if(*checkJogada == 1)
                {
                    printf("\n\nJogada Invalida!\n");
                    break;
                }

                //registo de jogadas
                sprintf(infoJogada, "Peca Amarela na linha %d, coluna %d pelo jogador %c.\n", linha, coluna, arrayJogadores[numJogadas%2].identificacao);
                *listaJogadas = adicionarJogada(*listaJogadas, *tab, arrayJogadores[numJogadas%2].identificacao, numJogadas, linha, coluna, infoJogada);

                if(verificaVitoria(*tab) == 1)
                {
                    vitoriaJogo(numJogadas, arrayJogadores[numJogadas%2], *tab, *listaJogadas);
                }

                break;

            case 3:
                pedeCoordenadas(*tab,&linha,&coluna);
                *checkJogada = verificaPeca(*tab,linha,coluna,'R');

                if(*checkJogada == 1)
                {
                    printf("\n\nJogada Invalida!\n");
                    break;
                }

                //registo de jogadas
                sprintf(infoJogada, "Peca Vermelha na linha %d, coluna %d pelo jogador %c.\n", linha, coluna, arrayJogadores[numJogadas%2].identificacao);
                *listaJogadas = adicionarJogada(*listaJogadas, *tab, arrayJogadores[numJogadas%2].identificacao, numJogadas, linha, coluna, infoJogada);

                if(verificaVitoria(*tab) == 1)
                {
                    vitoriaJogo(numJogadas, arrayJogadores[numJogadas%2], *tab, *listaJogadas);
                }

                break;

            case 4:
                if(arrayJogadores[numJogadas%2].pedra == 0)
                {
                    printf("\nEste jogador esgotou as Pedras.\n");
                    *checkJogada = 1;
                    break;
                }

                pedeCoordenadas(*tab,&linha,&coluna);
                *checkJogada = verificaPeca(*tab,linha,coluna,'P');

                if(*checkJogada == 1)
                {
                    printf("\n\nJogada Invalida!\n");
                    break;
                }

                if(*checkJogada == 0)
                    arrayJogadores[numJogadas%2].pedra = 0;

                //registo de jogadas
                sprintf(infoJogada, "Pedra na linha %d, coluna %d pelo jogador %c.\n", linha, coluna, arrayJogadores[numJogadas%2].identificacao);
                *listaJogadas = adicionarJogada(*listaJogadas, *tab, arrayJogadores[numJogadas%2].identificacao, numJogadas, linha, coluna, infoJogada);

                break;

            case 5:
                if(arrayJogadores[numJogadas%2].aumentarTabuleiro == 0)
                {
                    printf("\nEste jogador esgotou os seus aumentos do tabuleiro.\n");
                    *checkJogada = 1;
                    break;
                }

                *tab = aumentaLinhas(*tab, checkJogada);

                if(*checkJogada == 0)
                    arrayJogadores[numJogadas%2].aumentarTabuleiro -= 1;

                //registo de jogadas
                sprintf(infoJogada, "Aumento de uma linha ao tabuleiro pelo jogador %c.\n", arrayJogadores[numJogadas%2].identificacao);
                *listaJogadas = adicionarJogada(*listaJogadas, *tab, arrayJogadores[numJogadas%2].identificacao, numJogadas, tab->nLinhas, 0, infoJogada);

                break;

            case 6:
                if(arrayJogadores[numJogadas%2].aumentarTabuleiro == 0)
                {
                    printf("\nEste jogador esgotou os seus aumentos do tabuleiro.\n");
                    *checkJogada = 1;
                    break;
                }

                *tab = aumentaColunas(*tab, checkJogada);

                if(*checkJogada == 0)
                    arrayJogadores[numJogadas%2].aumentarTabuleiro -= 1;

                //registo de jogadas
                sprintf(infoJogada, "Aumento de uma coluna ao tabuleiro pelo jogador %c.\n", arrayJogadores[numJogadas%2].identificacao);
                *listaJogadas = adicionarJogada(*listaJogadas, *tab, arrayJogadores[numJogadas%2].identificacao, numJogadas, 0, tab->nColunas, infoJogada);

                break;

            case 7:

                printf("\nOcorreram ate agora %d jogadas.\n", numJogadas);
                do{

                    printf("Ver ultimas 'x' jogadas: ");
                    scanf("%d", &nJogadasAnteriores);
                }while(nJogadasAnteriores < 0 || nJogadasAnteriores > numJogadas);

                printf("\n");

                ponteiroJogadas aux;
                aux = *listaJogadas;

                for(int i = 1; i <= (numJogadas-nJogadasAnteriores);i++)
                {
                    aux = aux->next;
                }

                for(int i = 0; i < nJogadasAnteriores; i++)
                {
                    mostrarJogada(aux);
                    aux = aux->next;
                }
                *checkJogada = 1;
                break;

            case 9:
                interromperJogo(tipoJogo,numJogadas,arrayJogadores[0],arrayJogadores[1],*tab,*listaJogadas);
                break;

            case 0:
                printf("\nPretende mesmo desistir(y/n): ");
                scanf(" %c", &opcao);

                if(opcao == 'y' || opcao == 'Y')
                {
                    declararVitoria(arrayJogadores[(numJogadas+1)%2].identificacao);

                    //registo de jogadas
                    sprintf(infoJogada, "O jogador %c desistiu.\n", arrayJogadores[numJogadas%2].identificacao);
                    *listaJogadas = adicionarJogada(*listaJogadas, *tab, arrayJogadores[numJogadas%2].identificacao, numJogadas, 0, 0, infoJogada);

                    //terminar jogo
                    terminarJogo(*listaJogadas, tab);
                } else{
                    *checkJogada = 1;
                }

                break;

            default:
                printf("Ocorreu  um erro, tente novamente!\n");
                break;

        }
}

void terminarJogo(ponteiroJogadas listaJogadas, tabuleiro *tab)
{

    int resultadoFicheiroJogadas;
    char nomeFicheiro[99];

    printf("Indique o nome do ficheiro onde pretende guardar as jogadas: ");
    scanf("%s", nomeFicheiro);

    strcat(nomeFicheiro, ".txt");

    resultadoFicheiroJogadas = escreveJogadasFicheiro(nomeFicheiro, listaJogadas);

    if(resultadoFicheiroJogadas)
    {
        printf("\nOcorreu um erro a guardar as jogadas no seu ficheiro!\n\n");
    } else
    {
        printf("\nO ficheiro com as jogadas foi criado.\n\n");
    }

    libertarMemoria(listaJogadas, tab);

    exit(0);
}

void vitoriaJogo(int numJogadas, jogadores jogador, tabuleiro tab, ponteiroJogadas listaJogadas)
{
    char infoJogada[100];

    printf("\n\n--------------------------------------------------");

    printf("\n\n\n\n\nO jogador %c ganhou o jogo.\n\n\n", jogador.identificacao);
    mostraTabuleiro(tab);

    printf("\n\n\n--------------------------------------------------\n\n");

    //registo de jogadas
    sprintf(infoJogada, "O jogador %c ganhou o jogo.\n", jogador.identificacao);
    listaJogadas = adicionarJogada(listaJogadas, tab, jogador.identificacao, numJogadas+1, 0, 0, infoJogada);

    //terminar jogo
    terminarJogo(listaJogadas, &tab);

}

void libertarMemoria(ponteiroJogadas listaJogadas, tabuleiro *tab)
{

    ponteiroJogadas aux;

    // liberta cada linha da tabela
    for(int i = 0; i < tab->nLinhas; i++)
        free(tab->tabuleiro[i]);

    // liberta a tabela em si
    free(tab->tabuleiro);

    while(listaJogadas != NULL)
    {

        aux = listaJogadas;
        listaJogadas = listaJogadas->next;

        // liberta a tabela
        for(int i = 0; i < aux->tab.nLinhas; i++)
            free(aux->tab.tabuleiro[i]);

        free(aux->tab.tabuleiro);

        // liberta o nó
        free(aux);
    }
}
