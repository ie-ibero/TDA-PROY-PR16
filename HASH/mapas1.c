/**
*================================================================================
*@file   mapas1.c
*
*@brief  Este modulo contiene parte de las funciones correspondientes al 
*        funcionamiento de mapas en C, aqui podran econtrar la documentacion 
*        individual asi como el codigo de las siguientes funciones:
*
*        equals, keySet, put, remove_entry, collection.
*
*@author Luis Armando Vizcaino Magdaleno
*================================================================================
*/

#include "bibliotecas.h"

//FUNCIONES GENERALES DEL PROGRAMA
extern void limpia(void);
extern int ascii(char llave[]);
extern int verificar(MAPA *nodo, MAPA *mapa[]);

//FUNCIONES DESARROLLADAS POR LUIS VIZCAINO
int equals(MAPA *mapa1[], MAPA *mapa2[]); 
void keySet(MAPA *mapa[], MAPA **raiz);
char *put(MAPA *mapa[], char contenido[], char llave[]);  
char *remove_entry(MAPA *mapa[], char llave[]);  
void collection(MAPA *mapa[], MAPA **raiz);

//================================================================================================|||||||||||||||||||||||||||
//FUNCIONES DESARROLLADAS POR LUIS VIZCAINO

/**
 *================================================================================
 *@brief     Esta funcion toma los dos mapas ingresados y los recorre al mismo 
 *           tiempo comparando todas sus entradas de elementos, si los mapas son
 *           completamente identicos, regresa un 0, de lo contrario, regresa un 1.
 *
 *@entradas  MAPA *mapa1[]: Mapa a comparar.
 *           MAPA *mapa2[]: Mapa a comparar.
 *
 *@salidas   0: Valor verdadero, los mapas si son identicos.
 *           1: Valor falso, los mapas no son identicos.
 *
 *@variables *nodo1: Apuntador a estructura del mapa1.
 *			 *nodo2: Apuntador a esturctura del mapa2.
 *           *aux1:  Apuntador de soporte para "*nodo1"
 *           *aux2:  Apuntador de soporte para "*nodo2"
 *           count:  Longitud de la cadena de caracteres.
 *           i:      Contador de FOR.
 *
 *@author    Luis Armando Vizcaino Magdaleno
  *===============================================================================
 */
int equals(MAPA *mapa1[], MAPA *mapa2[])
{
	MAPA *nodo1, *nodo2, *aux1, *aux2;
	int i;
	for(i=0; i<T; i++)
	{
		nodo1 = mapa1[i];  //RECORRIDO DE MAPA1
		nodo2 = mapa2[i];  //RECORRIDO DE MAPA2
		if(mapa1[i] != NULL && mapa2[i] != NULL)  //ENTRADAS IGUALES...
		{
			aux1 = nodo1;
			aux2 = nodo2;
			if(strcmp(nodo1->LLAVE,nodo2->LLAVE) == 0)  //LLAVES IGUALES...
			{
				if(strcmp(nodo1->CONTENIDO,nodo2->CONTENIDO)  == 0)  //CONTENIDOS IGUALES...
				{
					if(aux1->sig != NULL && aux2->sig != NULL)  //NODOS ENCADENADOS IGUALES...
					{
						while(aux1->sig != NULL && aux2->sig != NULL)  //RECORRIDO DE NODOS ENCADENADOS
						{
							aux1 = aux1->sig;
							aux2 = aux2->sig;
							if(strcmp(aux1->LLAVE,aux2->LLAVE) == 0)  //LLAVES IGUALES...
							{
								if(strcmp(aux1->CONTENIDO,aux2->CONTENIDO) == 0);  //CONTENIDOS IGUALES...
								else
								{
									return 1;
								}
							}
							else
							{
								return 1;
							}

						}
					}
					else if(aux1->sig == NULL && aux2->sig == NULL);
					else
					{
						return 1;
					}
				}
				else
				{
					return 1;
				}
			}
			else
			{
				return 1;
			}
		}
		else if(mapa1[i] == NULL && mapa2[i] == NULL);
		else
		{
			return 1;
		}
	}
	return 0;  //VALIDACION REALIZADA, CONTENIDO IGUAL
}

/**
 *================================================================================
 *@brief     Este procedimiento recorre el mapa solicitado en la funcion y genera
 *           una lista encadenada simple que contiene todas las llaves de los 
 *           elementos dentro del mapa.
 *
 *@entradas  MAPA *mapa[]: Mapa a recorrer.
 *           MAPA **raiz:  Apuntador al inicio de la lista encadenada.
 *
 *@variables *nodo:   Apuntador a estructura del mapa.
 *           *aux:    Apuntador de soporte para "*nodo"
 *           *aux2:   Apuntador de soporte para "*nodo"
 *           i:       Contador de FOR.
 *           bandera: Indicador de primer elemento.
 *
 *@author    Luis Armando Vizcaino Magdaleno
  *===============================================================================
 */
