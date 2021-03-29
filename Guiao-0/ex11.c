#include <stdio.h>
#include <string.h>

void inverteString(char string[])
{

    for (int i = strlen(string); i >= 0; i--)
    {
        printf("%c", string[i]);
    }
}

int main(int argc, char const *argv[])
{
    char string[] = "Hoje e Domingo!";
    
    inverteString(string);

    return 0;
}
