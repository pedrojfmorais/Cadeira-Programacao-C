#include <stdio.h>
#include <stdlib.h>

#include "tabuleiro.h"

#include "utils.h"

//função que cria um estrutura do tipo tabuleiro e a inicializa
tabuleiro inicializarTabuleiro()
{

    //declara a estrutura do tipo tabuleiro
    tabuleiro tab;

    //recebe um número random entre 3 e 5, valor este que vai ser o número de linhas/colunas do tabuleiro de jogo
    int tam = intUniformRnd(3,5);

    //cria array dinâmico com 'tam' número de linhas
    tab.tabuleiro = (char**)malloc(sizeof(char*)*tam);

    //verifica se a alocação de memória foi realizada com sucesso
    if(tab.tabuleiro == NULL)
    {
        printf("Ocorreu um erro a alocar memória!");
        return;
    }

    //para cada linha cria 'tam' número de colunas
    for (int i=0; i<tam; i++)
    {
        //aloca o espaço para cada coluna
        tab.tabuleiro[i] = (char*)malloc(sizeof(char)* tam );

        //verifica se estas foram alocadas com sucesso
        if(tab.tabuleiro[i] == NULL)
        {
            printf("Erro na alocacao de memoria");
            free(tab.tabuleiro);
            return;
        }

        //inicializar o tabuleiro com espaços em branco
        for (int j = 0; j < tam; j++)
        {
            tab.tabuleiro[i][j] = ' ';
        }

    }

    //inicializa o número de linhas e colunas com o número random recebido em "tam"
    tab.nLinhas = tam;
    tab.nColunas = tam;

    return tab;
}

//função que imprime o estado do tabuleiro na consola
void mostraTabuleiro(tabuleiro tab)
{
    printf("  ");
    //mostra o número das colunas
    for(int i = 0; i < tab.nColunas;i++)
        printf(" %d", i+1);

    //para cada linha
    for(int i = 0; i < tab.nLinhas; i++)
    {
        //imprime o número da linha
        printf("\n%d |", i+1);

        //para cada coluna da linha
        for(int j = 0; j < tab.nColunas; j++)
        {
            //imprime o caractere nessa linha e coluna do tabuleiro
            printf("%c|", tab.tabuleiro[i][j]);
        }
    }
    printf("\n\n");
}

//função que pede as coordenadas do tabuleiro que ele pretende afetar
void pedeCoordenadas(tabuleiro tab, int *linha, int *coluna)
{
    //verifica o input do utilizador e verifica se é um valor de linhas corretas
    do{
        printf("Linha: ");
        scanf("%d", linha);
    }while((*linha) < 1 || (*linha) > tab.nLinhas);

    //verifica o input do utilizador e verifica se é um valor de colunas corretas
    do{
        printf("Coluna: ");
        scanf("%d", coluna);
    }while((*coluna) < 1 || (*coluna) > tab.nColunas);

}

//função que verifica se é possivel colocar a peça que o pretende no local dito pelo mesmo
int verificaPeca(tabuleiro tab, int linha, int coluna, char pecaColocar)
{
    //ao valor introduzido pelo utilizador para as linhas e colunas é decrementado um para se tornar no índice para a tabela
    linha = linha-1;
    coluna = coluna-1;

    //variável que guarda a peça que é necessária no local designado para colocar a peça que o utilizador pretende
    char pecaRequerida = ' ';

    switch(pecaColocar)
    {

        // para a pedra e para a peça verde é necessário uma local vazio
        case 'P':
            //a peca requerida a estar no local para a Pedra e igual a da peca Verde
        case 'G':
            pecaRequerida = ' ';
            break;

        // para a peça amarela tem que estar no local um peça amarela
        case 'Y':
            pecaRequerida = 'G';
            break;

        //para a peça vermelha tem que estar um peça amarela
        case 'R':
            pecaRequerida = 'Y';
            break;

        //caso não seja nenhuma desta a peça do utilizador mostra erro e sai da função
        default:
            printf("Peca invalida, tente novamente!\n");
            return 1;
    }

    //se a peça no tabuleiro não for a requerida devolve '1'
    if(tab.tabuleiro[linha][coluna] != pecaRequerida)
    {
        return 1;
    }

    //como a peça no tabuleiro é a requerida pode colocar a peça do utilizador e devolve '0'
    tab.tabuleiro[linha][coluna] = pecaColocar;

    return 0;
}

