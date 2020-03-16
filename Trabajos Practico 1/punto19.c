#include<stdio.h>
#include"conio.h"

int main()
{
    do
    {
        unsigned char a;
            
        do
        {
            printf("\nIngreso: ");
            scanf("%d%*c", &a);
        } while (a < 33);

        for (unsigned char i = 0; i < 6; i++)
        {
            for (unsigned char j = 0; j < i+1 ; j++)
            {
                printf("%c\t", a);
                a++;
            }
            printf("\n");
        }
    } while (getch() != 27);
    return 0;
}