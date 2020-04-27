#include <stdio.h>
#include <conio.h>

int main(void)
{
    int entrada, div = 1000, aux, cont=0;
    printf("\nIngrese el numero: \n");
    scanf("%i", &entrada);
    do
    {
        printf("\nDIV1= %i", div);
        cont++;
        aux = (entrada/div);
        entrada %= div;
        div /= 10;

        printf("\n Pasada %i",cont);
        printf("\nAUX= %i", aux);
        printf("\nAUX mod 10= %i", (aux%10));
        printf("\nEntrada= %i", entrada);
        printf("\nDIV= %i", div);

    }while (div != 0);
    

    getch();
    return 0;
}