#include <stdio.h>
#include <string.h>

void printTraducao(char string[])
{
    char traduz[24][20] = 
    {
        "janeiro", "january",
        "fevereiro", "february",
        "marco", "march",
        "abril", "april",
        "maio", "may",
        "junho", "june",
        "julho", "july",
        "agosto", "august",
        "setembro", "setember",
        "outubro", "october",
        "novembro", "november",
        "dezembro", "december"
    };

    for (int i = 0; i < 24; i+=2)
    {
        if (!stricmp(string, traduz[i]))
        {
            printf("A traducao de %s e: %s. \n", string, traduz[i+1]);
            return;
        }
    }
    
    printf("O mes introduzido esta incorreto.");
}

int main(int argc, char const *argv[])
{
    
    char entrada[20];

    printf("Introduza um mes em portugues: ");
    scanf("%s", entrada);

    printTraducao(entrada);
    
    return 0;
}
