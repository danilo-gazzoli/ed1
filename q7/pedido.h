#ifndef "PEDIDO_H"
#define "PEDIDO_H"

typedef struct pedido{
    int numero;
    int quantidade;
    char descricao[100];
}

typedef struct Lista lista;

int inserirInicio(Lista*l, Aluno*a);
int inserirFinal(Lisa*l, Aluno*a);
int removerInicio(Lista*l);
int removerFinal(Lista*l);
Aluno buscaPorNumero(Lista*l, int num);
void exibirLista(Lista*l);
int ordenarPorQuantidade(Lista*l);

#endif
