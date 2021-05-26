#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "registoJogadas.h"
#include "jogadores.h"
#include "tabuleiro.h"

//função que adiciona um novo nó à lista ligada, no fim da lista fornecida
ponteiroJogadas adicionarJogada(ponteiroJogadas listaJogadas, tabuleiro tab, char idJogador, int nJogada, int linha, int coluna, char infoJogada[])
{
    //cria dois ponteiro, um para o novo nó da lista e outro auxiliar para maniopular a lista ligada
    ponteiroJogadas nova, aux;

    //aloca memória para o novo nó da lista
    nova = malloc(sizeof(jogada));

    //verifica se a memória foi bem alocada
    if (nova == NULL)
    {
        printf("Erro na realocacao!\n");
        return listaJogadas;
    }

    //chama a função copiarTabuleiro para criar uma cópia do tabuleiro atual
    nova->tab = copiarTabuleiro(tab);

    //guarda os dados recebidos como parâmetro nas variáveis do nó
    nova->jogador = idJogador;
    nova->nJogada = nJogada+1; //guarda nJogada+1, pois o número de jogada é iniciado em '0', e para o utilizador as jogadas começam em '1'
    nova->linhaAfetada = linha;
    nova->colunaAfetada = coluna;
    strcpy(nova->infoJogada,infoJogada);

    //coloca o próximo nó da lista como NULL, pois, este ainda não existe
    nova->next = NULL;

    //se a lista fornecida estiver vazia coloca o novo nó no inicio da lista
    if(listaJogadas == NULL)
    {
        listaJogadas = nova;
    } else
    {
        //caso contrário percorre a lista fornecida até chegar ao último nó
        aux = listaJogadas;

        while(aux->next != NULL)
        {
            aux = aux->next;
        }

        // e coloca o novo nó como o último nó da lista
        aux->next = nova;
    }

    //devolve o primeiro nó da lista
    return listaJogadas;
}

//função que mostra as variáveis de um nó da listya fornecido
void mostrarJogada(ponteiroJogadas listaJogadas)
{

    printf("-------------------- Jogada %d --------------------\n", listaJogadas->nJogada);
    mostraTabuleiro(listaJogadas->tab);
    printf("Jogador %c\n", listaJogadas->jogador);
    printf("Jogada numero %d\n", listaJogadas->nJogada);
    printf("Linha %d, Coluna %d\n", listaJogadas->linhaAfetada, listaJogadas->colunaAfetada);
    printf("%s", listaJogadas->infoJogada);
    printf("--------------------------------------------------\n\n");

}

//função que escreve a lista de jogadas para um ficheiro
int escreveJogadasFicheiro(char *nomeFicheiro, ponteiroJogadas listaJogadas)
{

    //abre o ficheiro para escrita, nome do ficheiro é recebido por parâmetro
    FILE *f = fopen(nomeFicheiro, "w");

    //verifica se conseguiu abrir o ficheiro
    if(f == NULL)
    {
        fclose(f);
        return 1;
    }

    //enquanto não chegar ao fim da lista de jogadas
    while(listaJogadas != NULL)
    {

        //declara duas variáveis
        char linhaTabela[99], auxTexto[99];

        //coloca no ficheiro o número da jogada
        fprintf(f,"-------------------- Jogada %d --------------------\n", listaJogadas->nJogada);

        //copia para a variável "linhaTabela" dois espaços em branco, questão apenas visual para o ficheiro
        strcpy(linhaTabela, "  ");

        //para cada coluna
        for(int i = 0; i < listaJogadas->tab.nColunas;i++)
        {
            //imprime na variável "auxTexto" o número da coluna
            sprintf(auxTexto, " %d", i+1);

            //e concateniza com o conteudo de "linhaTabela"
            strcat(linhaTabela, auxTexto);
        }

        //imprime para o ficheiro as colunas da tabela
        fprintf(f,"%s", linhaTabela);

        //para cada linha da tabela
        for(int i = 0; i < listaJogadas->tab.nLinhas; i++)
        {
            //imprime para "auxTexto" o número da linha
            sprintf(auxTexto, "\n%d |", i+1);
            //e copia para a variável "linhaTabela"
            strcpy(linhaTabela, auxTexto);

            //para cada coluna
            for(int j = 0; j < listaJogadas->tab.nColunas; j++)
            {
                //imprime para "auxTexto" a peça guardada naquela linha e coluna
                sprintf(auxTexto, "%c|", listaJogadas->tab.tabuleiro[i][j]);
                //e concateniza com o que já tinha a peça em "auxTexto"
                strcat(linhaTabela, auxTexto);
            }
            //imprime esta linha para o ficheiro
            fprintf(f,"%s", linhaTabela);
        }
        //adiciona duas linhas ao tabuleiro, apenas visual
        fprintf(f,"\n\n", linhaTabela);

        //guarda no ficheiro os retantes dados da jogada
        fprintf(f,"Jogador %c\n", listaJogadas->jogador);
        fprintf(f,"Jogada numero %d\n", listaJogadas->nJogada);
        fprintf(f,"Linha %d, Coluna %d\n", listaJogadas->linhaAfetada, listaJogadas->colunaAfetada);
        fprintf(f,"%s", listaJogadas->infoJogada);
        fprintf(f,"--------------------------------------------------\n\n");

        //após escrever todos os dados deste nó passa para o próximo
        listaJogadas = listaJogadas->next;

    }

    //fecha o ficheiro
    fclose(f);

    return 0;
}
