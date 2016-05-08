/*@file  toArray.c
*
*@brief Este modulo contiene la funcion de toArray. Nos devuelve
*		la colección de elementos como un array de objetos.
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

char toArray(arbol *ptr, char array[]) {
    
    if (ptr != NULL) {
        toArray(ptr->izquierda, array);
        strcat(array, &ptr->idArbol); //dato
        toArray(ptr->derecha, array);
        printf("%c\n", array);
    }
    return TRUE;
}

/* @brief Este modulo contiene la funcion de toArrayB. Nos devuelve
*		la colección de elementos como un array de objetos. Aplica en el 
*		conjunto B
*
*@autor María Fernanda Corona Haneine
*@date  06/05/2016
*/

/**
*@brief     Esta funcion ejecuta el proceso de toArrayB.
*
*@autor     María Fernanda Corona Haneine
*/


char toArrayB(arbolB *ptrB, char arrayB[]) {
    
    if (ptrB != NULL) {
        toArrayB(ptrB->izquierdaB, arrayB);
        strcat(arrayB, &ptrB->idArbolB); //dato
        toArrayB(ptrB->derechaB, arrayB);
        printf("%c\n", arrayB);
    }
    return TRUE;
}