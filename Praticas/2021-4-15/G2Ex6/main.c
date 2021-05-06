#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

int main()
{
    contactos *array_contactos=NULL;
    char op, input[100];
    int total=0;


    do
    {
        op=menu();
        switch(op)
        {
        case '1':
            array_contactos=adiciona_contacto(array_contactos, &total);
            break;
        case '2':
            printf("\nNome do contacto a eliminar: ");
            scanf("%s", input);
            array_contactos=elimina_contacto(array_contactos, &total,input);
            break;
        case '3':
            escreve_contactos(array_contactos,total);
            break;
        case '4':
            printf("\nNome do contacto a pesquisar: ");
            scanf(" %99[^\n]", input);
            procura_contacto(array_contactos, total, input);
            break;
        case '5':
            printf("\nNome do contacto que pretende atualizar: ");
            scanf("%s", input);
            array_contactos=atualiza_contacto(array_contactos, total, input);
            break;
        case '6':
            array_contactos=ordena_contactos(array_contactos,total);
            break;
        case '7':
            break;
        default:
            printf("Ocorreu um erro! \n");
            break;
        }
    }
    while(op!='7');

    free(array_contactos);

    return 0;
}
