/*funcion  toArray.c
 *
 *@brief La funcion de toArray, nos devuelve un conjunto, almacenado en un arreglo de elementos (tipo cadena de caracteres).
 *
 *@autor María Fernanda Corona Haneine
 *@date  04/05/2016
 */

/**
 *@brief     Esta funcion ejecuta el proceso de toArray.
 *
 *@autor     María Fernanda Corona Haneine
 */

#include "biblioteca.h"

char toArray(conjunto *ptr, char array[]) {
    
    if (ptr != NULL) {
        toArray(ptr->izquierda, array);
        strcat(array, ptr->idConjunto); //dato
        toArray(ptr->derecha, array);
        printf("%s\n", array);
    }
    return t;
}

/*funcion  clear.c
 *
 *@brief La funcion de clear, limpia todo el contenido de un conjunto.
 *
 *@autor María Fernanda Corona Haneine
 *@date  04/05/2016
 */

/**
 *@brief     Esta funcion ejecuta el proceso de clear.
 *
 *@autor     María Fernanda Corona Haneine
 */


void clear(conjunto **ptr) {
    if(*ptr != NULL) {
        clear(&(*ptr)->derecha);
        clear(&(*ptr)->izquierda);
        free(*ptr);
    }
}

/*funcion  size.c
 *
 *@brief La funcion de size, nos devuelve el número de
 *		elementos que contiene el conjunto.
 *
 *@autor María Fernanda Corona Haneine
 *@date  04/05/2016
 */

/**
 *@brief     Esta funcion ejecuta el proceso de size.
 *
 *@autor     María Fernanda Corona Haneine
 */

void size(conjunto *ptr, int *count) {
    
    if (ptr != NULL) {
        size(ptr->izquierda, count);
        *count = *count+1;
        size(ptr->derecha, count);
    }
}
