#include <stdio.h>
#include <stdlib.h>
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

    printf("\n Nome: %s\t N Conta: %s \t Saldo: %d \n", 
           a.nome, a.nConta, a.montante);

}

cliente obtem_info()
{
    cliente t;
    
    printf("\n");

    printf("Nome: ");
    scanf(" %99[^\n]", t.nome);
    
    printf("N Conta: ");
    scanf(" %14s", t.nConta);
    
    printf("Saldo: ");
    scanf(" %d", &(t.montante));

    return t;

}

void mostraTodos(cliente *banco, int totalClientes)
{

    printf("\nExistem %d clientes: \n", totalClientes);

    for (int i = 0; i < totalClientes; i++)
    {
        escreve_info(banco[i]);
    }
    
}

cliente *adicionaCliente(cliente *banco, int *totalClientes)
{

    cliente *aux;
    aux = realloc(banco, sizeof(cliente)*(*totalClientes+1));
    
    if (aux == NULL)
    {
        printf("Erro na realocacao!\n");
        return banco;
    }
    
    banco = aux; 
    
    banco[(*totalClientes)] = obtem_info();
    (*totalClientes)+=1;

    return banco;
}

cliente *eliminaCliente(cliente *banco, int *totalClientes)
{
    int i;
    char nContaEliminar[100];
    cliente *aux;
    cliente t;

    printf("Insira o numero de conta do cliente a eliminar: ");
    scanf(" %s", nContaEliminar);

    for (i = 0; i < *totalClientes && strcmp(nContaEliminar, banco[i].nConta); i++);

    if (i == *totalClientes)
    {
        printf("\n\n !! -- Cliente nao existe -- !! \n\n");
        return banco;
    }
    
    if (*totalClientes == 1)
    {
        free(banco);
        *totalClientes = 0;
        return NULL;
    }

    t = banco[i];
    banco[i] = banco[*totalClientes-1];

    aux = realloc(banco, sizeof(cliente)*(*totalClientes-1));
    if (aux == NULL)
    {
        printf("Erro na realocacao!\n");
        banco[i]=t;
        return banco;
    }

    banco = aux; 

    (*totalClientes)--;

    return banco;

}

void guardarDados(cliente banco[], int totalClientes)
{
    FILE *f;
    
    f = fopen("banco.dat", "wb");

    if (f == NULL)
    {
        printf("Erro no acesso ao ficheiro! \n");
        return;
    }
    
    fwrite(&totalClientes, sizeof(int), 1, f);

    fwrite(banco,sizeof(cliente),totalClientes,f);
    
    fclose(f);

}

cliente *lerDados(int *totalClientes)
{

    FILE *f;
    cliente *aux;

    f = fopen("banco.dat","rb");

    if (f == NULL)
    {
        printf("Erro no acesso ao ficheiro! \n");
        *totalClientes = 0;
        return NULL;
    }
    
    fread(totalClientes, sizeof(int), 1, f);

    aux = malloc(sizeof(cliente)*(*totalClientes));

    if(aux == NULL){
        fclose(f);
        *totalClientes = 0;
        return NULL;
    }

    fread(aux, sizeof(cliente), *totalClientes, f);

    fclose(f);

    return aux;

}

int main(int argc, char const *argv[])
{
    int input = 0;
    cliente *banco = NULL;
    int totalClientes = 0;

    banco = lerDados(&totalClientes);

    while (1)
    {   
        printf("\n");
        printf(" 1 - Novo Cliente\n");
        printf(" 2 - Mostrar Clientes\n");
        printf(" 3 - Eliminar Cliente\n");
        printf(" 0 - Sair\n");

        printf("\n Opcao: ");
        scanf(" %d", &input);

        switch (input)
        {
        case 1:
            banco = adicionaCliente(banco, &totalClientes);
            break;
        case 2:
            mostraTodos(banco, totalClientes);
            break;
        case 3:
            banco = eliminaCliente(banco, &totalClientes);
            break;
        case 0:
            guardarDados(banco, totalClientes);

            if(banco != NULL)
                free(banco);

            return 0;
            break;
        
        default:
            printf("\n Opcao incorreta, tente novamente! \n\n");
            break;
        }
    }
    
    if(banco != NULL)
        free(banco);

    return 0;
}
