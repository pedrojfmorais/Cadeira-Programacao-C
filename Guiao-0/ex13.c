#include <stdio.h>
#include <string.h>

void comparaStrings(char string_1[], char string_2[], char resultado[])
{

    if (!strcmp(string_1, string_2))
    {   
        strcpy(resultado, "Conteudo Igual!");
        return;

    } else if (strlen(string_1) == strlen(string_2))
    {
        strcpy(resultado, "Tamanho Igual!");
        return;

    } else if (strcmp(string_1, string_2) > 0)
    {
        strcat(string_2, string_1);
        strcpy(resultado, string_2);
        return;

    } else
    {
        
        strcat(string_1, string_2);
        strcpy(resultado, string_1);
        return;

    }
}

int main(int argc, char const *argv[])
{
    char string_1[] = "Coje e Domigo!";
    char string_2[] = "Boje e Domingo!";
    char resultado[] = "";
    
    comparaStrings(string_1, string_2, resultado);

    printf("%s \n", resultado);

    return 0;
}