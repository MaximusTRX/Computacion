#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <dos.h> 
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//typedef
typedef union{
    struct{
        unsigned char b0: 1;
        unsigned char b1: 1;
        unsigned char b2: 1;
        unsigned char b3: 1;
        unsigned char b4: 1;
        unsigned char b5: 1;
        unsigned char b6: 1;
        unsigned char b7: 1;
    } bit;
    unsigned char byte;
}_sflag;
//.

//Prototipos
int Delay(int opt, int ms);

void DoCalc(short opt);
int SolveSimpleA(char *oprs, int noprs, double *opds, int nopds, double *result);
int SolveExpresion(const char *expresion, double *result);

void SetPixelColor(int aPixelcolor);
void SetPixelBackColor(int aBackColor);
void SetPixelChar(char aPixelChar);
void PutTextOnDisplay(int x, int y, const char *text, int length);
void RefreshDisplay(int top, int right, int bottom, int left);
void ClearDisplay(int top, int right, int bottom, int left);
void FillDisplay(int top, int right, int bottom, int left);
void Circle(int radius, int centerx, int centery);
void Line(int x1, int y1, int x2, int y2);
//.

//Definitions
#define MODEWATCH       0
#define MODECALC        1


#define IS200MS         flag1.bit.b0
#define CIRCLEWATCH     flag1.bit.b1
#define FROMWATCH       flag1.bit.b2
//.



