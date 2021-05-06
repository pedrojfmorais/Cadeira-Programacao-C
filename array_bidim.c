#include<stdio.h>
#include<stdlib.h>

int main()
{

    int l,c,i,j;
    char **v;
    char **auxl;
    char *auxc;

    printf("Linhas:");
    scanf("%d",&l);
    printf("Colunas:");
    scanf("%d",&c);

    v = (char**)malloc(sizeof(char*)* l );


    if(v == NULL)
    {
        printf("Erro na alocacao de memoria");
        return 0; //se numa função que retorna um ponteiro deve retornar NULL
    }
    for (i=0; i<l; i++)
    {
        v[i] = (char*)malloc(sizeof(char)* c );
        if(v[i] == NULL)
        {
            printf("Erro na alocacao de memoria");
            free(v);//porque estou no main
            return 0;
        }

        for (j = 0; j < c; j++)
        {
            v[i][j] = '*';
        }

    }
//Mostrar a matriz
    for(i=0;i<l;i++)
    {
        for(j=0;j<c;j++)
            printf("  %c",v[i][j]);

        printf("\n");
    }


    printf("\n\n Vou aumentar uma linha....\n");
    l++;

    auxl=(char **)realloc(v, sizeof(char *)*l);
    if(auxl==NULL)
    {
        printf("Erro na alocacao de memoria");
        return 0;
    }
    v=auxl;

    //for(i=l-1; i<l; i++)
    //{
        auxc=(char *)realloc(v[l-1], sizeof(char)*c);
        if(auxc == NULL)
        {
            printf("Erro na alocacao de memoria");

            return 0; //se for uma função que devolve um ponteiro deve fazer return NULL
        }
        v[l-1]=auxc;

    //}

    for (j = 0; j < c; j++)
            v[l-1][j] = '-';


    for(i=0;i<l;i++)
    {
        for(j=0;j<c;j++)
            printf("  %c",v[i][j]);

        printf("\n");
    }

    printf("\n\n Vou aumentar uma coluna....\n");
    c++;

    for(i=0; i<l; i++)
    {
        auxc=(char *)realloc(v[i], sizeof(char)*c);

        if(auxc == NULL)
        {
            printf("Erro na alocacao de memoria");
            return 0;
        }
        v[i]=auxc;
    }

    for (i = 0; i < l; i++)
            v[i][c-1] = '+';


    for(i=0;i<l;i++)
    {
        for(j=0;j<c;j++)
            printf("  %c",v[i][j]);

        printf("\n");
    }

    //Como libertar a memória

    for(i=0; i<l; i++)
    {
        free(v[i]);
    }
    free(v);
}


