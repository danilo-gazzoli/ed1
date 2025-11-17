#ifndef "LISTA_H"
#define "LISTA_H"

typedef struct aluno{
    int n1, n2, n3;
    char nome[30]
    int matricula;
} Aluno;

typedef struct Lista lista;

Aluno criarAluno(char*nome, int matricula, int n1,int n2, int n3);
Aluno *consultaPosicao(Lista*l, int pos);
Aluno *consultaConteudo(Lista*l, int matricula);
Lista *criarLista();
void liberarLista(Lista*l);
void imprimirLista(Lista*l)
int tamanhoLista(Lista*l);
int listaNula(Lista*l);
int listaCheia(Lista*l);
int listaVazia(Lista*l);
int inserirFinal(Lista*l, Aluno*a);
int inserirInicio(Lista*l, Aluno*a);
int inserirOrdenado(Lista*l, Aluno*a);
int removerInicio(Lista*l);
int removerFinal(Lista*l);
int removerMeio(Lista*l, int matricula);

#endif