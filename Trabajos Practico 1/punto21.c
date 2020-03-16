#include<stdio.h>
#include<math.h>
#include"conio.h"

int main()
{
    do
    {
        float a=0, b=0, c=0, dis=0;
        printf("\nFormato de la ecuacion: Ax^2+Bx+C");
        printf("\nIngrese A: ");
        scanf("%f%*c", &a);
        printf("\nIngrese B: ");
        scanf("%f%*c", &b);
        printf("\nIngrese C: ");
        scanf("%f%*c", &c);
        dis = (b*b) - (4*a*c);
        if ((a==0) && (b==0))
        {
            printf("\nEcuacion DENEGADA");
        }else if ((a==0) && (b != 0))
        {
            printf("\nLa raiz es: %.2f", (-c/b));
        }else if (dis >= 0)
        {
            printf("\nLa raiz 1 es: %.2f", (-b+sqrt(dis))/2*a);
            printf("\nLa raiz 2 es: %.2f", (-b-sqrt(dis))/2*a);
        }else if (dis < 0)
        {
            printf("\nLa raiz 1 es: %+.2f %+.2fi", (-b/2*a), (sqrt(-dis)/2*a));
            printf("\nLa raiz 2 es: %+.2f %+.2fi", (-b/2*a), (sqrt(-dis)/2*a));
        } 
        printf("\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");
    } while (getch() != 27);
    return 0;
}