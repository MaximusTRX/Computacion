#include<stdio.h>
#include<conio.h>

int main()
{
    do
    {
        unsigned char opt;

        opt = getch();
        if(opt == 0)
        {
            printf("%d\n", opt);
            opt = getch();
        }
        printf("%d", opt);


        printf("\n\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");
    } while (getch() != 27);
    return 0;
}