//Global Variables
const unsigned char ROMCHAR[2048] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	// Char 000 (.)
	0x7E, 0x81, 0xA5, 0x81, 0xBD, 0x99, 0x81, 0x7E,	// Char 001 (.)
	0x7E, 0xFF, 0xDB, 0xFF, 0xC3, 0xE7, 0xFF, 0x7E,	// Char 002 (.)
	0x6C, 0xFE, 0xFE, 0xFE, 0x7C, 0x38, 0x10, 0x00,	// Char 003 (.)
	0x10, 0x38, 0x7C, 0xFE, 0x7C, 0x38, 0x10, 0x00,	// Char 004 (.)
	0x38, 0x7C, 0xEE, 0xEE, 0xEE, 0x38, 0x38, 0x7C,	// Char 005 (.)
	0x00, 0x10, 0x38, 0x7C, 0xFE, 0x7C, 0x38, 0x7C,	// Char 006 (.)
	0x00, 0x00, 0x18, 0x3C, 0x3C, 0x18, 0x00, 0x00,	// Char 007 (.)
	0xFF, 0xFF, 0xE7, 0xC3, 0xC3, 0xE7, 0xFF, 0xFF,	// Char 008 (.)
	0x00, 0x3C, 0x66, 0x42, 0x42, 0x66, 0x3C, 0x00,	// Char 009 (.)
	0xFF, 0xC3, 0x99, 0xBD, 0xBD, 0x99, 0xC3, 0xFF,	// Char 010 (.)
	0x0F, 0x07, 0x0F, 0x7D, 0xCC, 0xCC, 0xCC, 0x78,	// Char 011 (.)
	0x3C, 0x66, 0x66, 0x66, 0x3C, 0x18, 0x7E, 0x18,	// Char 012 (.)
	0x3F, 0x33, 0x3F, 0x30, 0x30, 0x70, 0xF0, 0xE0,	// Char 013 (.)
	0x7F, 0x63, 0x7F, 0x63, 0x63, 0x67, 0xE6, 0xC0,	// Char 014 (.)
	0x18, 0xDB, 0x3C, 0xE7, 0xE7, 0x3C, 0xDB, 0x18,	// Char 015 (.)
	0x80, 0xE0, 0xF8, 0xFE, 0xF8, 0xE0, 0x80, 0x00,	// Char 016 (.) fLeft
	0x02, 0x0E, 0x3E, 0xFE, 0x3E, 0x0E, 0x02, 0x00,	// Char 017 (.) fRight
	0x18, 0x3C, 0x7E, 0x18, 0x18, 0x7E, 0x3C, 0x18,	// Char 018 (.)
	0x66, 0x66, 0x66, 0x66, 0x66, 0x00, 0x66, 0x00,	// Char 019 (.)
	0x7F, 0xDB, 0xDB, 0x7B, 0x1B, 0x1B, 0x1B, 0x00,	// Char 020 (.)
	0x3C, 0x66, 0x38, 0x6C, 0x6C, 0x38, 0xCC, 0x78,	// Char 021 (.)
	0x00, 0x00, 0x00, 0x00, 0x7E, 0x7E, 0x7E, 0x00,	// Char 022 (.)
	0x18, 0x3C, 0x7E, 0x18, 0x7E, 0x3C, 0x18, 0x7E,	// Char 023 (.)
	0x18, 0x3C, 0x7E, 0x18, 0x18, 0x18, 0x18, 0x00,	// Char 024 (.)
	0x18, 0x18, 0x18, 0x18, 0x7E, 0x3C, 0x18, 0x00,	// Char 025 (.)
	0x00, 0x18, 0x0C, 0xFE, 0x0C, 0x18, 0x00, 0x00,	// Char 026 (.)
	0x00, 0x30, 0x60, 0xFE, 0x60, 0x30, 0x00, 0x00,	// Char 027 (.)
	0x00, 0x00, 0xC0, 0xC0, 0xC0, 0xFE, 0x00, 0x00,	// Char 028 (.)
	0x00, 0x24, 0x66, 0xFF, 0x66, 0x24, 0x00, 0x00,	// Char 029 (.)
	0x00, 0x18, 0x3C, 0x7E, 0xFF, 0xFF, 0x00, 0x00,	// Char 030 (.) fUp
	0x00, 0xFF, 0xFF, 0x7E, 0x3C, 0x18, 0x00, 0x00,	// Char 031 (.) fDown
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	// Char 032 ( )
	0x30, 0x78, 0x78, 0x30, 0x30, 0x00, 0x30, 0x00,	// Char 033 (!)
	0x6C, 0x6C, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00,	// Char 034 (")
	0x6C, 0x6C, 0xFE, 0x6C, 0xFE, 0x6C, 0x6C, 0x00,	// Char 035 (#)
	0x18, 0x7E, 0xC0, 0x7C, 0x06, 0xFC, 0x18, 0x00,	// Char 036 ($)
	0x00, 0xC6, 0xCC, 0x18, 0x30, 0x66, 0xC6, 0x00,	// Char 037 (%)
	0x38, 0x6C, 0x38, 0x76, 0xDC, 0xCC, 0x76, 0x00,	// Char 038 (&)
	0x30, 0x30, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00,	// Char 039 (')
	0x18, 0x30, 0x60, 0x60, 0x60, 0x30, 0x18, 0x00,	// Char 040 (()
	0x60, 0x30, 0x18, 0x18, 0x18, 0x30, 0x60, 0x00,	// Char 041 ())
	0x00, 0x66, 0x3C, 0xFF, 0x3C, 0x66, 0x00, 0x00,	// Char 042 (*)
	0x00, 0x30, 0x30, 0xFC, 0x30, 0x30, 0x00, 0x00,	// Char 043 (+)
	0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x60,	// Char 044 (,)
	0x00, 0x00, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00,	// Char 045 (-)
	0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00,	// Char 046 (.)
	0x06, 0x0C, 0x18, 0x30, 0x60, 0xC0, 0x80, 0x00,	// Char 047 (/)
	0x7C, 0xC6, 0xC6, 0xD6, 0xC6, 0xC6, 0x7C, 0x00,	// Char 048 (0)
	0x30, 0x70, 0x30, 0x30, 0x30, 0x30, 0xFC, 0x00,	// Char 049 (1)
	0x78, 0xCC, 0x0C, 0x38, 0x60, 0xCC, 0xFC, 0x00,	// Char 050 (2)
	0x78, 0xCC, 0x0C, 0x38, 0x0C, 0xCC, 0x78, 0x00,	// Char 051 (3)
	0x1C, 0x3C, 0x6C, 0xCC, 0xFE, 0x0C, 0x1E, 0x00,	// Char 052 (4)
	0xFC, 0xC0, 0xF8, 0x0C, 0x0C, 0xCC, 0x78, 0x00,	// Char 053 (5)
	0x38, 0x60, 0xC0, 0xF8, 0xCC, 0xCC, 0x78, 0x00,	// Char 054 (6)
	0xFC, 0xCC, 0x0C, 0x18, 0x30, 0x30, 0x30, 0x00,	// Char 055 (7)
	0x78, 0xCC, 0xCC, 0x78, 0xCC, 0xCC, 0x78, 0x00,	// Char 056 (8)
	0x78, 0xCC, 0xCC, 0x7C, 0x0C, 0x18, 0x70, 0x00,	// Char 057 (9)
	0x00, 0x30, 0x30, 0x00, 0x00, 0x30, 0x30, 0x00,	// Char 058 (:)
	0x00, 0x30, 0x30, 0x00, 0x00, 0x30, 0x30, 0x60,	// Char 059 (;)
	0x18, 0x30, 0x60, 0xC0, 0x60, 0x30, 0x18, 0x00,	// Char 060 (<)
	0x00, 0x00, 0xFC, 0x00, 0x00, 0xFC, 0x00, 0x00,	// Char 061 (=)
	0x60, 0x30, 0x18, 0x0C, 0x18, 0x30, 0x60, 0x00,	// Char 062 (>)
	0x78, 0xCC, 0x0C, 0x18, 0x30, 0x00, 0x30, 0x00,	// Char 063 (?)
	0x7C, 0xC6, 0xDE, 0xDE, 0xDC, 0xC0, 0x78, 0x00,	// Char 064 (@)
	0x30, 0x78, 0xCC, 0xCC, 0xFC, 0xCC, 0xCC, 0x00,	// Char 065 (A)
	0xFC, 0x66, 0x66, 0x7C, 0x66, 0x66, 0xFC, 0x00,	// Char 066 (B)
	0x3C, 0x66, 0xC0, 0xC0, 0xC0, 0x66, 0x3C, 0x00,	// Char 067 (C)
	0xF8, 0x6C, 0x66, 0x66, 0x66, 0x6C, 0xF8, 0x00,	// Char 068 (D)
	0xFE, 0x62, 0x68, 0x78, 0x68, 0x62, 0xFE, 0x00,	// Char 069 (E)
	0xFE, 0x62, 0x68, 0x78, 0x68, 0x60, 0xF0, 0x00,	// Char 070 (F)
	0x3C, 0x66, 0xC0, 0xC0, 0xCE, 0x66, 0x3E, 0x00,	// Char 071 (G)
	0xCC, 0xCC, 0xCC, 0xFC, 0xCC, 0xCC, 0xCC, 0x00,	// Char 072 (H)
	0x78, 0x30, 0x30, 0x30, 0x30, 0x30, 0x78, 0x00,	// Char 073 (I)
	0x1E, 0x0C, 0x0C, 0x0C, 0xCC, 0xCC, 0x78, 0x00,	// Char 074 (J)
	0xE6, 0x66, 0x6C, 0x78, 0x6C, 0x66, 0xE6, 0x00,	// Char 075 (K)
	0xF0, 0x60, 0x60, 0x60, 0x62, 0x66, 0xFE, 0x00,	// Char 076 (L)
	0xC6, 0xEE, 0xFE, 0xFE, 0xD6, 0xC6, 0xC6, 0x00,	// Char 077 (M)
	0xC6, 0xE6, 0xF6, 0xDE, 0xCE, 0xC6, 0xC6, 0x00,	// Char 078 (N)
	0x38, 0x6C, 0xC6, 0xC6, 0xC6, 0x6C, 0x38, 0x00,	// Char 079 (O)
	0xFC, 0x66, 0x66, 0x7C, 0x60, 0x60, 0xF0, 0x00,	// Char 080 (P)
	0x78, 0xCC, 0xCC, 0xCC, 0xDC, 0x78, 0x1C, 0x00,	// Char 081 (Q)
	0xFC, 0x66, 0x66, 0x7C, 0x6C, 0x66, 0xE6, 0x00,	// Char 082 (R)
	0x78, 0xCC, 0xC0, 0x78, 0x0C, 0xCC, 0x78, 0x00,	// Char 083 (S)
	0xFC, 0xB4, 0x30, 0x30, 0x30, 0x30, 0x78, 0x00,	// Char 084 (T)
	0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xFC, 0x00,	// Char 085 (U)
	0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0x78, 0x30, 0x00,	// Char 086 (V)
	0xC6, 0xC6, 0xC6, 0xD6, 0xFE, 0xEE, 0xC6, 0x00,	// Char 087 (W)
	0xC6, 0x6C, 0x38, 0x38, 0x6C, 0xC6, 0xC6, 0x00,	// Char 088 (X)
	0xCC, 0xCC, 0xCC, 0x78, 0x30, 0x30, 0x78, 0x00,	// Char 089 (Y)
	0xFE, 0xC6, 0x8C, 0x18, 0x32, 0x66, 0xFE, 0x00,	// Char 090 (Z)
	0x78, 0x60, 0x60, 0x60, 0x60, 0x60, 0x78, 0x00,	// Char 091 ([)
	0xC0, 0x60, 0x30, 0x18, 0x0C, 0x06, 0x02, 0x00,	// Char 092 (\)
	0x78, 0x18, 0x18, 0x18, 0x18, 0x18, 0x78, 0x00,	// Char 093 (])
	0x10, 0x38, 0x6C, 0xC6, 0x00, 0x00, 0x00, 0x00,	// Char 094 (^)
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,	// Char 095 (_)
	0x30, 0x18, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00,	// Char 096 (`)
	0x00, 0x00, 0x78, 0x0C, 0x7C, 0xCC, 0x76, 0x00,	// Char 097 (a)
	0xE0, 0x60, 0x60, 0x7C, 0x66, 0x66, 0xDC, 0x00,	// Char 098 (b)
	0x00, 0x00, 0x78, 0xCC, 0xC0, 0xCC, 0x78, 0x00,	// Char 099 (c)
	0x1C, 0x0C, 0x0C, 0x7C, 0xCC, 0xCC, 0x76, 0x00,	// Char 100 (d)
	0x00, 0x00, 0x78, 0xCC, 0xFC, 0xC0, 0x78, 0x00,	// Char 101 (e)
	0x38, 0x6C, 0x60, 0xF0, 0x60, 0x60, 0xF0, 0x00,	// Char 102 (f)
	0x00, 0x00, 0x76, 0xCC, 0xCC, 0x7C, 0x0C, 0xF8,	// Char 103 (g)
	0xE0, 0x60, 0x6C, 0x76, 0x66, 0x66, 0xE6, 0x00,	// Char 104 (h)
	0x30, 0x00, 0x70, 0x30, 0x30, 0x30, 0x78, 0x00,	// Char 105 (i)
	0x0C, 0x00, 0x0C, 0x0C, 0x0C, 0xCC, 0xCC, 0x78,	// Char 106 (j)
	0xE0, 0x60, 0x66, 0x6C, 0x78, 0x6C, 0xE6, 0x00,	// Char 107 (k)
	0x70, 0x30, 0x30, 0x30, 0x30, 0x30, 0x78, 0x00,	// Char 108 (l)
	0x00, 0x00, 0xCC, 0xFE, 0xD6, 0xD6, 0xC6, 0x00,	// Char 109 (m)
	0x00, 0x00, 0xF8, 0xCC, 0xCC, 0xCC, 0xCC, 0x00,	// Char 110 (n)
	0x00, 0x00, 0x78, 0xCC, 0xCC, 0xCC, 0x78, 0x00,	// Char 111 (o)
	0x00, 0x00, 0xDC, 0x66, 0x66, 0x7C, 0x60, 0xF0,	// Char 112 (p)
	0x00, 0x00, 0x76, 0xCC, 0xCC, 0x7C, 0x0C, 0x1E,	// Char 113 (q)
	0x00, 0x00, 0xDC, 0x76, 0x66, 0x60, 0xF0, 0x00,	// Char 114 (r)
	0x00, 0x00, 0x7C, 0xC0, 0x78, 0x0C, 0xF8, 0x00,	// Char 115 (s)
	0x10, 0x30, 0x7C, 0x30, 0x30, 0x34, 0x18, 0x00,	// Char 116 (t)
	0x00, 0x00, 0xCC, 0xCC, 0xCC, 0xCC, 0x76, 0x00,	// Char 117 (u)
	0x00, 0x00, 0xCC, 0xCC, 0xCC, 0x78, 0x30, 0x00,	// Char 118 (v)
	0x00, 0x00, 0xC6, 0xD6, 0xD6, 0xFE, 0x6C, 0x00,	// Char 119 (w)
	0x00, 0x00, 0xC6, 0x6C, 0x38, 0x6C, 0xC6, 0x00,	// Char 120 (x)
	0x00, 0x00, 0xCC, 0xCC, 0xCC, 0x7C, 0x0C, 0xF8,	// Char 121 (y)
	0x00, 0x00, 0xFC, 0x98, 0x30, 0x64, 0xFC, 0x00,	// Char 122 (z)
	0x1C, 0x30, 0x30, 0xE0, 0x30, 0x30, 0x1C, 0x00,	// Char 123 ({)
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x00,	// Char 124 (|)
	0xE0, 0x30, 0x30, 0x1C, 0x30, 0x30, 0xE0, 0x00,	// Char 125 (})
	0x76, 0xDC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,	// Char 126 (~)
	0x00, 0x10, 0x38, 0x6C, 0xC6, 0xC6, 0xFE, 0x00 	// Char 127 (.)
};
    
