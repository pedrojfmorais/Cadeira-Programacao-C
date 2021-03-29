#include <stdio.h>
#include <string.h>

int capicua(char string[])
{
    char stringFinal[strlen(string)];
    int j = 0;

    for (int i = strlen(string)-1; i >= 0; i--)
    {   
        stringFinal[j] = string[i];
        j++;
        
    }

    stringFinal[j] = '\0';

    if (!strcmp(string, stringFinal))
    {
        return 1;
    }
    
    return 0;
}


int main(int argc, char const *argv[])
{
    char string[] = "racecar";
    int resultado = 0;
    
    resultado = capicua(string);

    if (resultado)
    {
        printf("A string e capicua. \n");
    } else
    {
        printf("A string nao e capicua. \n");
    }
    
    return 0;
}