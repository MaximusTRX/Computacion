#include <stdio.h>
#include <conio.h>

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

const unsigned char * const ROMCHAR[] = {ASII048, ASII049, ASII050, ASII051, ASII052, ASII053, ASII054, ASII055, ASII056, ASII057, ASII040, ASII041, ASII043, ASII045, ASII042, ASII047, ASII044, ASII101, ASII039, ASII0UP, ASIIDOW, ASIILEF, ASIIRIG};

void print_char(unsigned char posX, unsigned char posY, unsigned char key);
void CALCULADORA();
/*
    ASII 0 72 UP-ARROW
    ASII 0 80 DOWN-ARROW
    ASII 0 75 LEFT-ARROW
    ASII 0 77 RIGHT-ARROW'
    ASII 0 39 COMILLA
*/

int main(void)
{
    textmode(C4350);
    _setcursortype(_NOCURSOR);

    CALCULADORA();
/*
    unsigned char key, x=1, y=1;
 
    while (1)
    {
        key = getch();
        if (((key > 38) && (key < 46)) || ((key > 46) && (key < 58)) || (key == 101))//Compruebo que la tecla sea una imprimible
        {
            print_char(x, y, key);
            x+= 6;
        }
    }

    if ((print > 48) && (print < 57))
    {
        print -= 48;
    }else
    {
        switch (print)
        {
        case '(':
            print = 10;
            break;
        
        case ')':
            print = 11;
            break;

        case '+':
            print = 12;
            break;

        case '-':
            print = 13;
            break;

        case '*':
            print = 14;
            break;

        case '/':
            print = 15;
            break;

        case ',':
            print = 16;
            break;

        case 'e':
            print = 17;
            break;

        case 39:
            print = 18;
            break;
        }
    }
    for (unsigned char fila = 0; fila < 7; fila++)
    {
        for (unsigned char i = 0; i < 6; i++)
        {
            gotoxy(x+i, 1+fila);
            if ((ROMCHAR[print][fila] << i) & 0x10)
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
    x+=5;*/
    getch();
    return 0;
}

void CALCULADORA(){
    unsigned char key, x=1, y=1;
 
    while (1)
    {
        key = getch();
        if (((key > 38) && (key < 46)) || ((key > 46) && (key < 58)) || (key == 101))//Compruebo que la tecla sea una imprimible
        {
            print_char(x, y, key);
            x+= 6;
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

        case ',':
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
            gotoxy(posX+pixelY, posY+pixelX);
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