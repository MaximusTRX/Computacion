#include<stdio.h>
#include<conio.h>

int main()
{
    do
    {
        char entrada;
        unsigned char w = 27;
        textcolor(9);
        gotoxy(1, w);
        cprintf(" ----------------------------------------------------------------------------------------------");
        gotoxy(1, w+1);
        cprintf("| Presione [F1] | Se cargar la matriz con calores aleatorios entre A y F                       |");
        gotoxy(1, w+2);
        cprintf(" ----------------------------------------------------------------------------------------------|");
        gotoxy(1, w+3);
        cprintf("| Presione [F2] | Se resalta la combinacion de caracteres FDA                                  |");
        gotoxy(1, w+4);
        cprintf(" ----------------------------------------------------------------------------------------------|");
        gotoxy(1, w+5);
        cprintf("| Presione [F3] | Se encuentran los valores que se repiten, indicando el valor, cuantas veces, |");
        gotoxy(1, w+6);
        cprintf(" ----------------------------------------------------------------------------------------------|");
        gotoxy(1, w+7);
        cprintf("|               | y en que posiciones se encuentran dichos valores repetidos                   |");
        gotoxy(1, w+8);
        cprintf(" ----------------------------------------------------------------------------------------------");
        
        fflush(stdin);
        entrada = getch();
            if (entrada == 0)
            {
                entrada = getch();
                switch (entrada)
                {
                case 59://F1
                
                    break;
                case 60://F2

                    break;
                case 61://F3

                    break;
                }
            }

        printf("\n\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");
    } while (getch() != 27);
    return 0;
}