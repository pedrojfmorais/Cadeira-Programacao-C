#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
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

    char entrada[20];

    printf("Introduza um mes em portugues: ");
    scanf("%s", entrada);

    for (int i = 0; i < 24; i+=2)
    {
        if (!stricmp(entrada, traduz[i]))
        {
            printf("A traducao de %s e: %s. \n", entrada, traduz[i+1]);
            return 0;
        }
    }
    
    printf("O mes introduzido esta incorreto.");

    return 0;
}
