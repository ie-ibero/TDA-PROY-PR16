/**
 *===============================================================================
 * @file      deque.h
 *
 * @brief     
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
