
#include <stdio.h>
#include <stdlib.h>


typedef struct numero no, *pno;

struct numero{
    int val;
    pno prox;
};

pno criaLista(){
    int a[5] = {2, 5, 7, 9, 12}, i;
    pno lista=NULL, novo;
    
    for(i=4; i>=0; i--){
        novo = malloc(sizeof(no));
        if(!novo) return lista;
        novo->val = a[i];
        novo->prox = lista;
        lista = novo;
    }
    return lista;  
}



int contaL(pno lista){
    
    if(lista == NULL)
        return 0;
    else
        return 1 + contaL(lista->prox);
}

void escreveInv(pno lista){

    if(lista == NULL)
        return;
    else{
        escreveInv(lista->prox);
        printf("%d\t", lista->val);
    }
}

int mainL(){
    
    pno lista = criaLista();
    int x;
    
    escreveInv(lista);

/*
    x = contaL(lista); 
    printf("A lista tem %d nos\n", x);
*/
    
    return 0;
}


int potencia(int b, int e){
    
    if(e==0)
        return 1;
    else
        return b * potencia(b, e-1);
}


int main(){
    
    printf("Res: %d\n", potencia(2, 8));
    return 0;
}



