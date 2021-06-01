#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menus.h"
#include "jogadores.h"
#include "tabuleiro.h"
#include "registoJogadas.h"
#include "interromperJogo.h"

//função de jogo para um jogador
void umJogador(int numJogadas, jogadores jogadorA, jogadores jogadorB, tabuleiro tab, ponteiroJogadas listaJogadas)
{
    //declaração de variáveis
    int linha, coluna;
    int opcao;

    int checkJogada = 0;

    //criação de um array para os jogadores para alternar entre os dois conforme a jogada
    jogadores arrayJogadores[2] = {jogadorA,jogadorB};

    char infoJogada[100];
    int nJogadasAnteriores = 0;

    int vitoria = 0;

    //inicia o jogo
    while(1)
    {

        //caso seja a vez do computador jogar, Jogador B
        if(arrayJogadores[numJogadas%2].identificacao == 'B')
        {

            //recebe um número random entre '1' e o limite do tabuleiro, para as linhas e para as colunas
            linha = intUniformRnd(1,tab.nLinhas);
            coluna = intUniformRnd(1,tab.nColunas);

            //mostra o jogador que está a jogar
            printf("\n\n--------------------------------------------------\n");
            printf("Jogador %c.\n\n", arrayJogadores[numJogadas%2].identificacao);

            //mostra o tabuleiro
            mostraTabuleiro(tab);

            //enquanto não realizar um jogada válida
            do{
                //se na posição gerada aleatoriamente estiver uma pedra ou uma peça vermelha volta a gerar as linhas e colunas e volta ao início do ciclo "do while"
                if(tab.tabuleiro[linha-1][coluna-1] == 'P' || tab.tabuleiro[linha-1][coluna-1] == 'R')
                {
                    linha = intUniformRnd(1,tab.nLinhas);
                    coluna = intUniformRnd(1,tab.nColunas);
                    continue;
                }

                //gera um número aleatório entre 1 e 4 para a operação que o computador realizar
                opcao = intUniformRnd(1,4);

                //caso a opção gerada for
                switch(opcao)
                {
                    // '1' coloca uma peça de cor no local gerado anteriormente aleatoriamente
                    case 1:

                        if(tab.tabuleiro[linha-1][coluna-1] == ' ')
                        {
                            //se o local gerado anteriormente estiver em branco coloca uma peça verde
                            checkJogada = verificaPeca(tab,linha,coluna,'G');
                            sprintf(infoJogada, "Peca Verde na linha %d, coluna %d pelo jogador %c.\n", linha, coluna, arrayJogadores[numJogadas%2].identificacao);

                        } else if(tab.tabuleiro[linha-1][coluna-1] == 'G')
                        {
                            //se tiver uma peça verde coloca uma peça amarela
                            checkJogada = verificaPeca(tab,linha,coluna,'Y');
                            sprintf(infoJogada, "Peca Amarela na linha %d, coluna %d pelo jogador %c.\n", linha, coluna, arrayJogadores[numJogadas%2].identificacao);

                        }else if(tab.tabuleiro[linha-1][coluna-1] == 'Y')
                        {
                            //se tiver uma peça amarela coloca um peça vermelha
                            checkJogada = verificaPeca(tab,linha,coluna,'R');
                            sprintf(infoJogada, "Peca Vermelha na linha %d, coluna %d pelo jogador %c.\n", linha, coluna, arrayJogadores[numJogadas%2].identificacao);

                        }else{
                            //caso contrário diz que está numa jogada inválida
                            checkJogada = 1;
                        }

                        //se estiver em uma jogada invalida sai do switch
                        if(checkJogada == 1)
                            break;

                        //registo de jogadas
                        //adiciona à lista de jogadas a jogada atual
                        listaJogadas = adicionarJogada(listaJogadas, tab, arrayJogadores[numJogadas%2].identificacao, numJogadas, linha, coluna, infoJogada);

                        //verifica se o computador ganhou, e se sim declara vitória ao chamar a função "vitoriaJogo"
                        if(verificaVitoria(tab) == 1)
                        {
                            vitoriaJogo(numJogadas, arrayJogadores[numJogadas%2], tab, listaJogadas);
                        }
                        break;

                    //caso selecione 2 coloca uma pedra no local gerado
                    case 2:

                        // se o computador não tiver mais pedras diz que é uma jogada invalida e sai do switch
                        if(arrayJogadores[numJogadas%2].pedra == 0)
                        {
                            checkJogada = 1;
                            break;
                        }

                        //caso ainda tenha pedras restantes tenta colocar a pedra no local gerado anteriormente
                        checkJogada = verificaPeca(tab,linha,coluna,'P');

                        //se a jogada correu bem decrementa o número de pedras do jogador
                        if(checkJogada == 0)
                            arrayJogadores[numJogadas%2].pedra -= 1;

                        //registo de jogadas
                        // imprime para a string "infoJogada" um pequeno comentário sobre a jogada que ocorreu
                        sprintf(infoJogada, "Pedra na linha %d, coluna %d pelo jogador %c.\n", linha, coluna, arrayJogadores[numJogadas%2].identificacao);
                        //adiciona à lista de jogadas a jogada atual
                        listaJogadas = adicionarJogada(listaJogadas, tab, arrayJogadores[numJogadas%2].identificacao, numJogadas, linha, coluna, infoJogada);

                        break;

                    //caso selecione 3 incrementa o número de linhas do tabuleiro
                    case 3:

                        //verifica se o utilizador ainda pode incrementar o tabuleiro caso contrário diz que é jogada inválida e sai do switch
                        if(arrayJogadores[numJogadas%2].aumentarTabuleiro == 0)
                        {
                            checkJogada = 1;
                            break;
                        }

                        //tenta aumentar o tabuleiro
                        tab = aumentaLinhas(tab, &checkJogada);

                        //caso a operação seja realizada com sucesso decrementa o número de vezes que o utilizador pode incrementar o tabuleiro
                        if(checkJogada == 0)
                            arrayJogadores[numJogadas%2].aumentarTabuleiro -= 1;

                        //registo de jogadas
                        // imprime para a string "infoJogada" um pequeno comentário sobre a jogada que ocorreu
                        sprintf(infoJogada, "Aumento de uma linha ao tabuleiro pelo jogador %c.\n", arrayJogadores[numJogadas%2].identificacao);
                        //adiciona à lista de jogadas a jogada atual
                        listaJogadas = adicionarJogada(listaJogadas, tab, arrayJogadores[numJogadas%2].identificacao, numJogadas, tab.nLinhas, 0, infoJogada);

                        break;

                    //caso selecione 4 incrementa o número de colunas do tabuleiro
                    case 4:

                        //verifica se o utilizador ainda pode incrementar o tabuleiro caso contrário diz que é jogada inválida e sai do switch
                        if(arrayJogadores[numJogadas%2].aumentarTabuleiro == 0)
                        {
                            checkJogada = 1;
                            break;
                        }

                        //tenta aumentar o tabuleiro
                        tab = aumentaColunas(tab, &checkJogada);

                        //caso a operação seja realizada com sucesso decrementa o número de vezes que o utilizador pode incrementar o tabuleiro
                        if(checkJogada == 0)
                            arrayJogadores[numJogadas%2].aumentarTabuleiro -= 1;

                        //registo de jogadas
                        // imprime para a string "infoJogada" um pequeno comentário sobre a jogada que ocorreu
                        sprintf(infoJogada, "Aumento de uma coluna ao tabuleiro pelo jogador %c.\n", arrayJogadores[numJogadas%2].identificacao);
                        //adiciona à lista de jogadas a jogada atual
                        listaJogadas = adicionarJogada(listaJogadas, tab, arrayJogadores[numJogadas%2].identificacao, numJogadas, 0, tab.nColunas, infoJogada);

                        break;

                    //caso a opção recebida não for uma das anteriores mostra esta mensagem de erro
                    default:
                        printf("Ocorreu  um erro, tente novamente!\n");
                        break;

                }

                //caso a jogada seja válida incrementa o número de jogadas para passar para o próximo jogador
                if(checkJogada == 0)
                {
                    numJogadas++;
                    break;
                }

            }while(checkJogada == 1);

            //imprime a informação sobre a jogada que ocorreu para o utilizador
            printf("%s\n", infoJogada);

            printf("--------------------------------------------------\n");
        }
        else
        {
            //caso seja a vez do utilizador a jogar
            while(1)
            {
                //mostra o utilizador atual
                printf("\n\n--------------------------------------------------\n");
                printf("Jogador %c.\n\n", arrayJogadores[numJogadas%2].identificacao);

                //mostra o estado do tabuleiro e as possíveis jogadas do utilizador
                mostraTabuleiro(tab);
                menuJogadas(arrayJogadores[numJogadas%2]);
                printf("--------------------------------------------------\n");

                //verificação da opção inserida pelo utilizador
                do{

                    printf("Escolha uma jogada: ");
                    scanf("%d", &opcao);
                }while(opcao < 0 || opcao > 7 && opcao != 9);

                //chama a função "switchHumano" para decifrar, verificar e executar a operação desejada pelo utilizador
                switchJogadorHumano(numJogadas, &arrayJogadores, &tab, &listaJogadas, opcao, &checkJogada, 1);

                //se a jogada for válida incrementa o número de jogadas para passar para o próximo jogador e sai do ciclo "while"
                if(checkJogada == 0)
                {
                    numJogadas++;
                    break;
                }

            }
        }
    }
}

