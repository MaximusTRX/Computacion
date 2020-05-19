#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<dos.h>
#include<string.h>
#include <stdlib.h>

int main()
{ 
    static char Entrada[1024];
    static float Stack[10];
    int posIn = 0;
    int posSt = 0;
    unsigned char key, x = 1;
    int cont = 0;
    char *ptr;

    do
    {
        if(kbhit())//Input line
        {
            key = getch();

            if (((key > 38) && (key < 44)) || ((key > 44) && (key < 58)) || (key == 101))//Compruebo que la tecla sea una imprimible
            {

                //delay(1, (10*1000));//Restart last time key hit
                
                clrscr();

                Entrada[posIn] = key;
                
                if (posIn >= 10)
                {
                    cont = posIn - 9;
                }else
                {
                    cont = 0;
                }
                x = 1;
                for (cont ; cont < posIn+1; cont++)
                {
                    //print_char(x, 43, Entrada[cont]);
                    x+= 8;
                }
                posIn++;

            }else if (key == 27)
            {
                posIn = 0;
                clrscr();
                return;
            }else if (key == 13)
            {
                char k = 0;

                for (int i = 0; i < posIn; i++)// Compruevo caracteres y los separo
                {
                    if ((Entrada[i] > 47) && (Entrada[i] < 58) || (Entrada[i] == 46))
                    {
                        k++;
                    }else
                    {
                        break;
                    }
                }

                float convert[k];
                
                for (int i = 0; i < k; i++)
                {
                    convert[i] = Entrada[i];
                }

                gotoxy(1, 20);
                textcolor(15);
                cprintf("convert: %s",  Entrada);

                Stack[posSt] = strtod(Entrada, &ptr);
                posSt++;
                posIn = 0;
                
                gotoxy(1, 34);
                cprintf("%f",  Stack[0]);

                char out[1024];
                
                // gcvt(Stack[0], 6, out);
                // gotoxy(1, 34);
                // cprintf("%s", out);
            }
        }
    } while (getch() != 27);

    return 0;
}