# include <stdio.h>

void main(){
    int idade;

    printf("Digite a sua idade: ");

    scanf("%d", &idade);

    if (idade > 65){
        printf("Voce e idoso \n");
        
    } if (idade >= 18 && idade <= 65){
        
        printf("Voce e de maior \n");
        
    } if (idade < 18) {
        
        printf("Voce e de menor \n");
        
    }
}