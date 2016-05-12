#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Tipo de datos conjunto para determinar si existe nodo en el arbol
typedef enum { 
    int t=1;
    int f=0;
} boolean;

// Tipo de datos para crear el arbol del conjunto
typedef struct arbol {
  char idConjunto[];
  int dato;
  struct conjunto *derecha;
  struct conjunto *izquierda;
} arbol;