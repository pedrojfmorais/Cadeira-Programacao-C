#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct info no, *pno;

struct info{
    char letra;
    pno prox;
};


pno cria_lista(char st[]){
    int i;
    pno p=NULL, novo;
	
    for(i=strlen(st)-1; i>=0; i--){
        novo = malloc(sizeof(no));
        if(!novo) return p;
        novo->letra = st[i];
        novo->prox = p;
        p = novo;
    }
    return p;
}


void mostra_lista(pno p){

    while(p!=NULL){
        printf("%c\t", p->letra);
        p = p->prox;
    }
    printf("\n\n");
}


void transfere(pno* p1, pno* p2){
    pno aux;
		
    aux = *p1;   
    *p1 = (*p1)->prox;    
    aux->prox = *p2;
    *p2 = aux;
    
/*
    printf("Dentro da funcao\n");
    mostra_lista(p1);
    mostra_lista(p2);
*/
     
}

int main1(){
    pno l1, l2;
	
    l1 = cria_lista("ABC");
    l2 = cria_lista("DE");
	
    printf("\nAntes:\nLista 1: \n");
    mostra_lista(l1);
    printf("Lista 2: \n");
    mostra_lista(l2);
     
    transfere(&l1, &l2);
    
    printf("Depois\n");
    printf("Lista 1: \n");
    mostra_lista(l1);
	
    printf("Lista 2: \n");
    mostra_lista(l2);
	
    // Falta libertar listas
    return 0;
}




pno insere(pno p, pno x){
    x->prox = p;
    p = x;
    return p;
}


void divide(pno* p, pno* a, pno* b, pno* c){  
  
    pno lista=*p, l1=NULL, l2=NULL, l3=NULL, aux;

    while(lista != NULL){
        aux = lista;
        lista = lista->prox;
        
        if(isalpha(aux->letra))
            l1 = insere(l1, aux);
        else if(isdigit(aux->letra))
            l2 = insere(l2, aux);
        else
            l3 = insere(l3, aux);   
    }
    
    *p = NULL;
    *a = l1;
    *b = l2;
    *c = l3;

}

int main(){

     pno lista = cria_lista("ABC459D!#X");
     pno l1=NULL, l2=NULL, l3=NULL;
     
     mostra_lista(lista);
          
     divide(&lista, &l1, &l2, &l3);
     
    
     mostra_lista(l1);
     mostra_lista(l2);
     mostra_lista(l3);
     
     // Libertar as listas
     return 0;
     
}




