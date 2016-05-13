/**
 *===============================================================================
 * @file      deque.c
 *
 * @brief     Este archivo contiene funciones relacionadas con listas dinamicas
 *            en C, las funciones estan pensadas para implementarse en cualquier
 *            programa, a continuacion el nombre y una breve descripcion de que
 *            hace cada una de ellas.
 *
 *            -Push(Incio, Cadena): Esta funcion agrega un elemento al 
 *            final de la lista.
 *            Parametros:
 *            Inicio: Apuntador al inicio de la lista. (ptrLista)
 *            Cadena: Cadena de caracteres que se desea agregar a la lista. (char[])
 *            
 *            -Pop_LIFO(Incio): Esta funcion elimina el ultimo elemento que se agrego
 *            a la lista.
 *            Parametros:
 *            Inicio: Apuntador al inicio de la lista. (ptrLista)
 *              
 *            -Pop_FIFO(Incio): Esta funcion elimina el primer elemento que se agrego
 *            a la lista.
 *            Parametros:
 *            Inicio: Apuntador al inicio de la lista. (ptrLista)
 *              
 *            -Show(Incio): Esta funcion imprime todos los elementos de la lista.
 *            Parametros:
 *            Inicio: Apuntador al inicio de la lista. (ptrLista)
 *          
 *            -Clear(Incio): Esta funcion elimina todos los elementos de la lista.
 *            Parametros:
 *            Inicio: Apuntador al inicio de la lista. (ptrLista)
 *         
 *            -Size(Incio): Esta funcion regresa el numero de elementos dentro de la
 *            lista.
 *            Parametros:
 *            Inicio: Apuntador al inicio de la lista. (ptrLista)
 *         
 *            -Empty(Incio): Esta funcion regresa 1 si la lista esta vacia, regresa
 *            0 si hay elementos dentro de la lista.
 *            Parametros:
 *            Inicio: Apuntador al inicio de la lista. (ptrLista)
 *              
 *            -Contains(Incio, Cadena): Esta funcion regresa 1 si el elemento se encuentra dentro 
 *            de la lista o 0 si no lo esta.
 *            Parametros:
 *            Inicio: Apuntador al inicio de la lista. (ptrLista)
 *            Cadena: Cadena de caracteres que se desea agregar a la lista. (char[])
 *
 *            -Get(Incio, Posicion): Esta funcion regresa el elemento de una 
 *            posicion especifica dentro de la lista.
 *            Parametros:
 *            Inicio: Apuntador al inicio de la lista. (ptrLista)
 *            Posicion: La posicion de la cual deseas obtener el elemento. (int)
 *
 *            -Set(Incio, Posicion, Cadena): Esta funcion cambia un elemento por otro 
 *            elemento que se encuentra en una posicion especifica dentro de la lista.
 *            Parametros:
 *            Inicio: Apuntador al inicio de la lista. (ptrLista)
 *            Posicion: La posicion en donde deseas agregar el elemento. (int)
 *            Cadena: Cadena de caracteres que se desea agregar a la lista. (char[])
 *
 *            -Set(Incio, Posicion, Cadena): Esta funcion agrega un elemento especifico 
 *            a una posicion especifica dentro de la lista.
 *            Parametros:
 *            Inicio: Apuntador al inicio de la lista. (ptrLista)
 *            Posicion: La posicion en donde deseas agregar el elemento. (int)
 *            Cadena: Cadena de caracteres que se desea agregar a la lista. (char[])
 *
 * @author    Gerardo Blanco de Anzorena
 *            Santiago Menendez Barrera
 *
 *
 *
 *===============================================================================
 */
#include "deque.h"

/**
 *===============================================================================
 *@brief     -Push(Incio, Cadena): Esta funcion agrega un elemento al 
 *            final de la lista.
 *
 *@entradas  -Inicio: Apuntador al inicio de la lista. (ptrLista)
 *           -Cadena: Cadena de caracteres que se desea agregar a la lista. (char[])
 *
 *@variables Nuevo: Pointer por agragar a la lista
 *           Fin: Pointer que apunta al final de la lista
 *
 *@autor     -Gerardo Blanco de Anzorena
 *===============================================================================
 */
void Push(ptrLista *Inicio, char cadena[])
{
  ptrLista Nuevo, Fin=*Inicio;
 
 //Crea el elemento Nuevo
  Nuevo = (ptrLista)malloc(sizeof(tLista));
  strcpy(Nuevo->STR,cadena);
  Nuevo->Sig = NULL;

  if(*Inicio == NULL)
    {
      *Inicio = Nuevo;
      Nuevo->Ant = NULL;
    }
  else
    {
      while (Fin->Sig != NULL)
    	  Fin = Fin->Sig;
      Fin->Sig = Nuevo;
      Nuevo->Ant= Fin;
    }
}

/**
 *===============================================================================
 *@brief     -Pop_LIFO(Incio): Esta funcion elimina el ultimo elemento que se agrego
 *            a la lista.
 *
 *@entradas  -Inicio: Apuntador al inicio de la lista. (ptrLista) 
 *
 *@variables Borrame: Pointer al elemento por ser borrado
 *           Fin: Pointer que apunta al final de la lista
 *           AnteFin: Pointer que apunta al penultimo de la lista
 *
 *@autor     -Santiago Menendez Barrera
 *===============================================================================
 */
