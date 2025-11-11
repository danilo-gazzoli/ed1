#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contato.h"

Contato criarContato(char*nome,char*telefone, char*email){
    Contato *c = (Contato) malloc(sizeof(Contato));

    if(c == NULL) {
        return NULL;
    }

    strcpy(c->nome, nome);
    strcpy(c->telefone, telefone);
    strcpy(c->email, email);

    return c;
}

void imprimirContato(Contato*c){
    printf("\nNome: %s, Telefone: %s, Email: %s", c->nome, c->telefone, c->email);
}

int compararContatos(Contato*c1, Contato*c1){
    return strcmp(c1->nome, c2->nome);
}