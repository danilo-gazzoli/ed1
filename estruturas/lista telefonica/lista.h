#ifndef "LISTA_H"
#define "LISTA_H"
#include "contato.h"
#define MAX_CONTATOS = 100

typedef struct lista {
    Contato contatos[MAX_CONTATOS];
    int qtd;
} Lista;

void inicilizarLista(Lista*l);
int inserirContato(Lista*l, Contato*c);
int removerContato(Lista*l, char*nome);
Contato *buscarContato(Lista*l, char*nome);
void ordenarLista(Lista*l);
void imprimirLista(Lista*l);

#endif