#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){

    float R = 1.2;
    float r = 0.03;
    float time = 0;
    
    //printf("Ingrese el radio mayor: ");
    //scanf("%f", &R);

    //printf("\nIngrese el radio menor: ");
    //scanf("%f", &r);


    time = (14.0/15)*(pow(R,(5.0/2))/(pow(r,2*(pow(2*9.81,(1.0/2))))));

    printf("\nEl tiempo transcurrido hasta escurrir su contenido = %f\n", time);

    system("PAUSE");
    return 0;
}