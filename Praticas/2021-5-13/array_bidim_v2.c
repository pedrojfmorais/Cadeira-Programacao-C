#include<stdio.h>
#include<stdlib.h>

 char** Cria_matriz_dinamica(char **v, int l, int c)
 {
    int i,j;
    v = (char**)malloc(sizeof(char*)* l );


    if(v == NULL)
    {
        printf("Erro na alocacao de memoria");
        return NULL; //se numa função que retorna um ponteiro deve retornar NULL
    }
    for (i=0; i<l; i++)
    {
        v[i] = (char*)malloc(sizeof(char)* c );
        if(v[i] == NULL)
        {
            printf("Erro na alocacao de memoria");
            return NULL;
        }

        for (j = 0; j < c; j++)
        {
            v[i][j] = '*';
        }

    }
    return v;
 }

char** Aumenta_Linha(char **v, int* l, int c)
{
    char **auxl;
    char *auxc;
    int i,j;
    (*l)++;

    auxl=(char **)realloc(v, sizeof(char *)*(*l));
    if(auxl==NULL)
    {
        printf("Erro na alocacao de memoria");
        return NULL;
    }
    v=auxl;

    //for(i=l-1; i<l; i++)
    //{
        auxc=(char *)realloc(v[(*l)-1], sizeof(char)*c);
        if(auxc == NULL)
        {
            printf("Erro na alocacao de memoria");

            return NULL; //se for uma função que devolve um ponteiro deve fazer return NULL
        }
        v[(*l)-1]=auxc;

    //}
    //Escrita dos caracteres na nova linha
    for (j = 0; j < c; j++)
            v[(*l)-1][j] = '-';
    return v;
}

char** Aumenta_Coluna(char **v, int l, int *c)
{

    char *auxc;
    int i,j;
    (*c)++;


    for(i=0; i<l; i++)
    {
        auxc=(char *)realloc(v[i], sizeof(char)*(*c));

        if(auxc == NULL)
        {
            printf("Erro na alocacao de memoria");
            return NULL;
        }
        v[i]=auxc;
    }
    //Atualiza a nova coluna com o caracter
    for (i = 0; i < l; i++)
            v[i][(*c)-1] = '+';

    return v;
}



int main()
{

    int l,c,i,j;
    char **v;

    char *auxc;

    printf("Linhas:");
    scanf("%d",&l);
    printf("Colunas:");
    scanf("%d",&c);

    v = Cria_matriz_dinamica(v,l,c);
//Mostrar a matriz
    for(i=0;i<l;i++)
    {
        for(j=0;j<c;j++)
            printf("  %c",v[i][j]);

        printf("\n");
    }


    printf("\n\n Vou aumentar uma linha....\n");

    v=Aumenta_Linha(v,&l,c);

    for(i=0;i<l;i++)
    {
        for(j=0;j<c;j++)
            printf("  %c",v[i][j]);

        printf("\n");
    }

    printf("\n\n Vou aumentar uma coluna....\n");

    v=Aumenta_Coluna(v,l,&c);

    for(i=0;i<l;i++)
    {
        for(j=0;j<c;j++)
            printf("  %c",v[i][j]);

        printf("\n");
    }

    //Como libertar a memória

    for(i=0; i<l; i++) //Liberto o array de caracteres correspondente a cada linha
    {
        free(v[i]);
    }
    free(v);//liberto o array de ponteiros
}


