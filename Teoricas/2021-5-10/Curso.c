
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct dados disc, *pdisc;
typedef struct pessoa aluno, *paluno;

struct dados {
    char nome[50];
    int ano, semestre, n_alunos;
    paluno lista;
    pdisc prox;
};

struct pessoa {
    char nome[100];
    char numero[15];
    paluno prox;
};


void libertaAlunos(paluno p){
    paluno auxA;
    
    while(p!=NULL){
        auxA = p;
        p = p->prox;
        free(auxA);
    }
}


void libertaTudo(pdisc p){
    pdisc auxD;
    
    while(p != NULL){
        libertaAlunos(p->lista);
        auxD = p;
        p = p->prox;
        free(auxD);
    }
}

pdisc criaLista(){
    disc a[3] = {{"SD", 1,1,2,NULL,NULL}, {"TAC", 1,2,0,NULL,NULL}, {"Prog", 1,2,3,NULL,NULL}};
    aluno b[5] = {{"Diogo", "12345"},{"Carlos", "345444"},{"Sofia", "123432"},{"Ana", "954483"},{"Joao", "336892"}};
    
    pdisc lista = NULL, novoD;
    paluno novoA;
    int i, j, k=0;
    
    for(i=0; i<3; i++){
        novoD = malloc(sizeof(disc));
        if(novoD == NULL){
            libertaTudo(lista);
            return NULL;
        }
        *novoD = a[i];
        for(j=0; j<novoD->n_alunos; j++){
            novoA = malloc(sizeof(aluno));
            if(novoA == NULL){
                libertaTudo(lista);
                return NULL;
            }
            *novoA = b[k++];
            novoA->prox = novoD->lista;
            novoD->lista = novoA;
        }
        novoD->prox = lista;
        lista = novoD;
    }
    return lista;
}




void mostraCurso(pdisc p){    
    paluno aux; 
    
    while(p != NULL){
        printf("\n%s: %d-%d com %d alunos inscritos\n",
                p->nome, p->ano, p->semestre, p->n_alunos);
        
        aux = p->lista;
        
        while(aux != NULL){
            printf("%s - %s\n", aux->nome, aux->numero);
            aux = aux->prox;
        }
        
        p = p->prox;
    }
}

pdisc adicionaD(pdisc p, char *nomeD, int a, int s){   
    pdisc novo;

    novo = malloc(sizeof(disc));
    if(novo == NULL)
        return p;
    
    strcpy(novo->nome, nomeD);
    novo->ano = a;
    novo->semestre = s;
    novo->n_alunos = 0;
    novo->lista = NULL;
    
    novo->prox = p;
    p = novo;

    return p;
}

void inscreveA(pdisc p, char *nomeD, char *nomeA, char *numA){
    paluno novo;
    
    while(p!=NULL && strcmp(p->nome, nomeD)!=0)
        p = p->prox;
    
    if(p == NULL)
        return;
    
    novo = malloc(sizeof(aluno));
    if(novo == NULL)
        return;
    
    strcpy(novo->nome, nomeA);
    strcpy(novo->numero, numA);
    
    novo->prox = p->lista;
    p->lista = novo;
    
    p->n_alunos++;
}


pdisc eliminaD(pdisc p, char *nomeD){
    pdisc atual = p, ant = NULL;
    
    while(atual != NULL && strcmp(atual->nome, nomeD)!= 0){
        ant = atual;
        atual = atual->prox;
    }
    
    if(atual == NULL)
        return p;
    
    if(ant == NULL)
        p = p->prox;
    else
        ant->prox = atual->prox;
    
    libertaAlunos(atual->lista);
    free(atual);
    
    return p; 
}


int main(){
    
    pdisc curso = NULL;     // Criar a ED
    
    curso = criaLista();
    
    curso = adicionaD(curso, "FCG", 1, 2);
    
    inscreveA(curso, "FCG", "Maria", "1234");
    inscreveA(curso, "Prog", "Maria", "1234");
    inscreveA(curso, "AAAA", "Maria", "1234");
    
    curso = eliminaD(curso, "Prog");
    
    mostraCurso(curso);
        
    // Libertar memoria dinamica
    libertaTudo(curso);
    return 0;
}
