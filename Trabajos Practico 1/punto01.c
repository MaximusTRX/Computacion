#include<stdio.h>
#include<stdlib.h>

int main()
{

    int var1 = 5, var2 = 2;

    printf("\nEl valor de la suma es: %d", var1+var2);
    printf("\nEl valor de la diferencia es: %d", var1-var2);
    printf("\nEl valor del producto es: %d", var1*var2);
    printf("\nEl valor de la divicion exacta es: %.2f", (var1*1.0)/var2);
    printf("\nEl valor del resto de la divicion es: %d\n", var1%var2);

    system("PAUSE");
    return 0;
}
