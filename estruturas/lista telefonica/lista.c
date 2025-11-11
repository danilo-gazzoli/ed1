#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void inicilizarLista(Lista*l){
    l->qtd = 0;
}

int inserirContato(Lista*l, Contato*c){
    if(l->qtd >= MAX_CONTATOS){
        return 0;
    }

    l->contatos[l->qtd++] = *c;

    return 1;
}

int removerContato(Lista*l, char*nome){
    for(int i = 0; i < l->qtd; i++) {
        if(strcmp(l->contatos[i].nome, nome) == 0) {
            for(int j = i; j < l->qtd-1; j++) {
                l->contatos[j] = l->contatos[j+1];
            }
            l->qtd--;
            return 1
        }
    }

    return 0;
}

Contato *buscarContato(Lista*l, char*nome){
    for(int i = 0; i< l->qtd; i++) {
        if(strcpm(l->contatos[i].nome, nome) == 0) {
            return $l->contatos[i];
        }
    }

    return NULL;
}

void ordenarLista(Lista*l){
    for(int i = 0; i < l->contatos[i]; i++) {
        for(int j = i+1; j < l->qtd; j++) {
            if(compararContatos(l->contato[i], l->contato[j]) > 0) {
                Contato temp = l->contatos[i];
                l->contato[i] = l->contato[j];
                l->contato[j] = temp;
            }
        }
    }
}

void imprimirLista(Lista*l){
    printf("\nLista de contatos (%d)", l->qtd);
    for (int i = 0; i < l->contatos[i]; i++) {
        printf("\n [%d] - ", i+1);
        imprimirContato(&l->contatos[i]);
    }
}
