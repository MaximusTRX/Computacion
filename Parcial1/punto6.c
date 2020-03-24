/*Realizar un programa que lea un número entero y muestre sus dígitos en palabras. Si el
número es negativo debería empezar con la palabra “menos”. El programa debe aceptar enteros de
hasta 5 dígitos.*/

#include<stdio.h>
#include"conio.h"
#include<math.h>
int main()
{
    do
    {
        int entrada, div;
        printf("\nIngrese el numero: \n");
        scanf("%i%*c", &entrada);

        if (abs(entrada) >= 10000)
        {
            div =10000;
        }else if (abs(entrada) >= 1000)
        {
            div = 1000;
        }else if (abs(entrada) >= 100)
        {
            div = 100;
        }else if (abs(entrada) >= 10)
        {
            div = 10;
        }else
        {
            div = 1;
        }
        if (entrada < 0)
        {
            printf(" MENOS");
        }

        do
        {
            switch (abs(entrada)/div)
            {
            case 0:
                printf(" CERO");
                break;
            case 1:
                printf(" UNO");
                break;
            case 2:
                printf(" DOS");
                break;
            case 3:
                printf(" TRES"); 
                break;
            case 4:
                printf(" CUATRO");
                break;
            case 5:
                printf(" CINCO");
                break;
            case 6:
                printf(" SEIS");
                break;
            case 7:
                printf(" SIETE");
                break;
            case 8:
                printf(" OCHO");
                break;
            case 9:
                printf(" NUEVE");
                break;
            }
            entrada %= div;
            div /= 10;
        }while (div != 0);
        
        printf("\n\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");
    } while (getch() != 27);
    return 0;
}