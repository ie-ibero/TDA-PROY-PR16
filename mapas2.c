/**
*================================================================================
*@file   mapas2.c
*
*@brief  Este modulo contiene parte de las funciones correspondientes al 
*        funcionamiento de mapas en C, aqui podran econtrar la documentacion 
*        individual asi como el codigo de las siguientes funciones:
*
*        containsValue, entrySet, hashCode, isEmpty putAll.
*
*@author 
*================================================================================
*/

#include "bibliotecas.h"

//FUNCIONES GENERALES DEL PROGRAMA
extern void limpia(void);
extern int ascii(char llave[]);

//FUNCIONES DESARROLLADAS POR LUIS VIZCAINO
extern char *put(MAPA *mapa[], char contenido[], char llave[]);  

// FUNCIONES DESARROLLADAS POR LAEL
int containsValue(MAPA *mapa[],char contenido[]);  
void entrySet(MAPA *mapa[], MAPA **raiz);  
int hashCode(MAPA *mapa[]);  
int isEmpty(MAPA *mapa[]);  
void putAll(MAPA *mapa1[], MAPA *mapa2[]);  

//================================================================================================|||||||||||||||||||||||||||
//FUNCIONES DESARROLLADAS POR LAEL

/**
 *===============================================================================
 *@brief     Esta funcion almacena en un archivo binario espeficificado en el main
 *           por el usuario todos los registros de los mapas o tambien los 
 *           actualiza.
 *
 *@entradas  MAPA *mapa[]: Mapa en el cual se buscara el contenido   
 *           char contenido[]: Contenido del elemento nuevo.
 *
 *@salidas   0: Valor verdadero, si encontro el cotenido a buscar
 *           1: Valor falso, si no encontro el contenido a buscar
 *
 *@variables *nodo: Apuntador a estructura del mapa.  
 *           *aux:  Apuntador de soporte para "*nodo"
 *           i: Contador de FOR.
 *
 *@autor     Leonardo Lael Villar Benitez
 *===============================================================================
 */
int containsValue(MAPA *mapa[],char contenido[])
{
	MAPA *nodo, *aux;
	int i;
	for(i=0; i<T; i++)  //RECORRIDO DEL MAPA
	{
		if(mapa[i] != NULL)  //SI EXITEN ENTRADAS
		{
			nodo = mapa[i];
			aux = nodo;
			if(strcmp(contenido,nodo->CONTENIDO) == 0) //COMPARACION CON EL CONTENIDO A BUSCAR
			{
				return 0;
			}
			if(aux->sig != NULL)  //SI TIENE NODOS ENCADENADOS...
			{
				while(aux->sig != NULL)
				{
					aux = aux->sig;
					if(strcmp(contenido,aux->CONTENIDO) == 0)  //COMPARACION CON EL CONTENIDO A BUSCAR
					{
						return 0;
					}
				}
			}
		}
	}
	return 1;  //SI NO ENCONTRO EL CONTENIDO A BUSCAR
}  

/**
 *===============================================================================
 *@brief     Esta funcion despliega en forma de lista todos los elementos
 *           registrados dentro del mapa, mostrando sus llaves, contenidos y su
 *           valor de la tabla hash.
 *
 *@entradas  MAPA *mapa[]:  Mapa que mostrara los elementos
 *           MAPA **raiz:  Apuntador al inicio de la lista encadenada..
 *
 *@variables *nodo: Apuntador a estructura del mapa.
 *           *aux:  Apuntador de soporte para "*nodo"
 *           *aux2:   Apuntador de soporte para "*nodo"
 *           i: Contador de FOR.
 *           bandera: Indicador de primer elemento.
 *
 *@autor     Leonardo Lael Villar Benitez
 *===============================================================================
 */
void entrySet(MAPA *mapa[], MAPA **raiz)
{
	MAPA *nodo, *aux, *aux2;
	int i, bandera = 0;
	for(i=0; i<T; i++)  //RECORRIDO DE TABLA HASH
	{
		aux = mapa[i];
		if(mapa[i] != NULL)  //ENTRADA A ELEMENTOS DE LA TABLA
		{
			nodo = malloc(sizeof(MAPA));
			if(bandera == 0)  //IDENTIFICACION DE PRIMER ELEMENTO DE LA LISTA
			{
				*raiz = nodo;
				aux2 = nodo;
				strcpy(nodo->CONTENIDO,aux->CONTENIDO);  //COPIAR CONTENIDO DEL PRIMER ELEMENTO
				nodo->sig = NULL;
				bandera = 1;
				if(aux->sig != NULL)
				{
					while(aux->sig != NULL)  //SI EL PRIMER ELEMENTO TIENE NODOS ENCADENADOS...
					{
						aux = aux->sig;
						nodo = malloc(sizeof(MAPA));  
						aux2->sig = nodo;
						aux2 = nodo;
						strcpy(nodo->CONTENIDO,aux->CONTENIDO);  //COPIAR CONTENIDO DE ELEMENTO
						nodo->sig = NULL;
					}
				}
			}
			else  //RECORRIDO DE ELEMENTOS QUE NO SEAN EL PRIMERO
			{
				aux2->sig = nodo;
				aux2 = nodo;
				strcpy(nodo->CONTENIDO,aux->CONTENIDO);  //COPIAR CONTENIDO DE ELEMENTO
				nodo->sig = NULL;
				if(aux->sig != NULL)  //SI EL ELEMENTO TIENE NODOS ENCADENADOS...
				{
					while(aux->sig != NULL)
					{
						aux = aux->sig;
						nodo = malloc(sizeof(MAPA));
						aux2->sig = nodo;
						aux2 = nodo;
						strcpy(nodo->CONTENIDO,aux->CONTENIDO);  //COPIAR CONTENIDO DE ELEMENTO
						nodo->sig = NULL;
					}
				}
			}

		}
	}
	return;	
}  

