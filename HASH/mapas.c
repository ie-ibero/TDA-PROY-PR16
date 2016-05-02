/**
 *================================================================================================
 *@file   mapas.c
 *
 *@brief  En este modulo se encuentran todas las funciones y procedimientos  para el manejo de
 *        sistemas de mapas de java en C, las funciones estan formuladas para uso general y el 
 *        listado de abajo determina que accion realiza cada una:
 *
 *        -limpia:        Limpia el buffer.
 *        -ascii:         Calcula el valor ascii de una cadena de caracteres.
 *        -equals:        Compara el contenido de 2 mapas, si estos son iguales se regresa un 
 *                        0, de  lo contrario, regresa un 1.
 *        -keySet:        Regresa un arreglo que contiene las llaves del mapa que se le ingreso 
 *                        a la funcion.
 *        -put:           Ingresa un elemento nuevo a un mapa ingresado a la funcion y regresa
 *                        el contenido del elemento nuevo
 *        -remove_entry:  Elimina un elemento de un mapa ingresado a la funcion  buscandolo por
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
	char LLAVE[30];
	char CONTENIDO[30];
	struct mapa *sig;
}MAPA;

//FUNCIONES GENERALES DEL PROGRAMA
void limpia(void);
int ascii(char llave[]);
void verificar(MAPA *nodo, MAPA *mapa[]);

//FUNCIONES DESARROLLADAS POR LUIS VIZCAINO
int equals(MAPA *mapa1[], MAPA *mapa2[]); 
void keySet(MAPA *mapa[], char *set[]);  
char *put(MAPA *mapa[], char contenido[], char llave[]);  
char *remove_entry(MAPA *mapa[], char llave[]);  
void collection(MAPA *mapa[], MAPA **raiz);  

// FUNCIONES DESARROLLADAS POR LAEL VILLAR
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

//================================================================================================|||||||||||||||||||||||||||
//FUNCIONES GENERALES DEL PROGRAMA

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

int ascii(char llave[])
{
	int count, z, valor;
	count = strlen(llave);
	for(z=0; z<count; z++)
	{
  		valor = valor + llave[z];
 	}
 	return(valor);
}

void verificar(MAPA *nodo, MAPA *mapa[])
{
	MAPA *aux;
	int j;
	for(j=0;j<T;j++) //RECORRIDO DE TABLA HASH
	{
		aux = mapa[j];
		if(mapa[j] != NULL)
		{
			if(strcmp(aux->LLAVE,nodo->LLAVE) == 0)  //VERIFICACION DE LA LLAVE
			{
				printf("\n\tEsta clave ya fue usada... Sustitullendo valor\n\t");
				printf("\tVALOR ANTERIOR: %s\n",aux->CONTENIDO);
				strcpy(aux->CONTENIDO,nodo->CONTENIDO);
				return;
			}
			if(aux->sig != NULL)
			{
				while(aux->sig != NULL)  //CICLO RECURSIVO
				{
					aux = aux->sig;
					if(strcmp(aux->LLAVE,nodo->LLAVE) == 0)
					{
						printf("\n\tEsta clave ya fue usada... Sustitullendo valor\n\t");
						printf("\tVALOR ANTERIOR: %s\n",aux->CONTENIDO);
						strcpy(aux->CONTENIDO,nodo->CONTENIDO);
						return;
					}
				}
			}
		}
	}
	return;
}

//================================================================================================|||||||||||||||||||||||||||
//FUNCIONES DESARROLLADAS POR LUIS VIZCAINO

int equals(MAPA *mapa1[], MAPA *mapa2[])
{
	return;
}
void keySet(MAPA *mapa[], char *set[])
{
	return;
}
char *put(MAPA *mapa[], char contenido[], char llave[])
{
	MAPA *nodo, *aux, *aux2, *aux3;
	int i, hash, valor, comp;
	char *res;
	nodo = malloc(sizeof(MAPA));
	strcpy(nodo->CONTENIDO,contenido);
	strcpy(nodo->LLAVE,llave);
	res = nodo->CONTENIDO;
	verificar(nodo,mapa);
	valor = ascii(llave);
	hash = valor%T;
	aux = mapa[hash];
	if(mapa[hash] == NULL)
	{
		mapa[hash] = nodo;
		nodo->sig = NULL;
		return (res);
	}
	else if(mapa[hash] != NULL)
	{
		comp = strcmp(aux->CONTENIDO,nodo->CONTENIDO);
		if(comp == 0)
		{
			mapa[hash] = nodo;
			nodo->sig = aux;
			return (res);
		}
		else if(comp < 0)
		{
			mapa[hash] = nodo;
			nodo->sig = aux;
			return(res);
		}
		if(comp > 0)
		{
			while(aux->sig != NULL)
			{
				aux2 = aux;
				aux = aux->sig;
				comp = strcmp(aux->CONTENIDO,nodo->CONTENIDO);
				if(comp == 0)
				{
					aux2->sig = nodo;
					nodo->sig = aux;
					return (res);
				}
				if(comp < 0)
				{
					aux2->sig = nodo;
					nodo->sig = aux;
					return (res);					
				}
				if(aux->sig == NULL)
				{
					aux->sig = nodo;
					nodo->sig = NULL;
					return (res);
				}
			}
		}
	}
}
char *remove_entry(MAPA *mapa[], char llave[])
{
	MAPA *nodo, *aux;
	char contenido[30], *res, nocontenido[5] = {"NULL"}, sicontenido[30];
	int hash, valor;

	valor = ascii(llave);
	hash = valor%T;
	if(mapa[hash] != NULL)
	{
		nodo = malloc(sizeof(MAPA));
		nodo = mapa[hash];
		aux = nodo;
		if(strcmp(nodo->LLAVE,llave) == 0)
		{
			if(aux->sig == NULL)
			{
				strcpy(sicontenido,nodo->CONTENIDO);
				res = sicontenido;
				free(nodo);
				mapa[hash] = NULL;
			}
			else
			{
				strcpy(sicontenido,nodo->CONTENIDO);
				res = sicontenido;
				mapa[hash] = nodo->sig;
				free(nodo);
			}
		}
		else if(aux->sig != NULL)
		{
			nodo = nodo->sig;
			if(strcmp(nodo->LLAVE,llave) == 0)
			{
				if(nodo->sig == NULL)
				{
					strcpy(sicontenido,nodo->CONTENIDO);
					res = sicontenido;
					free(nodo);
					aux->sig = NULL;
				}
				else
				{
					strcpy(sicontenido,nodo->CONTENIDO);
					res = sicontenido;
					aux->sig = nodo->sig;
					free(nodo);	
				}
			}
		}
	}
	else
	{
		res = nocontenido;
		return(res);
	}
	return(res);
}
void collection(MAPA *mapa[], MAPA **raiz)
{
	MAPA *nodo, *aux, *aux2;
	int i, bandera = 0;
	for(i=0; i<T; i++)
	{
		aux = mapa[i];
		if(mapa[i] != NULL)
		{
			nodo = malloc(sizeof(MAPA));
			if(bandera == 0)
			{
				*raiz = nodo;
				aux2 = nodo;
				strcpy(nodo->LLAVE,aux->LLAVE);
				strcpy(nodo->CONTENIDO,aux->CONTENIDO);
				nodo->sig = NULL;
				bandera = 1;
				if(aux->sig != NULL)
				{
					while(aux->sig != NULL)
					{
						aux = aux->sig;
						nodo = malloc(sizeof(MAPA));
						aux2->sig = nodo;
						aux2 = nodo;
						strcpy(nodo->LLAVE,aux->LLAVE);
						strcpy(nodo->CONTENIDO,aux->CONTENIDO);
						nodo->sig = NULL;
					}
				}
			}
			else
			{
				aux2->sig = nodo;
				aux2 = nodo;
				strcpy(nodo->LLAVE,aux->LLAVE);
				strcpy(nodo->CONTENIDO,aux->CONTENIDO);
				nodo->sig = NULL;
				if(aux->sig != NULL)
				{
					while(aux->sig != NULL)
					{
						aux = aux->sig;
						nodo = malloc(sizeof(MAPA));
						aux2->sig = nodo;
						aux2 = nodo;
						strcpy(nodo->LLAVE,aux->LLAVE);
						strcpy(nodo->CONTENIDO,aux->CONTENIDO);
						nodo->sig = NULL;
					}
				}
			}

		}
	}
	return;
}

//================================================================================================|||||||||||||||||||||||||||
// FUNCIONES DESARROLLADAS POR LAEL

int containsValue(MAPA *mapa[],char contenido[])
{
	return;
}  
void entrySet(MAPA *mapa[], char *set[])
{
	return;
}  
int hashCode(MAPA *mapa[])
{
	return;
}
int isEmpty(MAPA *mapa[])
{
	return;
}  
void putAll(MAPA *mapa1[], MAPA *mapa2[])
{
	return;
}
//================================================================================================|||||||||||||||||||||||||||
//FUNCIONES DESARROLLADAS POR JOSE

void clear(MAPA *mapa[])
{
	return;
}  
int containsKey(MAPA *mapa[], char llave[])
{
	return;
}  
char *get(MAPA *mapa[], char llave[])
{
	return;
}
int size(MAPA *mapa[])
{
	return;
}  

//================================================================================================|||||||||||||||||||||||||||