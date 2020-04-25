#include <stdio.h>
#include <conio.h>

int main(void)
{
    char caracter;
    fflush(stdin);
    caracter = getch();

    printf("%d", caracter);

    getch();
    return 0;
}