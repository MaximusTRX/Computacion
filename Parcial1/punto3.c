/*Realizar un programa que lea un entero y la posición de dos bits, luego que muestre el valor
de los bits entre los bits indicados. Por ejemplo si el usuario ingrese el valor decimal 176 (binario
10110000) y los valores 6 y 4 para los bits, el programa deberá mostrar el valor decimal 3 que
corresponde al binario 011*/

#include<stdio.h>
#include<conio.h>

int main()
{
    do
    {
        int entrada = 0, aux, var1 = 0, var2 = 0; 
        do{
            printf("Ingrese un valor: ");
            scanf("%i%*c", &entrada);
        }while (entrada < 0);
        
        printf("\nIngrese el intervalo de BITS:\n");
        
        do{
            printf("Ingrese un valor: ");
            scanf("%i%*c", &var1);
        }while ((var1 < 0) || (var1 > sizeof(int)*8));
        
        do{
            printf("\nIngrese un valor: ");
            scanf("%i%*c", &var2);
        }while ((var2 < 0) || (var2 > sizeof(int)*8));
        
        if (var2 > var1)
        {
            aux = var1;
            var1 = var2;
            var2 = aux;
        }
        int izq = (32 - (var1+1));
        int der = (izq + var2);

        entrada = entrada << izq;
        entrada = entrada >> der;

        printf("El valor entre los BITS indicados es: %i", entrada);
        printf("\n\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");
    } while (getch() != 27);
    return 0;
}