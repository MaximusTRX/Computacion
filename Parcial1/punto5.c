/*Realizar un programa que ingrese 10 valores enteros, el programa debe devolver cuantas
veces se ingresaron valores sucesivos. Ejemplo se ingresa -5, 10, 17, -31, -30, -29, 75, 76, 9, -4.
Entonces el programa devuelve 3, {-31, -30} {-30, -29} {75, 76}.*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    do
    {
        unsigned int cont = 0, sucesivos = 0;
        int entrada, comp;
        printf("\nIngrese un numero: ");
        scanf("%i%*c", &entrada);
        do
        {
            comp = entrada;
            printf("\nIngrese un numero: ");
            scanf("%i%*c", &entrada);
            if (abs((entrada)-(comp)) == 1)
            {
                sucesivos++;
            }
            cont++;
        }while (cont < 9);
        
        printf("\nSe ingreso %d valores sucesivos", sucesivos);
        printf("\n\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");
    } while (getch() != 27);
    return 0;
}