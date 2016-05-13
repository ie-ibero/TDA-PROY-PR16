/**
 *===============================================================================
 * @file      deque.h
 *
 * @brief     Biblioteca para la implementacion de funciones de listas dinamicas.
 *			  Estructura para la creacion de listas.
 *	
 * @author	  Santiago Menendez Barrera
 *			  Gerardo Blanco de Anzorena
 *
 *===============================================================================
 */

/* BIBILIOTECAS */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

/* ESTRUCTURA */
struct Def_Lista
{
  char STR[50];
  struct Def_Lista *Sig;
  struct Def_Lista *Ant;
};
typedef struct Def_Lista tLista;

typedef struct Def_Lista *ptrLista;

/* FUNCIONES */
void Push(ptrLista *Inicio, char cadena[]);
void Pop_LIFO(ptrLista *Inicio);
void Pop_FIFO(ptrLista *Inicio);
void Show(ptrLista Inicio);
void Clear(ptrLista *Inicio);
int Size(ptrLista Inicio);
int Empty(ptrLista Inicio);
int Contains(ptrLista Inicio, char cadena[]);
char * Get(ptrLista Inicio, int Posicion);
void Set(ptrLista Inicio, int Posicion, char cadena[]);
void Push_Into(ptrLista *Inicio, int Posicion, char cadena[]);