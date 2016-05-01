/**
 *================================================================================================
 *@file   mapas.c
 *
 *@brief  En este modulo se encuentran todas las funciones y procedimientos  para el manejo de
 *        sistemas de mapas de java en C, las funciones estan formuladas para uso general y el 
 *        listado de abajo determina que accion realiza cada una:
 *
 *        -limpia:        Limpia el buffer
 *        -equals:        Compara el contenido de 2 mapas, si estos son iguales se regresa un 
 *                        0, de  lo contrario, regresa un 1.
 *        -keySet:        Regresa un arreglo que contiene las llaves del mapa que se le ingreso 
 *                        a la funcion.
 *        -put:           Ingresa un elemento nuevo a un mapa ingresado a la funcion.
 *        -remove:        Elimina un elemento de un mapa ingresado a la funcion  buscandolo por
 *                        su llave y regresa el contenido de este elemento.
 *        -collection:    Regresa el nodo raiz de una lista encadenada simple que contiene los 
 *                        elementos del mapa ingresado a la funcion.
 *        -containsValue: Esta funcion busca un contenido especifico dentro del mapa y regresa
 *                        un 0 si es que dicho contenido es encontrado o un 1 si no.
 *        -entrySet:      Regresa un arreglo que contiene los contenidos de todos los elemmentos
 *                        del mapa que ingreso a la funcion.
 *        -hashCode:      Regresa el numero de valor hash del mapa ingresado a la funcion.
 *        -isEmpty:       Regresa un 0 si el mapa ingresado a la funcion no tiene elmentos 
 *                        dentro y un 1 si tiene elementos.
 *        -putAll:        Convina todos los elementos de un mapa2 dentro de un mapa1 ingresado.
 *        -clear:         Elimina todos los elementos de un mapa ingresado a la funcion.
 *        -containsKey:   Esta funcion busca una llave especifica dentro del mapa y regresa
 *                        un 0 si es que esa llave es encontrada o un 1 si no.
 *        -get:           Esta funcion regresa el contenido de un elemento buscado por su llave
 *                        dentro de un mapa especificado.
 *        -size:          Esta funcion regresa el numero total de elementos que existen dentro 
 *                        de un mapa ingresado a la funcion.

 *        El sistema de mapas funciona mediante la implementacion de una tabla hash con resolucion
 *        de colisiones via encadenamiento separado, las tablas y nodos de las funciones deben de 
 *        ser determinados por quien las llegue usar en el programa que deba usarlas.
 *
 *        Los datos correspondientes a la funcionalidad, tipos de entradas y salidas de
 *        informacion de cada funcion estan en sus documentaciones individuales.
 *
 *@author Luis Armando Vizcaino Magdaleno
 *
 *
 *================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 240  //CONSTANTE DE TAMAÑO, TABLA HASH

typedef struct mapa  //ESTRUCTURA PARA CONTENIDO DE MAPA
{
	int LLAVE;
	char CONTENIDO[30];
	struct mapa *sig;
}MAPA;

//FUNCIONES GENERALES DEL PROGRAMA
void limpia(void);

//FUNCIONES DESARROLLADAS POR LUIS VIZCAINO
int equals(MAPA *mapa1[], MAPA *mapa2[]);
void keySet(MAPA *mapa[], char *set[]);
char *put(MAPA *mapa[], char contenido[], char llave[]);
char *remove(MAPA *mapa[], char llave[]);
void collection(MAPA *m[], MAPA *raiz);

// FUNCIONES DESARROLLADAS POR LAEL
int containsValue(MAPA *mapa[],char contenido[]);
void entrySet(MAPA *mapa[], char *set[]);
int hashCode(MAPA *mapa[]);
int isEmpty(MAPA *mapa[]);
void putAll(MAPA *mapa1[], MAPA *mapa2[]);

//FUNCIONES DESARROLLADAS POR JOSE
void clear(MAPA *mapa[]);
int containsKey(MAPA *mapa[], char llave[]);
char *get(MAPA *mapa[], char llave[]);
int size(MAPA *mapa[]);

/**
 *================================================================================
 *@brief        Este procedimiento limpia el buffer.
 *
 *@variables c: Limpiador de buffer.
  *===============================================================================
 */
void limpia(void)
{
	char c;
  	while((c=getchar())!='\n');  //LIMPIA EL BUFFER
  	return;
}