#include <stdio.h>
#include <stdlib.h>

typedef struct dados cliente;    

struct dados{
    char nome[100];
    char nconta[15];
    int montante;
};

void escreve_info(cliente a){
    printf("Nome: %s\nNº conta: %s\tSaldo: %d\n", 
            a.nome, a.nconta, a.montante);        
}

void escreve_tudo(cliente a[], int total){
    int i;
    
    printf("\nExistem %d clientes:\n", total);    
    for(i=0; i<total; i++)
        escreve_info(a[i]);
}

void guardaDados(cliente *a, int total){
    FILE *f;
    
    f = fopen("banco.dat", "wb");      
    if(f == NULL){
        printf("Erro no acesso ao ficheiro\n");
        return;
    }
      
    fwrite(&total, sizeof(int), 1, f);   
    fwrite(a, sizeof(cliente), total, f);

    fclose(f);  
}


void leDados(cliente *a, int *total){
    FILE *f;
    
    f = fopen("banco.dat", "rb");
    if(f == NULL){
        *total = 0;
        return;
    }
    
    fread(total, sizeof(int), 1, f);    
    fread(a, sizeof(cliente), *total, f);
    
    fclose(f);    
}

void guardaDadosV2(cliente *a, int total){
    FILE *f;
    
    f = fopen("bancoV2.dat", "wb");      
    if(f == NULL){
        printf("Erro no acesso ao ficheiro\n");
        return;
    }
      
    fwrite(a, sizeof(cliente), total, f);

    fclose(f);  
}


void leDadosV2(cliente *a, int *total){
    FILE *f;
    cliente aux;
    
    *total = 0;
    f = fopen("bancoV2.dat", "rb");
    if(f == NULL){
        return;
    }
    
    
    while(fread(&aux, sizeof(cliente), 1, f) == 1)
        a[(*total)++] = aux;
        
    
    fclose(f);    
}


cliente* leDadosDIN(int *total){
    FILE *f;
    cliente *a;
    
    f = fopen("banco.dat", "rb");
    if(f == NULL){
        *total = 0;
        return NULL;
    }    
    fread(total, sizeof(int), 1, f);    
    
    a = malloc(sizeof(cliente) * *total);
    if(a == NULL){
        fclose(f);
        *total = 0;
        return NULL;
    }
    
    fread(a, sizeof(cliente), *total, f);
    
    fclose(f);  
    return a;
}

int main(){
    cliente *banco = NULL;
    int total = 0;
    
    banco = leDadosDIN(&total);
    
    escreve_tudo(banco, total);
    
    if(banco != NULL)
        free(banco);
    
    return 0;
}



int mainL(){
    cliente banco[100];
    int total = 0;
    
    leDadosV2(banco, &total); 
    
    escreve_tudo(banco, total);   
    return 0;
}

int mainE(){
    
    cliente banco[100] = {{"Ana", "X100", 100},
        {"Bruno","Y10", 500},{"Carlos", "AAA", 1000}}; 
    int total = 3;
    
    guardaDadosV2(banco, total);
    
    return 0;
}