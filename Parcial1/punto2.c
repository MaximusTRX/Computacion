/*Escribir un programa que lea un texto y nos de cómo resultado el número de caracteres, el
número de palabras y el número de líneas del mismo. Suponemos que una palabra esta
separada de la otra por uno o más espacios, caracteres tab o caracteres nueva línea.
    cuente caracteres
    cuente palabras
    cuente lineas
*/

#include<stdio.h>
#include<conio.h>

int main()
{
    do
    {
        unsigned char flag;
        char caracter;
        int cantcaracter = 0, cantpalabra = 0, cantlinea = 1, bandpalabra = 0;

        printf("\nIngrese el texto: \n");
        do
        {
            fflush(stdin);
            caracter = getche();

            if ((caracter == 27) || (caracter > 31) || (caracter < 254) || (caracter == 13) || (caracter == 9))
            {
                cantcaracter++;
                switch (caracter)
                {
                case ' ':
                    cantcaracter--;
                    if (cantcaracter > 1)
                    {
                        cantpalabra++;
                    }
                    break;
                case '\t':
                    cantcaracter--;
                    if (cantcaracter > 1)
                    {
                        cantpalabra++;
                    }
                    break;
                case 27:
                    cantcaracter--;
                    if (flag != 0)
                    {
                        cantpalabra++;
                    }
                    break;
                case '\r':
                    cantcaracter--;
                    if (flag != 0)
                    {
                        cantpalabra++;
                    }
                    cantlinea++;
                    flag = 0;
                    printf("\n");
                    break;
                case 8:
                    cantcaracter--;
                    break;
                default:
                    
                    flag++;

                    break;
                }
            }
        }while (caracter != 27);
        
        if (cantcaracter < 1)
        {
            cantcaracter = 0;
            cantlinea = 0;
            cantpalabra = 0;
        }
        
        printf("\nEl texto tiene: ");
        printf("\n\t%i caracteres.", cantcaracter);
        printf("\n\t%i palabras.", cantpalabra);
        printf("\n\t%i lineas.", cantlinea);

        printf("\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");
    } while (getch() != 27);
    return 0;
}