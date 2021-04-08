#include <stdio.h>
#include <stdlib.h>

void inicializa(int a[], int n){
    int i;

    for(i=0; i<n; i++)
        a[i] = 2*i;
}

void mostra(int a[], int n){
    int i;

    printf("A tabela tem %d elementos:\n", n);
    for(i=0; i<n; i++)
        printf("%d\t", a[i]);
    putchar('\n');
}

    
int main(){   
    //int tab[5];
    
    int *tab, *b;    
    int tam, mais;
    
    printf("Tamanho do array: ");
    scanf("%d", &tam);          // tam -> 5
    
    tab = malloc(sizeof(int) * tam);
    if(tab == NULL){
        printf("Erro de memoria\n");
        return 0;
    }

    inicializa(tab, tam);  
    mostra(tab, tam);
    
    printf("Adicionar elementos: ");
    scanf("%d", &mais);
    
    b = realloc(tab, sizeof(int)*(tam+mais));
    if(b == NULL)
        printf("erro na realocacao\n");
    else{
        tab = b;
        
        inicializa(tab+tam, mais);
        tam += mais;
    }
       
    mostra(tab, tam);
       
    free(tab);
            
    return 0;
}