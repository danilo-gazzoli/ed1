#include <stdio.h>
#include <stdlib.h>

typedef struct pedido {
    int numero; 
    int quantidade; 
    char descricao[100];
} Pedido;

typedef struct node {
    Pedido dados;
    struct Node *prox;
} Node;

typedef struct lista{
    Node *head;
    int qtd;
} Lista;

Lista* criarLista(){
    Lista* l = (Lista*) malloc(sizeof(Lista));

    if (l != NULL) {
        l->head = NULL;
        l->qtd = 0;
    }

    return l;
}

int inserirInicio(Lista*l, Pedido*p){
    if(l == NULL || p == NULL) return 0;

    Node *newNode = (Node*) malloc(sizeof(Node));

    if (newNode == NULL) return 0;

    newNode->dados = *p;
    newNode->prox = l->head;

    l->head = newNode;

    l->qtd++;

    return 1;
}

int inserirFinal(Lista*l, Pedido*p){
    if(l == NULL || p == NULL) return 0;
    
    Node *newNode = (Node*) malloc(sizeof(Node));

    if (newNode == NULL) return 0;

    newNode->dados = *p;

    newNode->prox = NULL;

    if (l->head != NULL) {
        Node*aux = l->head;

        while (aux->prox != NULL) {
            aux = aux->prox;
        }

        aux->prox = newNode;

        l->qtd++;

        return 1;
    }

    l->head = newNode;
    l->qtd++;

    return 1;
}

int removerInicio(Lista*l){
    if(l == NULL || l->head == NULL) return 0;

    Node*aux = l->head;

    l->head = aux->prox;

    free(aux);

    l->qtd--;

    return 1;
}

int removerFim(Lista*l){
    if(l == NULL || l->head == NULL) return 0;

    Node*atual = l->head;
    Node*anterior = NULL;

    if (atual->prox == NULL) {
        free(atual);
        l->head = NULL;
        l->qtd = 0;
        return 1;
    }

    while (atual->prox != NULL) {
        anterior = atual;
        atual = atual->prox;
    }

    anterior->prox = NULL;
    free(atual);
    l->qtd--;
    return 1;
}

Pedido* buscaPorNum(Lista*l, int num){
    if(l == NULL || l->head == NULL) return NULL;

    Node*atual = l->head;

    while (atual->prox != NULL) {

        if (atual->dados.numero == num) {
            return atual->dados;
        }

        atual = atual->prox;
    }

    return NULL;
}

int exibirLista(Lista*l){
    if(l == NULL || l->head == NULL) return 0;
    
    Node*atual = l->head;

    while (atual != NULL) {
        printf("Numero: %d \n", atual->dados.numero);
        printf("Descricao: %s \n", atual->dados.descricao);
        printf("Quantidade: %d \n \n", atual->dados.quantidade);

        atual = atual->prox;
    }

    return 1;
}

int ordenarPorQuantidade(Lista*l){

    if (l == NULL || l->head == NULL) return;

    Node *i, *j, *menor;
    Pedido temp;

    for (i = l->head; i->prox != NULL; i = i->prox) {
        menor = i;

        for (j = i->prox; j != NULL; j = j->prox) {
            if (j->dados.quantidade < menor->dados.quantidade) {
                menor = j;
            }
        }

        if (menor != i) {
            temp = i->dados;
            i->dados = menor->dados;
            menor->dados = temp;
        }
    }
}
