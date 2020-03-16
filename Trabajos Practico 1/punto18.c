#include<stdio.h>
#include<stdlib.h>
#include"conio.h"

int main()
{
    do
    {
        float r1 = 0.00000001, r, eps, n;

        printf("\nIngrese el numero a calcular: ");
        scanf("%f%*c", &n);
        printf("\nIngrese el error aceptable de la operacion: ");
        scanf("%f%*c", &eps);
        
        do
        {
            r = r1;
            r1 = ((n/r)+r)/2;
        } while (abs(r-r1) > eps);
        
        printf("\nLa raiz cuadrada de %.2f es = %.2f\n", n, r1);
    } while (getch() != 27);
    
    return 0;
}
