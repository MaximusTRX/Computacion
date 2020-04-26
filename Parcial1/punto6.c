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
        int entrada, div, aux;
        printf("\nIngrese el numero: \n");
        scanf("%i", &entrada);

        if (abs(entrada) >= 10000)
        {
            div = 1000;
        }else if (abs(entrada) >= 1000)
        {
            div = 100;
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
        printf("\n\n");
        if (entrada < 0)
        {
            printf(" MENOS");
        }

        do
        {
            aux = (abs(entrada)/div);
            
            switch (aux)
            {
            case 10:
                printf("DIEZ ");
                break;
            case 11:
                printf("ONCE ");
                break;
            case 12:
                printf("DOCE ");
                break;
            case 13:
                printf("TRECE ");
                break;
            case 14:
                printf("CATORCE ");
                break;
            case 15:
                printf("QUINCE ");
                break;
            case 16:
                printf("DIECISEIS ");
                break;
            case 17:
                printf("DIECISIETE ");
                break;
            case 18:
                printf("DIECIOCHO ");
                break;
            case 19:
                printf("DIECINUEVE ");
                break;
            case 20:
                printf("VEINTE ");
                break;
            case 30:
                printf("TREINTA ");
                break;
            case 40:
                printf("CUARENTA ");
                break;
            case 50:
                printf("CINCUENTA ");
                break;
            case 60:
                printf("SESENTA ");
                break;
            case 70:
                printf("SETENTA ");
                break;
            case 80:
                printf("OCHENTA ");
                break;
            case 90:
                printf("NOVENTA ");
                break;
            default:
                switch (aux/10)
                {
                case 2:
                    printf("VEINTI ");
                    break;
                case 3:
                    printf("TREINTA Y ");
                break;
                case 4:
                    printf("CUARENTA Y ");
                    break;
                case 5:
                    printf("CINCUENTA Y ");
                    break;
                case 6:
                    printf("SESENTA Y ");
                    break;
                case 7:
                    printf("SETENTA Y ");
                    break;
                case 8:
                    printf("OCHENTA Y ");
                    break;
                case 9:
                    printf("NOVENTA Y ");
                    break;
                }
                switch (aux%10)
                {
                    case 1:
                    printf("UNO ");
                        break;
                    case 2:
                        printf("DOS ");
                        break;
                    case 3:
                        printf("TRES "); 
                        break;
                    case 4:
                        printf("CUATRO ");
                        break;
                    case 5:
                        printf("CINCO ");
                        break;
                    case 6:
                        printf("SEIS ");
                        break;
                    case 7:
                        printf("SIETE ");
                        break;
                    case 8:
                        printf("OCHO ");
                        break;
                    case 9:
                        printf("NUEVE ");
                        break;
                    }
                break;//Switch grande
            }
            if (div == 1000)
            {
                printf("MIL ");
            }
            
            entrada %= div;
            div /= 10;
        }while (div != 0);
        
        printf("\n\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");
    } while (getch() != 27);
    return 0;
}