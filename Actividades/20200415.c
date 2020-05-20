#include<stdio.h>
#include<conio.h>

int main()
{
    while (1)
    {
        gotoxy(1, 1);
        printf("-Presione cualquier tecla para volver a ejecutar");
        gotoxy(1, 2);
        printf("-Presione ESCAPE para finalizar");
    }
    return 0;
}