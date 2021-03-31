#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    
    char array[10][50];
    int i;
    int j = 1;

    if ((argc-1) % 2 != 0 || (argc-1) > 20)
    {
        return 0;
    }
    
    for (i = 0; i < (argc-1)/2; i++)
    {
        strcpy(array[i], "");
        
        strcat(array[i], argv[j]);
        strcat(array[i], argv[(argc-j)]);

        j+=1;
    }

    for (j = 0; j < i; j++)
    {
        printf("Linha %d: %s \n", j, array[j]);
    }    

    return 0;
}