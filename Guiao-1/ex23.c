#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    
    if (argc != 3)
    {
        printf("Mais ou menos que duas palavras. \n");
        return 0;
    }
    
    if (strlen(argv[1]) != strlen(argv[2]))
    {
        printf("As palavras tem tamanhos diferentes. \n");
        return 0;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        printf("%c%c", argv[1][i], argv[2][i]);
    }
    
    printf("\n");

    return 0;
}
