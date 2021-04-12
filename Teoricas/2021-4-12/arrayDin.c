#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Criar um novo tipo de dados chamado struct dados
typedef struct dados cliente;       // struct dados <==> cliente

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
	scanf(" %99[^\n]", t.nome);
	printf("Nº conta: "); 
	scanf(" %14s", t.nconta);
	printf("Saldo: "); 
	scanf("%d", &(t.montante));
	return t;
}

void escreve_tudo(cliente a[], int total){
    int i;
    
    printf("\nExistem %d clientes:\n", total);    
    for(i=0; i<total; i++)
        escreve_info(a[i]);
}



cliente* adiciona_cliente(cliente *b, int *total){ 
    cliente* aux;
    
    aux = realloc(b, sizeof(cliente) * (*total+1));
    
    if(aux == NULL){
        printf("Erro na realocacao\n");
        return b;
    }
    
    b = aux;   
    b[*total] = obtem_info();
    (*total)++;  
    return b;
}



cliente* elimina_cliente(cliente *b, int *total){
    char st[15];
    int i;
    cliente* aux;
    cliente t;
	
    printf("Nº de conta do cliente a eliminar: ");
    scanf(" %14s", st);
    
    for(i=0; i<*total && strcmp(st, b[i].nconta)!=0; i++)
        ;
    
    if(i == *total)     // cliente nao existe
        return b;
    
    // se for o unico
    if(*total == 1){
        free(b); *total = 0; return NULL;
    }
    
    t = b[i];
    b[i] = b[*total-1];   
    aux = realloc(b, sizeof(cliente)* (*total-1));
    
    if(aux == NULL){
        printf("Erro na realocacao\n");
        b[i] = t;
        return b;
    }
    else{
        b = aux;
        (*total)--;
    }    
    return b;
}




int main(){  
    
    cliente* banco = NULL;
    int total = 0, i;

    
    for(i=0; i<3; i++)
        banco = adiciona_cliente(banco, &total);
      
    escreve_tudo(banco, total);
    
    banco = elimina_cliente(banco, &total);
    
    escreve_tudo(banco, total);
    
    if(banco != NULL)
        free(banco);
  
    return 0;
}