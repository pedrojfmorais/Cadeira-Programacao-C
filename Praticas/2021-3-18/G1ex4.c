#include <stdio.h>
#include <stdlib.h>

void f1(int *t, int tam, int *np, int *ni, int *maior, int *pos)
{

    while(tam--)
    {
        if(*(t++)%2==0)
            ++*np;

        else
            (*ni)++;

        if(*t > *maior)
            {
                *maior=*t;
                *pos=10-tam;
            }
    }
}

void f2(int *t, int tam, int *np, int *ni, int *maior, int *pos)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(*(t+i)%2==0) //*(t+i) = t[i]
            ++*np; //*np=*np+1;

        else
            (*ni)++;

        if(*(t+i) > *maior)
            {
                *maior=*(t+i);
                *pos=i;
            }
    }
}

int main()
{
    int n=10,npares=0,nimpares=0,maior,pos=0, nimpares1=0, npares1=0;

    int tab[10]={1,3,7,5,2,10,9,7,7,1};
    maior=tab[0];

    f1(tab,n,&npares,&nimpares,&maior, &pos);
    printf("A tabela tem %d numeros pares e %d numeros impares",npares,nimpares);
    printf("\nO maior valor e %d e esta na posicao %d",maior,pos+1);

    printf("\nFUNCAO ALTERNATIVA\n");

    f2(tab,n,&npares1,&nimpares1,&maior, &pos);
    printf("A tabela tem %d numeros pares e %d numeros impares",npares,nimpares);
    printf("\nO maior valor e %d e esta na posicao %d",maior,pos+1);


}
