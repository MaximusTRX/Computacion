#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() 
{ 
    do{
        char *ptr;
        float X[10];
        char buf[1024]; 
        char Entrada[1024];
        int posIn = 0;
        do
        {
            Entrada[posIn] = getche();
            posIn++;
        } while (Entrada[posIn-1] != 13);
        
        posIn-= 1;
        for (int i = 1; i < posIn; i++)
        {
            Entrada[i-1] = Entrada[i];
        }
        
        posIn-=2;
        for (int i = 0; i < posIn; i++)
        {
            printf("%c  ", Entrada[i]);
        }
        

        /*
        X[0] = strtod(Entrada, &ptr);
        
        gotoxy(1, 10);
        cprintf("\n %f", X[0]);

        sprintf(buf,"%10g" , X[0]);

        printf("buffer is:\n");
        for (int i = 10; i > 0; i--)
        {
            if (buf[i] != '/0')
            {
                printf("%c ", buf[i]);
            }
        }*/
        

    }while(getch() != 27);
    return 0; 
} 