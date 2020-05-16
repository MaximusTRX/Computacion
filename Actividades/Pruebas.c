#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<dos.h>
#include<string.h>
#include <stdlib.h>

int main () { 
    do
    {
        char Entrada[1024];
        char *ptr;
        float Stack[10];
        int posIn = 0;
        int posSt = 0;
        char key;

        while (1)
        {
            if (kbhit())
            {
                key = getch();
                
                if (((key > 38) && (key < 46)) || ((key > 46) && (key < 58)) || (key == 101))//Compruebo que la tecla sea una imprimible
                {
                    Entrada[posIn] = key;
                    posIn++;
                }else if (key == 13)
                {
                    char k = 0;

                    for (int i = 0; i < posIn; i++)
                    {
                        if ((Entrada[i] > 46) && (Entrada[i] < 58))
                        {
                            float[k] 
                        }
                        
                    }
                    

                    Stack[posSt] = strtod(Entrada, &ptr);
                    posSt++;

                }else if (key == 27)
                {
                    for (int i = 0; i < posSt; i++)
                    {
                        printf("\n%f", Stack[i]);
                    }
                }
            }
        }
    } while (getch() != 27);
    return(0);
}