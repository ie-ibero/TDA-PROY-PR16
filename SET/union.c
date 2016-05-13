/*@file  union.c
*
*@brief Este modulo contiene la funcion de unionConjunto.  Muestra todos los 
*		elementos contenidos en los conjuntos A y B sin repetirse.
*
*@autor Avila Cortes Karina
*@date  28/04/2016
*/

/**
*@brief     Esta funcion ejecuta el proceso de unionConjunto.
*
*@autor     Avila Cortes Karina
*/

#include "biblioteca.h"

void unionConjunto(conjunto *ptr, conjuntoB *ptrB) {

	if ((ptr != NULL) && (ptrB != NULL))  {

	 	printf("%c\n%c\n", ptr->idconjunto, ptrB->idconjuntoB);
		unionConjunto(ptr->izquierda, ptrB->izquierdaB);
	 	unionConjunto(ptr->derecha, ptrB->derechaB);		
			
	 	}


}
