#include <stdio.h>
#include <string.h>

void removeEspacos(char string[])
{

    char stringFinal[strlen(string)];
    int j = 0;

    for (int i = 0; i < strlen(string); i++)
    {

        if (string[i] != ' ')
        {
            stringFinal[j] = string[i];
            j++;
        } else if (string[i] == ' ' && string[i-1] != ' '  && i != 0)
        {
            stringFinal[j] = string[i];
            j++;
        }
    }
    
    stringFinal[j] = '\0';
    strcpy(string, stringFinal);
    
}

int main(int argc, char const *argv[])
{
    char string[] = "    Hoje     e     Domingo!   ";
    
    printf("Antes de remover espacos: \"%s\" \n", string);

    removeEspacos(string);

    printf("Depois de remover espacos: \"%s\" \n", string);

    return 0;
}