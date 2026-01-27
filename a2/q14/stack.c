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

char* pop(Stack* s) {
    if (!s || !s->topo) return NULL;
    Node *aux = s->topo;
    
    // 2. Precisamos de um espaço novo na memória para a string de retorno
    // Assim, ela sobrevive ao free(aux)
    char *valorRec = (char*) malloc(100 * sizeof(char));
    if (valorRec == NULL) return NULL; 
    strcpy(valorRec, aux->string); 
    // 3. Desconecta o topo
    s->topo = aux->prox;
    // 4. Libera o nó antigo e ajusta a contagem
    free(aux);
    s->qtd--; // CORREÇÃO: Pop diminui a quantidade!
    return valorRec;
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
