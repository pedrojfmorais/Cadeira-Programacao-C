#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ex1.h"


int main()
{
    pno lista = NULL; //a)
    int op;

    do{
		printf("\n\n1 - Mostrar Lista\n");
		printf("2 - Inserir Elemento na Lista\n");
		printf("3 - Atualiza peso de uma pessoa\n");
		printf("4 - Elimina pessoa da lista\n");
		printf("5 - Elimina pessoas da lista com imc superior\n");
		printf("6 - Grava lista em ficheiro txt\n");
		printf("7 - Le lista de ficheiro txt\n");
		printf("8 - Sair\n");
		printf("Opcao: ");
		scanf("%d", &op);
    switch(op)
    {
        case 1: mostra_info(lista);
                break;
        case 2: //lista = insere_ord(lista);
                lista = insere_final(lista);
                break;
        case 3: atualiza_peso(lista, 1, 70);
                break;
        case 4: lista = elimina(lista,2);
                break;
        case 5: lista = elimina_lista_imc_superior(lista, 21);
                break;
        case 6: grava_lista_imc("lista_imc.txt",lista);
                break;
        case 7: //lista = le_lista_imc_ficheiro_ordenado("lista_imc.txt", lista);
                lista = le_lista_imc_ficheiro("lista_imc.txt", lista);
                break;
        case 8: //liberta_lista(lista);
                return 0;


    }
    }while(op>=1 && op<8);

    liberta_lista(lista);
    return 0;
}
