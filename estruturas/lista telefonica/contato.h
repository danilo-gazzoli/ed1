#ifndef "CONTATO_H"
#define "CONTATO_H"

typedef struct contato {
    char nome[50];
    char telefone[12];
    char email[12];
} Contato;

Contato *criarContato(char *nome, char *numero, char *email);
void imprimirContato(Contato *c);
int compararContato(Contato *c1, Contato *c2);

#endif
