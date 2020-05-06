#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<dos.h> 

void draw_circle();
int delay(int opt, int ms);
void draw_second(int sec);

int main()
{
    textmode(C4350);
    _setcursortype(_NOCURSOR);
        
    struct time hora;

    delay(1, 200);
    while (1)
    {

        draw_circle();

        

        if(delay(0, 200))
        {
            gotoxy(19,25);
            gettime(&hora);
            cprintf("%0.2d:%0.2d:%0.2d.%0.3d", hora.ti_hour, hora.ti_min, hora.ti_sec, hora.ti_hund);

            draw_second(5);
        }
    }
    return 0;
}

void draw_circle(){
    for (char x = 0; x < 80 ; x++)
    {
        for (char y = 0; y < 50; y++)
        {
            if (floor(0.5+ sqrt((x-40)*(x-40) + (y-25)*(y-25))) == 24)
            {
                textbackground(15);
                textcolor(0);
                gotoxy(x+1, y+1);
                cprintf(" ");
            }
        }
    }
    textbackground(0);
}

void draw_second(int sec){

    char x, y, xend, yend, m;

    textbackground(15);

    if ((sec > 0) && (sec < 15))
    {
        x = 40;
        xend = 64;
        y = 0;
        yend = 25;
    }else if ((sec > 15) && (sec < 30))
    {
        x = 40;
        xend = 64;
        y = 25;
        yend = 50;
    }else if ((sec > 30) && (sec < 45))
    {
        x = 0;
        xend = 40;
        y = 25;
        yend = 50;
    }else if ((sec > 45) && (sec < 60))
    {
        x = 0;
        xend = 40;
        y = 0;
        yend = 25;
    }

    for (x; x < xend; x++)
    {
        for (y; y < yend; y++)
        {
            m = (y-25)/(x-40);
            if ((m*x) == y)
            {
                gotoxy(x,y);
                cprintf(" ");
            }
            
        }
        
    }
    textbackground(0);
}

int delay(int opt, int ms){
    static clock_t lastTime = 0;
    clock_t currentTime;
    
    if(opt == 1)
        lastTime = clock();
    else{
        currentTime = clock();
        if((currentTime-lastTime)>=ms)
        {
            lastTime = currentTime;
            return 1;
        }
    }
    return 0;
}