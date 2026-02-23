/* Autores:
    Nome: Danilo Martins Gazzoli
    Nome: Matheus Lucas Klippel Tavares
*/

#ifndef ARVORE_H
#define ARVORE_H

// implementação da estrutura conforme o enunciado do trabalho
typedef struct arvore
{
    int info;
    struct arvore *esq;
    struct arvore *dir;
} Arvore;

//questão 1
int qtdFolhas(Arvore *a);
int qtdInt(Arvore *a, int c);
int iguais(Arvore *a, Arvore *b);
Arvore* copia(Arvore *a);
int maior(Arvore *a);

// questão 2
int ocorrenciasX(Arvore *a, int x);
void imprimirDecrescente(Arvore *a);

// funções para a questão 3
Arvore* criarNo(int valor);
void liberar(Arvore *a);

#endif
