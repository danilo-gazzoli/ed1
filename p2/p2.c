/* Autores:
    Nome: Danilo Martins Gazzoli
    Nome: Matheus Lucas Klippel Tavares
*/

#include <stdlib.h>
#include <stdio.h>

// implementação da estrutura conforme o enunciado do trabalho
typedef struct arvore
{
    int info;
    struct arvore *esq;
    struct arvore *dir;
} Arvore;

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

// questão 3
void main(){
    printf("========== TESTE DAS FUNCOES DE ARVORE BINARIA ==========\n\n");

    // ===== CONSTRUINDO ÁRVORES DE TESTE =====
    printf("--- Construindo árvores de teste ---\n");

    // Árvore A para teste
    //        5
    //       / \
    //      3   8
    //     / \ / \
    //    1  4 7  9
    Arvore *arvoreA = criarNo(5);
    arvoreA->esq = criarNo(3);
    arvoreA->dir = criarNo(8);
    arvoreA->esq->esq = criarNo(1);
    arvoreA->esq->dir = criarNo(4);
    arvoreA->dir->esq = criarNo(7);
    arvoreA->dir->dir = criarNo(9);
    printf("Árvore A criada com sucesso!\n\n");

    // ===== TESTANDO qtdFolhas =====
    printf("--- Testando qtdFolhas ---\n");
    int folhas = qtdFolhas(arvoreA);
    printf("Quantidade de folhas em Árvore A: %d (esperado: 4)\n", folhas);
    printf("Resultado: %s\n", folhas == 4 ? "PASSOU" : "FALHOU");

    // Teste com árvore vazia
    int folhasVazia = qtdFolhas(NULL);
    printf("Quantidade de folhas em árvore vazia: %d (esperado: 0)\n", folhasVazia);
    printf("Resultado: %s\n", folhasVazia == 0 ? "PASSOU" : "FALHOU");

    // Teste com árvore com um nó
    Arvore *arvoreUnica = criarNo(10);
    int folhasUnica = qtdFolhas(arvoreUnica);
    printf("Quantidade de folhas em árvore com um nó: %d (esperado: 1)\n", folhasUnica);
    printf("Resultado: %s\n\n", folhasUnica == 1 ? "PASSOU" : "FALHOU");

    // ===== TESTANDO qtdInt =====
    printf("--- Testando qtdInt ---\n");
    int qtd5 = qtdInt(arvoreA, 5);
    printf("Quantidade de nós com valor 5 em Árvore A: %d (esperado: 1)\n", qtd5);
    printf("Resultado: %s\n", qtd5 == 1 ? "PASSOU" : "FALHOU");

    int qtd3 = qtdInt(arvoreA, 3);
    printf("Quantidade de nós com valor 3 em Árvore A: %d (esperado: 1)\n", qtd3);
    printf("Resultado: %s\n", qtd3 == 1 ? "PASSOU" : "FALHOU");

    int qtd10 = qtdInt(arvoreA, 10);
    printf("Quantidade de nós com valor 10 em Árvore A: %d (esperado: 0)\n", qtd10);
    printf("Resultado: %s\n\n", qtd10 == 0 ? "PASSOU" : "FALHOU");

    // ===== TESTANDO copia =====
    printf("--- Testando copia ---\n");
    Arvore *cópia = copia(arvoreA);
    printf("Cópia criada com sucesso!\n");

    int folhasCópia = qtdFolhas(cópia);
    printf("Quantidade de folhas na cópia: %d (esperado: 4)\n", folhasCópia);
    printf("Resultado: %s\n\n", folhasCópia == 4 ? "PASSOU" : "FALHOU");

    // ===== TESTANDO iguais =====
    printf("--- Testando iguais ---\n");
    int saoIguais = iguais(arvoreA, cópia);
    printf("Árvore A e sua cópia são iguais: %d (esperado: 1)\n", saoIguais);
    printf("Resultado: %s\n", saoIguais == 1 ? "PASSOU" : "FALHOU");

    int iguaisArvoreUnica = iguais(arvoreA, arvoreUnica);
    printf("Árvore A e Árvore Única são iguais: %d (esperado: 0)\n", iguaisArvoreUnica);
    printf("Resultado: %s\n", iguaisArvoreUnica == 0 ? "PASSOU" : "FALHOU");

    int iguaisVazias = iguais(NULL, NULL);
    printf("Duas árvores vazias são iguais: %d (esperado: 1)\n", iguaisVazias);
    printf("Resultado: %s\n\n", iguaisVazias == 1 ? "PASSOU" : "FALHOU");

    // ===== TESTANDO maior =====
    printf("--- Testando maior ---\n");
    int maiorA = maior(arvoreA);
    printf("Maior elemento em Árvore A: %d (esperado: 9)\n", maiorA);
    printf("Resultado: %s\n", maiorA == 9 ? "PASSOU" : "FALHOU");

    int maiorUnica = maior(arvoreUnica);
    printf("Maior elemento em Árvore Única (valor 10): %d (esperado: 10)\n", maiorUnica);
    printf("Resultado: %s\n", maiorUnica == 10 ? "PASSOU" : "FALHOU");

    int maiorVazia = maior(NULL);
    printf("Maior elemento em árvore vazia: %d (esperado: -1)\n", maiorVazia);
    printf("Resultado: %s\n\n", maiorVazia == -1 ? "PASSOU" : "FALHOU");

    // ===== TESTANDO ocorrenciasX (ÁRVORE BINÁRIA DE BUSCA) =====
    printf("--- Testando ocorrenciasX (Árvore Binária de Busca) ---\n");
    //          5
    //         / \
    //        3   8
    //       / \   \
    //      1   4   9
    Arvore *arvoreBST = criarNo(5);
    arvoreBST->esq = criarNo(3);
    arvoreBST->dir = criarNo(8);
    arvoreBST->esq->esq = criarNo(1);
    arvoreBST->esq->dir = criarNo(4);
    arvoreBST->dir->dir = criarNo(9);
    printf("Árvore BST criada com sucesso!\n\n");

    int ocorr5 = ocorrenciasX(arvoreBST, 5);
    printf("Ocorrências de 5 em BST: %d (esperado: 1 - encontrado)\n", ocorr5);
    printf("Resultado: %s\n", ocorr5 == 1 ? "PASSOU" : "FALHOU");

    int ocorr1 = ocorrenciasX(arvoreBST, 1);
    printf("Ocorrências de 1 em BST: %d (esperado: 1 - encontrado)\n", ocorr1);
    printf("Resultado: %s\n", ocorr1 == 1 ? "PASSOU" : "FALHOU");

    int ocorr9 = ocorrenciasX(arvoreBST, 9);
    printf("Ocorrências de 9 em BST: %d (esperado: 1 - encontrado)\n", ocorr9);
    printf("Resultado: %s\n", ocorr9 == 1 ? "PASSOU" : "FALHOU");

    int ocorr10 = ocorrenciasX(arvoreBST, 10);
    printf("Ocorrências de 10 em BST: %d (esperado: 0 - não encontrado)\n", ocorr10);
    printf("Resultado: %s\n", ocorr10 == 0 ? "PASSOU" : "FALHOU");

    int ocorr2 = ocorrenciasX(arvoreBST, 2);
    printf("Ocorrências de 2 em BST: %d (esperado: 0 - não encontrado)\n", ocorr2);
    printf("Resultado: %s\n\n", ocorr2 == 0 ? "PASSOU" : "FALHOU");

    // ===== TESTANDO imprimirDecrescente =====
    printf("--- Testando imprimirDecrescente (folhas em ordem decrescente) ---\n");
    printf("Folhas da BST em ordem decrescente: ");
    imprimirDecrescente(arvoreBST);
    printf("\n(esperado: 9 | 4 | 1 | )\n\n");

    // ===== FINALIZANDO =====
    printf("========== FIM DOS TESTES ==========\n");

    // Liberando memória
    liberar(arvoreA);
    liberar(cópia);
    liberar(arvoreUnica);
    liberar(arvoreBST);
}
