#include <stdio.h>
#include <stdlib.h>

#include "jogadores.h"
#include "tabuleiro.h"
#include "registoJogadas.h"
#include "tipoJogo.h"

//função que guarda o estado do jogo, de forma a puder ser retomado mais tarde
int interromperJogo(int tipoJogo, int numJogadas, jogadores jogadorA, jogadores jogadorB, tabuleiro tab, ponteiroJogadas listaJogadas)
{
    /*
        recebe:
            tipoJogo -> 1 = 1 jogador; 2 = 2 jogadoress
            numJogadas -> número de jogadas
            jogadorA -> estrutura com os dados do jogador A
            jogadorB -> estrutura com os dados do jogador B
            tab -> tabuleiro atual de jogo
            listaJogadas -> lista ligada com o registo de todas as jogadas
    */

    //lista ligada auxiliar para manipular as jogadas anteriores
    ponteiroJogadas aux = listaJogadas;

    //abre o ficheiro "jogo.bin" para escrita binária
    FILE *f = fopen("jogo.bin", "wb");

    //verifica se o ficheiro foi bem aberto
    if (f == NULL)
    {
        printf("Erro ao aceder ao ficheiro! \n");
        return 1;
    }

    //escreve no ficheiro binário o tipo de jogo e o número de jogadas
    fwrite(&tipoJogo, sizeof(int), 1, f);
    fwrite(&numJogadas, sizeof(int), 1, f);

    //escreve no ficheiro a estrutura dos jogadores
    fwrite(&jogadorA, sizeof(jogadores), 1, f);
    fwrite(&jogadorB, sizeof(jogadores), 1, f);

    //escreve tabuleiro
    //primeiro escreve o número de linhas e colunas
    fwrite(&tab.nLinhas, sizeof(int), 1, f);
    fwrite(&tab.nColunas, sizeof(int), 1, f);

    //depois escreve a informação do tabuleiro em si, linha a linha
    for(int i = 0; i < tab.nLinhas; i++)
    {
        fwrite(tab.tabuleiro[i], sizeof(char)*tab.nColunas, 1, f);
    }

    //escreve listaJogadas
    //para cada jogada que ocorreu
    for(int i = 0; i < numJogadas; i++)
    {
        //escreve as informações simples,
        fwrite(&aux->jogador, sizeof(char), 1, f); //identificação jogador
        fwrite(&aux->nJogada, sizeof(int), 1, f); //número da jogada
        fwrite(&aux->linhaAfetada, sizeof(int), 1, f); // linha afetada pela jogada
        fwrite(&aux->colunaAfetada, sizeof(int), 1, f); // coluna afetada pela jogada
        fwrite(&aux->infoJogada, sizeof(char), 100, f); //texto descritivo da jogada

        //escreve o tabuleiro resultado da jogada
        // escreve o numero de linhas e colunas do tabuleiro
        fwrite(&aux->tab.nLinhas, sizeof(int), 1, f);
        fwrite(&aux->tab.nColunas, sizeof(int), 1, f);

        //escreve o tabuleiro linha a linha no ficheiro
        for(int j = 0; j < aux->tab.nLinhas; j++)
        {
            fwrite(aux->tab.tabuleiro[j], sizeof(char)*aux->tab.nColunas, 1, f);
        }

        //após escrever todos os dados da jogada passa para o próximo nó da lista
        aux = aux->next;

    }

    //fecha o ficheiro
    fclose(f);

    //mostra uma mensagem a indicar que foi tudo guardado com sucesso
    printf("\n\n O seu jogo foi guardado, volte mais tarde para continuar. \n\n");

    //liberta a memória alocada dinamicamente para a tabela e para a lista ligada
    libertarMemoria(listaJogadas, &tab);

    //termina o programa
    exit(0);
}