void Pop_LIFO(ptrLista *Inicio)
{
   ptrLista Borrame, AnteFin=*Inicio ,Fin=*Inicio;
   
   while(Fin->Sig != NULL)
      Fin = Fin->Sig;
   while((AnteFin->Sig)->Sig != NULL)
      AnteFin = AnteFin->Sig;

   AnteFin->Sig = NULL;
   Borrame = Fin;
   free(Borrame);   
}

/**
 *===============================================================================
 *@brief     -Pop_FIFO(Incio): Esta funcion elimina el primer elemento que se agrego
 *            a la lista.
 *
 *@entradas  -Inicio: Apuntador al inicio de la lista. (ptrLista)
 *
 *@variables Borrame: Pointer al elemento por ser borrado
 *           NuevoInicio: Pointer que apunta al nuevo inicio de la lista
 *
 *@autor     -Santiago Menendez Barrera
 *===============================================================================
 */
void Pop_FIFO(ptrLista *Inicio)
{
   ptrLista Borrame, NuevoInicio;
   
   NuevoInicio = (*Inicio)->Sig;
   NuevoInicio->Ant = NULL;
   Borrame = *Inicio;
   *Inicio = NuevoInicio;
   free(Borrame);  
}

/**
 *===============================================================================
 *@brief     -Show(Incio): Esta funcion imprime todos los elementos de la lista.
 *
 *@entradas  -Inicio: Apuntador al inicio de la lista. (ptrLista)
 *
 *@autor     -Santiago Menendez Barrera
 *===============================================================================
 */
void Show(ptrLista Inicio)
{
  if(Inicio == NULL)
      printf("\n\n-FIN de la lista-\n");
  if(Inicio != NULL)
    {
      puts(Inicio->STR);
      Show(Inicio->Sig);
    }
}

/**
 *===============================================================================
 *@brief     -Clear(Incio): Esta funcion elimina todos los elementos de la lista.
 *
 *@entradas  -Inicio: Apuntador al inicio de la lista. (ptrLista)
 *
 *@variables Borrame: Pointer al elemento por ser borrado
 *
 *@autor     -Santiago Menendez Barrera
 *===============================================================================
 */
void Clear(ptrLista *Inicio)
{
  ptrLista Borrame;
  
  while (*Inicio != NULL)
    {
      Borrame = *Inicio;
      *Inicio = (*Inicio)->Sig;
      free(Borrame);
    }
}

/**
 *===============================================================================
 *@brief     -Size(Incio): Esta funcion regresa el numero de elementos dentro de la
 *            lista.
 *
 *@entradas  -Inicio: Apuntador al inicio de la lista. (ptrLista)
 *
 *@salidas   ins Size: Regresa el tamano de la lista.
 *
 *@variables Fin: Pointer que apunta al final de la lista.
 *
 *@autor     -Gerardo Blanco de Anzorena
 *===============================================================================
 */
 int Size(ptrLista Inicio)
{
  ptrLista Fin=Inicio;
  int Cont=0;

  if(Inicio == NULL)
    Cont = -1;
  else
    while(Fin->Sig != NULL)
      {
        Fin = Fin->Sig;
        Cont = Cont + 1;
      }

   return Cont+1; 
}

/**
 *===============================================================================
 *@brief     -Empty(Incio): Esta funcion regresa 1 si la lista esta vacia, regresa
 *            0 si hay elementos dentro de la lista.
 *
 *@entradas  -Inicio: Apuntador al inicio de la lista. (ptrLista)
 *
 *@salidas   int bandera: Regresa 1 si la lista esta vacia, 0 si tiene algun elemento
 *
 *@variables bandera: bandera que indica si la lista esta vacia o con algun elemento
 *
 *@autor     -Santiago Menendez Barrera
 *===============================================================================
 */
int Empty(ptrLista Inicio)
{
  int bandera=2;

  if(Inicio == NULL)
      bandera=1;
  else
    bandera=0;

  return bandera;
}

/**
 *===============================================================================
 *@brief     -Contains(Incio, Cadena): Esta funcion regresa 1 si el elemento se encuentra dentro 
 *            de la lista o 0 si no lo esta.
 *
 *@entradas  -Inicio: Apuntador al inicio de la lista. (ptrLista)
 *           -Cadena: Cadena de caracteres que se desea buscar en la lista. (char[])
 *
 *@salidas   Regresa 1 si se encontro la cadena dentro de la lista
 *
 *@variables Fin: Pointer que apunta al final de la lista.
 *
 *@autor     -Gerardo Blanco de Anzorena 
 *===============================================================================
 */