void keySet(MAPA *mapa[], MAPA **raiz)
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
				strcpy(nodo->LLAVE,aux->LLAVE);  //COPIAR LLAVE DEL PRIMER ELEMENTO
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
						strcpy(nodo->LLAVE,aux->LLAVE);  //COPIAR LLAVE DE ELEMENTO
						nodo->sig = NULL;
					}
				}
			}
			else  //RECORRIDO DE ELEMENTOS QUE NO SEAN EL PRIMERO
			{
				aux2->sig = nodo;
				aux2 = nodo;
				strcpy(nodo->LLAVE,aux->LLAVE);  //COPIAR LLAVE DE ELEMENTO
				nodo->sig = NULL;
				if(aux->sig != NULL)  //SI EL ELEMENTO TIENE NODOS ENCADENADOS...
				{
					while(aux->sig != NULL)
					{
						aux = aux->sig;
						nodo = malloc(sizeof(MAPA));
						aux2->sig = nodo;
						aux2 = nodo;
						strcpy(nodo->LLAVE,aux->LLAVE);  //COPIAR LLAVE DE ELEMENTO
						nodo->sig = NULL;
					}
				}
			}

		}
	}
	return;
}
/**
 *================================================================================
 *@brief     Esta funcion ingresa un nuevo elemento dentro del mapa especificado,
 *           al ingresarlo, verifica que su llave sea unica contra las que estan
 *           actualmente en el mapa y regresa el contenido del elemento ingresado.
 *
 *@entradas  MAPA *mapa[]:     Mapa donde se ingresa el elemento nuevo.
 *           char contenido[]: Contenido del elemento nuevo.
 *           char llave[]:     Llave del elemento nuevo.
 *
 *@salidas   char *res: Apuntador al contenido recien ingresado al mapa.
 *
 *@variables *nodo: Apuntador a estructura del mapa.
 *           *aux:  Apuntador de soporte para "*nodo"
 *           *aux2: Apuntador de soporte para "*nodo"
 *           i:     Contador de FOR.
 *           hash:  Valor de tabla hash del nuevo elemento.
 *           valor: Valor ascii de la llave del nuevo elemento.
 *           veri:  Valor verificador de repetidos.
 *           comp:  Resultado de comparacion para el oder del mapa.
 *           *res:  Apuntador de resultado final de la funcion.
 *
 *@author    Luis Armando Vizcaino Magdaleno
  *===============================================================================
 */
