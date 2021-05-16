#include <stdio.h>
#include <stdlib.h>


void processa(char *nomefich,char *novofich)
{
    int nralunos,nrprovas,i,nota,nraluno;
    float media,total, pesos[5];
    FILE *f,*g;

    f = fopen(nomefich,"rt");
    if (!f) {
        fprintf(stderr,"Erro a abrir o ficheiro: %s\n",nomefich);
        return;
    }

    g = fopen(novofich,"wt");
    if (!g) {
        fclose(f);
        fprintf(stderr,"Erro a criar o ficheiro: %s\n",novofich);
        return;
    }

    if (fscanf(f,"   Numero  de alunos:%d",&nralunos) != 1 ||
        fscanf(f," Numero de provas: %d",&nrprovas) != 1 ||
        fscanf(f," Peso das provas: %f",&pesos[0]) != 1) {
        fprintf(stderr,"Erro de formato do ficheiro\n");
        fclose(f);fclose(g);
        return;
    }
    fprintf(g,"Numero de alunos: %d\n",nralunos);
    //fprintf(g,"Numero de provas: %d\n",nrprovas);
    //fprintf(g,"Peso das provas: %d",pesos[0]);
    //Leitura de todo o array de pesos
    total = pesos[0];
    for(i=1;i<nrprovas;i++) {
        if (fscanf(f,"%f",&pesos[i]) != 1) {
            fprintf(stderr,"Erro de formato do ficheiro\n");
            fclose(f);fclose(g);
            return;
        }
        //total é a soma de todos os pesos para cálculo da média
        total += pesos[i];
        //fprintf(g," %d",pesos[i]);
    }

//    fprintf(g,"\n\n");
    fprintf(g,"\n");

    while (nralunos--) {
        if (fscanf(f," Aluno %d: %d",&nraluno,&nota) != 2) {
            fprintf(stderr,"Erro de formato do ficheiro\n");
            fclose(f);fclose(g);
            return;
        }
        media = nota * pesos[0] / total;
        for(i=1;i<nrprovas;i++) {
            if (fscanf(f,"%d",&nota) != 1) {
                fprintf(stderr,"Erro de formato do ficheiro\n");
                fclose(f);fclose(g);
                return;
            }
            media += nota * pesos[i] / total;
        }

        fprintf(g,"Aluno %d: %.0f%%\n",nraluno,media);
    }

    fclose(f);
    fclose(g);
}
void mostra_fich2(char *nome) {
    char c;
    FILE *f=fopen(nome,"rt");
    if (!f) {
        fprintf(stderr,"Erro a abrir o ficheiro: %s\n",nome);
        return;
    }

    while ((c=fgetc(f)) != EOF)
        putchar(c);

    fclose(f);
}
int main(int argc, char** argv) {
    processa("notas_ex9.txt","res_ex9.txt");
    mostra_fich2("notas_ex9.txt");
    printf("\n--------------resultado---------------\n");
    mostra_fich2("res_ex9.txt");
    return 0;
}

