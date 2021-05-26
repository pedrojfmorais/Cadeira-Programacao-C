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
                if(tab.tabuleiro[linha-1][coluna-1] == 'P' || tab.tabuleiro[linha-1][coluna-1] == 'R')
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
                menuJogadas(arrayJogadores[numJogadas%2]);
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
        menuJogadas(arrayJogadores[numJogadas%2]);
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

//função que determina o que fazer, dada um operação por um jogador
void switchJogadorHumano(int numJogadas, jogadores *arrayJogadores, tabuleiro *tab, ponteiroJogadas *listaJogadas, int opcao, int *checkJogada, int tipoJogo)
{
    //declaração de variáveis
    int linha, coluna;
    int nJogadasAnteriores = 0;

    char infoJogada[100];

    //caso o utilizador selecione a opção
    switch(opcao)
        {
            // opção 1 -> colocar peça verde
            case 1:
                //pede as coordenadas do tabuleiro onde pretende colocar a peça
                pedeCoordenadas(*tab,&linha,&coluna);
                //verifica se é possivel colocar a peça, e se sim coloca-a
                *checkJogada = verificaPeca(*tab,linha,coluna,'G');

                //se a função de colocar peça devolver 1 significa que não foi possivel colocar a peça
                if(*checkJogada == 1)
                {
                    printf("\n\nJogada Invalida!\n");
                    //sai do switch
                    break;
                }

                //registo de jogadas
                // imprime para a string "infoJogada" um pequeno comentário sobre a jogada que ocorreu
                sprintf(infoJogada, "Peca Verde na linha %d, coluna %d pelo jogador %c.\n", linha, coluna, arrayJogadores[numJogadas%2].identificacao);
                //adiciona à lista de jogadas a jogada atual
                *listaJogadas = adicionarJogada(*listaJogadas, *tab, arrayJogadores[numJogadas%2].identificacao, numJogadas, linha, coluna, infoJogada);

                //verifica se após esta jogada existe uma condição de vitória
                if(verificaVitoria(*tab) == 1)
                {
                    //se sim chama a função "vitoriaJogo"
                    vitoriaJogo(numJogadas, arrayJogadores[numJogadas%2], *tab, *listaJogadas);
                }

                break;

            // opção 2 -> colocar peça amarela
            case 2:
                //pede as coordenadas do tabuleiro onde pretende colocar a peça
                pedeCoordenadas(*tab,&linha,&coluna);
                //verifica se é possivel colocar a peça, e se sim coloca-a
                *checkJogada = verificaPeca(*tab,linha,coluna,'Y');

                //se a função de colocar peça devolver 1 significa que não foi possivel colocar a peça
                if(*checkJogada == 1)
                {
                    printf("\n\nJogada Invalida!\n");
                    //sai do switch
                    break;
                }

                //registo de jogadas
                // imprime para a string "infoJogada" um pequeno comentário sobre a jogada que ocorreu
                sprintf(infoJogada, "Peca Amarela na linha %d, coluna %d pelo jogador %c.\n", linha, coluna, arrayJogadores[numJogadas%2].identificacao);
                //adiciona à lista de jogadas a jogada atual
                *listaJogadas = adicionarJogada(*listaJogadas, *tab, arrayJogadores[numJogadas%2].identificacao, numJogadas, linha, coluna, infoJogada);

                //verifica se após esta jogada existe uma condição de vitória
                if(verificaVitoria(*tab) == 1)
                {
                    //se sim chama a função "vitoriaJogo"
                    vitoriaJogo(numJogadas, arrayJogadores[numJogadas%2], *tab, *listaJogadas);
                }

                break;

            // opção 3 -> colocar peça vermelha
            case 3:
                //pede as coordenadas do tabuleiro onde pretende colocar a peça
                pedeCoordenadas(*tab,&linha,&coluna);
                //verifica se é possivel colocar a peça, e se sim coloca-a
                *checkJogada = verificaPeca(*tab,linha,coluna,'R');

                //se a função de colocar peça devolver 1 significa que não foi possivel colocar a peça
                if(*checkJogada == 1)
                {
                    printf("\n\nJogada Invalida!\n");
                    //sai do switch
                    break;
                }

                //registo de jogadas
                // imprime para a string "infoJogada" um pequeno comentário sobre a jogada que ocorreu
                sprintf(infoJogada, "Peca Vermelha na linha %d, coluna %d pelo jogador %c.\n", linha, coluna, arrayJogadores[numJogadas%2].identificacao);
                //adiciona à lista de jogadas a jogada atual
                *listaJogadas = adicionarJogada(*listaJogadas, *tab, arrayJogadores[numJogadas%2].identificacao, numJogadas, linha, coluna, infoJogada);

                //verifica se após esta jogada existe uma condição de vitória
                if(verificaVitoria(*tab) == 1)
                {
                    //se sim chama a função "vitoriaJogo"
                    vitoriaJogo(numJogadas, arrayJogadores[numJogadas%2], *tab, *listaJogadas);
                }

                break;

            // opção 4 -> colocar pedra
            case 4:
                //verifica se o jogador que está a jogar atualmente ainda tem pedras para colocar
                if(arrayJogadores[numJogadas%2].pedra == 0)
                {
                    //se não tiver imprime uma mensagem na consola e sai do switch
                    printf("\nEste jogador esgotou as Pedras.\n");
                    *checkJogada = 1;
                    break;
                }

                //caso ainda tenha pedras para colocar, pede as coordenadas do tabuleiro onde pretende colocar a peça
                pedeCoordenadas(*tab,&linha,&coluna);
                //verifica se é possivel colocar a pedra, e se sim coloca-a
                *checkJogada = verificaPeca(*tab,linha,coluna,'P');

                //se a função de colocar pedra devolver 1 significa que não foi possivel colocar a pedra
                if(*checkJogada == 1)
                {
                    printf("\n\nJogada Invalida!\n");
                    //sai do switch
                    break;
                }

                //caso devolva 0 significa que colocou a pedra e por isso o jogador esgotou as pedras que pode colocar
                if(*checkJogada == 0)
                    arrayJogadores[numJogadas%2].pedra = 0;

                //registo de jogadas
                // imprime para a string "infoJogada" um pequeno comentário sobre a jogada que ocorreu
                sprintf(infoJogada, "Pedra na linha %d, coluna %d pelo jogador %c.\n", linha, coluna, arrayJogadores[numJogadas%2].identificacao);
                //adiciona à lista de jogadas a jogada atual
                *listaJogadas = adicionarJogada(*listaJogadas, *tab, arrayJogadores[numJogadas%2].identificacao, numJogadas, linha, coluna, infoJogada);

                //neste caso é impossivel ganhar por colocar uma pedra

                break;

            // opção 5 -> aumentar linhas do tabuleiro
            case 5:
                //verifica se o utilizador a jogar atualmente ainda pode fazer alguma alteração ao tamanho do tabuleiro
                if(arrayJogadores[numJogadas%2].aumentarTabuleiro == 0)
                {
                    //se não puder imprime uma mensagem na consola e sai do switch
                    printf("\nEste jogador esgotou os seus aumentos do tabuleiro.\n");
                    *checkJogada = 1;
                    break;
                }

                //caso ainda tenha aumentos para fazer, chama a função que aumenta o numero de linhas do tabuleiro
                *tab = aumentaLinhas(*tab, checkJogada);

                //se a função de aumentar o tabuleiro devolver '0' significa que consegui aumentar o tabuleiro
                if(*checkJogada == 0)
                {
                    //como aumentou o tabuleiro vai decrementar os aumentos restantes do utilizador
                    arrayJogadores[numJogadas%2].aumentarTabuleiro -= 1;
                } else
                {
                    //senão sai do switch
                    break;
                }


                //registo de jogadas
                // imprime para a string "infoJogada" um pequeno comentário sobre a jogada que ocorreu
                sprintf(infoJogada, "Aumento de uma linha ao tabuleiro pelo jogador %c.\n", arrayJogadores[numJogadas%2].identificacao);
                //adiciona à lista de jogadas a jogada atual
                *listaJogadas = adicionarJogada(*listaJogadas, *tab, arrayJogadores[numJogadas%2].identificacao, numJogadas, tab->nLinhas, 0, infoJogada);

                break;

            // opção 6 -> aumentar colunas do tabuleiro
            case 6:
                //verifica se o utilizador a jogar atualmente ainda pode fazer alguma alteração ao tamanho do tabuleiro
                if(arrayJogadores[numJogadas%2].aumentarTabuleiro == 0)
                {
                    //se não puder imprime uma mensagem na consola e sai do switch
                    printf("\nEste jogador esgotou os seus aumentos do tabuleiro.\n");
                    *checkJogada = 1;
                    break;
                }

                //caso ainda tenha aumentos para fazer, chama a função que aumenta o numero de colunas do tabuleiro
                *tab = aumentaColunas(*tab, checkJogada);

                //se a função de aumentar o tabuleiro devolver '0' significa que consegui aumentar o tabuleiro
                if(*checkJogada == 0)
                {
                    //como aumentou o tabuleiro vai decrementar os aumentos restantes do utilizador
                    arrayJogadores[numJogadas%2].aumentarTabuleiro -= 1;
                } else
                {
                    //senão sai do switch
                    break;
                }

                //registo de jogadas
                // imprime para a string "infoJogada" um pequeno comentário sobre a jogada que ocorreu
                sprintf(infoJogada, "Aumento de uma coluna ao tabuleiro pelo jogador %c.\n", arrayJogadores[numJogadas%2].identificacao);
                //adiciona à lista de jogadas a jogada atual
                *listaJogadas = adicionarJogada(*listaJogadas, *tab, arrayJogadores[numJogadas%2].identificacao, numJogadas, 0, tab->nColunas, infoJogada);

                break;

            // opção 7 -> ver 'k' jogadas anteriores
            case 7:

                //imprime na consola uma mensagem a indicar o número de jogadas que decorreram até ao momento no jogo
                printf("\nOcorreram ate agora %d jogadas.\n", numJogadas);
                do{
                    //pede o número de jogadas que o utilizador pretende ver e verifica o numero introduzido
                    printf("Ver ultimas 'x' jogadas: ");
                    scanf("%d", &nJogadasAnteriores);
                }while(nJogadasAnteriores < 0 || nJogadasAnteriores > numJogadas);

                printf("\n");

                //cria uma lista ligada auxiliar para ajudar na manipulação da principal
                ponteiroJogadas aux;
                aux = *listaJogadas;

                //começa no primeiro nó e vai até ao nó numero de jogadas atual menos numero de jogadas que o utilizador pretende ver
                for(int i = 1; i <= (numJogadas-nJogadasAnteriores);i++)
                {
                    //passa para o próximo nó da lista
                    aux = aux->next;
                }

                //neste momento encontra-se no primeiro nó que pretende mostrar ao utilizador e vai até ao último nó da lista
                for(int i = 0; i < nJogadasAnteriores; i++)
                {
                    //mostra os dados do nó atual
                    mostrarJogada(aux);
                    //passa para o nó seguinte
                    aux = aux->next;
                }
                //coloca o checkJogada a '1', pois esta operação não significa que se irá passar para a vez do outro jogador
                *checkJogada = 1;
                break;

            // opção 9 -> interromper jogo
            case 9:
                //chama a função interromper jogo e envia as variáveis necessárias para a funcão
                interromperJogo(tipoJogo,numJogadas,arrayJogadores[0],arrayJogadores[1],*tab,*listaJogadas);
                break;

            // opção 0 -> desitir
            case 0:

                //pergunta ao utilizador se este pretende mesmo desistir
                printf("\nPretende mesmo desistir(y/n): ");
                scanf(" %c", &opcao);

                //caso o utilizador indique que sim
                if(opcao == 'y' || opcao == 'Y')
                {
                    //declara vitória ao outro jogador
                    declararVitoria(arrayJogadores[(numJogadas+1)%2].identificacao);

                    //registo de jogadas
                    // imprime para a string "infoJogada" que o jogador atual desistiu
                    sprintf(infoJogada, "O jogador %c desistiu.\n", arrayJogadores[numJogadas%2].identificacao);
                    //adiciona à lista de jogadas a jogada atual
                    *listaJogadas = adicionarJogada(*listaJogadas, *tab, arrayJogadores[numJogadas%2].identificacao, numJogadas, 0, 0, infoJogada);

                    //chama a função terminar jogo
                    terminarJogo(*listaJogadas, tab);
                } else{
                    //caso o utilizador indique que não quer desistir volta a ser a sua vez de jogar
                    *checkJogada = 1;
                }

                break;

            //caso a opção recebida não for uma das anteriores mostra esta mensagem de erro
            default:
                printf("Ocorreu  um erro, tente novamente!\n");
                break;

        }
}

