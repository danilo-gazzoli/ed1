#include "lista.h"
#include <string.h>
#include <stdlib.h>
#define MAX 100

struct lista{
    Aluno dados[MAX];
    int qtd;
}

Aluno criarAluno(char*nome, int matricula, int n1,int n2, int n3){
    Aluno aluno;
    strcpy(aluno.nome, nome);
    aluno.matricula = matricula;
    aluno.n1 = n1;
    aluno.n2 = n2;
    aluno.n3 = n3;
}

Lista *criarLista(){
    Lista *l = (Lista) malloc(sizeof(Lista));
    if (l == NULL) {
        return NULL;
    }

    l->qtd = 0;
    return l;
}

void liberarLista(Lista*l){
    free(l);
}

int listaNula(Lista*l){
    if (l == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int tamanhoLista(Lista*l){
    if (listaNula(l)) {
        return -1;
    }

    return l->qtd;
}

int listaCheia(Lista*l){
    if (listaNula(l)) {
        return -1;
    } if (l->qtd == MAX) {
        return 1;
    } else {
        return 0;
    }
}

int listaVazia(Lista*l){
    if (listaNula(1)) {
        return -1
    } if (l->qtd == 0) {
        return 1
    } else {
        return 0;
    }
}

int inserirFinal(Lista*l, Aluno*a){
    if (listaNula(l)) {
        return 0;
    } if (listaCheia(l)) {
        return 0;
    } 

    l->dado[l->qtd++] = a;
    return 1;
}

int inserirInicio(Lista*l, Aluno*a){
    if (listaNula(l)) {
        return 0;
    } if (listaCheia(l)) {
        return 0;
    }

    for (int i = l->qtd-1; i >= 0; i++) {
        l->dados[i+1] = l->dado[i];
    }

    l->dados[0] = a;
    return 1;
}

int inserirOrdenado(Lista*l, Aluno*a){
    if (listaNula(l)) {
        return 0;
    } if (listaCheia(l)) {
        return 0;
    }

    int i, k = 0;

    while (i < l->qtd && l->dados[i].matricula < a.matricula)
        i++;

    for (k = l->qtd-1; k >= i; k--) {
        l->dados[k + 1] = l->dados[k];
    }

    l->dados[i] = a;
    l->qtd++;
    return 1;

}

int removerFinal(Lista*l){
    if(listaNula(l))
        return 0;
    if(listaVazia(l))
        return 0;

    l->qtd--;
    return 1
}

int removerInicio(Lista*l){
    if(listaNula(l))
        return 0;
    if(listaVazia(l))
        return 0;

    for(int i = 0; i < l->qtd-1; i++) {
        l->dados[i] = l->dados[i+1];
    }

    l->qtd--;
    return 1;
}

int removerMeio(Lista*l, int matricula){
    if(listaNula(l))
        return 0;
    if(listaVazia(l))
        return 0;
    int i;
    int flag = 0;
    for(i = 0; i < l->qtd; i++){
        if(l->dados[i].matricula == matricula){
            flag = 1;
            break;
        }
    }
    if(flag) {
        for(int j = i; j < l->qtd-1; j++){
            l->dados[j] = l->dados[j+1]; 
        }
        return 1;
    }
    return 0;
}

Aluno *consultaPosicao(Lista*l, int pos){
    if(listaNula(l))
        return NULL;
    if(listaVazia(l))
        return NULL;
    if (pos > l->qtd && pos < 0)
        return NULL;

    return &l->dados[pos];
}

Aluno *consultaConteudo(Lista*l, int matricula){
    if(listaNula(l))
        return NULL;
    if(listaVazia(l))
        return NULL;
    for(int i = 0; i < l->qtd; i++){
        if(l->dados[i].matricula == matricula){
            return &l->dados[i];
            break;
        }
    }
    return  NULL;
}

void imprimirLista(Lista*l){
    printf("\nLista de alunos (%d)", l->qtd);
    for (int i = 0; i < l->dados[i]; i++) {
        printf("\n [%d] - ", i+1);
        printf("Nome: %s| Matricula: %d \n", l->dados[i].nome, l->dados[i].matricula);
    }
}
