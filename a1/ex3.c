# include <stdio.h>
# include <math.h>

void main(){
    int vetor[5];
    int quadrado[5];

    for (int i = 0; i < 5; i++)
    {
        printf("\n Digite um num inteiro: ");

        scanf("%d", &vetor[i]);

        quadrado[i] = pow(vetor[i], 2);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("Valores ao quadrado: %d \n", quadrado[i]);
    }
}