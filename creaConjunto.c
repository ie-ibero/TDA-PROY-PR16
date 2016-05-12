/*@file  creaConjunto.c
*
*@brief La funcion de creaConjunto, crea el conjunto de acuerdo
*		a la estructura llamada conjunto, esta la obtiene de biblioteca.h e inicializa
*		su puntero en 0. Recibe valor del puntero.
*
*@autor Avila Cortes Karina
*@date  28/04/2016
*/

/**
*@brief     Esta funcion ejecuta el proceso de creaArbol.
*
*@variables conjunto *ptr  : Puntero de la estructura arbol.
*
*@autor     Avila Cortes Karina
*/

#include "biblioteca.h"

void creaConjunto(conjunto **ptr) {

	//Inicializa arbol en 0
	*ptr = NULL;
}

/*@funcion  addAll.c
 *
 *@brief La funcion de addAll añade elementos al final
 *		del conjunto conforme el usuario ingrese valores para cada nodo
 *
 *@autor Avila Cortes Karina
 *@date  28/04/2016
 */

/**
 *@brief     Esta funcion ejecuta el proceso de addAll.
 *
 *@autor     Avila Cortes Karina
 */

void addAll(conjunto **ptr, char elemento[]) {
    
    //Si el puntero esta vacio, se crea el arbol.
    if (*ptr == NULL) {
        *ptr = (conjunto *) malloc(sizeof(conjunto));
        strcmp(((*ptr)->idConjunto, elemento)=0));
        //Asegura ramas igual a null.
        (*ptr)->izquierda = (*ptr)->derecha = NULL;
    }
    //verifica que lugar del nodo sea menor al elemento y lo coloca en rama derecha
    else if ((strcmp((*ptr)->idConjunto,elemento))<0) {
        addAll(&(*ptr)->derecha, elemento);
    }
    //permite que se repitan los elementos
    else if (strcmp((*ptr)->idConjunto,elemento)=0) {
        //addAll(&(*ptr)->derecha, elemento);
        printf("Error: Este valor ya existe.\n");
    }
    //verifica que lugar del nodo sea mayor al elemento y lo coloca en rama izq
    else if (strcmp((*ptr)->idConjunto, elemento)>0) {
        addAll(&(*ptr)->izquierda, elemento);
    }
}

/*@funcion  cambioNodo.c
 *
 *@brief La funcion de cambioNodo, genera un nodo temporal para
 *		recorrer el conjunto y eliminar posteriormente el nodo, cambiandolo por el mayor
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

void cambioNodo(conjunto **ptr, conjunto **auxiliar) {
    
    if ((*ptr)->derecha != NULL) {
        cambioNodo(&(*ptr)->derecha, auxiliar);
    }
    else {
        (*auxiliar)->idArbol = (*ptr)->idArbol;
        *auxiliar = *ptr;
        *ptr = (*ptr)->izquierda;
    }
}

/*@funcion  contains.c
 *
 *@brief La funcion de contains, muestra si los elementos
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
 *@return    boolean t=1 : Devuelve valor verdadero si existe elemento en el arbol.
 *           boolean f=0 : Devuelve valor falso si no existe elemento en el arbol.
 *
 *@autor     Avila Cortes Karina
 */


int contains(conjunto *ptr, char elemento[]) {
    
    int contadorRamas_der = 0;
    int contadorRamas_izq = 0;
    
    if (ptr == NULL) {
        printf("No existe en el arbol\n");
        return f; //No existe elemento en el arbol
    }
    
    //Si existe elemento en el arbol, verifica en que rama
    else if (strcmp(ptr->idConjunto , elemento)<0) {
        //printf("Derecha: %d\n", ptr->idArbol);
        return contains(ptr->derecha, elemento);
    }
    else if (strcmp(ptr->idConjunto , elemento)>0) {
        //printf("Izquierda: %d\n", ptr->idArbol);
        return contains(ptr->izquierda, elemento);
    }
    else {
        printf("Existe %c\n", elemento);
        return t;
    }
}

/*@funcion  remove.c
 *
 *@brief La funcion de removes, elimina un determinado
 *		elemento (objeto) del conjunto. Devuelve valor despues de la
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

extern void cambioNodo(conjunto **ptr, conjunto **auxiliar);

void removes(conjunto **ptr, char elemento) {
    
    arbol *auxiliar;
    
    if (*ptr == NULL) {
        return;
    }
    
    if (strcmp((*ptr)->idConjunto , elemento)<0) {
        removes(&(*ptr)->derecha, elemento);
    }
    else if (strcmp((*ptr)->idConjunto , elemento)>0) {
        removes(&(*ptr)->izquierda, elemento);
    }
    else if (strcmp((*ptr)->idConjunto , elemento)=0) {
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
/*@funcion  verConjunto.c
 *
 *@brief La funcion de verConjunto, muestra las ramas
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

void verConjunto(conjunto *ptr) {
    
    if (ptr != NULL) {
        printf("%c\n", ptr->idConjunto); //dato
        verConjunto(ptr->izquierda);
        verConjunto(ptr->derecha);
    }
}