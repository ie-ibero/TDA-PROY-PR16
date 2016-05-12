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

//FUNCIONES GENERALES DEL PROGRAMA
extern void limpia(void);
extern int ascii(char llave[]);

//FUNCIONES DESARROLLADAS POR LUIS VIZCAINO
extern int equals(MAPA *mapa1[], MAPA *mapa2[]); 
extern void keySet(MAPA *mapa[], MAPA **raiz);
extern char *put(MAPA *mapa[], char contenido[], char llave[]);  
extern char *remove_entry(MAPA *mapa[], char llave[]);  
extern void collection(MAPA *mapa[], MAPA **raiz);  

// FUNCIONES DESARROLLADAS POR LAEL
extern int containsValue(MAPA *mapa[],char contenido[]);  
extern void entrySet(MAPA *mapa[], MAPA **raiz);  
extern int hashCode(MAPA *mapa[]);  
extern int isEmpty(MAPA *mapa[]);  
extern void putAll(MAPA *mapa1[], MAPA *mapa2[]);  

//FUNCIONES DESARROLLADAS POR JOSE
extern void clear(MAPA *mapa[]);  
extern int containsKey(MAPA *mapa[], char llave[]);  
extern char *get(MAPA *mapa[], char llave[]);
extern int size(MAPA *mapa[]);  
