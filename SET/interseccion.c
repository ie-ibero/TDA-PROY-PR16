/*@file  interseccion.c
*
*@brief Este modulo contiene la funcion de interseccionConjunto. Muestra los
* 		valores que se repiten entre los conjuntos A y B.
*
*@autor Avila Cortes Karina
*@date  28/04/2016
*/

/**
*@brief     Esta funcion ejecuta el proceso de interseccionConjunto.
*
*@autor     Avila Cortes Karina
*/

#include "biblioteca.h"

void interseccionConjunto(conjunto *ptr, conjuntoB *ptrB) {

	 if ((ptr != NULL) && (ptrB != NULL))  {
			
			unionConjunto(ptr->izquierda, ptrB->izquierdaB);
			unionConjunto(ptr->derecha, ptrB->derechaB);


	 	if (ptr->idconjunto == ptrB->idconjuntoB) {
	 		//printf("%c\n%c\n", ptr->idconjunto, ptrB->idconjuntoB);
	 		printf("%c\n", ptr->idconjunto);
			
	 		}
			
	 	}

}
