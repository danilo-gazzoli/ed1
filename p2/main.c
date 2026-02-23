/* Autores:
    Nome: Danilo Martins Gazzoli
    Nome: Matheus Lucas Klippel Tavares
*/

#include <stdio.h>
#include <stdlib.h>
#include "arvore.c"

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