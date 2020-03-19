/*Escribir un programa que lea un texto y nos de cómo resultado el número de palabras con
al menos cuatro vocales diferentes. Suponemos que una palabra este separada de la otra
por uno o más espacios (' '), caracteres tab (\t) o caracteres nueva línea (\n).*/

#include<stdio.h>
#include"conio.h"

int main()
{
    do
    {
        char entrada;
        unsigned char banda = 0, bande = 0, bandi = 0, bando = 0, bandu = 0;
        int palabras = 0;

        printf("\n\nIngrese el texto a evaluar:\n");
        while ((entrada = getche()) != 27)
        {
            if (entrada != ' ' && entrada != '\t' && entrada != '\n')
            {
                switch (entrada)
                {
                case 'A':
                case 'a':
                    banda = 1;
                    break;
                
                case 'E':
                case 'e':
                    bande = 1;
                    break;

                case 'I':
                case 'i':
                    bandi = 1;
                    break;

                case 'O':
                case 'o':
                    bando = 1;
                    break;

                case 'U':
                case 'u':
                    bandu = 1;
                    break;
                }
                
            }else
            {
                banda = 0, bande = 0, bandi = 0, bando = 0, bandu = 0;
                palabras = 0;
            }
            if((banda+bande+bandi+bando+bandu) >= 4)
            {
                palabras++;
            }
        }
        
        printf("\nEn el texto hay %i palabras con al menos 4 vocales diferentes", palabras);

        printf("\n\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");
    } while (getch() != 27);
    return 0;
}