#include<stdio.h>
#include<stdlib.h>
#include"conio.h"

int main()
{
    do
    {
        unsigned char f, c;
        printf("\nIngrese la fila del Alfil: ");
        scanf("%d%*c", &f);
        printf("\nIngrese la columna del Alfil: ");
        scanf("%d%*c", &c);
        printf("\n");
        for (unsigned char i = 1; i < 9; i++)
        {
            for (unsigned char j = 1; j < 9; j++)
            {
                if (abs(i-f) == abs(j-c))
                {
                    if ((i ==(f)) && (j == (c)))
                    {
                      printf(" A ");  
                    }else
                    {
                        printf(" · ");
                    }
                }else
                {
                    printf(" # ");
                }
            }
            printf("\n");
        }
    } while (getch() != 27);
    return 0;
}