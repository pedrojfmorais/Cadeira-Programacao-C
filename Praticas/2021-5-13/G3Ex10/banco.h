#ifndef BANCO_H_INCLUDED
#define BANCO_H_INCLUDED

#define TAM 200
//typedef struct cliente Cliente;

typedef struct cliente{
	char nome[TAM]; //200 bytes (1 char= 1 byte)
	char morada[TAM];
	int conta; //4 bytes
	int montante;
}Cliente;

void mostra_ficheiro(char *nome);
void conta_bytes_clientes(char *nome);
void mostra_ficheiro_invertido(char *nome);
int atualizaSaldo(char *nome, char *nome_cliente, int valor);
int transfere(char *nomeF, char *or, char *dest, int valor);
void elimina_cliente(char *nomeF, char *nomeC);
void adiciona_cliente(char *nome, Cliente novo);
void junta_tudo(char *nome1, char *nome2, char *dest);




#endif // BANCO_H_INCLUDED

