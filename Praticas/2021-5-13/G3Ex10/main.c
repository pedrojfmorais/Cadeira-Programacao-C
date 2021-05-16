#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banco.h"

int main(void)
{
    int op;
	Cliente novo = {"Ricardo Lopes", "Coimbra", 100, 5000};
	char origem[TAM], destino[TAM];

	do{
		printf("\n\n1 - Mostrar ficheiro\n");
		printf("2 - Mostrar tamanho em bytes e numero de clientes\n");
		printf("3 - Mostrar ficheiro por ordem inversa\n");
		printf("4 - Efetuar transferencia\n");
		printf("5 - Eliminar um cliente\n");
		printf("6 - Adicionar cliente a um ficheiro\n");
		printf("7 - Juntar dois ficheiros\n");
		printf("8 - Sair\n");
		printf("Opcao: ");
		scanf("%d", &op);
		switch(op){
			case 1:	  printf("Ficheiro 1:\n"); mostra_ficheiro("clientes1_ex10.dat") ;
					  printf("Ficheiro 2:\n"); mostra_ficheiro("clientes2_ex10.dat") ;
					  break;
			case 2:   //printf("Ficheiro 1:\n"); conta_bytes_clientes("clientes1_ex10.dat") ;
					  //printf("Ficheiro 2:\n"); conta_bytes_clientes("clientes2_ex10.dat") ;
					  break;
			case 3:   //printf("Ficheiro 1:\n"); mostra_ficheiro_invertido("clientes1_ex10.dat") ;
					  //printf("Ficheiro 2:\n"); mostra_ficheiro_invertido("clientes2_ex10.dat") ;
					  break;
			case 4:   //transfere("clientes1_ex10.dat", "Elsa Ourem", "Dinis Pais", 200); //deveria receber o 1 ou 0 para saber se a transferência correu bem
					  break;
			case 5:   //elimina_cliente("clientes1_ex10.dat", "Ricardo Lopes");
                      break;
		    case 6:   //adiciona_cliente("clientes1_ex10.dat",novo);
					  break;
		    case 7:   //junta_tudo("clientes1_ex10.dat", "clientes2_ex10.dat", "tudo.dat");
				      //printf("Ficheiro unico:\n"); mostra_ficheiro("tudo.dat") ;
					  break;
		}
	}while(op!=8);
	return 0;
}
