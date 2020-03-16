#include<stdio.h>
#include"conio.h"

int main()
{
    do
    {
        int numero;
        unsigned int posi;

        printf("\n====================================================================\n"); 
        printf("\nIngrese un numero: ");
        scanf("%i%*c", &numero);
        printf("\nCual bit quiere conocer su valor: ");
        scanf("%i%*c", &posi);

        if (0x01 & (numero>>posi))
        {
            printf("\nEl valor del bit %d del numero %i es: 1\n", posi, numero);
        }else
        {
            printf("\nEl valor del bit %d del numero %i es: 0\n", posi, numero);
        }
        
        printf("\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");
        
    } while (getch() != 27);
    
    return 0;
}