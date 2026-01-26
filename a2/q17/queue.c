

#include <stdlib.h>
typedef struct client {
    int codigo;
    char nome[100];
} Client;

typedef struct node{
    Client client;
    struct node *next;
} Node;

typedef struct queue {
    Node*head;
    Node*tail;
    int qtd;
} Queue;

int newClient(Queue*q, Client*c){

    Node*new = (Node*) malloc(sizeof(Node));

    if (!new) return 0;

    new->client = c;
    new->next = NULL;

    if (q->head == NULL) {
        q->head = new;
        q->tail = q->head;
        q->qtd++;
        return 1;
    }

    q->tail->next = new;
    q->tail = q->tail->next;
    return 1;
}

int toMeet(Queue*q){
    if(q == NULL) return 0;

    Node *aux = q->head;
    q->head = q->head->next;
    
    if(q->head == NULL){
        q->tail = NULL;
        return 0;
    }

    free(aux);
    return 1;
}
