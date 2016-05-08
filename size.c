/*@file  size.c
*
*@brief Este modulo contiene la funcion de size. Nos devuelve el número de
*		elementos que contiene la colección.
*
*@autor María Fernanda Corona Haneine
*@date  04/05/2016
*/

/**
*@brief     Esta funcion ejecuta el proceso de size.
*
*@autor     María Fernanda Corona Haneine
*/
#include "biblioteca.h"

int size(arbol *ptr, int *count) {
    
    if (ptr != NULL) {
        size(ptr->izquierda, count);
        *count = *count+1;
        size(ptr->derecha, count);
    }
}


/* @brief Este modulo contiene la funcion de sizeB. Nos devuelve el número de 
*		  elementos que contiene la colección. Aplica en el conjunto B.
*
*@autor María Fernanda Corona Haneine
*@date  06/05/2016
*/

/**
*@brief     Esta funcion ejecuta el proceso de sizeB.
*
*@autor     María Fernanda Corona Haneine
*/

int sizeB(arbolB *ptrB, int *countB) {
    
    if (ptrB != NULL) {
        sizeB(ptrB->izquierdaB, countB);
        *countB = *countB+1;
        sizeB(ptrB->derechaB, countB);
    }
}