/**
 *===============================================================================
 *@brief     Esta funcion calcula el valor de tabla hash del mapa completo
 *           sumando el valor hash de cada uno de los registros que se encuentran
 *           dentro del mapa y luego calculado el valor hash de dicha sumatoria. 
 *
 *@entradas  MAPA *mapa[]: Mapa al que se le calculara hash
 *
 *@salidas   totalhash: El valor hash de la funcion
 *
 *@variables *nodo: Apuntador a estructura del mapa.  
 *           *aux:  Apuntador de soporte para "*nodo"
 *           hash: Guarda el valor hash de la llave
 *           valor: Guarda el valor ascii de la llave
 *           llave[]: Guarda la llave del elemento
 *           i: Contador de FOR.
 *
 *@autor     Leonardo Lael Villar Benitez
 *===============================================================================
 */
int hashCode(MAPA *mapa[])
{
	MAPA *nodo, *aux;
	int totalhash=0, valor, hash, i;
	char llave[30];
	for(i=0; i<T; i++)  //RECORRIDO DEL MAPA
	{
		if(mapa[i] != NULL)  //RECORRIDO DE LOS REGISTROS
		{
			nodo = mapa[i];
			aux = nodo;
			strcpy(llave,nodo->LLAVE); //OBTENER LLAVE DE ELEMENTO
			valor = ascii(llave);  //CALCULO DE VALOR ASCII DE LLAVE
			hash = valor%T;  //CALCULO DE VALOR HASH DE LLAVE
			totalhash = totalhash + hash;  //SUMATORIA DE VALORES HASH
			if(aux->sig != NULL)
			{
				while(aux->sig != NULL)
				{
					aux = aux->sig;
					strcpy(llave,nodo->LLAVE);  //OBTENER LLAVE DE ELEMENTO
					valor = ascii(llave);  //CALCULO DE VALOR ASCII DE LLAVE
					hash = valor%T;  //CALCULO DE VALOR HASH DE LLAVE
					totalhash = totalhash + hash;  //SUMATORIA DE VALORES HASH
				}
			}
		}
	}
	totalhash = totalhash%T;  //CALCULO DE VALOR HASH DEL MAPA
	return (totalhash);
}  

/**
 *===============================================================================
 *@brief     Esta funcion muestra si el mapa tiene registros dentro de el o 
 *           esta completamente vacio.
 *
 *@entradas  MAPA *mapa[]: Mapa a revisar
 *
 *@salidas   0: Valor verdadero, si el mapa tiene contenido
 *           1: Valor falso, si el mapa esta vacio
 *
 *@variables i: Contador de FOR.
 *
 *@autor     Leonardo Lael Villar Benitez
 *===============================================================================
 */
int isEmpty(MAPA *mapa[])
{
	int i;
	for(i=0; i<T; i++)  //RECORRIDO DEL MAPA
	{
		if(mapa[i] != NULL)  //ENTRADA DE REGISTROS
		{
			return 1;			
		}
	}
	return 0;
}  

/**
 *===============================================================================
 *@brief     Esta funcion permite insertar todos los registros
 *           de un mapa a otro mapa incluyendo todos su elementes.
 *
 *@entradas  MAPA *mapa1[]: Mapa al que se añadira el contenido
 *           MAPA *mapa2[]: Mapa que se copiara el contenido
 *
 *@variables llave[]: Guarda la llave del elemento
 *           char contenido[]: Contenido del elemento nuevo.
 *           i: Contador de FOR.
 *
 *@autor     Leonardo Lael Villar Benitez
 *===============================================================================
 */
void putAll(MAPA *mapa1[], MAPA *mapa2[])
{
	MAPA *nodo, *aux;
	int i;
	char *res, contenido[30], llave[30];

	for(i=0; i<T; i++)
	{
		if(mapa2[i] != NULL)
		{
			nodo = mapa2[i];
			aux = nodo;
			strcpy(contenido,nodo->CONTENIDO);
			strcpy(llave,nodo->LLAVE);
			res = put(mapa1,contenido,llave);
			if(aux->sig != NULL)
			{
				while(aux->sig != NULL)
				{
					aux = aux->sig;
					strcpy(contenido,nodo->CONTENIDO);
					strcpy(llave,nodo->LLAVE);
					res = put(mapa1,contenido,llave);
				}
			}
		}
	}
	return;
} 

//================================================================================================|||||||||||||||||||||||||||
