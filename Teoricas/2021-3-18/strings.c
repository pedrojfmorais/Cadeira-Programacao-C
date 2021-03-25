#include <stdio.h>
#include <string.h>


void mostraMSG(){
    char msg[][20] = {"Out of range", 
                      "Printer off-line", 
                      "Paper out", 
                      "Irrecoverable error"};
     
     char *p_msg[4] = {"Out of range", 
                      "Printer off-line", 
                      "Paper out", 
                      "Irrecoverable error"};
        
    int i=0;
    
    for(i=0; i<4; i++)
        if(msg[i][0] == 'P')
            puts(msg[i]);
    
    putchar('\n');
    
    for(i=0; i<4; i++)
        if(p_msg[i][0] == 'P')
           puts(p_msg[i]);
    
   
}

int main(){

    mostraMSG();
    
    return 0;
    
    char *p;    
    p = "Ola Mundo!";
    
    //p[4] ='m';
    
    puts(p);

    
    char st[20] = "Ola Mundo!"; 
    
    st[4] = 'm';
    puts(st);
    
    return 0;
}