_sflag flag1;

unsigned char display[50][80][2];
unsigned char pixelChar, pixelColor, pixelBackColor;
unsigned char pixelClearColor; 

//.
                                         

//Funciones
int Delay(int opt, int ms){
    static clock_t lastTime = 0;
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


void SetPixelColor(int aPixelColor){
    pixelColor = aPixelColor;    
}

void SetPixelBackColor(int aBackColor){
    pixelBackColor = aBackColor;
}

void SetPixelChar(char aPixelChar){
    pixelChar = aPixelChar;
}

void SetPixelClearColor(char aPixelColor){
    pixelClearColor = aPixelColor;
}



void PutTextOnDisplay(int x, int y, const char *text, int length){
    int xpos, ypos, k, j;
    unsigned char c, mask, bit;
    int charPos;
    
    for(j=0; j<length; j++){
        charPos = text[j]*8;
        for(k=0; k<8; k++){
            mask = 0x80;
            ypos = y + k;
            if(ypos>50)
                break;
            for(bit=0; bit<8; bit++){
                xpos = x + j*8 + bit;
                if(xpos>80)
                    break;
                display[ypos][xpos][1] = ((pixelColor << 4) | (pixelBackColor & 0x0F));   
                display[ypos][xpos][0] = ' ';
                if(ROMCHAR[charPos+k] & mask)
                    display[ypos][xpos][0] = pixelChar;
                mask >>= 1; 
            }                           
        }
    }
}


void RefreshDisplay(int top, int right, int bottom, int left){
    for(int y=top; y<bottom; y++){
        for(int x=right; x<left; x++){
            gotoxy(x+1, y+1);
            textcolor(display[y][x][1] >> 4);
            textbackground(display[y][x][1] & 0x0F);
            cprintf("%c", display[y][x][0]);
        }
    }
}

void ClearDisplay(int top, int right, int bottom, int left){
    for(int y=0; y<50; y++){
        for(int x=0; x<80; x++){
            display[y][x][0] = 0;
        }
    }
}

void FillDisplay(int top, int right, int bottom, int left){
    for(int y=0; y<50; y++){
        for(int x=0; x<80; x++){
            display[y][x][0] = pixelChar;
            display[y][x][1] = ((pixelColor << 4) | (pixelBackColor & 0x0F));
        }
    }
}

void Circle(int radius, int centerx, int centery){
    int x, y, r;
    float angr;
    
    for(r=0; r<360; r++){
        angr = r*M_PI/180;
        x = centerx + floor(radius*cos(angr)+0.5);            
        y = centery + floor(radius*sin(angr)+0.5);            
        display[y][x][0] = pixelChar;
        display[y][x][1] = ((pixelColor << 4) | (pixelBackColor & 0x0F));
    }
}

void Line(int x1, int y1, int x2, int y2){
    float angr;
    int x, y, l, l1;

    angr = atan2((y2-y1)*1.0,(x2-x1)*1.0);
    l = floor(sqrt(1.0*(y2-y1)*(y2-y1)+(x2-x1)*(x2-x1)) + 0.5);
    l1 = 0;
    
    while(l1 < l){
        x = x1+floor(l1*cos(angr)+0.5);                    
        y = y1+floor(l1*sin(angr)+0.5);                    
        display[y][x][0] = pixelChar;
        display[y][x][1] = ((pixelColor << 4) | (pixelBackColor & 0x0F));
        l1++;
    }
}



void DoCalc(short opt){
    static int iStack = -1;
    static int iStackMax = 0;
    static int iPosCur = 0;
    static int iPosLine = 0;
    static int iMaxLine = 0;
    static float valuesStack[10] = {0.0, 0.0, 0.0, 0.0, 0.0,
                                    0.0, 0.0, 0.0, 0.0, 0.0};
                                  
    static char entryLine[1024] = {0};
    char statusLine[11] = {"          "};
    char auxStr[24];
    static _sflag flagCALC = {.byte = 0};
   
    int iS1, i, npos, err;
    float ope1, ope2;
    char *endptr;
    double auxf, result;
    
    #define ALGMODE         flagCALC.bit.b0
    #define ADDCHARENTRY    flagCALC.bit.b1 
    #define REFRESHSTACK    flagCALC.bit.b2

    if(FROMWATCH){
        REFRESHSTACK = 1;
        opt = 0;
    }
    FROMWATCH = 0;    
    ADDCHARENTRY = 0;
    npos = -1;
    
    if(iMaxLine == 1024)
        return;
    
    ALGMODE = 0;
    if(entryLine[0] == '\'')
        ALGMODE = 1;
    
    switch(opt){
        case '\r'://ENTER
            if(iMaxLine!=0 && iStack==-1){
                if(ALGMODE == 0){
                    auxf = strtod(entryLine, &endptr);
                    if(*endptr != NULL){
                        statusLine[6] = 'E';
                        statusLine[7] = *endptr;
                        break;
                    }
                }
                else{
                    err = SolveExpresion(entryLine, &auxf); 
                    if(err != 1){
                        statusLine[5] = 'e';
                        statusLine[6] = 'A';
                        statusLine[7] = 'L';
                        iPosLine = -err; 
                        iPosCur = iPosLine%10;
                        break;
                    }
                    else
                        ALGMODE = 0;
                }
                for(int i=9; i>0; i--)
                    valuesStack[i] = valuesStack[i-1];
                valuesStack[0] = auxf;
                iStackMax++;
                if(iStackMax > 10)
                    iStackMax = 10;
                memset(entryLine, '\0', 1024);
                iPosCur = 0;
                iPosLine = 0;
                iMaxLine = 0;    
                REFRESHSTACK = 1;    
            }
        break;
        case 8://BACKSPACE
            if(iStack != -1){
                if(iStackMax > 0){
                    for(i=iStack; i<10; i++)
                        valuesStack[i] =  valuesStack[i+1];
                    iStackMax--;
                    valuesStack[9] = 0.0;
                    if(iStackMax == 0)
                        iStack = -1;
                    REFRESHSTACK = 1;
                }
            }
            else{
                if(iPosLine != 0){
                    for(i=iPosLine; i<1024; i++)
                        entryLine[i-1] = entryLine[i];
                    iPosLine--;
                    iMaxLine--;
                    iPosCur--;
                    if(iPosCur < 0)
                        iPosCur = 0;
                    if(iPosCur==0 && iPosLine<10)
                        iPosCur = iPosLine;    
                    entryLine[iMaxLine] = '\0';    
                }
            }
        break;
        case 'n':
            if(entryLine[0] == '\0'){
                if(iStackMax){
                    valuesStack[0] *= -1.0;
                    REFRESHSTACK = 1;
                }
            }
            else{
                i = iPosLine;
                if(!isdigit(entryLine[iPosLine]) && 
                    entryLine[iPosLine]!='+' && entryLine[iPosLine]!='-')
                    i--;               
                for(; i>=1; i--){
                    if(entryLine[i]=='\0')
                        break;
                    if(!(isdigit(entryLine[i]) || entryLine[i]=='.') && entryLine[i]!='\'')
                        break;    
                }
                if(entryLine[i] == '-')
                    entryLine[i] = '+';
                else{
                    if(entryLine[i] == '+')
                        entryLine[i] = '-';
                    else{
                        if(!isdigit(entryLine[i]))
                            i++;
                        npos = i;               
                        ADDCHARENTRY = 1;
                    }
                }    
            }
        break;
        case '\'':
            ADDCHARENTRY = 1;
        break;
        case 1075://LEFT
            if(iStack == -1){
                iPosLine--;
                if(iPosLine < 0)
                    iPosLine = 0;
                iPosCur--;
                if(iPosCur < 0)
                    iPosCur = 0;    
            }
        break;
        case 1077://RIGHT
            if(iStack == -1){
                iPosLine++;
                if(iPosLine >= iMaxLine)
                    iPosLine = iMaxLine;
                iPosCur++;
                if(iPosCur > iPosLine)
                    iPosCur = iPosLine;
                if(iPosCur == 10)
                    iPosCur = 9;    
            }
        break;
        case 1072://UP
            iStack++;
            if(iStack == iStackMax)
                iStack = iStackMax-1;
            REFRESHSTACK = 1;    
        break;
        case 1080://DOWN
            iStack--;
            if(iStack < -1)
                iStack = -1;
            REFRESHSTACK = 1;    
        break;
        case 1082://INSERT
            if(iStack > 0){
                auxf = valuesStack[iStack];
                for(i=iStack; i>0; i--)
                    valuesStack[i] = valuesStack[i-1];
                valuesStack[0] = auxf;    
                iStack = 0;
                REFRESHSTACK = 1;    
            }
        break;
        case 1083://DELETE
            if(iPosLine != iMaxLine){
                for(i=iPosLine; i<1023; i++)
                    entryLine[i] = entryLine[i+1];
                entryLine[1023] = '\0';    
                iMaxLine--;
            }
        break;
        case '+':
        case '-':
        case '*':
        case '/':
            if(ALGMODE)
                ADDCHARENTRY = 1;
            else{
                if(entryLine[0] == '\0'){
                    if(iStackMax < 2){
                        statusLine[5] = 'e'; 
                        statusLine[6] = 'M';
                        statusLine[7] = 'O';
                        break;
                    }    
                    else{
                        ope1 = valuesStack[1];
                        ope2 = valuesStack[0];
                        if(opt=='/' && ope1==0.0){
                            statusLine[5] = 'e';
                            statusLine[6] = 'D';
                            statusLine[7] = '0';
                            break;
                        }
                        for(i=1; i<10; i++)
                            valuesStack[i] = valuesStack[i+1];
                        valuesStack[9] = 0.0;
                        iStackMax--;    
                    }            
                }
                else{
                    auxf = strtod(entryLine, &endptr);
                    if(*endptr != NULL){
                        statusLine[5] = 'e';
                        statusLine[6] = 'C';
                        statusLine[7] = *endptr;
                        break;
                    }
                    if(opt=='/' && auxf==0.0){
                        statusLine[5] = 'e';
                        statusLine[6] = 'D';
                        statusLine[7] = '0';
                        break;
                    }
                    ope1 = valuesStack[0];
                    ope2 = auxf; 
                }
                switch(opt){
                    case '+':
                        ope1 += ope2;
                    break;
                    case '-':
                        ope1 -= ope2;
                    break;
                    case '*':
                        ope1 *= ope2;
                    break;
                    case '/':
                        ope1 /= ope2;
                    break;
                }
                valuesStack[0] = ope1;
                memset(entryLine, '\0', 1024);
                iPosCur = 0;
                iPosLine = 0;
                iMaxLine = 0;    
                REFRESHSTACK = 1;    
            }    
        break;
        default:
            if(iStack != -1)
                break;
            if(isdigit(opt) || opt=='e' || opt=='(' || 
               opt==')' || opt=='.'){
                ADDCHARENTRY = 1;
            }
    }
    
    if(ADDCHARENTRY){
        if(npos == -1){
            memcpy(&entryLine[iPosLine+1], &entryLine[iPosLine], 1023-iPosLine);
            entryLine[iPosLine] = opt;
        }    
        else{    
            memcpy(&entryLine[npos+1], &entryLine[npos], 1023-npos);
            entryLine[npos] = '-';
        }
        
        iPosLine++;
        iMaxLine++;
        if(iPosLine > iMaxLine)
            iPosLine = iMaxLine;    
        if(iMaxLine > 1024)
            iMaxLine = 1024;
        iPosCur++;
        if(iPosCur == 10)
            iPosCur = 9;
    }

    iS1 = 0;
    if(iStack > 3)
        iS1 = iStack-3;
      
    SetPixelChar(219);
    for(i=0; i<4; i++){
        SetPixelColor(LIGHTGRAY);
        if(iS1 >= iStackMax)
            PutTextOnDisplay(0, (3-i)*8, "          ", 10);
        else{
            if(iStack == iS1){
                SetPixelColor(YELLOW);
            }    
            sprintf(auxStr, "%10g", valuesStack[iS1++]);
            PutTextOnDisplay(0, (3-i)*8, auxStr, 10);
        }    
    }
    SetPixelColor(LIGHTGRAY);
    if(iStack > -1){
        statusLine[8] = 's';
        if(iStackMax>3 && (iStack+1)!=iStackMax)
            statusLine[1] = '\x1E';
        if(iStack > 3)
            statusLine[2] = '\x1F';    
    }
    Line(1, 32, 79, 32);    
    if(entryLine[0] == '\0')
        PutTextOnDisplay(0, 41, "          ", 10);
    else{        
        i = iPosLine - (iPosCur%10);    
        if((i+10) <= iMaxLine)
            statusLine[9] = '\x10';
        if(i > 0)    
            statusLine[0] = '\x11';
        PutTextOnDisplay(0, 41, &entryLine[i], 10);
    }  
    if(entryLine[0] == '\'')
        statusLine[3] = 'A';
    PutTextOnDisplay(0, 33, statusLine, 10);
    Line((iPosCur%10)*8, 48, (iPosCur%10)*8+8, 48);      
    if(REFRESHSTACK)
        RefreshDisplay(0, 0, 49, 79);
    else
        RefreshDisplay(33, 0,  49, 79); 
    REFRESHSTACK = 0;           
}

int SolveSimpleA(char *oprs, int noprs, double *opds, int nopds, double *result){
    int i, l;
    int r;
    
    //*,/
    if((nopds-noprs) != 1)
        return 0;
    for(i=0; i<noprs; i++){
        r = 0;    
        if(oprs[i] == '*'){
            opds[i] *= opds[i+1];
            r = 1; 
        }    
        if(oprs[i] == '/'){
            if(opds[i+1] == 0.0)
                return -1;
            opds[i] /= opds[i+1];
            r = 1; 
        }
        
        if(r == 1){
            for(l=i; l<noprs-1; l++)
                oprs[l] = oprs[l+1];
            for(l=i+1; l<nopds-1; l++)
                opds[l] = opds[l+1];
           noprs--;
           nopds--;
           i = -1;     
        }
    } 
    //+,-
    for(i=0; i<noprs; i++){
        r = 0;    
        if(oprs[i] == '+'){
            opds[i] += opds[i+1];
            r = 1; 
        }    
        if(oprs[i] == '-'){
            opds[i] -= opds[i+1];
            r = 1; 
        }
        
        if(r == 1){
            for(l=i; l<noprs-1; l++)
                oprs[l] = oprs[l+1];
            for(l=i+1; l<nopds-1; l++)
                opds[l] = opds[l+1];
           noprs--;     
           nopds--;
           i = -1;     
        }
    } 
    
    *result = opds[0];
    
    return 1;   
}


int SolveExpresion(const char *expresion, double *result){
    int l, i, j, noprs, nopds;
    char oprs[512];
    double opds[512] = {0.0};
    char *endptr;
    char numStr[24];
    int inumStr;
    int pL, pD;
    int addNum;
    
    l = strlen(expresion);
    if(l < 3)
        return 0;
        
    if(expresion[0]!='\'' || expresion[l-1]!='\'')
        return 0;
    
    inumStr = 0;
    noprs = 0;
    nopds = 0;
    pL = 0;
    for(i=1; i<1024 && i<l; i++){
        addNum = 0;
        if(expresion[i]>127)
            return 0;
        if(isdigit(expresion[i]) || expresion[i]=='.')
            numStr[inumStr++] = expresion[i];
        if(expresion[i]=='e'){
            if(isdigit(expresion[i-1]) || expresion[i-1]=='.')
                numStr[inumStr++] = expresion[i];
            else
                return -i;    
        }                
            
        if(expresion[i]=='('){
            if(isdigit(expresion[i-1]) || expresion[i-1]=='e' || expresion[i-1]=='.')
                return -i;
            if(inumStr){
                opds[nopds] = 1.0;
                if(numStr[inumStr - 1] == '-')
                    opds[nopds] *= -1.0;
                nopds++;
                oprs[noprs++] = '*';
                inumStr = 0;    
            }
            oprs[noprs++] = expresion[i] | 0x80;
            nopds++;
        }
        if(expresion[i]==')' || expresion[i]=='*' || expresion[i]=='/' || expresion[i]=='\''){
            if(!(isdigit(expresion[i-1]) || expresion[i-1]==')'))
               return -i;
            if(expresion[i] != '\'')   
                oprs[noprs++] = expresion[i];
            addNum = 1;
        }
            
        if(expresion[i]=='+' || expresion[i]=='-'){
            if(isdigit(expresion[i-1]) || expresion[i-1]==')'){
                oprs[noprs++] = expresion[i];
                addNum = 1;
            }    
            else{
                if(inumStr==0 || expresion[i-1]=='e')
                    numStr[inumStr++] = expresion[i];
                else{
                    if(expresion[i] == '-'){
                        if(numStr[inumStr-1] == '-')
                            numStr[inumStr-1] = '+';
                        else
                            numStr[inumStr-1] = '-';     
                    }
                }
            }
        }         
        
        if(addNum){
            if(inumStr != 0){
                numStr[inumStr] = '\0';
                opds[nopds++] = strtod(numStr, &endptr);
                if(*endptr != NULL)
                    return -i;
                inumStr = 0;    
            }
        }
    }
    
    for(i=0; i<noprs; i++){
        if((oprs[i] & 0x7F) == '('){
            pL = i+1;
            j = 0;
        }    
        if(oprs[i] == ')'){
            j++;
            pD = i-pL;    
            if((j-pD) != 1)
                return 0;

            if(SolveSimpleA(&oprs[pL], pD, &opds[pL], j, result) == 0)
                return 0;
            
            opds[pL-1] = *result;
                
            memmove(&oprs[pL-1], &oprs[i+1], 512-(i+1));
            memmove(&opds[pL], &opds[i+1], 512-(i+1));
            noprs -= (j+1);
            nopds -= j;
            
            i = 0;
            j = 0;
            pL = 0;
            continue;            
        }
        if(!(oprs[i] & 0x80))
            j++;
    }
    
    if(nopds == 1){
        *result = opds[0];
        return 1;
    }
    
    if(noprs!=0 && pL==0){
        if(SolveSimpleA(oprs, noprs, opds, nopds, result) == 0)
            return 0;
    }
    else
        return 0;

    return 1;
}

//.




int main()
{
    struct time hora;
    short opt;
    int x, y, i, j, k, l;
    unsigned char c, mode;
    int timeOutScreen;
    float angr;
    
    textmode(C4350);
    _setcursortype(_NOCURSOR);
    
    mode = MODEWATCH;
    flag1.byte = 0;
    timeOutScreen = 0;
    FROMWATCH = 1;
    
    Delay(1, 200);
    while(1){
        opt = 0;
        if(kbhit()){
            opt = getch();
            if(opt == 0)
                opt  = getch() + 1000;
            
            if(opt == 27)
                break;
                
            mode = MODECALC;
        }
        
        IS200MS = 0;
        if(Delay(0, 200)){
            IS200MS = 1;
            if(timeOutScreen){
                timeOutScreen--;
                if(!timeOutScreen){
                    mode = MODEWATCH;
                    FROMWATCH = 1;
                }
            }
        }    
        
        switch(mode){
            case MODEWATCH:
                if(CIRCLEWATCH == 0){
                    SetPixelChar(' ');
                    FillDisplay(0, 0, 49, 79);
                }
                if(IS200MS){
                    SetPixelChar(' ');
                    if(CIRCLEWATCH)
                        FillDisplay(0, 16, 47, 62);
                    gettime(&hora);
                    SetPixelChar(219);
                    SetPixelColor(YELLOW);
                    Circle(22, 39, 24);
                    if(hora.ti_hour>12)
                        hora.ti_hour -= 12;
                    angr = (hora.ti_hour*30+(hora.ti_min/20)*10-90)*M_PI/180;
                    x = 39+floor(12*cos(angr)+0.5);
                    y = 24+floor(12*sin(angr)+0.5);
                    Line(39, 24, x, y); 
                    angr = (hora.ti_min*6+floor((hora.ti_sec/20)*2.0)-90)*M_PI/180;
                    x = 39+18*cos(angr);
                    y = 24+18*sin(angr);
                    Line(39, 24, x, y); 
                    angr = (hora.ti_sec*6+(hora.ti_hund/20)*1.2-90)*M_PI/180;
                    x = 39+floor(21*cos(angr)+0.5);
                    y = 24+floor(21*sin(angr)+0.5);
                    SetPixelColor(LIGHTGRAY);
                    Line(39, 24, x, y); 
                    if(CIRCLEWATCH)
                        RefreshDisplay(0, 0, 49, 79);
                    else    
                        RefreshDisplay(0, 16, 47, 62);
                
                }
                CIRCLEWATCH = 1;
            break;
            case MODECALC:
                if(opt){
                    timeOutScreen = 50;
                    DoCalc(opt);
                }
            break;
        }    
    }


	return 0;	
}