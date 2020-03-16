#include<stdio.h>
#include<conio.h>

int main()
{
    do
    {
        int entrada = 0, suma = 0;
        printf("\nIngrese un numero a sumar: ");

        while (scanf("%i%*c", &entrada) != EOF)
        {
            suma += entrada;
        }

        printf("El valor de la suma es: %d", suma);
                

        printf("\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");

    } while (getch() != 27);
    
    return 0;
}
