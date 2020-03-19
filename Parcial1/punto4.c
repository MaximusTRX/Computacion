/*Escribir un programa que lea un entero entre [0, 255] y el número de bits de desplazamiento
(n). El programa debe mostrar la suma de:
a.- El número ingresado desplazado n veces hacia la izquierda sumado con los bits que
fueron desplazados a la derecha.
b.- El número ingresado desplazado n veces hacia la derecha sumado con los bits que fueron
desplazados a la izquierda.
Ejemplo: Ingresa el número 42 (00101010 2 ) y 3 bits de desplazamiento =>
a.- Sum = 81,
01010001 2
b.- Sum = 69,
01000101 2*/

#include<stdio.h>
#include"conio.h"

int main()
{
    do
    {

        unsigned char entrada = 0, n = 0, resul1, resul2;

        printf("\nIngrese un valor: ");
        scanf("%d%*c", &entrada);
        printf("\nIngrese la cantidad de bits a correr: ");
        scanf("%d%*c", &n);

        resul1 = (entrada << n) + (entrada >> (8-n));
        resul2 = (entrada >> n) + (entrada << (8-n));

        printf("\nEl número ingresado desplazado %d veces hacia la izquierda sumado con los bits que fueron desplazados a la derecha es: %d", n, resul1);
        printf("\nEl número ingresado desplazado %d veces hacia la derecha sumado con los bits que fueron desplazados a la izquierda es: %d", n, resul2);
        
        printf("\n\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");
    } while (getch() != 27);
    return 0;
}