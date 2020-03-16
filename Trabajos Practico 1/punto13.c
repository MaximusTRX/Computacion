#include<stdlib.h>
#include"conio.h"

int main()
{
    do
    {
        unsigned char num;
        printf("\n====================================================================\n"); 
        printf("\nIngrese un numero: ");
        scanf("%d%*c", &num);
        if (num & 0x01)
        {
            printf("%d es un numero impar\n", num);
        }else
        {
            printf("\n%d es un numero par\n", num);
        }
        printf("\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");
        
    } while (getch() != 27);
    
    return 0;
}
