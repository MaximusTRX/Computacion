#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main()
{
    randomize();
    unsigned char w = 10, i, j, x, y, flagfil = 0, flagcol = 0, cont = 0;
    char entrada;
    int matriz[5][5] = {0};
    int aux;
    do
    {

        textcolor(9);
            gotoxy(60, w);
            cprintf(" -----------------------------------------------------------");
            gotoxy(60, w+1);
            cprintf("| Opt [F1] | Se cargar la matriz con valores aleatorios     |");
            gotoxy(60, w+2);
            cprintf(" -----------------------------------------------------------");
            gotoxy(60, w+3);
            cprintf("| Opt [F2] | Numeros aleatorios sin repetir entre 100 y 500 |");
            gotoxy(60, w+4);
            cprintf(" -----------------------------------------------------------");
            fflush(stdin);
            entrada = getch();

            if (entrada == 0)
            {
                
                entrada = getch();
                switch (entrada)
                {
                case 59://F1
                    for (i = 0; i < 5; i++)
                    {
                        for (j = 0; j < 5; j++)
                        {
                            matriz[i][j] = random(1000);
                        }
                    }
                    textcolor(9);
                    gotoxy(1,1);
                    cprintf("MATRIZ ORIGINAL");
                    gotoxy(1, 3);
                    textcolor(15);
                    for (i = 0; i < 10; i++)
                    {
                        gotoxy(1, 3+i);
                        for (j = 0; j < 10; j++)
                        {
                            cprintf("%3i  ", matriz[i][j]);
                        }
                    }
                    break;
                case 60://F2
                    for (i = 0; i < 5; i++)
                    {
                        gotoxy(1, 10+i);
                        for (j = 0; j < 5; j++)
                        {
                            aux = matriz[i][j];
                            for (x = 0; x < 5; x++)
                            {
                                if (aux < matriz[x][j])
                                {
                                    aux = matriz[x][j];
                                }
                            }
                            if (matriz[i][j] == aux)
                            {
                                flagfil = 1;
                            }
                            
                            aux = matriz[i][j];
                            for (y = 0; y < 5; y++)
                            {
                                if (aux < matriz[i][y])
                                {
                                    aux = matriz[i][y];
                                }
                            }
                            if (matriz[i][j] == aux)
                            {
                                flagcol = 1;
                            }
                            if ((flagfil == 1) && (flagcol == 1))
                            {
                                textcolor(9);
                                cprintf("%03d", matriz[i][j]);
                                cont++;
                                
                                textcolor(15);
                                gotoxy(1, 16+cont);
                                cprintf("[%d][%d]", i+1, j+1);
                            }else
                            {
                                textcolor(15);
                                cprintf("%03d", matriz[i][j]);
                            }
                            cprintf("  ");
                        }
                    }
                    break;
                }
            }
        printf("\n\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");
    } while (getch() != 27);
    return 0;
}