#include<stdio.h>
#include<conio.h>
int main()
{
    unsigned char esc = 99;
    do
    {
        
        printf("\nA continuacion ingrese 3 numeros:\n");
        int a = 0, b = 0, c = 0;
        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &c);
        if (a < b && a < c)
        {
            printf("El menor es %d", a);
        }else
        {
            if(b < c)
            {
                printf("El menor es %d", b);
            }else
            {
                printf("El menor es %d", c);
            }
        }
        esc = getch();
    } while (esc != 27);
    return 0;
}
