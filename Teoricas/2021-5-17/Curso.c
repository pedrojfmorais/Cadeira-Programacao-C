
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




pdisc insereDiscFinal(pdisc p, pdisc nova){
    pdisc aux;
    
    if(p==NULL)
        p = nova;
    else{
        aux = p;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = nova;
    }
    return p;
}

paluno insereAlunoFinal(paluno p, paluno novo){
    paluno aux;
    
    if(p==NULL)
        p = novo;
    else{
        aux = p;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    return p;
}

pdisc recuperaCurso(char *nomeF){
    pdisc p = NULL, novaD;
    paluno novoA;
    FILE *f;
    int total, i, j;
   
    f = fopen(nomeF, "rb");
    if(f == NULL)
        return NULL;    
    fread(&total, sizeof(int), 1, f);       // numero total de disciplinas
    for(i=0; i<total; i++){
        novaD = malloc(sizeof(disc));
        if(novaD == NULL){
            libertaTudo(p);
            fclose(f);
            return NULL;  
        }
        fread(novaD, sizeof(disc), 1, f);
        novaD->prox = NULL;
        novaD->lista = NULL;
        p = insereDiscFinal(p, novaD);
        for(j=0; j<novaD->n_alunos; j++){
            novoA = malloc(sizeof(aluno));
            if(novoA == NULL){
                libertaTudo(p);
                fclose(f);
                return NULL;  
            }
            fread(novoA->nome, sizeof(char), 100, f);
            fread(novoA->numero, sizeof(char), 15, f);
            novoA->prox = NULL;
            novaD->lista = insereAlunoFinal(novaD->lista, novoA);       
        }     
    }
    fclose(f);  
    return p; 
}



int main(){
    
    pdisc curso = NULL;     // Criar a ED
    
    curso = recuperaCurso("curso.dat");
    
    mostraCurso(curso);
   
    
    
    
    // Libertar memoria dinamica
    libertaTudo(curso);
    return 0;
}
