#include <stdio.h>
#include <stdlib.h>

typedef struct objeto livro, *pLivro;

struct objeto
{
    char titulo[100];
    char autor[100];
    int cota;

    pLivro prox;
};

void preenche(pLivro p)
{

    printf("Insira o titulo: ");
    scanf(" %99[^\n]", p->titulo);

    printf("Insira o autor: ");
    scanf(" %99[^\n]", p->autor);

    printf("Insira a cota: ");
    scanf(" %d", &p->cota);

    p->prox = NULL;

    printf("\n");
}

pLivro insere_inicio(pLivro p)
{
    pLivro novo;

    // 1. Alocar espaço

    novo = malloc(sizeof(livro));

    if (novo == NULL)
    {
        return p;
    }

    // 2. Preencher informação
    preenche(novo);

    // 3. Inserir no inicio da lista
    novo->prox = p;

    p = novo;
    return p;
}

void mostra_info(pLivro p)
{
    printf("\n");
    while (p != NULL)
    {
         
        printf("Titulo: %s\n", p->titulo);
        printf("Autor: %s\n", p->autor);
        printf("Cota: %d\n\n", p->cota);

        p = p->prox;
    }
}

int main(int argc, char const *argv[])
{
    
    pLivro lista = NULL; // criar lista ligada

    //adicionar alguns livros
    for (int i = 0; i < 3; i++)
    {
        lista = insere_inicio(lista);
    }
    
    mostra_info(lista);

    //Falta libertar a lista

    return 0;
}
