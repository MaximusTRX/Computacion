#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main()
{
    randomize();
    unsigned char w = 10;
    char entrada, i, j, k, x, y, flag, cant, repetidos;
    char matriz[10][10][3];
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
            cprintf("| Opt [F2] | Se resalta la combinacion de caracteres FDA    |");
            gotoxy(60, w+4);
            cprintf(" -----------------------------------------------------------");
            gotoxy(60, w+5);
            cprintf("| Opt [F3] | Se encuentran los valores que se repiten       |");
            gotoxy(60, w+6);
            cprintf(" -----------------------------------------------------------");
            fflush(stdin);
            entrada = getch();

                if ((entrada == 0) || (entrada == 224))
                {
                    
                    entrada = getch();
                    switch (entrada)
                    {
                    case 59://F1

                        for (i = 0; i < 10; i++)
                        {
                            for (j = 0; j < 10; j++)
                            {
                                matriz[i][j][0] = random(6) + 65;
                                matriz[i][j][1] = random(6) + 65;
                                matriz[i][j][2] = random(6) + 65;
                            }
                        }

                        textcolor(9);
                        gotoxy(1,1);
                        cprintf("MATRIZ ORIGINAL");
                        textcolor(15);
                        for (i = 0; i < 10; i++)
                        {
                            gotoxy(1, 3+i);
                            for (j = 0; j < 10; j++)
                            {
                                cprintf("%c", matriz[i][j][0]);
                                cprintf("%c", matriz[i][j][1]);
                                cprintf("%c  ", matriz[i][j][2]);
                            }
                        }
                        break;
                    case 60://F2
                        textcolor(9);
                        gotoxy(1,14);
                        cprintf("MATRIZ MOSTRANDO COMBINACION DE CARACTERES");
                        textcolor(15);
                        for (i = 0; i < 10; i++)
                        {
                            gotoxy(1, 16+i);
                            for (j = 0; j < 10; j++)
                            {
                                for ( k = 0; k < 3; k++)
                                {
                                    switch (matriz[i][j][k])
                                    {
                                    case 70://Letra F
                                        if ((k == 0) && (matriz[i][j][1] == 68) && (matriz[i][j][2] == 65))
                                        {
                                            textcolor(9);
                                            cprintf("%c", matriz[i][j][k]);
                                        }else if ((k == 1) && (matriz[i][j][2] == 68) && (matriz[i][j+1][0] == 65))
                                        {
                                            textcolor(9);
                                            cprintf("%c", matriz[i][j][k]);
                                        }else if ((k == 2) && (matriz[i][j+1][0] == 68) && (matriz[i][j+1][1] == 65))
                                        {
                                            textcolor(9);
                                            cprintf("%c", matriz[i][j][k]);
                                        }else if ((i == 9) && (j == 9) && (k == 1) && (matriz[i][j][2] == 68) && (matriz[0][0][0] == 65))
                                        {
                                            textcolor(9);
                                            cprintf("%c", matriz[i][j][k]);
                                        }else if ((i == 9) && (j == 9) && (k == 2) && (matriz[0][0][0] == 68) && (matriz[0][0][1] == 65))
                                        {
                                            textcolor(9);
                                            cprintf("%c", matriz[i][j][k]);
                                        }else
                                        {
                                            textcolor(15);
                                            cprintf("%c", matriz[i][j][k]);
                                        }
                                        break;
                                    
                                    case 68://Letra D
                                        if ((i == 0) && (j == 0) && (k == 0) && (matriz[0][0][1] == 65) && (matriz[9][9][2] == 70))
                                        {
                                            textcolor(9);
                                            cprintf("%c", matriz[i][j][k]);
                                        }else if ((i == 9) && (j == 9) && (k == 2) && (matriz[0][0][0] == 65) && (matriz[9][9][1] == 70))
                                        {
                                            textcolor(9);
                                            cprintf("%c", matriz[i][j][k]);
                                        } else if ((k == 1) && (matriz[i][j][0] == 70) && (matriz[i][j][2] == 65))
                                        {
                                            textcolor(9);
                                            cprintf("%c", matriz[i][j][k]);
                                        }else if ((k == 2) && (matriz[i][j][1] == 70) && (matriz[i][j+1][0] == 65))
                                        {
                                            textcolor(9);
                                            cprintf("%c", matriz[i][j][k]);
                                        }else if ((k == 0) && (matriz[i][j-1][2] == 70) && (matriz[i][j][1] == 65))
                                        {
                                            textcolor(9);
                                            cprintf("%c", matriz[i][j][k]);
                                        }else
                                        {
                                            textcolor(15);
                                            cprintf("%c", matriz[i][j][k]);
                                        }
                                        break;

                                    case 65://Letra A
                                        if ((i == 0) && (j == 0) && (k == 0) && (matriz[9][9][2] == 68) && (matriz[9][9][1] == 70))
                                        {
                                            textcolor(9);
                                            cprintf("%c", matriz[i][j][k]);
                                        }else if ((i == 0) && (j == 0) && (k == 1) && (matriz[0][0][0] == 68) && (matriz[9][9][2] == 70))
                                        {
                                            textcolor(9);
                                            cprintf("%c", matriz[i][j][k]);
                                        }else if ((k == 2) && (matriz[i][j][0] == 70) && (matriz[i][j][1] == 68))
                                        {
                                            textcolor(9);
                                            cprintf("%c", matriz[i][j][k]);
                                        }else if ((k == 0) && (matriz[i][j-1][1] == 70) && (matriz[i][j-1][2] == 68))
                                        {
                                            textcolor(9);
                                            cprintf("%c", matriz[i][j][k]);
                                        }else if ((k == 1) && (matriz[i][j][0] == 68) && (matriz[i][j-1][2] == 70))
                                        {
                                            textcolor(9);
                                            cprintf("%c", matriz[i][j][k]);
                                        }else
                                        {
                                            textcolor(15);
                                            cprintf("%c", matriz[i][j][k]);
                                        }
                                        break;
                                        
                                    default:
                                        textcolor(15);
                                        cprintf("%c", matriz[i][j][k]);
                                        break;
                                    }
                                }
                                cprintf("  ");
                            }
                        }
                        break;
                    
                    case 61://F3
                        gotoxy(1, 26);
                        for (i = 0; i < 10; i++)
                        {
                            for ( j = 0; j < 10; j++)
                            {
                                flag = 0;
                                for (x = 0; x < 10; x++)
                                {
                                    for (y = 0; y < 10; y++)
                                    {
                                        if ((matriz[i][j][0] == matriz[x][y][0]) && (i != x) && (j != y) && (matriz[x][y][0] < 71))
                                        {
                                            if (matriz[i][j][1] == matriz[x][y][1])
                                            {
                                                if (matriz[i][j][2] == matriz[x][y][2])
                                                {
                                                    if (flag == 0)
                                                    {
                                                        printf("\n------------------------------------------------------------");
                                                        printf("\nLa combinacion %c%c%c se repite en las posiciones \n\n", matriz[i][j][0], matriz[i][j][1], matriz[i][j][2]);
                                                        printf("|[%02d] [%02d]|", i+1, j+1);
                                                    }
                                                    flag++;
                                                    printf("|[%02d] [%02d]|", x+1, y+1);

                                                    matriz[x][y][0] += 32;
                                                    matriz[x][y][1] += 32;
                                                    matriz[x][y][2] += 32;
                                                }
                                            }
                                        }
                                    }
                                }
                                if (flag != 0)
                                {
                                    printf("\n\nY se repitio: %d veces", flag+1);
                                    printf("\n------------------------------------------------------------");
                                }
                            }
                        }
                        for (i = 0; i < 10; i++)
                        {
                            for (j = 0; j < 10; j++)
                            {
                                if (matriz[i][j][0] > 71)
                                {
                                    matriz[i][j][0] -= 32;
                                    matriz[i][j][1] -= 32;
                                    matriz[i][j][2] -= 32;
                                }
                            }
                        }
                        break;
                    }
                }
        }while (entrada != 27);
        
        printf("\n\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");
    } while (getch() != 27);
    return 0;
}