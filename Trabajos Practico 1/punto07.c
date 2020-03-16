#include<stdio.h>
#include<conio.h>

int main()
{
    unsigned char esc;
    do
    {
        int segundos;
        printf("\nIngrese una cantidad de segundos: ");
        scanf("%i", &segundos);

        int hora;
        int minuto;
        int segundo;

        hora = segundos/3600;
        minuto = (segundos % 3600)/60;
        segundo = (minuto % 60)/60;

        printf("Es igual a: %2i : %2i : %2i\n", hora, minuto, segundo);

        esc = getch();
    } while (esc != 27);
    return 0;
}
