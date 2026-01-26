#include <stdlib.h>
#include <string.h>

typedef struct node {
    char string[100];
    struct node *prox;
} ;

typedef struct stack{
    node *topo;
    int qtd;
} Stack;

int push(Stack*s, char*str){
    
    node *newNode = (node*) malloc(sizeof(node));

    if (newNode == NULL) 
        return 0;

    strcpy(newNode->string, str);

    newNode->prox = s->topo;
    s->topo = newNode;
    s->qtd++;
    return 1;
}

void pop(Stack*s){
    if (!s->topo) return NULL;

    node *aux = s->topo;
    char* valorRec = &(aux->string);

    s->topo = aux->prox;

    free(aux);
    s->qtd++;
}

int estaBalanceada(char*str){
    Stack s;
    s.topo = NULL;
    s.qtd = 0;

    for (int i=0; str[i] 1= "\0"; i++){
        if (str[i] == '(') {

            push(s, '(');    

        } else if (str[i] == ')') {

            if (s.qtd == 0) return 0;
            pop(&s);

        }
    }

    if (s.qtd == 0) return 1;

    return 0;
}
