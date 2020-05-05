#include <stdio.h>
#include <conio.h>
#include<ctype.h>
void Suma(void);
void Resta(void);
void Producto(void);
void Divicion(void);
void Conversion(void);

//typedef int (*PtrFun)(int, int); //Puntero entero a una funcion con dos argumentos enteros

typedef void (*PtrFunV)(void);  

typedef struct{
    char Name[24];
    PtrFunV DoAction; 
}_sMenu;


const _sMenu Menu[] = {{"[1] = SUMA", Suma},
                       {"[2] = RESTA", Resta},
                       {"[3] = PRODUCTO", Producto},
                       {"[4] = Divicion", Divicion},
                       {"[5] = Conversion", Conversion},
                       {"", NULL} 
                      };
                        //TODO, divicion, para a numero romano 0-2000

void Suma(void){
    clrscr();
    int a, b;
    printf("\nSUMA\n");
    printf("Ingrese valores a operar:\n");
    printf("\nPrimer valor: ");
    scanf("%i",&a);
    printf("\nSegundo valor: ");
    scanf("%i",&b);
    printf("\nEl resultado es: %i", a+b);
}

void Resta(void){
    clrscr();
    int a, b;
    printf("\nRESTA\n");
    printf("Ingrese valores a operar:\n");
    printf("\nPrimer valor: ");
    scanf("%i",&a);
    printf("\nSegundo valor: ");
    scanf("%i",&b);
    printf("\nEl resultado es: %i", a-b);
}

void Producto(void){
    clrscr();
    int a, b;
    printf("\nPRODUCTO\n");
    printf("Ingrese valores a operar:\n");
    printf("\nPrimer valor: ");
    scanf("%i",&a);
    printf("\nSegundo valor: ");
    scanf("%i",&b);
    printf("\nEl resultado es: %i", a*b);
}

void Divicion(void){
    clrscr();
    int a, b;
    printf("\nDIVICION\n");
    printf("Ingrese valores a operar:\n");
    printf("\nPrimer valor: ");
    scanf("%i",&a);
    printf("\nSegundo valor: ");
    scanf("%i",&b);
    printf("\nEl resultado es: %i", a/b);
}

void Conversion(void){
    clrscr();
    int a, b;
    printf("\nConversion a Numero Romano\n");
    printf("Ingrese valor a operar:\n");
    printf("\nValor: ");
    scanf("%i",&a);
}

int main()
{
    short opt;
    int contMenuItems;
    
    while(1){
        clrscr();    
        contMenuItems=0;    
        while(Menu[contMenuItems].DoAction != NULL){
            printf("%s\n", Menu[contMenuItems].Name);
            contMenuItems++;
        }
        printf("[ESC]: SALE");       

        do{
            opt = getch();
        }while ((opt < '0') || (opt > '5'));
        
        if(opt == 0)
            opt = getch() + 1000;
         
        if(opt == 27)
            break;

        if(isdigit(opt)){//TODO: Controlar que opt < a la cantidad de Funciones en el menu
            Menu[opt-'1'].DoAction();
            printf("\nPresione una tecla para volver al Menu\n");
            opt = getch();
            if(opt == 0)
            opt = getch() + 1000;
        }  
    }
	return 0;	
}