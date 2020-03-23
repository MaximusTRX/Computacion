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
#include<conio.h>

int main()
{
    do
    {

        unsigned char entrada = 0, n = 0, resul1, resul2;
        int aux1 = 0, aux2 = 0;
        do
        {
            printf("\nIngrese un valor: ");
            scanf("%i%*c", &aux1);
        } while ((aux1 < 0) || (aux1 > 255));
        
        do{
            printf("\nIngrese la cantidad de bits a correr: ");
            scanf("%i%*c", &aux2);
        } while ((aux2 < 0) || (aux2 > 255));
        
        entrada = aux1;
        n = aux2;

        resul1 = (entrada << n) + (entrada >> (8-n));
        resul2 = (entrada >> n) + (entrada << (8-n));

        printf("\nEl numero ingresado desplazado %d veces hacia la izquierda sumado con los bits que fueron desplazados a la derecha es: %d", n, resul1);
        printf("\nEl numero ingresado desplazado %d veces hacia la derecha sumado con los bits que fueron desplazados a la izquierda es: %d", n, resul2);
        
        printf("\n\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");
    } while (getch() != 27);
    return 0;
}