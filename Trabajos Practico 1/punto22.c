#include<stdio.h>
#include"conio.h"

int main()
{
    do
    {
        int entrada, positivo = 0, negativo = 0;
        unsigned char bandpos = 0, bandneg = 0;
        do
        {
            printf("\nIngrese un valor: ");
            scanf("%i%*c", &entrada);

            if (entrada > 0)
            {
                if (entrada > positivo)
                {
                    positivo = entrada;
                }
                bandpos++;
            }else if (entrada < 0)
            {
                if (entrada < negativo)
                {
                    negativo = entrada;
                }
                bandneg++;
            }
        } while (entrada != 0);
        
        if (bandpos > 0)
        {
            printf("\nEl mayor valor ingresado es: %i", positivo);
        }else
        {
            printf("\nNo se ingresaron valores positivos");
        }

        if (bandneg > 0)
        {
            printf("\n El menor valor ingresado es: %i", negativo);
        }else
        {
            printf("\nNo se ingresaron valores negativos");
        }
        printf("\n\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");
    } while (getch() != 27);
    return 0;
}