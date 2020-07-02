#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<dos.h>
#include<string.h>

//Caracteres de Operacion
const unsigned char ASII048[] = {0x0E, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0E, 0x00};	// Char 000 ('0')
const unsigned char ASII049[] = {0x04, 0x0C, 0x04, 0x04, 0x04, 0x04, 0x0E, 0x00};	// Char 001 ('1')
const unsigned char ASII050[] = {0x0E, 0x11, 0x01, 0x02, 0x04, 0x08, 0x1F, 0x00};	// Char 002 ('2')
const unsigned char ASII051[] = {0x0E, 0x11, 0x01, 0x06, 0x01, 0x11, 0x0E, 0x00};	// Char 003 ('3')
const unsigned char ASII052[] = {0x02, 0x06, 0x0A, 0x12, 0x1F, 0x02, 0x02, 0x00};	// Char 004 ('4')
const unsigned char ASII053[] = {0x1F, 0x10, 0x10, 0x1E, 0x01, 0x01, 0x1E, 0x00};	// Char 005 ('5')
const unsigned char ASII054[] = {0x0E, 0x11, 0x10, 0x1E, 0x11, 0x11, 0x0E, 0x00};	// Char 006 ('6')
const unsigned char ASII055[] = {0x1F, 0x01, 0x02, 0x04, 0x04, 0x04, 0x04, 0x00};	// Char 007 ('7')
const unsigned char ASII056[] = {0x0E, 0x11, 0x11, 0x0E, 0x11, 0x11, 0x0E, 0x00};	// Char 008 ('8')
const unsigned char ASII057[] = {0x0E, 0x11, 0x11, 0x0F, 0x01, 0x11, 0x0E, 0x00};	// Char 009 ('9')
const unsigned char ASII040[] = {0x04, 0x08, 0x08, 0x08, 0x08, 0x08, 0x04, 0x00};	// Char 010 ('(')
const unsigned char ASII041[] = {0x08, 0x04, 0x04, 0x04, 0x04, 0x04, 0x08, 0x00};	// Char 011 (')')
const unsigned char ASII043[] = {0x00, 0x04, 0x04, 0x1F, 0x04, 0x04, 0x00, 0x00};	// Char 012 ('+')
const unsigned char ASII045[] = {0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00};	// Char 013 ('-')
const unsigned char ASII042[] = {0x00, 0x00, 0x11, 0x0A, 0x04, 0x0A, 0x11, 0x00};	// Char 014 ('*')
const unsigned char ASII047[] = {0x00, 0x04, 0x00, 0x1F, 0x00, 0x04, 0x00, 0x00};	// Char 015 ('/')
const unsigned char ASII044[] = {0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x08, 0x00};	// Char 016 (',')
const unsigned char ASII101[] = {0x00, 0x00, 0x0C, 0x12, 0x1E, 0x10, 0x0E, 0x00};	// Char 017 ('e')
const unsigned char ASII039[] = {0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};	// Char 018 (COMILLA)

//Caracteres de Instruccion
const unsigned char ASII0UP[] = {0x00, 0x00, 0x04, 0x0E, 0x1F, 0x00, 0x00, 0x00};	// Char 019 (UP-ARROW)
const unsigned char ASIIDOW[] = {0x00, 0x00, 0x1F, 0x0E, 0x04, 0x00, 0x00, 0x00};	// Char 020 (DOWN-ARROW)
const unsigned char ASIILEF[] = {0x00, 0x01, 0x03, 0x07, 0x03, 0x01, 0x00, 0x00};	// Char 021 (LEFT-ARROW)
const unsigned char ASIIRIG[] = {0x00, 0x10, 0x18, 0x1C, 0x18, 0x10, 0x00, 0x00};	// Char 022 (RIGHT-ARROW)

//Matrix de Caracteres
const unsigned char * const ROMCHAR[] = {ASII048, ASII049, ASII050, ASII051, ASII052, ASII053, ASII054, ASII055, ASII056, ASII057, ASII040, ASII041, ASII043, ASII045, ASII042, ASII047, ASII044, ASII101, ASII039, ASII0UP, ASIIDOW, ASIILEF, ASIIRIG};


