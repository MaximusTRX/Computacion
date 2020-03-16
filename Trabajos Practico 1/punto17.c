#include<stdio.h>
#include<conio.h>

int main()
{
    do
    {

        unsigned char z, x = 1, y;

        while (x <= 50)
        {
            y = 1;
            while (y <= 50)
            {
                z = 1;
                while (z <= 50)
                {
                    z++;
                    if (z*z==x*x+y*y)
                    {
                        printf("El numero Z= %i cumple con la condicion Z^2= X^2 + Y^2\n", z);
                    }   
                }
                y++;
            }
            x++;
        }
        printf("\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");
    } while (getch() != 27);
    return 0;
}
