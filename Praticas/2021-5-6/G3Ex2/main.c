#include <stdio.h>
#include <stdlib.h>

typedef struct med_sum{
    float media;
    int soma;
} MedSum;

void mostra_numeros(char * nomefich) {
    int num;

    FILE *f = fopen(nomefich,"rb");
    if (!f) {
        fprintf(stderr,"Erro a abrir o ficheiro %s\n",nomefich);
        return;
    }

    while (fread(&num,sizeof(int),1,f)==1)
        printf("%3d\n",num);

    fclose(f);
}


void mostra_numeros_2_a_2(char *nomefich)
{
    int i=1,num;

    FILE *f = fopen(nomefich,"rb");
    if (!f) {
        fprintf(stderr,"Erro a abrir o ficheiro %s\n",nomefich);
        return;
    }

    while (fread(&num,sizeof(int),1,f)==1 && i<=5)
    {
        fseek(f, sizeof(int), SEEK_CUR); //anda de dois em dois (um para o fread e um para o fseek)
        printf("\n%3d\n",num);
        i++;
    }

    fclose(f);

}

MedSum calcula_soma_media(char * nomefich)
{
    MedSum t;
    int num,contador=0;
    t.soma=0;
    FILE *f = fopen(nomefich,"rb");
    if (!f) {
        fprintf(stderr,"Erro a abrir o ficheiro %s\n",nomefich);
        return;
        }


    while (fread(&num,sizeof(int),1,f)==1)
    {   t.soma+=num;
        contador++;
    }
        t.media=t.soma/(float)contador;
    fclose(f);
    return t;
}

int* criaVetor(char *nomeFich, int *tam)
{
    FILE *f;
    int *b = NULL,num, *aux;
    (*tam)=0;
    f = fopen(nomeFich,"rb");
    if(f == NULL)
    {
        printf("Erro a abrir o ficheiro\n");
        (*tam)=0;
        return b;
    }
 /*   while(fread(&num,sizeof(int),1,f)==1 && num%2!=0);
    if (feof(f)!=0)
    {
        printf("Nao ha numeros pares");
        return b;

    }
    else
    {
        b=malloc(sizeof(int) * (*tam+1));
        if(b==NULL)
        {
            printf("erro alocacao de memoria");
            return b;
        }
        b[(*tam)] = num;
        (*tam)++;
    }*/


    while (fread(&num,sizeof(int),1,f)==1)
    {
        if(num%2==0)
        {
            aux = realloc(b,sizeof(int) * (*tam+1));
            //If pointer passed to realloc is null, then it will behave exactly like malloc
            if(aux == NULL)
            {       // realocação falhou
                printf("Falhou realocacao. Mantem tamanho\n");
                (*tam)=0;
                return NULL;
            }
            else
            {
                b = aux;
                b[(*tam)] = num;
            }
            (*tam)++;
        }
    }
    fclose(f);
    return b;
}

void cria_ficheiro(char *fich,char *fichmedsup, char *fichmedinf)
{
    FILE *f, *g, *t;
    float media;
    int num;
    if ((f=fopen(fich,"rb"))==NULL) {
        fprintf(stderr,"Erro a abrir o ficheiro %s\n",fich);
        return;
    }
    if ((g=fopen(fichmedsup,"wb"))==NULL) {
        fclose(f);
        fprintf(stderr,"Erro a criar o ficheiro %s\n",fichmedsup);
        return;
    }

    if ((t=fopen(fichmedinf,"wb"))==NULL) {
        fclose(f);
        fclose(g);
        fprintf(stderr,"Erro a criar o ficheiro %s\n",fichmedinf);
        return;
    }
    media = calcula_soma_media(fich).media;
    while (fread(&num,sizeof(int),1,f)==1)
    {
        if (num >=media)
            fwrite(&num,sizeof(int),1,g);
        else
            fwrite(&num,sizeof(int),1,t);
    }
    fclose(f);
    fclose(g);
    fclose(t);
}
int main(int argc, char** argv) {

    char *fich = "valoresEx2.bin";
    char *fichsupmed = "valEx2SupMed.bin";
    char *fichinfmed = "valEx2InfMed.bin";
    MedSum t;
    int* b = NULL;
    int tam=0,i;

    t = calcula_soma_media(fich);

    mostra_numeros(fich);

    printf("\nA soma dos valores e %d ",calcula_soma_media(fich).soma);
    printf("\nA media dos valores e %.2f ",t.media);

    b=criaVetor(fich,&tam);
    printf("\nO vetor criado tem %d valores ",tam);
    for(i=0;i<tam;i++)
        printf("\n%3d",b[i]);


    cria_ficheiro(fich,fichsupmed,fichinfmed);

    printf("\nValores superiores ou iguais a media: \n");
    mostra_numeros(fichsupmed);

    printf("\nValores inferiores a media: \n");
    mostra_numeros(fichinfmed);

    free(b);

    return (EXIT_SUCCESS);
}

//Meu código
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct devolverSomaMedia
{

    int soma;
    double media;

} devolveSomaMedia;

void mostra_numeros(char * nomefich) {
    int num;

    FILE *f = fopen(nomefich,"rb");
    if (!f) {
        fprintf(stderr,"Erro a abrir o ficheiro %s\n",nomefich);
        return;
    }

    while (fread(&num,sizeof(int),1,f)==1)
        printf("%3d\n",num);

    fclose(f);
}

devolveSomaMedia mediaValoresFicheiro(char *ficheiro)
{

    FILE *f = fopen(ficheiro, "rb");

    if(f == NULL)
    {
        printf("Erro a abrir o ficheiro!");
        return;
    }

    devolveSomaMedia devolver;
    devolver.soma = 0;
    devolver.media = 0;

    int temp;
    int count = 0;

    while(fread(&temp,sizeof(int),1,f) == 1)
    {
        count++;

        devolver.soma += temp;
        devolver.media += temp;
    }
    devolver.media /= count;

    fclose(f);

    return devolver;
}

int *criaVetor(char *ficheiro, int *tam)
{
    int *vetor = NULL;
    FILE *f = fopen(ficheiro, "rb");

    if(f == NULL)
    {
        printf("Erro a abrir o ficheiro!");
        *tam = 0;
        return NULL;
    }

    int *aux;
    int temp;

    while(fread(&temp,sizeof(int),1,f) == 1)
    {

        if(temp%2!=0)
            continue;

        aux = realloc(vetor, sizeof(int)*(*tam+1));

        if(aux == NULL)
        {
            printf("Ocorreu um erro a alocar memoria!");
            fclose(f);
            *tam = 0;
            return NULL;
        }

        aux[*tam] = temp;
        (*tam)++;
        vetor = aux;
    }

    fclose(f);

    if(*tam == 0)
        return NULL;

    return vetor;
}

int main()
{
    char *ficheiro = "valoresEx2.bin";

    int *numeros = NULL;
    int tam = 0;

    mostra_numeros(ficheiro);
    devolveSomaMedia somaMedia = mediaValoresFicheiro(ficheiro);

    printf("A soma e: %d\n", somaMedia.soma);
    printf("A media e: %.2f\n", somaMedia.media);

    numeros = criaVetor(ficheiro, &tam);

    for(int i = 0; i<tam; i++)
    {
        printf("%d ", numeros[i]);
    }

    return 0;
}
*/
