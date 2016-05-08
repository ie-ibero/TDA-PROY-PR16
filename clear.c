/*@file  clear.c
*
*@brief Este modulo contiene la funcion de clear. Libera el espacio de memoria 
ocupado por el arbol al final de la ejecucion.
*
*@autor María Fernanda Corona Haneine
*@date  04/05/2016
*/

/**
*@brief     Esta funcion ejecuta el proceso de clear.
*
*@autor     María Fernanda Corona Haneine
*/

#include "biblioteca.h"

void clear(arbol **ptr) {
    if(*ptr != NULL) {
    	clear(&(*ptr)->derecha);
        clear(&(*ptr)->izquierda);
        free(*ptr);
    }
}

/* @brief Este modulo contiene la funcion de clearB. Libera el espacio de memoria 
ocupado por el arbol al final de la ejecucion. Aplica para el conjunto B.
*
*@autor María Fernanda Corona Haneine
*@date  06/05/2016
*/

/**
*@brief     Esta funcion ejecuta el proceso de clearB.
*
*@autor     María Fernanda Corona Haneine
*/

void clearB(arbolB **ptrB) {
    if(*ptrB != NULL) {
    	clearB(&(*ptrB)->derechaB);
        clearB(&(*ptrB)->izquierdaB);
        free(*ptrB);
    }
}