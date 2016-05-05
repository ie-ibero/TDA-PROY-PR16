// FUNCIONES DESARROLLADAS POR LAEL

/**
 *===============================================================================
 *@brief     Esta funcion almacena en un archivo binario espeficificado en el main
 *           por el usuario todos los registros de los mapas o tambien los 
 *           actualiza.
 *
 *@entradas  DATOS *m[]: Arreglo de apuntadores para direccion de la tabla hash.
 *
 *@salidas   Guarda todos los registros en un archivo binario.
 *
 *@variables *nodo: Apuntador a la estructura especificada del tipo determinado
 *                  ubicada en "bibliotecas.h".  
 *           *aux: Apuntador secundario de soporte al apuntador "*nodo".
 *           i: Contador de FOR.
 *           j: Contador de registros encontrados.
 *           hash: Valor asignado de la tabla hash.
 *           clave: Valor que tiene un registro dentro de la tabla hash.
 *           valor: Dato especificado a buscar.
 *
 *@autor     Leonardo Lael Villar Benitez
 *===============================================================================
 */
int containsValue(MAPA *mapa[],char contenido[])
{
DATOS *nodo,*aux;
	char valor[30];
	int i,j=0;
	system("clear");
	limpia();
	printf("\n\tVALOR A BUSCAR: ");
	gets(valor);
	for(i=0;i<T;i++)
	{
		if(m[i] != NULL)
		{
			nodo = m[i];
			aux = nodo;
			if(strcmp(valor,aux->DATO) == 0)
			{
				j++;
			}
			if(aux->sig != NULL)
			{
				while(aux->sig != NULL)
				{
					aux = aux->sig;
					if(strcmp(valor,aux->DATO) == 0)
					{
						j++;
					}
				}
			}
		}
	}
	printf("\n\tTotal de llaves encontradas : %d\n",j);
	printf("\n\tPRESIONE \"ENTER\" PARA REGRESAR.");
	getchar();
	return;
}


/**
 *===============================================================================
 *@brief     Esta funcion despliega en forma de lista todos los elementos
 *           registrados dentro del mapa, mostrando sus llaves, contenidos y su
 *           valor de la tabla hash.
 *
 *@entradas  DATOS *m[]: Arreglo de apuntadores para direccion de la tabla hash.
 *
 *@salidas   Muestra los datos registrados dentro del mapa.
 *
 *@variables *nodo: Apuntador a la estructura especificada del tipo determinado
 *                  ubicada en "bibliotecas.h".  
 *           *aux: Apuntador secundario de soporte al apuntador "*nodo".
 *           i: Contador de FOR.
 *           hash: Valor asignado de la tabla hash.
 *
 *@autor     Leonardo Lael Villar Benitez
 *===============================================================================
 */
void entrySet(MAPA *mapa[], MAPA **raiz)
{
DATOS *nodo,*aux;
	int i, hash;
	system("clear");
	nodo = malloc(sizeof(DATOS));
	printf("\n\t===== LISTA DE REGISTROS =====\n");
	for(i=0;i<T;i++)  //RECORRIDO DE LA TABLA HASH
	{
		if(m[i] != NULL)  //RECORRIDO DE LOS REGISTROS DE MAPAS
		{  //DESPLIEGE DE INFORMACION
			nodo = m[i];
			aux = nodo;
			hash = nodo->KEY%T;
			printf("\n\tLlave: %d",nodo->KEY);
			printf("\n\tDato: %s",nodo->DATO);
			printf("\n\tHash-code: %d\n",hash);
			if(aux->sig != NULL)
			{
				while(aux->sig != NULL)
				{
					aux = aux->sig;
					printf("\n\tLlave: %d",aux->KEY);
					printf("\n\tDato: %s",aux->DATO);
					printf("\n\tHash-code: %d\n",hash);
				}
			}
		}
	}
	limpia();
	printf("\n\tPRESIONE \"ENTER\" PARA REGRESAR.");
	getchar();
	return;
}


