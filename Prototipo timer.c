#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <dos.h> 

//Prototipos
int delay(int opt, int ms);

//Funciones
int delay(int opt, int ms){
    static clock_t lastTime = clock();
    clock_t currentTime;
    
    if(opt == 1)
        lastTime = clock();
    else{
        currentTime = clock();
        if((currentTime-lastTime)>=ms){
            lastTime = currentTime;
            return 1;
        }
    }

    return 0;
}

int main()
{
    struct time hora;
    short opt;
    int i, j;

    textmode(C4350);
    _setcursortype(_NOCURSOR);

    delay(1, 200);
    while(1){
        if(kbhit()){
            opt = getch();
            if(opt == 0)
                opt  = getch() + 1000;
            
            if(opt == 27)
                break;
                
            gotoxy(1, 3);
            printf("%0.4d", opt);    
        }
            
         if(delay(0, 200)){
            gotoxy(1,1);
            gettime(&hora);
            printf("%0.2d:%0.2d:%0.2d.%0.3d", hora.ti_hour, hora.ti_min, hora.ti_sec, hora.ti_hund);
        }    
    }
	return 0;	
}