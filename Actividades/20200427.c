#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main()
{
    randomize();
    unsigned char w = 10, flagfil, flagcol, cont;
    char entrada;
    int matriz[5][5] = {0};
    int aux, i, j, x, y;
    do
    {
        do{
            textcolor(9);
            gotoxy(60, w);
            cprintf(" -----------------------------------------------------------");
            gotoxy(60, w+1);
            cprintf("| Opt [F1] | Se cargar la matriz con valores aleatorios     |");
            gotoxy(60, w+2);
            cprintf(" -----------------------------------------------------------");
            gotoxy(60, w+3);
            cprintf("| Opt [F2] | Encuentra valores mayor fila y menor columna   |");
            gotoxy(60, w+4);
            cprintf(" -----------------------------------------------------------");
            fflush(stdin);
            entrada = getch();

            if ((entrada == 0) || (entrada == 224))
            {
                entrada = getch();
                switch (entrada)
                {
                case 59://F1
                    clrscr();
                    for (i = 0; i < 5; i++)
                    {
                        for (j = 0; j < 5; j++)
                        {
                            matriz[i][j] = random(1000);
                        }
                    }
                    textcolor(9);
                    gotoxy(3,1);
                    cprintf("MATRIZ ORIGINAL");
                    gotoxy(1, 3);
                    textcolor(15);
                    for (i = 0; i < 5; i++)
                    {
                        gotoxy(1, 3+i);
                        for (j = 0; j < 5; j++)
                        {
                            cprintf("%3i  ", matriz[i][j]);
                        }
                    }
                    break;
                case 60://F2
                    textcolor(9);
                    gotoxy(3, 10);
                    cprintf("CASOS ENCONTRADOS");
                    textcolor(15);
                    cont = 0;
                    for (i = 0; i < 5; i++)
                    {
                        for (j = 0; j < 5; j++)
                        {
                            gotoxy((1+5*j), 12+i);
                            flagfil = 0;
                            flagcol = 0;
                            aux = matriz[i][j];
                            for (x = 0; x < 5; x++)
                            {
                                if (aux > matriz[x][j])
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
                                gotoxy(1, 17+cont);
                                cprintf("Caso encontrado en la posicion: [%d][%d]", i+1, j+1);
                            }else
                            {
                                textcolor(15);
                                cprintf("%03d", matriz[i][j]);
                            }
                        }
                    }
                    break;
                }
            }
        } while (entrada != 27);
        printf("\n\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");
    } while (getch() != 27);
    return 0;
}