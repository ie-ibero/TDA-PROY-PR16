/**
 *===============================================================================
 * @file      bibliotecas.h
 *
 * @brief     En este modulo, se encuentran las bibliotecas y las estructuras
 *            correspondientes para la ejecución del programa.
 *
 *===============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 240  //CONSTANTE DE TAMAÑO, TABLA HASH

typedef struct mapa  //ESTRUCTURA PARA CONTENIDO DE MAPA
{
	char LLAVE[30];
	char CONTENIDO[30];
	struct mapa *sig;
}MAPA;
