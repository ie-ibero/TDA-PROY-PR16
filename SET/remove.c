/*@file  remove.c
*
*@brief Este modulo contine la funcion de remove. Elimina un determinado
*		elemento (objeto) de la coleccion. Devuelve valor despues de la 
*		operacion. Recibe valores del puntero y nodo auxiliar.
*
*@autor Avila Cortes Karina
*@date  28/04/2016
*/

/**
*@brief     Esta funcion ejecuta el proceso de removes.
*
*@variables arbol *auxiliar  : Nodo temporal para recorrer arbol y eliminar nodo.
*
*@autor     Avila Cortes Karina
*/
#include "biblioteca.h"

extern void cambioNodo(arbol **ptr, arbol **auxiliar);

void removes(arbol **ptr, int elemento) {
	
	arbol *auxiliar;

	if (*ptr == NULL) {
		return;
	}
	
	if ((*ptr)->idArbol < elemento) {
		removes(&(*ptr)->derecha, elemento);
	}
	else if ((*ptr)->idArbol > elemento) {
		removes(&(*ptr)->izquierda, elemento);
	}
	else if ((*ptr)->idArbol == elemento) {
		auxiliar = *ptr;
		
		if ((*ptr)->izquierda == NULL) {
			*ptr = (*ptr)->derecha;
		}
		else if ((*ptr)->derecha == NULL) {
			*ptr = (*ptr)->izquierda;
		}
		//reemplaza al nodo para tomar el lugar del mayor y recorre rama
		else {
			cambioNodo(&(*ptr)->izquierda, &auxiliar);
		}
		
		free(auxiliar);
  	}	
}