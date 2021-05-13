#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 27

typedef struct palavra no, *pno;

struct palavra{
    char pal[50];
    int conta;
    pno prox;
}; 


void criaED(pno t[]){
    pno novo;
    char s[][50] = {"coimbra", "circo", "cereja", "carro"};
    int i, x[] = {3, 2, 4, 1};

    for(i=0; i<4; i++){
        novo = malloc(sizeof(no));
        if(novo == NULL)
            return;
        strcpy(novo->pal, s[i]);
        novo->conta = x[i];
        novo->prox = t[novo->pal[0]-'a'];
        t[novo->pal[0]-'a'] = novo;
    }  
}



void listaTudo(pno t[]){
    int i;
    pno aux;
    
    for(i=0; i<N; i++){
        printf("\nLista %c:\n", i==N-1? '?' : 'a'+i);
        aux = t[i];
        while(aux != NULL){
            printf("%s: %d\n", aux->pal, aux->conta);
            aux = aux->prox;
        }       
    }
}







int consulta(pno t[], char *st){
    int index = N-1;
    pno aux;

    // Descobrir a lista que interessa
    
    if(*st>='a' && *st<='z')
        index = *st - 'a';
    
    aux = t[index];
    
    // Procurar a palavra na lista
    while(aux!=NULL && strcmp(aux->pal, st) <0)
        aux = aux->prox;
    
    if(aux == NULL || strcmp(aux->pal, st) > 0)
        return 0;
    else
        return aux->conta;
}


pno criaPreenche(char *pal)
{
    pno novo;
	
    novo = malloc(sizeof(no));
    if(novo == NULL)
        return NULL;

    novo->conta = 1;
    strcpy(novo->pal, pal);
    novo->prox = NULL;
    return novo;
} 


void atualizaED(pno t[], char *st){
    int index = N-1;
    pno atual, ant = NULL, novo;
    
    if(*st>='a' && *st<='z')
        index = *st - 'a';
    
    atual = t[index];
    while(atual!=NULL && strcmp(atual->pal, st)<0){
        ant = atual;
        atual = atual->prox;
    }
    
    if(atual!=NULL && strcmp(atual->pal, st)==0){   // Palavra já existe
        atual->conta++;
        return;
    }
     
    novo = criaPreenche(st);
    
    if(ant == NULL){
        novo->prox = t[index];
        t[index] = novo;
    }
    else{
        novo->prox = atual;
        ant->prox = novo;
    }
}


int main()
{
    pno texto[N] = {NULL};
    int x;
    char st[50] = "foca";
  
    criaED(texto);
    
     atualizaED(texto, "cabo");
    atualizaED(texto, "centro");
    
    atualizaED(texto, "coimbra");
     atualizaED(texto, "centro");
      atualizaED(texto, "foca");
    
    listaTudo(texto);
    
    
   

/*
    x = consulta(texto, st);
    printf("A palavra %s surgiu %d vezes\n", st, x);        
*/
            
    // Falta libertar memoria

    return 0;
    
}
