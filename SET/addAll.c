/*@file  addAll.c
*
*@brief Este modulo contine la funcion de addAll. Se añaden elementos al final
*		del conjunto conforme el usuario ingrese valores para cada nodo..Recibe
*		valores del puntero y elemento numerico.
*
*@autor Avila Cortes Karina
*@date  28/04/2016
*/

/**
*@brief     Esta funcion ejecuta el proceso de addAll.
*
*@autor     Avila Cortes Karina
*/

#include "biblioteca.h"

void addAll(arbol **ptr, int elemento) {

	//Si el puntero esta vacio, se crea el arbol.
	if (*ptr == NULL) {
	    *ptr = (arbol *) malloc(sizeof(arbol));
	    (*ptr)->idArbol = elemento;
	    //Asegura ramas igual a null.
	    (*ptr)->izquierda = (*ptr)->derecha = NULL;
  	}
  	//verifica que lugar del nodo sea menor al elemento y lo coloca en rama derecha
	else if ((*ptr)->idArbol < elemento) {
		addAll(&(*ptr)->derecha, elemento);
	}
	//permite que se repitan los elementos
	else if ((*ptr)->idArbol == elemento) { 
		addAll(&(*ptr)->derecha, elemento);
	}
	//verifica que lugar del nodo sea mayor al elemento y lo coloca en rama izq
	else if ((*ptr)->idArbol > elemento) {
		addAll(&(*ptr)->izquierda, elemento);
	}
}