//função que retoma o jogo a partir do ficheiro binário
void lerJogoGuardado()
{
    //declaração das variáveis necessárias para receber os dados do ficheiro
    int tipoJogo;
    int numJogadas;
    jogadores jogadorA;
    jogadores jogadorB;
    tabuleiro tab;
    ponteiroJogadas listaJogadas = NULL;

    //abertura do ficheiro "jogo.bin" para leitura binária
    FILE *f;
    f = fopen("jogo.bin", "rb");

    //verifica se o ficheiro foi bem aberto
    if (f == NULL)
    {
        printf("Erro ao aceder ao ficheiro! \n");
        return 1;
    }

    //lê o tipo de jogo e o número de jogadas
    fread(&tipoJogo, sizeof(int), 1, f);
    fread(&numJogadas, sizeof(int), 1, f);

    //lê os dados das estruturas dos jogadores
    fread(&jogadorA, sizeof(jogadores), 1, f);
    fread(&jogadorB, sizeof(jogadores), 1, f);

    //lê tabuleiro
    // lê o número de linhas e colunas do tabuleiro
    fread(&tab.nLinhas, sizeof(int), 1, f);
    fread(&tab.nColunas, sizeof(int), 1, f);

    //aloca espaço para as diversas linhas do tabuleiro
    tab.tabuleiro = (char**)malloc(sizeof(char*)*tab.nLinhas);

    //verifica se a alocação de memória correu bem
    if(tab.tabuleiro == NULL)
    {
        printf("Ocorreu um erro a alocar memória!");
        return;
    }

    //para cada linha tabela vai
    for(int i = 0; i < tab.nLinhas; i++)
    {
        //alocar espaço para as diversas colunas da tabela
        tab.tabuleiro[i] = (char*)malloc(sizeof(char)* tab.nColunas);

        //verifica a alocação de memória
        if(tab.tabuleiro[i] == NULL)
        {
            printf("Ocorreu um erro a alocar memória!");
            return;
        }

        //lê a linha atual do ficheiro
        fread(tab.tabuleiro[i], sizeof(char)*tab.nColunas, 1, f);
    }

    //para cada registo de jogadas
    for(int i = 0; i < numJogadas; i++)
    {
        //cria uma variavel do tipo estrutura jogadas auxiliar para ler os dados do ficheiro
        jogada aux;

        //lê os dados simples do ficheiro
        fread(&aux.jogador, sizeof(char), 1, f);
        fread(&aux.nJogada, sizeof(int), 1, f);
        fread(&aux.linhaAfetada, sizeof(int), 1, f);
        fread(&aux.colunaAfetada, sizeof(int), 1, f);
        fread(&aux.infoJogada, sizeof(char), 100, f);

        // lê o número de linhas e colunas do ficheiro
        fread(&aux.tab.nLinhas, sizeof(int), 1, f);
        fread(&aux.tab.nColunas, sizeof(int), 1, f);

        //aloca espaço para as diversas linhas da tabela
        aux.tab.tabuleiro = (char**)malloc(sizeof(char*)*aux.tab.nLinhas);

        //verifica a alocação de memória
        if(aux.tab.tabuleiro == NULL)
        {
            printf("Ocorreu um erro a alocar memória!");
            return;
        }

        //para cada linha
        for(int j = 0; j < aux.tab.nLinhas; j++)
        {
            //aloca espaço para as diversas colunas
            aux.tab.tabuleiro[j] = (char*)malloc(sizeof(char)* aux.tab.nColunas);

            //verifica a alocação de memória
            if(aux.tab.tabuleiro[j] == NULL)
            {
                printf("Ocorreu um erro a alocar memória!");
                return;
            }

            //lê a linha atual da tabela
            fread(aux.tab.tabuleiro[j], sizeof(char)*aux.tab.nColunas, 1, f);
        }

        //coloca o próximo nó da lista como "NULL"
        aux.next = NULL;

        //adiciona à lista ligada o novo nó da lista
        listaJogadas = adicionarJogada(listaJogadas, aux.tab, aux.jogador, aux.nJogada-1, aux.linhaAfetada, aux.colunaAfetada, aux.infoJogada);
    }

    //fecha o ficheiro
    fclose(f);
    //elimina o ficheiro
    remove("jogo.bin");

    //verifica o tipo de jogo
    if(tipoJogo == 1)
    {
        // inicia um jogo contra o computador com os dados lidos do ficheiro
        printf("\n\n\n\n------------- A retomar UM JOGADOR -------------\n\n\n\n");
        umJogador(numJogadas, jogadorA, jogadorB, tab, listaJogadas);
    }
    else if(tipoJogo == 2)
    {
        //inicia um jogo contra o computador com os dados recebidos do ficheiro lido
        printf("\n\n\n\n------------ A retomar DOIS JOGADORES ------------\n\n\n\n");
        doisJogadores(numJogadas, jogadorA, jogadorB, tab, listaJogadas);
    }
}
