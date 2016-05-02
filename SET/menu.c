/*@file  menu.c
*
*@brief Este modulo contine la funcion menu. Muestra la parte interactiva con
*       el usuario proporcionandole un menu que despliega las opciones que el
*       usuario puede elegir para realizar una accion.
*
*@autor Avila Cortes Karina
*@date  28/04/2016
*/

/**
*@brief     Esta funcion ejecuta el proceso del menu.
 *
 *@variables int opcion : recibe entrada del usuario. Se inicializa en 0.
 *
 *@return    int opcion : regresa valor del menu.
 *
 *@autor     Avila Cortes Karina
 */
#include "biblioteca.h"

int menu(void) {
    int opcion = 0;
    do {
        printf("\n---------\n");
        printf("Menu\n");

        printf("\n1- Operaciones\n2- AddAll\n3- Ver coleccion\n4- Salir\n\n");
        //Valida que la entrada del usuario solo sea un caracter numerico.
        if(scanf("%d",&opcion)!=1) {
            printf("Error: Opcion debe ser numerica\n");
            system("clear");
        }
        printf("----- %d \n\n",opcion);
        while(getchar()!='\n');
    } while(opcion == 0);   
    return opcion;
}
