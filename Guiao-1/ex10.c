#include <stdio.h>
#include <string.h>

int tres_consecutivos(char *frase)
{

    for (int i = 1; i < strlen(frase)-1; i++)
    {
        if (frase[i-1] == frase[i] && frase[i] == frase[i+1])
        {
            return 1;
        }
    }
    
    return 0;
}

int main(int argc, char const *argv[])
{
    char frase[] = "isto e uma frase abc";
    int resultado;
    
    resultado = tres_consecutivos(frase);

    printf("Na frase \"%s\" ", frase);

    if (resultado == 0)
    {
        printf("nao ");
    }
    
    printf("existem 3 caracteres consecutivos iguais. \n");

    return 0;
}
