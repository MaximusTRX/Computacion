/*Escribir un programa que lea un texto y nos de cómo resultado el número de caracteres, el
número de palabras y el número de líneas del mismo. Suponemos que una palabra esta
separada de la otra por uno o más espacios, caracteres tab o caracteres nueva línea.
    cuente caracteres
    cuente palabras
    cuente lineas
*/

#include<stdio.h>
#include"conio.h"

int main()
{
    do
    {
        char caracter;
        int cantcaracter = 0, cantpalabra = 0, cantlinea = 0;

        printf("\nIngrese el texto: \n");
        do
        {
            caracter = getche();
            printf("\ncant caract %i", cantcaracter);
            if ((caracter == ' ') || (caracter == '\t') || (caracter == '\n'))
            {
                cantpalabra++;
                printf("\ncant palabra %i", cantpalabra);
                if (caracter == '\n')
                {
                    cantlinea++;
                    printf("\ncant linea %i", cantlinea);
                }
            }else 
            cantcaracter++;
        } while (caracter != 27);
        
        printf("\nEl texto tiene: ");
        printf("\n\t%d caracteres.");
        printf("\n\t%d palabras.");
        printf("\n\t%d lineas.");

        printf("\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");
    } while (getch() != 27);
    return 0;
}