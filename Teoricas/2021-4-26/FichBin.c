#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dados cliente;    

struct dados{
    char nome[100];
    char nconta[15];
    int montante;
};

void escreve_info(cliente a){
    printf("Nome: %s\tNº conta: %s\tSaldo: %d\n", 
            a.nome, a.nconta, a.montante);        
}




int atualizaSaldoV1(char *nome, char *conta, int valor){
    FILE *f, *g;
    cliente c;
    int flag=0;
    
    f = fopen(nome, "rb");
    if(f == NULL) return 0;
    
    g = fopen("temp.dat", "wb");
    if(g == NULL){fclose(f); return 0;}
    
    while(fread(&c, sizeof(cliente), 1, f)== 1){
        if(strcmp(c.nconta, conta) == 0){
            c.montante += valor;
            flag = 1;
        }
        fwrite(&c, sizeof(cliente), 1, g);
    }   
    fclose(f);
    fclose(g);   
    remove(nome);
    rename("temp.dat", nome);
 
    return flag;
}


int atualizaSaldoV2(char *nome, char *conta, int valor){
    FILE *f;
    cliente c;
    
    f = fopen(nome, "rb+");
    if(f == NULL)
        return 0;
    
    while(fread(&c, sizeof(cliente), 1, f)== 1){
        if(strcmp(c.nconta, conta) == 0){
            c.montante += valor;
            fseek(f, -sizeof(cliente), SEEK_CUR);
            fwrite(&c, sizeof(cliente), 1, f);
            fclose(f);
            return 1;
        }       
     }
    fclose(f);
    return 0;
}



void listarTodos(char *nomeF){
    FILE *f;
    cliente c;
 
    f = fopen(nomeF, "rb");
    if(f == NULL)
        return;
    
    while(fread(&c, sizeof(cliente), 1, f)== 1)
        escreve_info(c);

    fclose(f); 
}




int main(){

    listarTodos("bancoD.dat");
    
    atualizaSaldoV2("bancoD.dat", "ZZZ", 500);
    
    listarTodos("bancoD.dat");
    

    return 0;
}


int mainAAA(){

    FILE *f;
    cliente c;
    
    f = fopen("bancoD.dat", "rb");

    fseek(f, 0, SEEK_END);
    
    printf("O ficheiro tem %d bytes\n", ftell(f));
    
    printf(" Existem %d clientes\n", ftell(f)/sizeof(cliente));
    
/*
    fseek(f, 3*sizeof(cliente),SEEK_SET);
    fread(&c, sizeof(cliente),1, f);
    
    fseek(f, -2*sizeof(cliente),SEEK_CUR);
    fread(&c, sizeof(cliente),1, f);
    
*/
    //escreve_info(c);
    

    fclose(f);

    return 0;
}