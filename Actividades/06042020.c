#include<stdio.h>
#include <string.h>
#include"conio.h"

int main()
{
       random
    typedef struct 
    {
        unsigned char id;
        char nombre[50];
        char telefono[16];
    }agenda;
    

    do
    {

        agenda lista[10], aux[10];
        char entrada, id = 0, edit = 0, mov = 0, delete;
        do
        {
            printf("\n\n[F1] Agregar\n");
            printf("[F2] Eliminar\n");
            printf("[F3] Editar\n");
            printf("[IZQ][DER]\n");
            
            fflush(stdin);
            entrada = getch();

            if (entrada == 0)
            {
                entrada = getch();
                switch (entrada)
                {
                case 59://F1
                    if (id < 11)
                    {
                        printf("ID: %2d\n", id+1);
                        lista[id].id = id;
                        printf("Ingrese Nombre: ");
                        fflush(stdin);
                        gets(lista[id].nombre);
                        fflush(stdin);
                        printf("\nIngrese Telefono: ");
                        gets(lista[id].telefono);
                        id++;
                    }else
                    {
                        printf("\nTodos los registros estan cargados\n");
                    }
                    
                    break;
                
                case 60://F2
                    do
                    {
                        printf("Seleccione ID a eliminar: ");
                        scanf("%u%*c", &delete);
                    } while (delete > 10);
                    
                    unsigned char j=0;
                    for (unsigned char i = 0; i < 10; i++){
                        if (i != (delete-1))
                        {
                            aux[j].id = j;
                            strcpy(aux[j].nombre,lista[i].nombre);
                            strcpy(aux[j].telefono,lista[i].telefono);
                            j++;
                        }
                    }

                    for (unsigned char l = 0; l < 10; l++)
                    {
                        lista[l].id = l;
                        strcpy(lista[l].nombre,aux[l].nombre);
                        strcpy(lista[l].telefono,aux[l].telefono);
                    }
                    break;
                
                case 61://F3
                    do
                    {
                        printf("Seleccione ID a modificar: ");
                        scanf("%u%*c", &edit);
                    } while (edit > 10);

                    printf("ID: %2u\n", edit);
                    printf("Ingrese Nombre: ");
                    fflush(stdin);
                    gets(lista[edit-1].nombre);
                    printf("\nIngrese Telefono: ");
                    fflush(stdin);
                    gets(lista[edit-1].telefono);
                    break;
                
                case 77://DER
                    if (mov >= id)
                    {
                        mov = 0;
                    }
                    printf("ID: %u | Nombre: %s | Telefono %16s \n", lista[mov].id, lista[mov].nombre, lista[mov].telefono);
                    mov++;
                    break;

                case 75://IZQ
                    if (mov == -1)
                    {
                        mov = id;
                    }
                    
                    printf("ID: %u | Nombre: %s | Telefono %16s \n", lista[mov].id, lista[mov].nombre, lista[mov].telefono);
                    mov--;
                    break;
                }
            }
        } while (entrada != 27);
        printf("\n\n-Presione cualquier tecla para volver a ejecutar");
        printf("\n-Presione ESCAPE para finalizar\n");
    } while (getch() != 27);
    return 0;
}