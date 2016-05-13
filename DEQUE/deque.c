/**
 *===============================================================================
 * @file      deque.c
 *
 * @brief     
 *
 *===============================================================================
 */
#include "deque.h"

/**
 *===============================================================================
 *@brief     
 *
 *@entradas  
 *
 *@salidas   
 *
 *@variables 
 *
 *@autor     
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
 *@brief     
 *
 *@entradas  
 *
 *@salidas   
 *
 *@variables 
 *
 *@autor     
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
 *@brief     
 *
 *@entradas  
 *
 *@salidas   
 *
 *@variables 
 *
 *@autor     
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
 *@brief     
 *
 *@entradas  
 *
 *@salidas   
 *
 *@variables 
 *
 *@autor     
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
 *@brief     
 *
 *@entradas  
 *
 *@salidas   
 *
 *@variables 
 *
 *@autor     
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
 *@brief     
 *
 *@entradas  
 *
 *@salidas   
 *
 *@variables 
 *
 *@autor     
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
 *@brief     
 *
 *@entradas  
 *
 *@salidas   
 *
 *@variables 
 *
 *@autor     
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
