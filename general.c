
#include "bibliotecas.h"

//FUNCIONES GENERALES DEL PROGRAMA
void limpia(void);
int ascii(char llave[]);
int verificar(MAPA *nodo, MAPA *mapa[]);

//================================================================================================|||||||||||||||||||||||||||
//FUNCIONES GENERALES DEL PROGRAMA

/**
 *================================================================================
 *@brief     Este procedimiento limpia el buffer.
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

/**
 *================================================================================
 *@brief     Esta funcion tranforma una cadena de caracteres a la suma de los
 *           valores ascii de cada letra que contiene, luego, regresa dicho valor.
 *
 *@entradas  char llave[]; Arreglo a tranformar.
 *
 *@salidas   int valor: La suma de todos los valores ascii del arreglo.
 *
 *@variables count: Longitud de la cadena de caracteres.
 *           z:     Contador de FOR.
 *           valor: Suma de los valores ascii de la cadena.
 *
 *@author    Luis Armando Vizcaino Magdaleno
  *===============================================================================
 */
int ascii(char llave[])
{
	int count, z, valor=0;
	count = strlen(llave);  //CALCULA LONGITUD DE CADENA
	for(z=0; z<count; z++)
	{
  		valor = valor + llave[z];  //SUMA DE VALORES ASCII
 	}
 	return(valor);
}

/**
 *================================================================================
 *@brief     Esta funcion sirve como apoyo para la funcion "put", esta
 *           verifica que la llave ingresada para valor de nuevo elemento de un
 *           mapa sea unica, y en el caso de que sea repetida, sustiuye el valor
 *           previo del elemento por el nuevo ingresado. Asi tambien regresa
 *           0 si ya estaba repetida la llave y 1 si el valor era unico.
 *
 *@entradas  MAPA *nodo:   Elemento nuevo a ser comparado contra el resto de los 
 *                         elementos.
 *           MAPA *mapa[]: Mapa donde el nuevo elemento sera ingresado.   
 *
 *@salidas   0: Valor verdadero, el elemento a verificar tiene llave repetida
 *           1: Valor falso, el elemento a verificar es unico.
 *
 *@variables *aux: Apuntador a la tabla hash para realizar el recorrido y la
 *                 comparacion.
 *
 *@author    Luis Armando Vizcaino Magdaleno
  *===============================================================================
 */
int verificar(MAPA *nodo, MAPA *mapa[])
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
				return 0;
			}
			if(aux->sig != NULL)
			{
				while(aux->sig != NULL)  //VERIFICACION DE NODOS LIGADOS
				{
					aux = aux->sig;
					if(strcmp(aux->LLAVE,nodo->LLAVE) == 0)
					{
						printf("\n\tEsta clave ya fue usada... Sustitullendo valor\n\t");
						printf("\tVALOR ANTERIOR: %s\n",aux->CONTENIDO);
						strcpy(aux->CONTENIDO,nodo->CONTENIDO);
						return 0;
					}
				}
			}
		}
	}
	return 1;
}



//================================================================================================|||||||||||||||||||||||||||