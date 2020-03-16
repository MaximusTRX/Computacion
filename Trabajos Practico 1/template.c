#include<stdio.h>
#include"conio.h"

int main()
{
    do
    {

        printf("\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");
    } while (getch() != 27);
    return 0;
}