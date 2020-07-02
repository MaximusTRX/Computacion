#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct
{
    unsigned char pos;          //Posicion donde cargar el proximo valor
    unsigned char dataSize;     //Tamaño de cada dato en el arreglo buf
    unsigned char dataCount;    //Tamaño del buffer
    unsigned char *buf;         //Buffer de almacenamiento
}pilaData;

void pilaInit(pilaData *p, void *buffer, unsigned char bufLen, unsigned char dataSize);
void pilaPush(pilaData *p, void *data);
void pilaPop(pilaData *p, void *data);
unsigned char pilaEmpty(pilaData*p);
unsigned char pilaFull(pilaData *p);
void IntToStr(int Value, char *strValue);


int main()
{
    return 0;
}
void pilaInit(pilaData *p, void *buffer, unsigned char bufLen, unsigned char dataSize){
    p->dataSize = dataSize;
    p->dataCount = bufLen;
    p->pos = 0;
    p->buf = (unsigned char *)malloc(bufLen*dataSize);
}

void pilaPush(pilaData *p, void *data){
    for (int i = 0; i < p->dataSize; i++)
    {
        p->buf[p->pos++] = *((unsigned char *)data + i);
    }
}

void pilaPop(pilaData *p, void *data){
    p->pos -= p->dataSize;
    for (int i = 0; i < p->dataSize; i++)
    {
        *((unsigned char *)data+i) = p->buf[p->pos++];
    }
    p->pos -= p->dataSize;
}

void pilaPop(pilaData *p, void *data){
    p->pos -= p->dataSize;
    for (int i = 0; i < p->dataSize; i++)
    {
        *((unsigned char *)data+i) = p->buf[p->pos++];
    }
    p->pos -= p->dataSize;
    
}

unsigned char pilaEmpty(pilaData*p){
    return (p->pos == 0);
}

unsigned char pilaFull(pilaData *p){
    return(p->pos == (p->dataSize*p->dataCount));
}

void IntToStr(int Value, char *strValue){
    pilaData strInt;
    char aux;

    pilaInit(&strInt, 12, sizeof(char));
    aux = '\0';
    pilaPush(&strInt, &aux);
    for (int i = 0; Value != 0; i++)
    {
        aux = Value%10;
        pilaPush(strInt, &aux);
        Value /= 10;
    }
    
}
