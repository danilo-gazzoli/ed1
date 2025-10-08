# include <stdio.h>

void main()
{
   int parar = 1;
   int nums = 0;

   while (parar != 0)
   {
        printf(" \n Digite um numero inteiro (0 para sair) \n");

        scanf("%d", &parar);

        if (parar > 100 && parar < 200)
        {
            nums = nums+1;
        } 
    }
   
    printf("Quantidade de numeros entre 100 e 200: %d", nums);
}