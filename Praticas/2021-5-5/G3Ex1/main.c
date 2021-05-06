#include <stdio.h>
#include <stdlib.h>

#include "viagens_cp.h"

int main()
{

    char *ficheiro = "cp_ex1.dat";
    char *cidadeA = "Aveiro";
    char *cidadeB = "Porto";

    mostraPercurso(ficheiro);
    printf("\nO total de minutos do percurso e: %d\n", tempo_percurso_completo(ficheiro));

    int duracao = ligacao_cidades(ficheiro, cidadeA, cidadeB);

    if(duracao == -1)
    {
        printf("Nao existe percurso entre %s e %s!\n", cidadeA, cidadeB);

    }else
    {
        printf("\nO percurso de %s a %s demora %d minutos. \n", cidadeA, cidadeB, duracao);
    }

    return 0;
}