//função de jogo para dois jogadores
void doisJogadores(int numJogadas, jogadores jogadorA, jogadores jogadorB, tabuleiro tab, ponteiroJogadas listaJogadas)
{
    //declaração de variáveis
    int checkJogada = 0;
    int opcao;

    //criação de um array para os jogadores para alternar entre os dois conforme a jogada
    jogadores arrayJogadores[2] = {jogadorA,jogadorB};

    //inicio do jogo
    while(1)
    {
        //mostra o jogador atual
        printf("\n\n--------------------------------------------------\n");
        printf("Jogador %c.\n\n", arrayJogadores[numJogadas%2].identificacao);

        //mostra o tabuleiro
        mostraTabuleiro(tab);
        //mostra as jogadas possíveis para o utilizador
        menuJogadas(arrayJogadores[numJogadas%2]);
        printf("--------------------------------------------------\n");
        //verificação da opção selecionada pelo utilizador
        do{

            printf("Escolha uma jogada: ");
            scanf("%d", &opcao);
        }while(opcao < 0 || opcao > 7 && opcao != 9);

        //envia para a função os dados necessários para realizar a jogada selecionada
        switchJogadorHumano(numJogadas, &arrayJogadores, &tab, &listaJogadas, opcao, &checkJogada,2);

        //se a jogada correr bem passa para a próxima jogada
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

                //caso ainda tenha pedras para colocar, pede as coordenadas do tabuleiro onde pretende colocar a pedra
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

                //caso devolva 0 significa que colocou a pedra e por isso decrementa o número de pedras do utilizador
                if(*checkJogada == 0)
                    arrayJogadores[numJogadas%2].pedra -= 1;

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

                //caso ainda tenha aumentos para fazer, chama a função que aumenta o número de linhas do tabuleiro
                *tab = aumentaLinhas(*tab, checkJogada);

                //se a função de aumentar o tabuleiro devolver '0' significa que conseguiu aumentar o tabuleiro
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

                //caso ainda tenha aumentos para fazer, chama a função que aumenta o número de colunas do tabuleiro
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
                    //pede o número de jogadas que o utilizador pretende ver e verifica o número introduzido
                    printf("Ver ultimas 'k' jogadas: ");
                    scanf("%d", &nJogadasAnteriores);
                }while(nJogadasAnteriores < 0 || nJogadasAnteriores > numJogadas);

                printf("\n");

                //cria uma lista ligada auxiliar para ajudar na manipulação da principal
                ponteiroJogadas aux;
                aux = *listaJogadas;

                //começa no primeiro nó e vai até ao nó número de jogadas atual menos número de jogadas que o utilizador pretende ver
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
                    printf("\n\n\n\n\nO jogador %c ganhou o jogo.\n\n\n", arrayJogadores[(numJogadas+1)%2].identificacao);

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

    //chama a função "terminar jogo"
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
