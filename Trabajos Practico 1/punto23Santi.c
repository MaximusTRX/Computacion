/*============================================================================
Filename.c 

(c) 2019
Autor: Prados Santiago Andr�s.

Fecha: 

Decripci�n del Programa.

==============================================================================*/
#include <stdio.h>
#include "conio.h"
#include <stdlib.h>
int main()
{
    char letra;
    int cA,cE,cI,cO,cU;
    int palabras=0;
	do{
        printf("\n ==================================================");
		printf("\n | ingrese un trexto, al terminar precione escape :");
        printf("\n ==================================================\n");
        while((letra=getche())!=27){

            if(letra!= ' ' || letra!='\t' || '\n'){

                switch (letra){

                    case 'A':
                    case 'a':
                      cA=1;
                      break;
                
                    case 'E':
                    case 'e' :
                        cE=1;
                        break;

                    case 'I':
                    case 'i': 
                        cI=1;
                        break;

                    case 'O':
                    case 'o':
                        cO=1;
                        break;

                    case 'U':
                    case 'u':
                        cU=1;
                        break;

                    default:
                        break;
                }
                if((cA+cE+cI+cO+cU)>4){
                    palabras++;
                }
            }else{
                cA=0,cE=0,cI=0,cO=0,cU=0;
                palabras=0;
            }
        }

        printf("\n ======================================================");
		printf("\n | enel texto hay : %d palabras con mas de 4 vocales |" ,palabras);
        printf("\n ======================================================");
		
	}while(getch()!= 27);

	return 0;	
}