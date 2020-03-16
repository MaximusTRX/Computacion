#include<stdio.h>
#include<conio.h>

int main()
{
    do
    {
        printf("\n\nQue mes quiere saber cuatos dias tiene");
        int anio, mes;
        printf("\nIngrese el anio: ");
        scanf("%d",&anio);
        printf("\nIngrese el mes: ");
        scanf("%d",&mes);

        switch (mes)
        {
        case 1:
            printf("\nEl mes de Enero tiene 31 dias\n");
            break;
        case 2:
        //anio bisiensto
            if ((anio%100) == 0)
            {
                if((anio%400) == 0)
                {
                    printf("\nEl mes de Febrero tiene 29 dias\n");                    
                }else
                {            
                    if((anio%4 == 0))
                    {
                        printf("\nEl mes de Febrero tiene 29 dias\n");
                    }
                }
            }else
            {
                printf("\nEl mes de Febrero tiene 28 dias\n");
            }
            break;
        case 3:
            printf("\nEl mes de Enero tiene 31 dias\n");
            break;
        case 4:
            printf("\nEl mes de Enero tiene 30 dias\n");
            break;
        case 5:
            printf("\nEl mes de Enero tiene 31 dias\n");
            break;
        case 6:
            printf("\nEl mes de Enero tiene 3 dias\n");
            break;
        case 7:
            printf("\nEl mes de Enero tiene 31 dias\n");
            break;
        case 8:
            printf("\nEl mes de Enero tiene 31 dias\n");
            break;
        case 9:
            printf("\nEl mes de Enero tiene 30 dias\n");
            break;
        case 10:
            printf("\nEl mes de Enero tiene 31 dias\n");
            break;
        case 11:
            printf("\nEl mes de Enero tiene 30 dias\n");
            break;
        case 12:
            printf("\nEl mes de Enero tiene 31 dias\n");
            break;
        }
        printf("\n\nPresione ESCAPE si desea terminar la ejecucion");
    } while (getch() != 27);
    
    return 0;
}
