#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct objeto livro, *plivro;   

struct objeto{
    char titulo[100], autor[100];
    int cota;
    plivro prox;
};


void preenche(plivro p)
{
    printf("Titulo: ");
    scanf(" %99[^\n]", p->titulo);  
    printf("Autor: ");
    scanf(" %99[^\n]", p->autor); 
    printf("Cota: ");
    scanf("%d", &p->cota); 
    p->prox = NULL;
}



void mostra_info(plivro p){
    
    while(p != NULL){
        printf("%s\t%s\t%d\n", p->titulo, p->autor, p->cota);   
        p = p->prox;
    }
}

plivro insere_inicio(plivro p){
    
    plivro novo;
    
    // 1. Alocar espaço
    
    novo = malloc(sizeof(livro));
    if(novo == NULL)
        return p;
    
    // 2. Preencher informação
    preenche(novo);
    
    // 3. Inserir no inicio da lista
    
    novo->prox = p;
    p = novo;
    
    return p;   
}


int main(){
    
    plivro lista = NULL;        // Criar uma lista ligada
    
    // Adicionar alguns livros
    
    for(int i=0; i<3; i++)
        lista = insere_inicio(lista);
    
    mostra_info(lista);
    
    // Falta libertar a lista

    
    return 0;
}