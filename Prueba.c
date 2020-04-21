#include <stdio.h>
int main(void)
{
    int *p, **pp, i = 10, j = 20;
    p = &i;
    pp = &p;
    **pp += 100;
    p = &j;
    **pp += 100;
    
    printf("%d\n", i+j);
    return 0;
}