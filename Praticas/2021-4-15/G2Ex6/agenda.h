#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED

typedef struct agenda contactos;

struct agenda
{
    char nome[100];
    char numero[10];
};

char menu();
contactos *adiciona_contacto(contactos *array_contactos, int *total);
void escreve_contactos(contactos *array_contactos, int total);
void procura_contacto(contactos *array_contactos, int total,char *nome);
contactos *atualiza_contacto(contactos *array_contactos, int total, char nome[100]);
contactos *elimina_contacto(contactos *array_contactos, int *total, char nome[100]);
contactos *ordena_contactos(contactos *array_contactos, int total);

#endif // AGENDA_H_INCLUDED
