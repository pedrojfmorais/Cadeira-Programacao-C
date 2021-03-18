#include <stdio.h>
#include <stdlib.h>
#define TAM 10

void procura_dupla(int *t, int tam, int *prim, int *seg) //INEFICIENTE
{
    int i;
    *prim=*t; *seg=*t;
    for(i=1;i<tam;i++)
        if (*prim < *(t+i))
            *prim = *(t+i);
    for(i=1;i<tam;i++)
        if ((*seg < *(t+i)) &&  (*prim != *(t+i)))
            *seg = *(t+i);
}

void procura_dupla1(int *t, int tam, int *prim, int *seg) {
    int i;

    *prim = *t;
    *seg = *(t+1);
    for(i=1;i<tam;i++) {
        if (*prim < *(t+i)) { //primeiro verifica se o primeiro é maior e se sim atribui o antigo primeiro ao segundo e troca o primeiro com o novo valor
                *seg = *prim;
                *prim = *(t+i);
        } else if (*seg < *(t+i) && *prim != *(t+i))//caso o primeiro não troque verifica o segundo desde que o valor não seja igual ao primeiro (para primeiros repetidos)
            *seg = *(t+i);
    }
}

void procura_dupla2(int *t, int tam, int *prim, int *seg) {
    int i,p=0,s=1;

    for(i=1;i<tam;i++) {
        if (*(t+p) < *(t+i)) { //O algoritmo é igual ao anterior mas guarda as posições em vez dos conteúdos
            s = p;
            p = i;
        } else if (*(t+s) < *(t+i) && *(t+p)!=*(t+i))
            s = i;
    }
    *prim = *(t+p);
    *seg = *(t+s);
}

void procura_dupla3(int *t, int tam, int *prim, int *seg) {
    *prim = *t;
    *seg = *(t+1);
    while (tam--) {
        if (*prim < *t) {
            *seg = *prim;
            *prim = *t;
        } else if (*seg < *t && *prim!=*t)
            *seg = *t;
        t++;
    }
}



int main()
{
    int n=10,primeiro,segundo;

   // printf("Quantos valores pretende guardar? ");
   // scanf("%d", &n);
    //int tab[10]={1,8,3,4,8,6,7,10,2,10};
    int tab[TAM] = {10,9,7,5,2,10,8,7,1,9};
    procura_dupla3(tab,n,&primeiro, &segundo);
    printf("O maior elemento da tabela e %d",primeiro);
    printf("\nO segundo maior elemento da tabela e %d",segundo);



}