//função que aumenta o número de linhas do tabuleiro
tabuleiro aumentaLinhas(tabuleiro tab, int *checkJogada)
{
    //a variavel "checkJogada" aponta para uma variável onde é guardado um inteiro que indica se esta função conseguiu atingir o seu objetivo com sucesso

    //cria uma nova estrutura tabuleiro auxiliar
    tabuleiro aux;

    //copia do tabuleiro recebido o número de linhas e colunas, mas como queremos aumentar as linhas incrementamos as linhas em 1
    aux.nLinhas = tab.nLinhas+1;
    aux.nColunas = tab.nColunas;

    // realoca espaço para o novo número de linhas, sendo que usa o tabuleiro recebido como primeiro parâmetro para manter os dados da tabela para as linhas que já estavam criadas
    aux.tabuleiro = (char**)realloc(tab.tabuleiro, sizeof(char*)*aux.nLinhas);

    //verifica se a alocação correu bem
    if(aux.tabuleiro == NULL)
    {
        printf("Ocorreu um erro a alocar memória!");
        //coloca '1' no endereço apontado por "checkJogada" caso corra mal a alocação
        *checkJogada = 1;
        return tab;
    }

    //para a última linha que é a nova, aloca espaço para as diversas colunas
    aux.tabuleiro[aux.nLinhas-1] = (char*)malloc(sizeof(char)* aux.nColunas);

    //verifica se a alocação correu bem
    if(aux.tabuleiro[aux.nLinhas-1] == NULL)
    {
        printf("Erro na alocacao de memoria");
        //coloca '1' no endereço apontado por "checkJogada" caso corra mal a alocação
        *checkJogada = 1;
        return tab;
    }

    // inicializa as colunas da última linha como espaços em branco
    for (int j = 0; j < aux.nColunas; j++)
    {
        aux.tabuleiro[aux.nLinhas-1][j] = ' ';
    }

    //devolve o tabuleiro auxiliar e coloca '0' no endereço apontado por "checkJogada"
    *checkJogada = 0;
    return aux;
}

//função que aumenta o número de colunas do tabuleiro
tabuleiro aumentaColunas(tabuleiro tab, int *checkJogada)
{
    //a variável "checkJogada" aponta para uma variável onde é guardado um inteiro que indica se esta função conseguiu atingir o seu objetivo com sucesso

    //estrutura tabuleiro auxiliar onde serão realizadas as alterações
    tabuleiro aux;

    //utiliza o mesmo número de linhas do tabuleiro recebido, mas incrementa em 1 o número de colunas
    aux.nLinhas = tab.nLinhas;
    aux.nColunas = tab.nColunas+1;

    //dá realloc às linhas do tabuleiro recebido para o auxilizar para preservar os dados do tabuleiro
    aux.tabuleiro = (char**)realloc(tab.tabuleiro, sizeof(char*)*aux.nLinhas);

    //verifica se a alocação foi realizada com sucesso
    if(aux.tabuleiro == NULL)
    {
        printf("Ocorreu um erro a alocar memória!");
        //coloca o checkJogada a '1', pois deu erro
        *checkJogada = 1;
        return tab;
    }

    //para cada uma das linhas do tabuleiro
    for(int i = 0; i < aux.nLinhas; i++)
    {
        //realoca as colunas com o novo número de colunas, realloc para preservar os dados anteriores
        aux.tabuleiro[i] = (char*)realloc(aux.tabuleiro[i], sizeof(char)* aux.nColunas);

        //verifica se a alocação foi realizada com sucesso
        if(aux.tabuleiro[i] == NULL)
        {
            printf("Erro na alocacao de memoria");
            //coloca o checkJogada a '1', pois deu erro
            *checkJogada = 1;
            return tab;
        }

        //inicializa a nova coluna como vazio
        aux.tabuleiro[i][aux.nColunas-1] = ' ';
    }

    //devolve o tabuleiro auxiliar e coloca o checkJogada a '0'
    *checkJogada = 0;
    return aux;
}

//função que cria uma cópia do tabuleiro recebido
tabuleiro copiarTabuleiro(tabuleiro tabRecebido)
{

    //cria uma nova estrutura tabuleiro
    tabuleiro tab;

    //aloca o mesmo número de linhas do tabuleiro recebido
    tab.tabuleiro = (char**)malloc(sizeof(char*)*tabRecebido.nLinhas);

    //verifica se a alocação correu bem
    if(tab.tabuleiro == NULL)
    {
        printf("Ocorreu um erro a alocar memória!");
        return;
    }

    //para cada linha
    for (int i=0; i<tabRecebido.nLinhas; i++)
    {
        //aloca espaço para as colunas
        tab.tabuleiro[i] = (char*)malloc(sizeof(char)*tabRecebido.nColunas);

        //verifica se a alocação correu bem
        if(tab.tabuleiro[i] == NULL)
        {
            printf("Erro na alocacao de memoria");
            free(tab.tabuleiro);
            return;
        }

        //para cada célula da tabela copia o valor da tabela recebida
        for (int j = 0; j < tabRecebido.nColunas; j++)
        {
            tab.tabuleiro[i][j] = tabRecebido.tabuleiro[i][j];
        }

    }

    //coloca o número de linhas e colunas iguais aos da tabela recebida
    tab.nLinhas = tabRecebido.nLinhas;
    tab.nColunas = tabRecebido.nColunas;

    //devolve a nova estrutura tabela
    return tab;
}

