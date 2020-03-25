#include<stdio.h>
#include<conio.h>

int main()
{
    do
    {
        int i=0,j=0,entrada=0,colu=0,fila=0,x=0,y=0;

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

            printf("\n=>Usando las flechitas posicione donde quiere colocar la pieza. Al finalizar presione ENTER.\n");

            gotoxy(3,2);
            fila=1;
            colu=1;

            do //do de movimiento
            {
                gotoxy(0, 50);
                printf("//");

                entrada=getch();
                if (entrada == 0)
                {
                    entrada=getch();a
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
                }
                x=colu*5-2;
                y=fila*3-1;
                gotoxy(x,y);
            cprintf("%c", getch());
            }while (entrada!=27);
            

        printf("\n\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");
    } while (getch()!=27);
    return 0;
}