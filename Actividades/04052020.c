#include<stdio.h>
#include<conio.h>
#include<math.h>

int main()
{
    do
    {

        textmode(C4350);
        _setcursortype(_NOCURSOR);

        int x, y, res;

        for (x = 0; x < 80 ; x++)
        {
            for (y = 0; y < 50; y++)
            {
                res = floor(pow((x-40),2) + pow((y-25), 2));

                cprintf("%.1i",res);
                if (res == (24*24))
                {
                    textbackground(15);
                    textcolor(0);
                    gotoxy(x+1, y+1);
                    cprintf(" ");
                }else
                {
                    textbackground(0);
                    textcolor(15);
                    gotoxy(x+1, y+1);
                    cprintf(" ");
                }
            }
        }
        


        printf("\n\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");
    } while (getch() != 27);
    return 0;
}