int Contains(ptrLista Inicio, char cadena[])
{
  ptrLista Fin=Inicio;

  while(Fin->Sig != NULL)
    {
      if (strcmp(Fin->STR,cadena)==0)
        return 1;
      Fin = Fin->Sig;
    }

   return 0; 
}

 /**
 *===============================================================================
 *@brief     -Get(Incio, Posicion): Esta funcion regresa el elemento de una 
 *            posicion especifica dentro de la lista.
 *
 *@entradas  -Inicio: Apuntador al inicio de la lista. (ptrLista)
 *           -Posicion: La posicion de la cual deseas obtener el elemento. (int)
 *
 *@salidas   string: Es la cadena encontrada 
 *           0 : si no se encuntra nada en esa posicion
 *
 *@variables Fin: Pointer que apunta al final de la lista.
 *           Cont: Contador de elementos en la lista
 *
 *@autor     -Gerardo Blanco de Anzorena
 *===============================================================================
 */
char * Get(ptrLista Inicio, int Posicion)
{
  ptrLista Fin= Inicio;
  int i=1, Cont=1;
  char *string = malloc(sizeof(char) * 50);


  if(Inicio != NULL)
  {
    while(Fin->Sig != NULL)
      {
        Fin = Fin->Sig;
        Cont = Cont + 1;
      }
    Fin=Inicio;
    if (Cont >= Posicion)
    {
      while(i<Posicion)
      {
        Fin = Fin->Sig;
        i=i+1;
      }
      strcpy(string,Fin->STR);
      return string; 
    }
  }
  
  return 0;  
}


 /**
 *===============================================================================
 *@brief     -Set(Incio, Posicion, Cadena): Esta funcion cambia un elemento por otro 
 *            elemento que se encuentra en una posicion especifica dentro de la lista.
 *
 *@entradas  -Posicion: La posicion en donde deseas agregar el elemento. (int)
 *           -Cadena: Cadena de caracteres que se desea agregar a la lista. (char[])
 *
 *@variables Fin: Pointer que apunta al final de la lista.
 *           Cont: Contador de elementos en la lista
 *
 *@autor     -Gerardo Blanco de Anzorena
 *===============================================================================
 */
void Set(ptrLista Inicio, int Posicion, char cadena[])
{
  ptrLista Fin= Inicio;
  int i=1, Cont=1;

  if(Inicio != NULL)
  {
    while(Fin->Sig != NULL)
      {
        Fin = Fin->Sig;
        Cont = Cont + 1;
      }
    Fin=Inicio;
    if (Cont >= Posicion)
    {
      while(i<Posicion)
      {
        Fin = Fin->Sig;
        i=i+1;
      }
      strcpy(Fin->STR,cadena);
    }
  }
}

 /**
 *===============================================================================
 *@brief     -Set(Incio, Posicion, Cadena): Esta funcion agrega un elemento especifico 
 *            a una posicion especifica dentro de la lista.
 *
 *@entradas  -Inicio: Apuntador al inicio de la lista. (ptrLista)
 *           -Posicion: La posicion en donde deseas agregar el elemento. (int)
 *           -Cadena: Cadena de caracteres que se desea agregar a la lista. (char[])
 *
 *@variables Fin: Pointer que apunta al final de la lista.
 *           Nuevo: Pointer que apunta al nuevo elemento por agregar
 *           AnteFin: Pointer que apunta al penultimu lugar
 *           Respaldo: Pointer que apunta a inicio como respaldo
 *           Next: Pointer que apunta al siguiente elemento
 *           Cont: Contador de elementos en la lista
 *
 *@autor     -Gerardo Blanco de Anzorena
 *===============================================================================
 */
void Push_Into(ptrLista *Inicio, int Posicion, char cadena[])
{
  ptrLista Next, Nuevo, AnteFin=*Inicio ,Fin=*Inicio, Reslpaldo = *Inicio;
  int i=1, Cont=1;
  
  Nuevo = (ptrLista)malloc(sizeof(tLista));
  strcpy(Nuevo->STR,cadena);
  Nuevo->Sig = NULL;

    if(*Inicio == NULL)
      Cont = 0;
    else
      while(Fin->Sig != NULL)
        {
          Fin = Fin->Sig;
          Cont = Cont + 1;
        }
    Fin=Reslpaldo;
    if(*Inicio == NULL && Cont == 0)
    {
      *Inicio = Nuevo;
      Nuevo->Ant = NULL;
    }
    else
      if(Posicion==1)
    {
      Fin=Reslpaldo->Sig;
      Nuevo->Sig=Fin;
      Fin->Ant=Nuevo;
      *Inicio = Nuevo;
      Nuevo->Ant = NULL;
    }
    else
    {
      if(Cont == 1)
      {
        Fin = Reslpaldo->Sig;
        Fin->Ant = Nuevo;
        Nuevo->Sig = Fin;
        Nuevo->Ant = NULL;
        *Inicio = Nuevo;
      }
      else
      {
        if (Cont >= Posicion)
        {
           while(i<Posicion)
            {
              Fin = Fin->Sig;
              if (i!=1)
              {
                AnteFin = AnteFin->Sig;
              }
              i=i+1;
            }
            AnteFin->Sig=Nuevo;
            Nuevo->Ant=AnteFin;
            Nuevo->Sig=Fin;
            Fin->Ant=Nuevo;
        }
      }
    }
}

   