char *put(MAPA *mapa[], char contenido[], char llave[])
{
	MAPA *nodo, *aux, *aux2;
	int i, hash, valor, comp, veri = 2;
	char *res;
	nodo = malloc(sizeof(MAPA));
	strcpy(nodo->CONTENIDO,contenido);  //ASIGNACION DE CONTENIDO A NODO DE MAPA
	strcpy(nodo->LLAVE,llave);  //ASIGNACION DE LLAVE A NODO DE MAPA
	res = nodo->CONTENIDO; //VALOR DE RESPUESTA FINAL
	veri = verificar(nodo,mapa);  //VERIFICA QUE LA LLAVE SEA UNICA
	printf("\n\t%d\n",veri);
	if(veri == 0)
	{
		return (res);
	}
	valor = ascii(llave);
	hash = valor%T;
	aux = mapa[hash];
	if(mapa[hash] == NULL)  //ASIGNACION DEL ELEMENTO DENTRO DE LA TABLA
	{
		mapa[hash] = nodo;
		nodo->sig = NULL;
		return (res);
	}
	else if(mapa[hash] != NULL)
	{
		comp = strcmp(aux->CONTENIDO,nodo->CONTENIDO);//ASIGNACION DEL ORDEN DE LOS ELEMENTOS
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
			while(aux->sig != NULL)  //RECORRIDO Y ASIGNACION DEL ORDEN DE LOS ELEMENTOS ENCADENADOS
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

/**
 *================================================================================
 *@brief     Esta funcion elimina un elemento dentro del mapa buscandolo por su
 *           llave, despues, regresa el contenido que solia tener dicho elemento.
 *
 *@entradas  MAPA *mapa[]: Mapa donde se ingresa el elemento nuevo.
 *           char llave[]: Llave del elemento a borrar.
 *
 *@salidas   char *res: Apuntador al contenido recien eliminado del mapa.
 *
 *@variables *nodo:         Apuntador a estructura del mapa.
 *           *aux:          Apuntador de soporte para "*nodo"
 *           hash:          Valor de tabla hash del nuevo elemento.
 *           valor:         Valor ascii de la llave del nuevo elemento.
 *           *res:          Apuntador de resultado final de la funcion.
 *           nocontenido[]: Mensaje "NULL" que indica que ningun contenido a 
 *                          eliminar fue encontrado.
 *           sicontenido[]: Copia el contenido del elemento a elminar.
 *
 *@author    Luis Armando Vizcaino Magdaleno
  *===============================================================================
 */
char *remove_entry(MAPA *mapa[], char llave[])
{
	MAPA *nodo, *aux;
	char *res, nocontenido[5] = {"NULL"}, sicontenido[30];
	int hash, valor;

	valor = ascii(llave);  //CALCULO DE VALOR HASH
	hash = valor%T;
	if(mapa[hash] != NULL)  //BUSQUEDA DEL ELEMENTO
	{
		nodo = malloc(sizeof(MAPA));
		nodo = mapa[hash];
		aux = nodo;
		if(strcmp(nodo->LLAVE,llave) == 0)  //COMPARACION DE LLAVES
		{
			if(aux->sig == NULL)
			{
				strcpy(sicontenido,nodo->CONTENIDO);  //ELIMINACION DE PRIMER ELEMENTO
				res = sicontenido;
				free(nodo);
				mapa[hash] = NULL;
			}
			else
			{
				strcpy(sicontenido,nodo->CONTENIDO);  //ELIMINACION DE ELEMENTO
				res = sicontenido;
				mapa[hash] = nodo->sig;
				free(nodo);
			}
		}
		else if(aux->sig != NULL)  //SI EXITEN NODOS ENCADENADOS
		{
			nodo = nodo->sig;
			if(strcmp(nodo->LLAVE,llave) == 0)  //COMPARACION DE LLAVES
			{
				if(nodo->sig == NULL)
				{
					strcpy(sicontenido,nodo->CONTENIDO);  //ELIMINACION DE PRIMAR ELEMENTO
					res = sicontenido;
					free(nodo);
					aux->sig = NULL;
				}
				else
				{
					strcpy(sicontenido,nodo->CONTENIDO);  //ELIMINACION DE ELEMENTO
					res = sicontenido;
					aux->sig = nodo->sig;
					free(nodo);	
				}
			}
		}
	}
	else  //SI NO SE PUDO REALIZAR LA BUSQUEDA...
	{
		res = nocontenido;
	}
	return(res);
}

/**
 *================================================================================
 *@brief     Este procedimiento genera una lista encadenada simple de todos los
 *           elementos dentro del mapa que incluye tanto su llave como su 
 *           contenido, al final, regresa el apuntador a la raiz de la lista.
 *
 *@entradas  MAPA *mapa[]: Mapa donde se ingresa el elemento nuevo.
 *           MAPA **raiz:  Apuntador al inicio de la lista encadenada.
 *
 *@variables *nodo:   Apuntador a estructura del mapa.
 *           *aux:    Apuntador de soporte para "*nodo"
 *           *aux2:   Apuntador de soporte para "*nodo"
 *           i:       Contador de FOR.
 *           bandera: Indicador de primer elemento.

 *
 *@author    Luis Armando Vizcaino Magdaleno
  *===============================================================================
 */
void collection(MAPA *mapa[], MAPA **raiz)
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
				strcpy(nodo->LLAVE,aux->LLAVE);  //COPIAR DATOS DEL PRIMER ELEMENTO
				strcpy(nodo->CONTENIDO,aux->CONTENIDO);
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
						strcpy(nodo->LLAVE,aux->LLAVE);  //COPIAR DATOS DEL PRIMER ELEMENTO
						strcpy(nodo->CONTENIDO,aux->CONTENIDO);
						nodo->sig = NULL;
					}
				}
			}
			else  //RECORRIDO DE ELEMENTOS QUE NO SEAN EL PRIMERO
			{
				aux2->sig = nodo;
				aux2 = nodo;
				strcpy(nodo->LLAVE,aux->LLAVE);  //COPIAR DATOS DEL PRIMER ELEMENTO
				strcpy(nodo->CONTENIDO,aux->CONTENIDO);
				nodo->sig = NULL;
				if(aux->sig != NULL)  //SI EL ELEMENTO TIENE NODOS ENCADENADOS...
				{
					while(aux->sig != NULL)
					{
						aux = aux->sig;
						nodo = malloc(sizeof(MAPA));
						aux2->sig = nodo;
						aux2 = nodo;
						strcpy(nodo->LLAVE,aux->LLAVE);  //COPIAR DATOS DEL PRIMER ELEMENTO
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