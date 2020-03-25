#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
    do
    {
        int i=0,j=0,colu=1,fila=1,x=0,y=0;
        char selec, entrada;
            for (i=0;i<8;i++)//Dibuja tablero vasio
            {
                for (j=0;j<8;j++)
                {
                    if (((i+j)%2)==0)
                    {
                        textbackground(0);//blanco
                    }else
                    {
                        textbackground(15);//negro
                    }
                    gotoxy(i*5+1,j*3+1);
                    cprintf("     ");
                    gotoxy(i*5+1,j*3+2);
                    cprintf("     ");
                    gotoxy(i*5+1,j*3+3);
                    cprintf("     ");
                }
            }

            gotoxy(56, 2);
            textcolor(9);
            cprintf("FUNCIONES");
            gotoxy(45, 6);
            cprintf("Seleccione la pieza:");
            gotoxy(50, 8);
            cprintf("Presione [A] para el Alfil");
            gotoxy(50, 10);
            cprintf("Presione [C] para el Caballo");
            gotoxy(50, 12);
            cprintf("Presione [T] para la Torre");
                
            gotoxy(3,2);
            do //do de movimiento
            {
                fflush(stdin);
                entrada=getch();
                for (i=0;i<8;i++)
                {
                    for (j=0;j<8;j++)
                    {
                        if (((i+j)%2)==0)
                        {
                            textbackground(0);//blanco
                        }else
                        {
                            textbackground(15);//negro
                        }
                        gotoxy(i*5+1,j*3+1);
                        cprintf("     ");
                        gotoxy(i*5+1,j*3+2);
                        cprintf("     ");
                        gotoxy(i*5+1,j*3+3);
                        cprintf("     ");
                    }
                }

                gotoxy(x, y);
                if (entrada == 0)
                {
                    entrada=getch();
                    if (entrada==72)
                    {
                        //FLECHITA ARRIBA
                        fila--;
                        if (fila==0)
                        {
                            fila=8;
                        }
                    }
                    if (entrada==80)
                    {
                        //FLECHITA ABAJO
                        fila++;
                        if (fila==9)
                        {
                            fila=1;
                        }
                    }
                    if (entrada==77)
                    {
                        //FLECHITA DERECHA
                        colu++;
                        if (colu==9)
                        {
                            colu=1;
                        }
                    }
                    if (entrada==75)
                    {
                        //FLECHITA IZUIERDA
                        colu--;
                        if (colu==0)
                        {
                            colu=8;
                        }
                    }
                }else
                {
                    switch (entrada)
                    {
                    case 65:
                    case 97:
                        //gotoxy(0,0);
                        for (i=0;i<8;i++)
                        {
                            for (j=0;j<8;j++)
                            {
                                if (((i+j)%2)==0)
                                {
                                    textcolor(15);
                                    textbackground(0);//blanco
                                }else
                                {
                                    textcolor(0);
                                    textbackground(15);//negro
                                }
                                if (abs(x-i) == abs(y-j))
                                {
                                    if ((x==i) && (y==j))
                                    {
                                        gotoxy(i*5+1,j*3+1);
                                        cprintf("     ");
                                        gotoxy(i*5+1,j*3+2);
                                        cprintf("  A  ");
                                        gotoxy(i*5+1,j*3+3);
                                        cprintf("     ");
                                    }else
                                    {
                                    gotoxy(i*5+1,j*3+1);
                                    cprintf("     ");
                                    gotoxy(i*5+1,j*3+2);
                                    cprintf("  X  ");
                                    gotoxy(i*5+1,j*3+3);
                                    cprintf("     ");
                                    }
                                }else
                                {
                                    gotoxy(i*5+1,j*3+1);
                                    cprintf("     ");
                                    gotoxy(i*5+1,j*3+2);
                                    cprintf("     ");
                                    gotoxy(i*5+1,j*3+3);
                                    cprintf("     ");
                                }
                            }
                        }
                        break;
                    case 67:
                    case 99:
                        textcolor(9);
                        gotoxy(x,y);
                        cprintf("C");
                        break;
                    case 84:
                    case 116:
                        textcolor(9);
                        gotoxy(x,y);
                        cprintf("T");
                        break;
                    }
                }
                
                x=colu*5-2;
                y=fila*3-1;
                gotoxy(x,y);
            }while (entrada!=27);
            

        printf("\n\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");
    } while (getch()!=27);
    return 0;
}