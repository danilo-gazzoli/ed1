#include <stdio.h>
#include <string.h>

int trocarCharEContar(char menssagem[], char caracter){
    int numCaracteresModificados = 0;

    for (int i = 0; menssagem[i] != '\0'; i++){
        if (menssagem[i] == caracter)
        {
            menssagem[i] = '*';
            numCaracteresModificados++;
        }
    }
    return numCaracteresModificados;
}

void main(){
    int numCharsSubstituidos = 0;
    char mensagem[100];
    char caractere;

    printf("\n Digite uma mensagem curta: ");

    fgets(mensagem, 100, stdin);
    
    mensagem[strcspn(mensagem, "\n")] = 0;

    printf("\n Digite um caractere: ");

    scanf(" %c", &caractere);

    numCharsSubstituidos = trocarCharEContar(mensagem, caractere);

    printf("\n Mensagem: %s", mensagem);
    printf("\n Numero de caracteres Alterados: %d", numCharsSubstituidos);
}