#include <stdio.h>
#include <stdlib.h>
void roda_variavel(float *primeira, float *segunda, float *terceira)
{
    float temp;
    //printf("%p\t%p\t%p: ",primeira, segunda, terceira);
    temp= *segunda;
    *segunda=*primeira;
    *primeira=*terceira;
    *terceira=temp;
   // printf("\n%p\t%p\t%p: ",primeira, segunda, terceira);
}

void roda_variavel_sem_ponteiros(float primeira, float segunda, float terceira)
{
    float temp;
    printf("\nO QUE ACONTECE NA FUNCAO");
    printf("\n%.1f\t%.1f\t%.1f: ",primeira, segunda, terceira);
    temp= segunda;
    segunda=primeira;
    primeira=terceira;
    terceira=temp;
    printf("\n%.1f\t%.1f\t%.1f: ",primeira, segunda, terceira);
}

int main()
{
    float x=1.0, y=2.5, z=3.7;

    printf("ANTES DA ROTACAO: ");
    printf("\n%.1f\t%.1f\t%.1f",x,y,z);
    roda_variavel_sem_ponteiros(x, y, z);
    printf("\nO QUE ACONTECE NO MAIN DEPOIS DE CHAMAR A FUNCAO");
    printf("\nSEM PONTEIROS NAO RODA: ");
    printf("\n%.1f\t%.1f\t%.1f",x,y,z);
    roda_variavel(&x, &y, &z);
    printf("\nDEPOIS DA ROTACAO COM PONTEIROS: ");
    printf("\n%.1f\t%.1f\t%.1f",x,y,z);
}
