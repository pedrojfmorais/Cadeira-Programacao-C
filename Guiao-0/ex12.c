#include <stdio.h>
#include <string.h>

void removeEspacos(char string[])
{

    for (int i = 0; i < strlen(string); i++)
    {

        if (string[i] == ' ' && string[i-1] != ' ' && i != 0)
        {
            printf("\n");
        } else if (string[i] != ' ')
        {
            printf("%c", string[i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    char string[] = "    Hoje     e     Domingo!   ";
    
    removeEspacos(string);

    return 0;
}