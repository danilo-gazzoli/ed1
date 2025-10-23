#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value; // valor que o nó armazena
    struct Node *nextNode; 
} Node;

typedef struct linkedlist {
    Node *head;
    Node *tail;
    int size;
} LinkedList;

void initLinkedList(LinkedList *list){
    if (list != NULL){
        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
    }
}

void addFirst(LinkedList *list, int value){
    Node *newnode = (Node*) malloc(sizeof(Node));
    if (newnode == NULL){
        printf("Erro na alocação de memória \n");
        return;
    }
    newnode->value = value;
    newnode->nextNode = list->head;
    list->head = newnode;

    if (list->tail == NULL)
    {
        list->tail = newnode;
    }

    list->size++;
    printf("%d inserido no começo da lista com sucesso", value);
}

void addLast(LinkedList *list, int value){
    Node *newnode = (Node*) malloc(sizeof(Node));
    if (newnode==NULL){
        printf("Erro na alocação de memória");
        return;
    }
    newnode->value = value;
    newnode->nextNode == NULL;

    if (list->head == NULL)
    {
        list->head = newnode;
        list->tail = newnode;
    } else {
        list->tail->nextNode = newnode;
        list->tail = newnode;
    }
    
    list->size++;
    printf("%d inserido no final da lista com sucesso", value);
}

void print(LinkedList *list){
    Node *currentNode = list->head;

    if (currentNode==NULL){
        printf("A lista está vazia. \n");
        return;
    }
    
    printf("Lista (%d elementos)", list->size);
    while (currentNode != NULL){
        printf("%d -> ", currentNode->value);
        currentNode = currentNode->nextNode;
    }
    printf("NULL\n");
}

void remove(LinkedList *list, int value){
    Node *current = list->head;
    Node *prev = NULL;

    if (current != NULL && current->value == value){
        list->head = current->nextNode;
        free(current);
        list->size--;
        return;
    }

    while (current != NULL && current->value != value){
        prev = current;
        current = current->nextNode;
    }
    
    if (current == NULL){
        printf("O valor %d não foi encontrado. \n", value); 
        return;
    }
    
    prev->nextNode = current->nextNode;

    list->size--;

    printf("Removido %d.\n", value);
}

void freeList(LinkedList *list){
    Node *current = list->head;
    Node *next;

    while (current != NULL) {
        next = current->nextNode;
        free(current);
        current = next;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}
