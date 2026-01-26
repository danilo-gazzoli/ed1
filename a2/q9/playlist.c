#include <stdlib.h>
#include <stdio.h>

typedef struct musica {
    char nome[100];
    char autor[100];
} Musica;

typedef struct node {
    Musica musica;
    struct node *prox;
    struct node *anterior;
} Node;

typedef struct playlist {
    Node *head;
    Node *tail;
    Node *musicaAtual;
    int qtd;
} Playlist;

int adicionarMusicaAposAtual(Playlist* p, Musica* m) {
    if (!p || !m) return 0;
    
    Node *novo = (Node*) malloc(sizeof(Node));
    if (!novo) return 0;
    novo->musica = *m;

    if (!p->head) {
        novo->prox = novo->anterior = NULL;
        p->head = p->tail = p->musicaAtual = novo;
    } else {
        Node *atual = p->musicaAtual;
        
        novo->prox = atual->prox;
        novo->anterior = atual;
        atual->prox = novo;

        if (novo->prox) novo->prox->anterior = novo;
        else p->tail = novo;
    }
    p->qtd++;
    return 1;
}

int proximaMusica(Playlist* p) {
    if (p == NULL || p->musicaAtual == NULL || p->musicaAtual->prox == NULL) return 0;
    p->musicaAtual = p->musicaAtual->prox;
    return 1;
}

int voltarMusica(Playlist* p) {
    if (p == NULL || p->musicaAtual == NULL || p->musicaAtual->anterior == NULL) return 0;
    p->musicaAtual = p->musicaAtual->anterior;
    return 1;
}

