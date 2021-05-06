#ifndef VIAGENS_CP_H_INCLUDED
#define VIAGENS_CP_H_INCLUDED

typedef struct paragem{
    char nome[50];
    int minutos;
} Paragem;

void mostraPercurso(char *ficheiro);
int tempo_percurso_completo(char *ficheiro);
int ligacao_cidades(char *ficheiro, char *cidadeA, char *cidadeB);

#endif // VIAGENS_CP_H_INCLUDED