/**
 *===============================================================================
 *@brief     Esta funcion calcula el valor de tabla hash del mapa completo
 *           sumando el valor hash de cada uno de los registros que se encuentran
 *           dentro del mapa y luego calculado el valor hash de dicha sumatoria. 
 *
 *@entradas  DATOS *m[]: Arreglo de apuntadores para direccion de la tabla hash.
 *
 *@salidas   Regresa el codigo hash del mapa actual.
 *
 *@variables *nodo: Apuntador a la estructura especificada del tipo determinado
 *                  ubicada en "bibliotecas.h".  
 *           *aux: Apuntador secundario de soporte al apuntador "*nodo".
 *           hash: Valor asignado de la tabla hash.
 *           totalhash: Sumatoria de los valores hash de los registros.
 *           i: Contador de FOR.
 *
 *@autor     Leonardo Lael Villar Benitez
 *===============================================================================
 */
int hashCode(MAPA *mapa[])
{
DATOS *nodo,*aux;
	int hash, totalhash=0,i;
	for(i=0;i<T;i++)  //RECORRIDO DE LA TABLA HASH
	{
		if(m[i] != NULL) //RECORRIDO DE LOS REGISTROS
		{
			nodo = m[i];
			aux = nodo;
			hash = nodo->KEY%T;
			totalhash = totalhash + hash;  //SUMATORIA DE VALORES HASH
			if(aux->sig != NULL)
			{
				while(aux->sig != NULL)
				{
					aux = aux->sig;
					hash = aux->KEY%T;
					totalhash = totalhash + hash;  //SUMATORIA DE VALORES HASH
				}

			}
		}
	}
	totalhash = totalhash%T;  //CALCULO DE VALOR HASH DEL MAPA
	system("clear");
	printf("\n\n\tCODIGO DEL MAPA: %d",totalhash);
	limpia();
	printf("\n\tPRESIONE \"ENTER\" PARA REGRESAR.");
	getchar();
	return;
}


/**
 *===============================================================================
 *@brief     Esta funcion muestra si el mapa tiene registros dentro de el o 
 *           esta completamente vacio.
 *
 *@entradas  DATOS *m[]: Arreglo de apuntadores para direccion de la tabla hash.
 *
 *@salidas   Muestra si el mapa esta vacio o no.
 *
 *@variables *nodo: Apuntador a la estructura especificada del tipo determinado
 *                  ubicada en "bibliotecas.h".  
 *           *aux: Apuntador secundario de soporte al apuntador "*nodo".
 *           i: Contador de FOR.
 *           j: Contador de registros.
 *
 *@autor     Leonardo Lael Villar Benitez
 *===============================================================================
 */
int isEmpty(MAPA *mapa[])
{
DATOS *nodo,*aux;
	int i,j;
	system("clear");
	nodo = malloc(sizeof(DATOS));
	for(i=0;i<T;i++)  //RECORRIDO DE LA TABLA HASH
	{
		if(m[i] != NULL)  //RECORRIDO DE LOS REGISTROS DE MAPAS
		{  //DESPLIEGE DE INFORMACION
			nodo = m[i];
			aux = nodo;
			j++;  //CONTEO DE LLAVES
			if(aux->sig != NULL)
			{
				while(aux->sig != NULL)
				{
					aux = aux->sig;
					j++; //CONTEO DE LLAVES
				}
			}
		}
	}
	if(j == 0)
	{
		printf("\n\tEste mapa esta vacio...\n");
	}
	else
	{
		printf("\n\tEl mapa contiene %d elementos registrados.\n",j);
	}
	limpia();
	printf("\n\tPRESIONE \"ENTER\" PARA REGRESAR.");
	getchar();
	return;
}


void putAll(MAPA *mapa1[], MAPA *mapa2[])
{
	return;
}
