/*Realizar un programa que lea un número entero y muestre sus dígitos en palabras. Si el
número es negativo debería empezar con la palabra “menos”. El programa debe aceptar enteros de
hasta 5 dígitos.*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
    do
    {
        int entrada, div, var1;
        
        do{
            printf("\nIngrese el numero: \n");
            scanf("%i", &entrada);
            printf("\n\n");
        }while (entrada > 99999);

        if (entrada < 0)
        {
            printf(" MENOS");
        }
        
            if (abs(entrada) >= 10000)
            {
                div =10000;
            }else if (abs(entrada) >= 1000)
            {
                div = 1000;
            }else if (abs(entrada) >= 100)
            {
                div = 100;
            }else if (abs(entrada) >= 10)
            {
                div = 10;
            }else
            {
                div = 1;
            }
        do
        {
            var1 = (abs(entrada)/div);
            if (var1 >= 1000)
            {
                if (var1 < 10)
                {
                    switch (var1)
                    {
                    case 2:
                        printf(" DOS");
                        break;
                    case 3:
                        printf(" TRES"); 
                        break;
                    case 4:
                        printf(" CUATRO");
                        break;
                    case 5:
                        printf(" CINCO");
                        break;
                    case 6:
                        printf(" SEIS");
                        break;
                    case 7:
                        printf(" SIETE");
                        break;
                    case 8:
                        printf(" OCHO");
                        break;
                    case 9:
                        printf(" NUEVE");
                        break;
                    }
                }else if (var1 < 20)
                {
                    switch (var1)
                    {
                    case 10:
                        printf(" DIEZ");
                        break;
                    case 11:
                        printf(" ONCE");
                        break;
                    case 12:
                        printf(" DOCE");
                    break;
                    case 13:
                        printf(" TRECE");
                        break;
                    case 14:
                        printf(" CATORCE");
                        break;
                    case 15:
                        printf(" QUINCE");
                        break;
                    case 16:
                        printf(" DIECISEIS");
                        break;
                    case 17:
                        printf(" DIECISIETE");
                        break;
                    case 18:
                        printf(" DIECIOCHO");
                        break;
                    case 19:
                        printf(" DIECINUEVE");
                        break;;
                    }
                }else if (var1 < 30)
                {
                    switch (var1)
                    {
                    case 20:
                        printf(" VEINTE");
                        break;
                    default:
                        printf(" VEINTI");
                        switch (var1/10)
                        {
                        case 1:
                            printf(" UNO");
                            break;
                        case 2:
                            printf(" DOS");
                            break;
                        case 3:
                            printf(" TRES"); 
                            break;
                        case 4:
                            printf(" CUATRO");
                            break;
                        case 5:
                            printf(" CINCO");
                            break;
                        case 6:
                            printf(" SEIS");
                            break;
                        case 7:
                            printf(" SIETE");
                            break;
                        case 8:
                            printf(" OCHO");
                            break;
                        case 9:
                            printf(" NUEVE");
                            break;
                        }
                            break;
                    }
                }
                printf(" MIL");
            }
            
            

            
            entrada %= div;
            div /= 10;
        }while (div != 0);
        
        printf("\n\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");
    } while (getch() != 27);
    return 0;
}