#include<stdio.h>
#include<conio.h>
#include<math.h>

void drawcircle();

int main()
{
    do
    {

        textmode(C4350);
        _setcursortype(_NOCURSOR);

        drawcircle();

        gotoxy(52, 1);
        /*cprintf("\n\n-Presione cualquier tecla para volver a ejecutar");
        gotoxy(53, 1);
        cprintf("\n-Presione ESCAPE para finalizar\n");*/
    } while (getch() != 27);
    return 0;
}

void drawcircle(){
        for (char x = 0; x < 80 ; x++)
        {
            for (char y = 0; y < 50; y++)
            {
                if (floor(0.5+ sqrt((x-40)*(x-40) + (y-25)*(y-25))) == 24)
                {
                    textbackground(15);
                    textcolor(0);
                    gotoxy(x+1, y+1);
                    cprintf(" ");
                }
            }
        }
}