#include <stdio.h>
#include <ctype.h>
#include <string.h>

void verifica(char *tel, char *c)
{

    if (strlen(tel) != 9)
    {
        *c = 'I';
        return;

    } else if (tel[0] != '2')
    {
        *c = 'I';
        return;
    }
    
    for (int i = 1; i < 9; i++)
    {
        if (isdigit(tel[i]) == 0)
        {
            *c = 'I';
            return;
        }
    }
    *c = 'V';
}

int main(int argc, char const *argv[])
{
    char tel[] = "232567120";
    char resultado;

    verifica(tel, &resultado);

    printf("O numero de telefone da rede fixa PT encontra-se ");

    switch (resultado)
    {
        case 'I':
            printf("incorreto.\n");
            break;

        case 'V':
            printf("correto.\n");
            break;
        
        default:
            break;
    }

    return 0;
}
