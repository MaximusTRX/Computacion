/*Realizar un programa que lea un número entero y muestre sus dígitos en palabras. Si el
número es negativo debería empezar con la palabra “menos”. El programa debe aceptar enteros de
hasta 5 dígitos.*/

#include<stdio.h>
#include"conio.h"

int main()
{
    do
    {
        printf("\nIngrese los numeros: \n");
        char entrada;

        while ((entrada = getche()) != 27)
        {
            switch (entrada)
            {
            case '-':
            printf("\t| MENOS\n");
                break;
            case '0':
                printf("\t| CERO\n");
                break;
            case '1':
                printf("\t| UNO\n");
                break;
            case '2':
                printf("\t| DOS\n");
                break;
            case '3':
                printf("\t| TRES\n"); 
                break;
            case '4':
                printf("\t| CUATRO\n");
                break;
            case '5':
                printf("\t| CINCO\n");
                break;
            case '6':
                printf("\t| SEIS\n");
                break;
            case '7':
                printf("\t| SIETE\n");
                break;
            case '8':
                printf("\t| OCHO\n");
                break;
            case '9':
                printf("\t| NUEVE\n");
                break;
            }
        }
        printf("\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");
    } while (getch() != 27);
    return 0;
}