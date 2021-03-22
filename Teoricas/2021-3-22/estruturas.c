#include <stdio.h>
#include <string.h>


// 1. Criação de um novo tipo de dados -> Chamado struct dados

typedef struct dados cliente; // Sinonimo

struct dados{
    char nome[100];
    char nconta[15];
    int montante;
};


void escreve_info(cliente a){
	printf("Nome: %s\nNº conta: %s\tSaldo: %d\n", 
          a.nome, a.nconta, a.montante);
}

cliente obtem_info(){
	cliente t;
	
	printf("Nome: "); 
	scanf("%99[^\n]", t.nome);
	printf("Nº conta: "); 
	scanf(" %14s", t.nconta);
	printf("Saldo: "); 
	scanf("%d", &(t.montante));
	return t;
}


int main(){
      
    cliente a;
    
    cliente b = {"Pedro Pires", "X222", 1000};     //2. Declarar variavel  
    
    cliente *p;
    
    p = &b;
    
   // (*p).montante = 5000;
    
    // ou
    
    p->montante = 5000;
    
    
    escreve_info(*p);
    
    
    return 0;
    
    a = obtem_info();

    escreve_info(a);
    
    
   // a.montante = 100;
    //strcpy(a.nome, "Maria Silva");
  //  strcpy(a.nconta, "A123");  
/*
    scanf(" %s", a.nome);   
    printf("%s - %d\n", a.nome, a.montante);
*/
  
    return 0;
}