//função que verifica se um dos jogadores ganhou
int verificaVitoria(tabuleiro tab)
{
    //devolve 1 se se encontrar um condição de vitória


    int verifica;

    //verificação das linhas
    //para cada linha
    for(int i = 0; i < tab.nLinhas; i++)
    {
        //reseta o contador "verifica" para cada verificação de linha
        verifica = 0;

        //se a primeira coluna estiver vazia passa para a próxima linha
        if(tab.tabuleiro[i][0] == ' ')
            continue;

        //para cada coluna da linha
        for(int j = 0; j < tab.nColunas; j++)
        {
            //verifica se é igual à primeira, se for igual e diferente de um espaço em branco incrementa o contador "verifica"
            if(tab.tabuleiro[i][j] == tab.tabuleiro[i][0] && tab.tabuleiro[i][j] != ' ')
            {

                verifica++;
            }else
            {
                //caso uma falhe não vale a pena verificar as restantes colunas por isso sai do segundo ciclo for
                break;
            }
        }

        //se o contador "verifica" tiver o mesmo número que o número de colunas significa que ganhou
        if(verifica == tab.nColunas)
            return 1;
    }

    //verificação das colunas
    //para cada coluna
    for(int i = 0; i < tab.nColunas; i++)
    {
        //reseta o contador "verifica"
        verifica = 0;

        //se a primeira linha da coluna estiver vazia passa para a próxima coluna
        if(tab.tabuleiro[0][i] == ' ')
            continue;

        //para cada linha
        for(int j = 0; j < tab.nLinhas; j++)
        {

            //verifica se o conteudo da atual é igual à primeira e diferente de um espaço em branco, se forem verdade estas condições incrementa o contador "verifica"
            if(tab.tabuleiro[j][i] == tab.tabuleiro[0][i] && tab.tabuleiro[j][i] != ' ')
            {
                verifica++;
            }else
            {
                //se uma das linhas dessa coluna estiver incorreta sai do segundo ciclo for
                break;
            }
        }

        //se o número no "verifica" for igual ao número de linhas significa que tem uma coluna completa igual
        if(verifica == tab.nLinhas)
            return 1;
    }

    //verificação diagonais
    //se o número de linhas for igual ao número de colunas, ou seja, a matriz for quadrada verifica as diagonais
    if(tab.nLinhas == tab.nColunas)
    {

        //verifica diagonal principal
        //verificamos as células nas posições 1x1, 2x2, 3x3, etc
        verifica = 0;

        //o valor de i vai de '0' até 'nLinhas-1', pois é 'i' menor que nLinhas
        for(int i = 0; i < tab.nLinhas; i++)
        {
            //verifica se as células da diagonal principal são iguais à primeira posição da diagonal e se são diferentes de espaço em branco
            if(tab.tabuleiro[i][i] == tab.tabuleiro[0][0] && tab.tabuleiro[i][i] != ' ')
            {
                verifica++;
            }else
            {
                // se for diferente ou um espaço em branco não acaba a verificação, pois, uma já falhou
                break;
            }
        }

        //se o número em "verifica" for igual ao número de linhas significa que foi encontrada vitória na diagonal principal
        if(verifica == tab.nLinhas)
            return 1;


        //verifica diagonal secundária
        //verificamos as células nas posições 3x1, 2x2, 3x1, exemplo para uma matriz 3x3
        verifica = 0;

        //começa na primeira linha, '0', e na última coluna, 'nLinhas-1', enquanto o 'i' for menor que o número total de linhas executa,
        // e incremeta o número de linhas e decrementa o número de colunas
        for(int i = 0, j = tab.nLinhas-1; i < tab.nLinhas; i++, j--)
        {

            //verifica se as células da diagonal secundária são iguais à última, encontrada no canto inferior esquerdo do tabuleiro
            // verifica ainda se alguma delas é um espaço em branco
            if(tab.tabuleiro[i][j] == tab.tabuleiro[tab.nLinhas-1][0] && tab.tabuleiro[i][j] != ' ')
            {
                verifica++;
            }else
            {
                //se não for verdade significa que pelo menos uma célula está incorreta, por isso, não vale a pena continuar
                break;
            }

        }

        //se o valor de "verifica" for igual ao número de linhas significa que encontrou vitória na diagonal secundária
        if(verifica == tab.nLinhas)
            return 1;
    }

    //caso não encontre vitória devolve '0'
    return 0;
}
