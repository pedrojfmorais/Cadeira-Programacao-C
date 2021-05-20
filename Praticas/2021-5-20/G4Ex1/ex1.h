#ifndef EX1_H_INCLUDED
#define EX1_H_INCLUDED
typedef struct pessoa no, *pno;
typedef struct pessoa
{
    char nome[100];
    int id;
    float peso, altura;
    pno prox;
};

void preenche(pno p);
void mostra_info(pno p);
pno insere_final(pno p);
void liberta_lista(pno p);
/*void atualiza_peso(pno p, int id, int novo_peso);
pno elimina(pno p, int id);
pno elimina_lista_imc_superior(pno p, float imc);
void grava_lista_imc(char *nomeFich, pno p);
pno le_lista_imc_ficheiro(char *nomeFich, pno p);*/


#endif // EX1_H_INCLUDED
