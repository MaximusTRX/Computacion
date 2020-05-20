#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys\stat.h>
#include <io.h>
#include <errno.h>

typedef struct{
    int id;         
    char nombre[80];
    char tel[20];  
}_sAgenda;


int main()
{
    _sAgenda Agenda1;
    int nItems, iView, sizeChar, i;
    short opt;
    char c;

    nItems = 0;
    iView = 0;
    
    int fhandle, length;
    int value;
    char buffer[128];

    if((fhandle = open("D:\\File1.dat", O_RDWR | O_BINARY)) == -1)
    {
        if(errno == ENOENT)
        {
            printf("%s", strerror(errno));
            if((fhandle = open("D:\\File1.dat", O_CREAT | O_BINARY | O_RDWR, S_IREAD | S_IWRITE)) == -1)
            {
                printf("%s", strerror(errno));
                return -1;
            }
            printf("FILE CREATED\n");
        }
    }
    else
    {
        printf("FILE OPENED\n");
    }

    system("PAUSE");

    nItems = lseek(fhandle, 0, SEEK_END) / sizeof(Agenda1);


    while(1){
        _setcursortype(_NOCURSOR);
        clrscr();
        gotoxy(1, 1);    
        printf("***************************\n");
        printf("* [F1]: NUEVO             *\n");
        printf("* [F2]: EDITAR            *\n");
        printf("* [F3]: ELIMINAR          *\n");
        printf("* [IZQ] y [DER]: DESPLAZA *\n");
        printf("* [ESC]: SALE             *\n");
        printf("***************************");
        
        gotoxy(1, 10);
        if(nItems == 0)
            printf("***\t\tNO HAY ITEMS\t\t***");
        if(nItems == 10)
            printf("***\t\tAGENDA COMPLETA\t\t***");
        if(nItems){
            gotoxy(1, 12);
            
            lseek(fhandle, iView * sizeof(Agenda1), SEEK_END);
            read(fhandle, &Agenda1, sizeof(Agenda1));

            printf("ITME Nro: %d de %d\n\n", iView+1, nItems);
            printf("ID:\t\t%d\n", Agenda1.id);
            printf("NOMBRE:\t\t%s\n", Agenda1.nombre);
            printf("TEL:\t\t%s\n", Agenda1.tel);
        }

        opt = getch();
        if(opt == 0)
            opt = 1000 + getch();
        if(opt == 27)
            break;
            
        switch(opt){
            case 1059://AGREGAR
                if(nItems == 10)
                    break;    
                for(i=12; i<17; i++){
                    gotoxy(1, i);
                    clreol();
                }
                gotoxy(1, 12);
                clreol();
                _setcursortype(_NORMALCURSOR);
                printf("*** NUEVO ITEM ***\n\n");
                printf("Ingrese Nombre: ");
                sizeChar = sizeof(Agenda1.nombre)-1;
                i = 0;
                while((c=getchar())){
                    if(sizeChar){
                        Agenda1.nombre[i++] = c;
                        sizeChar--;
                    }
                    if(c == 10)
                        break;
                }
                Agenda1.nombre[i-1] = '\0';     
                printf("\nIngrese Tel: ");
                sizeChar = sizeof(Agenda1.tel)-1;
                i = 0;
                while((c=getchar())){
                    if(sizeChar){
                        Agenda1.tel[i++] = c;
                        sizeChar--;
                    }
                    if(c == 10)
                        break;
                }
                Agenda1.tel[i-1] = '\0';
                Agenda1.id = nItems;
                nItems++;
                iView = nItems-1;
            break;
            case 1060://EDITAR
                _setcursortype(_NORMALCURSOR);
                if(nItems == 0)
                    break;    
                for(i=12; i<17; i++){
                    gotoxy(1, i);
                    clreol();
                }
                gotoxy(1, 12);
                printf("*** EDITAR ITEM  Nro: %d ***\n\n", iView+1);
                printf("Ingrese Nombre: %s", Agenda1.nombre);
                sizeChar = sizeof(Agenda1.nombre)-1;
                i = strlen(Agenda1.nombre);
                while((c=getch()) != 13){
                    if(c == 0)
                        c = getch();
                    else{
                        if(iscntrl(c)){
                            if(c==8 && i>0){
                                i--;    
                                Agenda1.nombre[i] = '\0';
                            }
                        }
                        else{
                            if(i < sizeChar){
                                Agenda1.nombre[i++] = c;
                                Agenda1.nombre[i] = '\0';
                            }
                        }
                        gotoxy(1,14);
                        clreol();    
                        printf("Ingrese Nombre: %s", Agenda1.nombre);
                    }
                }
                gotoxy(1, 16);
                printf("Ingrese Tel: %s", Agenda1.tel);
                sizeChar = sizeof(Agenda1.tel)-1;
                i = strlen(Agenda1.tel);
                while((c=getch()) != 13){
                    if(c == 0)
                        c = getch();
                    else{
                        if(iscntrl(c)){
                            if(c==8 && i>0){
                                i--;    
                                Agenda1.tel[i] = '\0';
                            }
                        }
                        else{
                            if(i < sizeChar){
                                Agenda1.tel[i++] = c;
                                Agenda1.tel[i] = '\0';
                            }
                        }    
                        gotoxy(1, 16);
                        clreol();    
                        printf("Ingrese Tel: %s", Agenda1.tel);
                    }
                }
            break;
            case 1061://ELIMINAR
                if(nItems == 0)
                    break;    
                if(nItems > 0){
                    for(i=iView; i<nItems-1; i++){
                        Agenda1.id = Agenda1.id;
                        strcpy(Agenda1.nombre, Agenda1.nombre);  
                        strcpy(Agenda1.tel, Agenda1.tel);  
                    }
                    nItems--;
                    if(iView == nItems)
                        iView = nItems - 1;
                }
            break;
            case 1077://DERECHA
                iView++;
                if(iView == nItems)
                    iView = 0;
            break;
            case 1075://IZQUIERDA
                iView--;
                if(iView < 0)
                    iView = nItems-1;
            break;
        }     
    }
    close(fhandle);
	return 0;	
}