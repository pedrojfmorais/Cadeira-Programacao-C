#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct objeto livro, *plivro;   

struct objeto{
    char titulo[100], autor[100];
    int cota;
    plivro prox;
};

void preenche(plivro p){
    printf("Titulo: ");
    scanf(" %99[^\n]", p->titulo);  
    printf("Autor: ");
    scanf(" %99[^\n]", p->autor); 
    printf("Cota: ");
    scanf("%d", &p->cota); 
    p->prox = NULL;
}

void mostra_info(plivro p){
    
    printf("\n");
    while(p != NULL){
        printf("%s\t%s\t%d\n", p->titulo, p->autor, p->cota);
        p = p->prox;
    }
}

plivro insere_ord(plivro p){
    plivro novo, aux;
    
    // 1. Alocar espaço   
    novo = malloc(sizeof(livro));
    if(novo == NULL)
        return p;
    
    // 2. Preencher dados do livro  
    preenche(novo);
    
    // 3. Inserir ordenadamente na lista  
    
    if(p == NULL || p->cota > novo->cota){  // Inserção à cabeça
       novo->prox = p;
       p = novo;
    }
    else{
        aux = p;
        while(aux->prox != NULL && aux->prox->cota < novo->cota)
            aux = aux->prox;
        
        novo->prox = aux->prox;
        aux->prox = novo;
    }
    
    return p;   
}

plivro elimina(plivro p, int x){
    plivro ant, atual;
    
    ant = NULL;
    atual = p;
    
    while(atual!=NULL && atual->cota!=x){
        ant = atual;
        atual = atual->prox;
    }

    if(atual == NULL)       // Livro nao existe
        return p;
    
    if(ant == NULL)     // 1º nó da lista
        p = p->prox;
    else                            // outro nó
        ant->prox = atual->prox;
    
    free(atual);

    return p;
}

void elimina_lista(plivro p){
    plivro aux;
    
    while(p != NULL){
        aux = p;
        p = p->prox;
        printf("A libertar %d\n", aux->cota);
        free(aux);
    }
}


int main(){
    
    plivro lista = NULL;        // Criar a lista

    // Adicionar alguns livros 
    for(int i=0; i<4; i++)
        lista = insere_ord(lista);
    
    mostra_info(lista);

    lista =  elimina(lista, 12);
    lista =  elimina(lista, 3);
    lista =  elimina(lista, 23);

    
    mostra_info(lista); 
      
    // Libertar a memoria da lista
    
    elimina_lista(lista);
            
    return 0;
}