//função que termina o jogo
void terminarJogo(ponteiroJogadas listaJogadas, tabuleiro *tab)
{
    //declaração de variáveis
    int resultadoFicheiroJogadas;
    char nomeFicheiro[99];

    //pede ao utilizador o nome do ficheiro onde serão guardados os registos das jogadas realizadas
    printf("Indique o nome do ficheiro onde pretende guardar as jogadas: ");
    scanf("%s", nomeFicheiro);

    //adiciona ao nome a extensão de ficheiro de texto, ".txt"
    strcat(nomeFicheiro, ".txt");

    //guarda as jogadas no ficheiro e recebe se correu bem ou não
    resultadoFicheiroJogadas = escreveJogadasFicheiro(nomeFicheiro, listaJogadas);

    //mostra no ecrã uma mensagem conforme tenha ou não conseguido guardar os dados no ficheiro de texto
    if(resultadoFicheiroJogadas)
    {
        printf("\nOcorreu um erro a guardar as jogadas no seu ficheiro!\n\n");
    } else
    {
        printf("\nO ficheiro com as jogadas foi criado.\n\n");
    }

    //liberta a memória das variáveis dinâmicas
    libertarMemoria(listaJogadas, tab);

    //termina o programa
    exit(0);
}

//função que declara qual jogador ganhou e adiciona a jogada ao registo
void vitoriaJogo(int numJogadas, jogadores jogador, tabuleiro tab, ponteiroJogadas listaJogadas)
{
    //declaração de variáveis
    char infoJogada[100];

    //mostra na consola o jogador que ganhou e o estado do tabuleiro final
    printf("\n\n--------------------------------------------------");

    printf("\n\n\n\n\nO jogador %c ganhou o jogo.\n\n\n", jogador.identificacao);
    mostraTabuleiro(tab);

    printf("\n\n\n--------------------------------------------------\n\n");

    //adiciona ao registo de jogadas a jogada final, ou seja, a indicar qual jogador ganhou
    sprintf(infoJogada, "O jogador %c ganhou o jogo.\n", jogador.identificacao);
    listaJogadas = adicionarJogada(listaJogadas, tab, jogador.identificacao, numJogadas+1, 0, 0, infoJogada);

    //chama a funçãoterminar jogo
    terminarJogo(listaJogadas, &tab);

}

//função que liberta a memória alocada dinamicamente
void libertarMemoria(ponteiroJogadas listaJogadas, tabuleiro *tab)
{
    //lista jogadas auxiliar para ajudar na manipulação da lista
    ponteiroJogadas aux;

    //libertar a tabela
    // liberta cada linha da tabela
    for(int i = 0; i < tab->nLinhas; i++)
        free(tab->tabuleiro[i]);

    // liberta a tabela em si
    free(tab->tabuleiro);

    //para cada jogada
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
