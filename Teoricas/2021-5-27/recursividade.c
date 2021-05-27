#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
void f1(int x){
    printf("%d\n", x++);
    f1(x);
}
*/

int fatorial(int v){
    if(v<=1)            // Condição de paragem / Caso de base
        return 1;
    else                // Chamada recursiva
        return v * fatorial(v-1);
}

int mainF(){

    int val=4, res;
    
    res = fatorial(val);
    printf("O fatorial de %d e %d\n", val, res);

    return 0;
}


int contaC(char *st){
    
    if(*st == '\0')
        return 0;
    else
        return 1 + contaC(st+1);
}

void f2(char *st){
    if(*st == '\0')
        return;
    else{
        f2(st+1);
        putchar(*st);
    }
}

int capicua(char *st, int tam){   
    if(tam <= 1)
        return 1;
    else if(st[0] != st[tam-1])
        return 0;
    else
        return capicua(st+1, tam-2);
}

int main(){
    char st[20] = "ABAB";
    int x;
    
    printf("Res: %d\n", capicua(st, strlen(st)));
    
    //f2(st);
    
/*
    x = contaC(st);
    printf("A string %s tem %d caracteres\n", st, x);
*/
    
    return 0;
}