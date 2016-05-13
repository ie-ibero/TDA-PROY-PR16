#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Tipo de datos conjunto para determinar si existe nodo en el arbol
typedef enum {
    t=1,
    f=0
} boolean;

// Tipo de datos para crear el arbol del conjunto
typedef struct conjunto {
  char idConjunto[1000];
  int dato;
  struct conjunto *derecha;
  struct conjunto *izquierda;
}conjunto;