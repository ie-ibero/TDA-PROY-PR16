#include <stdio.h>
#include <stdlib.h>

//Tipo de datos conjunto para determinar si existe nodo en el arbol
typedef enum { 
	TRUE, FALSE 
} boolean;

// Tipo de datos para crear el arbol
typedef struct arbol {
  int idArbol;
  int dato;
  struct arbol *derecha;
  struct arbol *izquierda;
} arbol;
