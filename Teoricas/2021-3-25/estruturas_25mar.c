#include <stdio.h>
#include <string.h>

#define MAX 100

// 1. Criação do tipo struct dados
typedef struct dados cliente;   // struct dados <==> cliente

struct dados{
    char nome[100];
    char nconta[15];
    int montante;
};

void escreve_info(cliente a){
    printf("Nome: %s\nNº conta: %s\tSaldo: %d\n", a.nome, a.nconta, a.montante);
}

cliente obtem_info(){
	cliente t;
	
	printf("Nome: "); 
	scanf(" %99[^\n]", t.nome);
	printf("Nº conta: "); 
	scanf(" %14s", t.nconta);
	printf("Saldo: "); 
	scanf("%d", &(t.montante));
	return t;
}

void escreve_todos(cliente a[], int total){
    int i;
    
    printf("\nExistem %d clientes:\n", total);
    for(i=0; i<total; i++)
        escreve_info(a[i]);  
}

void adiciona_cliente(cliente tab[], int* n){
    
	if(*n == MAX)
		printf("Tabela completa\n");
	else
	{
		tab[*n] = obtem_info();
		(*n)++;
	}
}

void elimina_cliente(cliente tab[], int *n){
	char st[100];
	int i;
	
	printf("Nº de conta do cliente a eliminar: ");
	scanf(" %s", st);
	
	for(i=0; i<*n && strcmp(st, tab[i].nconta)!=0; i++)
            ;
	
	if(i==*n)
 		printf("Cliente não existe\n");
	else{
		tab[i] = tab[*n-1];
		(*n)--;
	}
}

int main(){
    
    cliente banco[MAX];
    int total = 0;
 
    int j;
    for(j=0; j<3; j++)
        adiciona_cliente(banco, &total);
    
    escreve_todos(banco, total);
    
    elimina_cliente(banco, &total);
    
     escreve_todos(banco, total);
   
    return 0;
}