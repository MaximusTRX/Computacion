#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<dos.h> 

#define G2RAD(x) ((M_PI/180*x)-((M_PI/2))) // Macro para cambiar de sistemas de angulos

int delay(int opt, int ms);
void draw_circle();
void draw_line(int rad, float ang, char color);
void clear_line(int rad, float ang);

int main()
{
    textmode(C4350);
    _setcursortype(_NOCURSOR);
        
    struct time hora;
    float ang;
    float sec_ang, min_ang, hora_ang; //Guardo valor previo del angulo para borrarlo

    delay(1, 200);
    while (1)
    {
        draw_circle();

        if(delay(0, 200))
        {
            gettime(&hora);
            //cprintf("%0.2d:%0.2d:%0.2d.%0.3d", hora.ti_hour, hora.ti_min, hora.ti_sec, hora.ti_hund);
            clear_line(22, sec_ang);
            ang = (hora.ti_sec * 6 + ((6/5) * (hora.ti_hund / 20)));
            sec_ang = ang;
            draw_line(22, ang, 1);

            clear_line(16, min_ang);
            ang = (hora.ti_min * 6 + (2 * (hora.ti_sec / 20)));
            min_ang = ang;
            draw_line(16, ang, 3);


            clear_line(10, hora_ang);
            ang = (hora.ti_hour * 30 + (10 * (hora.ti_min / 20)));
            hora_ang = ang;
            draw_line(10, ang, 6);
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
                gotoxy(x, y);
                cprintf(" ");
            }
        }
    }
    textbackground(0);
}

void draw_line(int rad, float ang, char color){
    
    ang = G2RAD(ang);

    int x,i,x1,y1;
    int x0 = 40;
    int y0 = 25;
    x1=floor(0.5+(x0+(rad*(cos(ang)))));
    y1=floor(0.5+(y0+(rad*(sin(ang)))));
    int dx =  abs (x1 - x0); 
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs (y1 - y0);
    int sy = y0 < y1 ? 1 : -1; 
    int err = dx + dy; 
    int e2; /* error value e_xy */

    while (1)
    {
        textbackground(color);
        gotoxy(x0,y0);
        cprintf(" ");

        if (x0 == x1 && y0 == y1)
        {
            break;
        }

        e2 =2 * err;

        if(e2 >= dy)
        { /* e_xy+e_x > 0 */
            err += dy;
            x0 += sx;
        }
        if(e2 <= dx)
        { /* e_xy+e_y < 0 */
            err += dx;
            y0 += sy;
        } 
    }
}

void clear_line(int rad, float ang){
    
    ang = G2RAD(ang);

    int x,i,x1,y1;
    int x0 = 40;
    int y0 = 25;
    x1=floor(0.5+(x0+(rad*(cos(ang)))));
    y1=floor(0.5+(y0+(rad*(sin(ang)))));
    int dx =  abs (x1 - x0); 
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs (y1 - y0);
    int sy = y0 < y1 ? 1 : -1; 
    int err = dx + dy; 
    int e2; /* error value e_xy */

    while (1)
    {
        textbackground(0);
        gotoxy(x0,y0);
        cprintf(" ");

        if (x0 == x1 && y0 == y1)
        {
            break;
        }

        e2 =2 * err;

        if(e2 >= dy)
        { /* e_xy+e_x > 0 */
            err += dy;
            x0 += sx;
        }
        if(e2 <= dx)
        { /* e_xy+e_y < 0 */
            err += dx;
            y0 += sy;
        } 
    }
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