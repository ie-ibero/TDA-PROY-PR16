/*@file  verColeccion.c
*
*@brief Este modulo contine la funcion de verColeccion. Muestra las ramas
*		del arbol en pre orden.
*
*@autor Avila Cortes Karina
*@date  28/04/2016
*/

/**
*@brief     Esta funcion ejecuta el proceso de verColeccion.
*
*@autor     Avila Cortes Karina
*/
#include "biblioteca.h"

void verColeccion(arbol *ptr) {

	if (ptr != NULL) {
	    printf("%d\n", ptr->idArbol); //dato
	    verColeccion(ptr->izquierda);
	    verColeccion(ptr->derecha);
  	}
}