#include<stdio.h>
#include<conio.h>

int main()
{
    do
    {

        float codigo, unitario, cantidad, total;

        printf("\n\nIngrese el codigo del producto: ");
        scanf("%f",&codigo);
        printf("\nIngrese el precio unitario: ");
        scanf("%f",&unitario);
        printf("\nIngrese la cantidad comprada: ");
        scanf("%f",&cantidad);

        total = (cantidad * unitario);
        if(cantidad >= 100)
        {
            printf("\nEl precio total es: %.2f", total*0.6);
        }else
        {
            if(cantidad >= 25)
            {
                printf("\nEl precio total es: %.2f", total*0.8);
            }else
            {
                if(cantidad >= 10)
                {
                    printf("\nEl precio total es %.2f", total*0.9);
                }else
                {
                    printf("\nEl precio total es %.2f", total);
                }
            }
            
        }
    } while (getch() != 27);
    
    return 0;
}
