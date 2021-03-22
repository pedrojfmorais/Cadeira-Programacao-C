#include <stdio.h>
#include <string.h>

struct data
{
    int dia, mes, ano;
};

struct dados
{
    char nome[100];
    char nConta[15];
    int montante;
    struct data in;
};

typedef struct dados cliente;

void escreve_info(cliente a)
{

    printf("\n Nome: %s\n N Conta: %s \n Saldo: %d \n", 
           a.nome, a.nConta, a.montante);

}

cliente obtem_info()
{
    cliente t;

    printf("Nome: ");
    scanf("%99[^\n]", t.nome);
    
    printf("N Conta: ");
    scanf("%14s", t.nConta);
    
    printf("Saldo: ");
    scanf("%d", &(t.montante));

    return t;

}

int main(int argc, char const *argv[])
{
    cliente a;
    cliente b = {"Pedro Pires", "X222", 1000};

    cliente c = obtem_info();

    cliente *p;

    p = &b;

    (*p).montante = 5000; 

    // ou

    p->montante = 200;

    escreve_info(*p);

    a.montante = 100;
    strcpy(a.nome, "Maira Silva");
    strcpy(a.nConta, "A123");

 
    escreve_info(c);

    return 0;
}
