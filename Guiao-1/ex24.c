#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    float media;

    for (int i = 1; i < argc; i++)
    {
        media += atoi(argv[i]);
    }
    
    media /= argc-1;

    printf("%.2f\n", media); 

    return 0;
}
