#include <stdio.h>

void escreve(char *nome, int num[]){
    int i;
    
    printf("%s: ", nome);
    for(i=0; i<7; i++)
        printf(" %d, ", num[i]);
    putchar('\n');
}


void processaFicheiro(char *nomeF){
    char nome[100];
    int num[7], i;
    FILE *f;
    
    f = fopen(nomeF, "r");
    if(f == NULL)
        return;
    
    // Leitura da informação
    
    while( fscanf(f, " %99[^\n]", nome) != EOF){
        for(i=0; i<7; i++)
            fscanf(f, "%d", &num[i]);
    
        escreve(nome, num);
    }

    fclose(f);
}


/*
 Ana Silva
2 5 28 12 34 1 5

Joao Cruz
4 8 10 12 13 2 3

Luis Silva Mota
2 3 4 5 6 1 7

Zulmira Patrao
5 8 12 34 35 2 5
 */


int main(){
        
    processaFicheiro("dados.txt");
    
    return 0;
}


int mainR(){
    
    char st[10];
    
    fgets(st, 10, stdin);
    
    puts(st);
    
    
/*
    
    FILE *f;    
    int i=10;  
    putchar('A');
    
    fprintf(stdout, "\nValor: %d\n", i);
    
    f = fopen("aula.txt", "w");
    
    fputc('A', f);
    
    fclose(f);
*/
    
    return 0;
}

