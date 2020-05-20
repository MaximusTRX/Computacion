#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<dos.h>
#include<string.h>

int delay(int opt, int ms);
void CALCULADORA();

int main(){

    while (1)
    {
        CALCULADORA();
    }
    return 0;
}

void CALCULADORA(){
    static char Entrada[1024];
    static float Stack[10];
    int posIn = 0;
    int posSt = 0;
    unsigned char key, x = 1;
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
                    gotoxy(x, 43);
                    cprintf("%c", Entrada[cont]);
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
                    float convert[k];
                    
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
        

        char out[1024];
        char posStX, posStY = 34;
        
        // if (posSt != 0)
        // { 
            for (char j = (posSt-1); j >= 0; j--)
            {
                posStX = 72;
                posStY-=8;
                sprintf(out, "%10g", Stack[j]);

                for (char i = 10; i > 0; i--)
                {
                    gotoxy(posStY, posStY);
                    cprintf("%c", out[i]);
                    posStX-=8;
                }
            }
        //}

        if (delay(2, (10*1000)))//Compruebo tiempo transcurrido
        {
            clrscr();
            return;
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