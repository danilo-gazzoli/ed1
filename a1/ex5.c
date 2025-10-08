#include <stdio.h>

typedef struct aluno {
    char nome[30];
    int matricula;
    float p1, p2, p3, media;
} Aluno;

int main(){
    struct aluno aluno[5];

    float maiorMedia = 0.0;

    int indiceMelhorAluno = 0;

    for (int i = 0; i < 5; i++) {
        printf("\n Digite o nome do aluno: ");

        scanf("%29s", aluno[i].nome);

        printf("\n Digite a matrícula do aluno: ");

        scanf("%d", &aluno[i].matricula);

        printf("\n Digite a nota da p1: ");

        scanf("%f", &aluno[i].p1);

        printf("\n Digite a nota da p2: ");

        scanf("%f", &aluno[i].p2);

        printf("\n Digite a nota da p3: ");

        scanf("%f", &aluno[i].p3);

        aluno[i].media = (aluno[i].p1 + aluno[i].p2 + aluno[i].p3)/3.0;

        if (aluno[i].media > maiorMedia) {
            maiorMedia = aluno[i].media;
            indiceMelhorAluno = i;
        }
        
    }

    printf("\n Nome: %s | ", aluno[indiceMelhorAluno].nome);
    printf("Matricula: %d | ", aluno[indiceMelhorAluno].matricula);
    printf("Prova 1: %f | ", aluno[indiceMelhorAluno].p1);
    printf("Prova 2: %f | ", aluno[indiceMelhorAluno].p2);
    printf("Prova 3: %f | \n", aluno[indiceMelhorAluno].p3);
    printf("Media: %f | \n", aluno[indiceMelhorAluno].media);

    return 0;
}