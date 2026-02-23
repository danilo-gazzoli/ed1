/* Autores:
    Nome: Danilo Martins Gazzoli
    Nome: Matheus Lucas Klippel Tavares
*/

#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

// questão 1
int qtdFolhas(Arvore *a){
    // verifica se a árvore é nula, se for, retorna 0
    if (!a)
        return 0;

    // se os nós filhos esquerdos e direitos forem nulos, entao é uma folha, logo retorna 1
    if (!(a->esq) && !(a->dir))
        return 1;

    // usa recursividade para retornar a soma da quantidade de folhas da subárvore esquerda e direita
    return qtdFolhas(a->esq) + qtdFolhas(a->dir);
}

int qtdInt(Arvore *a, int c){
    // verifica se a árvore é nula, se for, retorna 0
    if (!a)
        return 0;

    // incia um contador de nós da árvore com valor 0
    int n = 0;

    // se o valor do nó for igual ao valor passado por parâmetro, define o contador como 1
    if (a->info == c)
        n = 1;

    // usa recursividade para incrementar o contador com a qtd de nós da esquerda e direita com valor igual ao parâmetro
    return n + qtdInt(a->esq, c) + qtdInt(a->dir, c);
}

int iguais(Arvore *a, Arvore *b){
    // verifica se as árvores a e b são nulas, se for, retorna 1, se apenas uma delas for nula, retorna 0
    if(!a && !b)
        return 1;

    // se uma das árvores for nula, ou seja, apenas uma delas for nula, retorna 0
    if(!a || !b)
        return 0;

    // se o valor do nó de a for diferente do valor do nó de b, retorna 0
    if(a->info != b->info)
        return 0;

    // retorna 1 ou 0 se as subárvores esquerdas e direitas de a e b forem iguais ou diferentes, usando recursividade
    return iguais(a->esq, b->esq) && iguais(a->dir, b->dir);
}

Arvore* copia(Arvore *a){
    // verifica se a árvore é nula, se for, retorna 0
    if(!a)
        return NULL;

    // limpa a memória e aloca dinamicamente uma nova árvore, retorna NULL se a alocação falhar
    Arvore *nova = (Arvore*) calloc(1, sizeof(Arvore));

    // verifica se a alocação falhou, se for, retorna NULL
    if(!nova)
        return NULL;

    // copia os valores da árvore passada por parâmetro para a nova árvore
    nova->info = a->info;

    //usando recursividade para copiar as subárvores esquerdas e direitas
    nova->esq = copia(a->esq);
    nova->dir = copia(a->dir);

    // retorna a nova árvore copiada
    return nova;
}

int maior(Arvore *a){
    // verifica se a árvore é nula, se for, retorna -1
    if(!a)
        return -1;

    // define o maior valor como o valor do nó atual
    int m = a->info;

    // usando recursividade para encontrar o maior valor nas subárvores esquerdas e direitas
    int me = maior(a->esq);
    int md = maior(a->dir);

    // compara o maior valor encontrado nas subárvores com o valor do nó atual, e retorna o maior entre eles
    if(me > m) m = me;
    if(md > m) m = md;

    return m;
}

// questão 2
int ocorrenciasX(Arvore *a, int x){
    // verifica se a árvore é nula, se for, retorna 0
    if(!a)
        return 0;

    // verifica se o valor do nó atual é igual ao valor passado por parâmetro, se for, retorna 1
    if(a->info == x)
        return 1;

    // se x é maior que a->info, então x só pode estar presente na subárvore direita
    if(a->info > x)
        // usando recursividade para verificar a presença de x na subárvore
        return ocorrenciasX(a->esq, x);
    //caso contrário, x só pode estar presente na subárvore esquerda
    else
        // usando recursividade para verificar a presença de x na subárvore
        return ocorrenciasX(a->dir, x);
}

void imprimirDecrescente(Arvore *a){
    // verifica se a árvore é nula, se for, retorna
    if(!a)
        return;

    // usa recursividade para imprimir os valores da subávore direita em ordem decrescente
    imprimirDecrescente(a->dir);

    // verifica se o nó atual é uma folha, ou seja, se os nós filhos esquerdos e direitos forem nulos, se for, imprime o valor do nó
    if(!(a->esq) && !(a->dir))
        printf("%d | ", a->info);

    // usa recursividade para imprimir os valores da subávore esquerda em ordem decrescente
    imprimirDecrescente(a->esq);
}

// função auxiliar para liberar memória da árvore
void liberar(Arvore *a){
    if(!a)
        return;

    liberar(a->esq);
    liberar(a->dir);
    free(a);
}

// função auxiliar para criar um nó da árvore
Arvore* criarNo(int valor){
    Arvore *novo = (Arvore*) malloc(sizeof(Arvore));
    if(!novo)
        return NULL;

    novo->info = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}