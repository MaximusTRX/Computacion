#include<stdio.h>
#include<conio.h>

int main()
{
    do
    {
        unsigned char entrada, aux1, aux2;
        printf("\nIngrese un numero: ");
        scanf("%d%*c", &entrada);
        printf("\nEl numero ingresa en hexadecimal es: %X", entrada);
        
        
        aux1 = entrada;
        
        aux2 = (entrada<<4 | aux1>>4);

        printf("\nEl resultado es: %X", aux2);

        printf("\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");

    } while (getch() != 27);
    
    return 0;
}
