/*@file  contains.c
*
*@brief Este modulo contine la funcion de contains. Muestra si los elementos
* 		pertenecen al conjunto. Recorre el array hasta encontrarlo. Devuelve
*		true si se encuentra o false si no. Recibe valores del puntero y 
*		elemento numerico.
*
*@autor Avila Cortes Karina
*@date  28/04/2016
*/

/**
*@brief     Esta funcion ejecuta el proceso de contains.
*
*@return    boolean TRUE : Devuelve valor verdadero si existe elemento en el arbol.
*           boolean FALSE : Devuelve valor falso si no existe elemento en el arbol.
*
*@autor     Avila Cortes Karina
*/
#include "biblioteca.h"

int contains(arbol *ptr, int elemento) {

  int contadorRamas_der = 0;
  int contadorRamas_izq = 0;

	if (ptr == NULL) {
		printf("No existe en el arbol\n");
		return FALSE; //No existe elemento en el arbol
	}

	//Si existe elemento en el arbol, verifica en que rama
  	else if (ptr->idArbol < elemento) {
      printf("Derecha: %d\n", ptr->idArbol);
  		return contains(ptr->derecha, elemento);
  	}
  	else if (ptr->idArbol > elemento) {
      printf("Izquierda: %d\n", ptr->idArbol);
  		return contains(ptr->izquierda, elemento);
  	}
  	else {
  		printf("Existe el %d\n", elemento);
      return TRUE;
  	}
}
