/*@file  cambioNodo.c
*
*@brief Este modulo contine la funcion de cambioNodo. Es un nodo temporal para
*		recorrer arbol y eliminar posteriormente el nodo, cambiandolo por el mayor
*		de los menores nodos.
*
*@autor Avila Cortes Karina
*@date  28/04/2016
*/

/**
*@brief     Esta funcion ejecuta el proceso de cambioNodo.
*
*@autor     Avila Cortes Karina
*/
#include "biblioteca.h"

void cambioNodo(arbol **ptr, arbol **auxiliar) {
	
	if ((*ptr)->derecha != NULL) {
		cambioNodo(&(*ptr)->derecha, auxiliar);
	}
  	else {
    	(*auxiliar)->idArbol = (*ptr)->idArbol;
    	*auxiliar = *ptr;
    	*ptr = (*ptr)->izquierda;
  	}
}