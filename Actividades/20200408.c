#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main()
{
    randomize();
    do
    {
        unsigned char i, j, x, y, delator, w = 10;
        char entrada, flag = 0;
        int matriz[10][10] = {0}, aleat, aux, selec, fselec, cselec;
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
            gotoxy(60, w+5);
            cprintf("| Opt [F3] | Carga la matriz con valores que se incrementan|");
            gotoxy(60, w+6);
            cprintf(" -----------------------------------------------------------");
            fflush(stdin);
            entrada = getch();

            if (entrada == 0)
            {
                
                entrada = getch();
                switch (entrada)
                {
                case 59://F1
                    delator++;
                    for (i = 0; i < 10; i++)
                    {
                        for (j = 0; j < 10; j++)
                        {
                            matriz[i][j] = random(1000);
                        }
                    }
                    break;
                
                case 60://F2
                    delator++;
                    for (i = 0; i < 10; i++)
                    {
                        for (j = 0; j < 10; j++)
                        {
                            do
                            {
                                flag = 0;
                                aleat = random(500);
                                if ((aleat > 100) && (aleat < 500))
                                {
                                    for (x = 0; x < i; x++)
                                    {
                                        for (y = 0; y < j; y++)
                                        {
                                            if (matriz[x][y] == aleat)
                                            {
                                                flag++;
                                            }
                                        }
                                    }
                                }else
                                {
                                    flag++;
                                }
                                
                            } while (flag != 0);
                            matriz[i][j] = aleat;
                        }
                    }
                    break;
                
                case 61://F3
                    clrscr();
                    delator = 0;
                    do
                    {
                        gotoxy(1, 14);
                        printf("Ingrese la fila: ");
                        scanf("%i", &fselec);
                    } while ((fselec < 1) || (fselec > 10));
                    fselec--;
                    do
                    {
                        gotoxy(1, 16);
                        printf("Ingrese la columna: ");
                        scanf("%i", &cselec);
                    } while ((cselec < 1) || (cselec > 10));
                    cselec--;

                    gotoxy(1, 18);
                    printf("Ingrese el valor: ");
                    scanf("%i", &selec);

                    for (i = 0; i < 10; i++)
                    {
                        for (j = 0; j < 10; j++)
                        {
                            {
                                if (abs(fselec - i) >= abs(cselec - j))
                                {
                                    matriz[i][j] = selec + abs(fselec - i);
                                }
                                else
                                {
                                    matriz[i][j] = selec + abs(cselec - j);
                                }
                            }
                        }
                    }
                    break;
                }
            }
            textcolor(9);
            gotoxy(1,1);
            cprintf("MATRIZ ORIGINAL");
            gotoxy(1, 3);
            textcolor(15);
            for (i = 0; i < 10; i++)
            {
                for (j = 0; j < 10; j++)
                {
                    cprintf("%3i  ",matriz[i][j]);
                }
                gotoxy(1, 3+i);
            }
            
            if (delator != 0)//ordenar o no la matriz
            {
                for(i = 0; i < 10; i++)
                {
                    for(j = 0; j < 10; j++)
                    {
                        for(x = 0; x < 10;x++)
                        {
                            for(y = 0; y < 10; y++)
                            {
                                if(matriz[i][j] < matriz[x][y])
                                {
                                    aux = matriz[i][j];
                                    matriz[i][j] = matriz[x][y];
                                    matriz[x][y] = aux;
                                }
                            }
                        }
                    }
                }
                textcolor(9);
                gotoxy(1,14);
                cprintf("MATRIZ ORDENADA DE MENOR A MAYOR");
                gotoxy(1,16);
                textcolor(15);
                for (i = 0; i < 10; i++)
                {
                    for (j = 0; j < 10; j++)
                    {
                        cprintf("%3i  ",matriz[i][j]);
                    }
                    gotoxy(1, 16+i);
                }
            }
        } while (entrada != 27);
        printf("\n\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");
    } while (getch() != 27);
    return 0;
}