//Macros
#define G2RAD(x) ((M_PI/180*x)-((M_PI/2))) // Macro para cambiar de sistemas de angulos

int delay(int opt, int ms);
void draw_circle();
void draw_line(int rad, float ang, char color);
void clear_line(int rad, float ang);
void RELOJ();
void print_char(unsigned char posX, unsigned char posY, unsigned char key);
void CALCULADORA();

/*
    ASII 0 72 UP-ARROW
    ASII 0 80 DOWN-ARROW
    ASII 0 75 LEFT-ARROW
    ASII 0 77 RIGHT-ARROW'
    ASII   39 COMILLA

    ASII   110 "n"
*/

int main()
{
    //cprintf("%0.2d:%0.2d:%0.2d.%0.3d", hora.ti_hour, hora.ti_min, hora.ti_sec, hora.ti_hund);
    textmode(C4350);
    _setcursortype(_NOCURSOR);

    while (1)
    {
        RELOJ();
        clrscr();
        CALCULADORA();
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

void draw_line(int rad, float ang, char color){//Algoritmo de Bresenham

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
    textbackground(color);
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

void RELOJ(){
    struct time hora;//Formato: hora.ti_hour, hora.ti_min, hora.ti_sec, hora.ti_hund);
    float ang;
    float sec_ang, min_ang, hora_ang; //Guardo valor previo del angulo para borrarlo
    unsigned char key;
    delay(1, 200);

    draw_circle();

    while (1)
    {
        if (kbhit())
        {
            key = getch();
            if (((key > 38) && (key < 46)) || ((key > 46) && (key < 58)) || (key == 101))//Compruebo que la tecla sea una imprimible
            {
                textbackground(0);
                return;
            }
        }

        if(delay(0, 200))//Graficado RELOJ
        {
            gettime(&hora);
            ang = (hora.ti_sec * 6 + ((6/5) * (hora.ti_hund / 20)));
            if (ang != sec_ang)
            {
                clear_line(22, sec_ang);
            }
            sec_ang = ang;
            draw_line(22, ang, 1);

            ang = (hora.ti_min * 6 + (2 * (hora.ti_sec / 20)));
            if(ang != min_ang)
            {
                clear_line(16, min_ang);
            }
            min_ang = ang;
            draw_line(16, ang, 3);


            ang = (hora.ti_hour * 30 + (10 * (hora.ti_min / 20)));
            if(ang != hora_ang)
            {
                clear_line(10, hora_ang);
            }
            hora_ang = ang;
            draw_line(10, ang, 6);
        }
    }
    textbackground(0);
}

void CALCULADORA(){
    static char Entrada[1024];
    static float Stack[10];
    int posIn = 0;
    int posSt = 0;
    unsigned char key, x = 1, changeSt = 0;
    int cont = 0;
    char *ptr;

    delay(1, (10*1000));
    while (1)
    {
        if(kbhit())//Input line
        {
            key = getch();

            if (((key > 38) && (key < 44)) || ((key > 44) && (key < 58)) || (key == 101))//Compruebo que la tecla sea una imprimible
            {

                delay(1, (10*1000));//Restart last time key hit

                clrscr();

                Entrada[posIn] = key;

                if (posIn >= 10)
                {
                    cont = posIn - 9;
                }else
                {
                    cont = 0;
                }
                x = 1;
                for (cont ; cont < posIn+1; cont++)
                {
                    print_char(x, 43, Entrada[cont]);
                    x+= 8;
                }
                posIn++;

            }else if (key == 27)
            {
                posIn = 0;
                clrscr();
                return;
            }else if (key == 13)
            {
                changeSt = 1;
                int k=0;
                if (Entrada[0] != 39)
                {
                    for (int i = 0; i < posIn; i++)// Compruevo caracteres y los separo
                    {
                        if ((Entrada[i] > 47) && (Entrada[i] < 58) || (Entrada[i] == 46))
                        {
                            k++;
                        }else
                        {
                            break;
                        }
                    }
                    char convert[k];
                    
                    for (int i = 0; i < k; i++)
                    {
                        convert[i] = Entrada[i];
                    }
                    
                    Stack[posSt] = strtod(convert, &ptr);
                    
                }else if (posSt > 2)
                {
                    float aux;
                    switch (Entrada[0])
                    {
                    case '+':
                        aux = Stack[posSt-1] + Stack[posSt];

                        if ((posSt+1) == 11)
                        {
                            posSt = 0;
                        }else
                        {
                            posSt+=1;
                        }
                        Stack[posSt] = aux;
                        break;
                    
                    case '-':
                        aux = Stack[posSt-1] - Stack[posSt];

                        if ((posSt+1) == 11)
                        {
                            posSt = 0;
                        }else
                        {
                            posSt+=1;
                        }
                        Stack[posSt] = aux;
                        break;

                    case '*':
                        aux = Stack[posSt-1] * Stack[posSt];

                        if ((posSt+1) == 11)
                        {
                            posSt = 0;
                        }else
                        {
                            posSt+=1;
                        }
                        Stack[posSt] = aux;
                        break;
                    
                    case '/':
                        if (Stack[posSt] == 0)
                        {
                            break;
                        }

                        aux = Stack[posSt-1] / Stack[posSt];

                        if ((posSt+1) == 11)
                        {
                            posSt = 0;
                        }else
                        {
                            posSt+=1;
                        }
                        Stack[posSt] = aux;
                        break;
                    }
                }
                posSt++;
                posIn = 0;
                clrscr();
            }
        }

        //Re escribo en el stack
        if (posSt == 11)
        {
            posSt = 0;
        }
        

        if (changeSt)
        {
            char out[10] = {0};
            char posStX, posStY, j;

            posStX = 72;
            posStY = 34;
            
            if ((posSt-1) > 4)
            {
                j = (posSt-1) - (posSt-5);
            }else
            {
                j = 0;
            }

            for (char k; k > j; k--)
            {
                sprintf(out,"%10g", Stack[k]);
                for (char i = 0; i < 10; i++)
                {
                    gotoxy(posStX, posStY);
                    print_char(posStX, posStY, out[i]);
                    posStX-=8;
                }
                posStY-=8;
            }
            for (char i = 10; i > 0; i--)
            {
                out[i] = 0;
            }
            
            changeSt = 0;
        }

        /*
        char out[1024];
        char posStX, posStY = 34;
        
        if (posSt != 0)
        {
            for (char j = (posSt-1); j >= 0; j--)
            {
                posStX = 72;
                posStY-=8;
                sprintf(out, "%10g", Stack[j]);

                for (char i = 10; i > 0; i--)
                {
                    print_char(posStX, posStY, out[i]);
                    posStX-=8;
                }
            }
        }*/

        if (delay(2, (10*1000)))//Compruebo tiempo transcurrido
        {
            clrscr();
            return;
        }
    }
}

void print_char(unsigned char posX, unsigned char posY, unsigned char key){

    if ((key >= '0') && (key <= '9'))
    {
        key -= 48;
    }else
    {
        switch (key)
        {
        case '(':
            key = 10;
            break;

        case ')':
            key = 11;
            break;

        case '+':
            key = 12;
            break;

        case '-':
            key = 13;
            break;

        case '*':
            key = 14;
            break;

        case '/':
            key = 15;
            break;

        case '.':
            key = 16;
            break;

        case 'e':
            key = 17;
            break;

        case 39:
            key = 18;
            break;
        }
    }

    for (unsigned char pixelX = 0; pixelX < 7; pixelX++)
    {
        for (unsigned char pixelY = 0; pixelY < 6; pixelY++)
        {
            gotoxy(posX+pixelY+1, posY+pixelX);
            if ((ROMCHAR[key][pixelX] << pixelY) & 0x10)
            {
                textbackground(15);
                cprintf(" ");
            }else
            {
                textbackground(0);
                cprintf(" ");
            }
        }
    }
}