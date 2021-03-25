#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define TAM1 10
#define TAM2 10
#define TEL 9


int comuns(int *tabA, int tamA, int *tabB, int tamB);

void ex5(){

    int array_1[TAM1] = {1,2,3,5,12,16,19,27,60,71};
    int array_2[TAM2] = {2,3,7,15,22,30,39,47,50,51};

    printf("A tabela A e a tabela B tem %d elementos em comum. \n", comuns(array_1, TAM1, array_2, TAM2));

}

int comuns(int *tabA, int tamA, int *tabB, int tamB)
{
    int comuns = 0;
    int j = 0;

    for (int i = 0; i < tamA; i++)
    {
        if (tabA[i] > tabB[tamB-1]) // se o valor de tabA[i] for maior que o ultimo valor de tabB sai do ciclo for
            break;
        
        while (tabA[i]>=tabB[j]) // se o valor de tabA[i] for maior ou igual ao de tabB[j] vai compara-los
        {
            if (tabA[i] == tabB[j])
                comuns++;
            
            j++;
        }
    }
    
    return comuns;
}

void verifica(char *tel, char *c);

void ex9()
{

    char tel[TEL] = {"223922562"};
    char verify = ' ';

    verifica(tel, &verify);

    printf("O numero de telefone da rede fixa PT fornecido encontra-se ");

    switch (verify)
    {
    case 'V':
        printf("valido. \n");
        break;
    
    case 'I':
        printf("invalido. \n");
        break;

    default:
        printf("NONE \n");
        printf("Ocorreu um erro ao executar o programa!");
        break;
    }
}

void verifica(char tel[], char *c)
{  
    
    for (int i = 0; i < 9; i++)
    {
        if (isdigit(tel[i]) == 0 || tel[0] != '2' || strlen(tel) < 9)
        {
            *c = 'I';
            return;
        }
    }

    *c = 'V';
}

int main(int argc, char const *argv[])
{
    //ex5();
    ex9();

    return 0;
}
