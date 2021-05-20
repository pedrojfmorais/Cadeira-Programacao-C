
// Exame Normal Prog 2011-2012

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para array dinamico
typedef struct equipa eq, *peq;
struct equipa{
    char nome[50];
    int jogos; 
    int v, e, d;
};

// Estrutura para lista
typedef struct equipaL eqL, *peqL;
struct equipaL{
    char nome[50];
    int jogos; 
    int v, e, d;
    peqL prox;
};


void libertaLista(peqL p){
    peqL aux;
    
    while(p != NULL){
        aux = p;
        p = p->prox;
        free(aux);
    }
}

void mostraLista(peqL p){
    while(p != NULL){
        printf("Equipa %s realizou %d jogos:\t{%dV, %dE, %dD}\n",
                p->nome, p->jogos, p->v, p->e, p->d);
        p = p->prox;
    }
}

void resultado(peqL p, int m, int s){
       if(m > s)
            (p->v)++;
        else if(m == s)
            (p->e)++;
        else
            (p->d)++;   
}

peqL atualizaLista(peqL p, char* nome, int m, int s){
    
    peqL atual=p, ant=NULL, novo;
    
    while(atual!=NULL && strcmp(atual->nome, nome)<0){
        ant = atual;
        atual = atual->prox;
    }
    
    if(atual!=NULL && strcmp(atual->nome, nome) == 0){      // Equipa ja existe
        atual->jogos++;
        resultado(atual, m, s);
        return p;
    }    
    // Inserir nova equipa na lista    
    novo = malloc(sizeof(eqL));
    if(novo == NULL)
        return p;
    
    strcpy(novo->nome, nome);
    novo->jogos = 1;
    novo->d = novo->e = novo->v = 0;
    resultado(novo, m, s);
    
    if(ant == NULL){
        novo->prox = p;
        p = novo;
    }
    else{
        novo->prox = atual;
        ant->prox = novo;
    }
    return p;
}

peqL criaLista(char *nomeF){
    peqL lista = NULL;
    FILE* f;
    char eq1[50], eq2[50];
    int g1, g2;
    
    f = fopen(nomeF, "r");
    if(f == NULL)
        return lista;
    
    while(fscanf(f, " %s - %s : %d - %d", eq1, eq2, &g1, &g2) != EOF){ 
        lista = atualizaLista(lista, eq1, g1, g2);
        lista = atualizaLista(lista, eq2, g2, g1);
    }   
    
    fclose(f);
    return lista;
}


int main(){   
    peqL lista = NULL;
 
    lista = criaLista("res.txt");
    
    mostraLista(lista);
  
    libertaLista(lista);
    return 0;
}
