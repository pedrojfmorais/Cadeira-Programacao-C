#include <stdio.h>

#define N 5

int repetidos(int a[], int tam){
    int i, j;
    
    for(i=0; i<tam; i++)        // Pegar num elemento de cada vez: a[i]
        for(j=i+1; j<tam; j++){
            printf("%d %d\n", i, j);
            if(a[i] == a[j])
                return 1;
        }
    
    return 0;
}

int main(){
    int tab[N] = {0, 2, 3, 2, 6};
    
    printf("Resultado: %d\n", repetidos(tab, N));
    
    return 0;
}