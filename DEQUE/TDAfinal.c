#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

struct Def_Lista
{
  int NUM;
  struct Def_Lista *Sig;
  struct Def_Lista *Ant;
};
typedef struct Def_Lista tLista;

typedef struct Def_Lista *ptrLista;


void Add(ptrLista *Inicio, int Numero);
void Pop_LIFO(ptrLista *Inicio);
void Pop_FIFO(ptrLista *Inicio);
void Show(ptrLista Inicio);
void Clear(ptrLista *Inicio);
int Size(ptrLista Inicio);
int Empty(ptrLista Inicio);
int Contains(ptrLista Inicio, int Numero);
int * To_Array(ptrLista Inicio);
int Get(ptrLista Inicio, int Posicion);
void Set(ptrLista Inicio, int Posicion, int Numero);
void Add2(ptrLista *Inicio, int Posicion, int Numero);
void Menu();


int main(void)
{
  int Numero, Tipo, Opcion, Tamano, Vacio, Existe, *Cadena, i, Posicion; 
  ptrLista Inicio = NULL;

  do
  {
    system("clear");
    Menu();
    scanf("%i", &Opcion);
    switch(Opcion)
    {
    case 1:
      printf("Agregar Numero: ");
      scanf("%i", &Numero);
        Add(&Inicio,Numero);
    break;
    case 2:
      printf("Tipo de Pop\n\tLIFO : 1\n\tFIFO : 2\nOpcion deseada:\n");
      scanf("%i", &Tipo);
      if(Tipo == 1)
        Pop_LIFO(&Inicio);
      else
        Pop_FIFO(&Inicio);
    break;
    case 3:
        Show(Inicio);
        getchar();
    break;
    case 4:
        Clear(&Inicio);
    break;
    case 5:
      Tamano = Size(Inicio);
      printf("Tamano = %i\n", Tamano);
    break;
    case 6:
      Vacio = Empty(Inicio);
      if (Vacio == 1)
        printf("Si esta vacio\n");
      else
        printf("No esta vacio\n");
    break;
    case 7:
      printf("Buscar Numero: ");
      scanf("%i", &Numero);
      Existe = Contains(Inicio,Numero);
      if (Existe == 1)
        printf("Si esta existe\n");
      else
        printf("No esta existe\n");
    break;
    case 8:
        Cadena = To_Array(Inicio);
        for (i = 0; i < sizeof(Cadena); ++i)
        {
          printf("%i/", Cadena[i]);
        }
        printf("\n");
    break;
    case 9:
      printf("Cual posicion : ");
      scanf("%i", &Posicion);
      Numero = Get(Inicio,Posicion);
    break;
    case 10:
      printf("Agregar Numero: ");
      scanf("%i", &Numero);
      printf("Cual posicion : ");
      scanf("%i", &Posicion);
      Set(Inicio,Posicion,Numero);
    break;
    case 11:
      printf("Agregar Numero: ");
      scanf("%i", &Numero);
      printf("Cual posicion : ");
      scanf("%i", &Posicion);
      Add2(&Inicio,Posicion,Numero);
    break;
    }  
    getchar();
    getchar();
  }
  while(Opcion != 0);
  Clear(&Inicio);
 return 0;
}

void Menu()
{
  printf("0) Exit\n");
  printf("1) Add\n");
  printf("2) Remove\n");
  printf("3) Print\n");
  printf("4) Clear\n");
  printf("5) Size\n");
  printf("6) Is Empty\n");
  printf("7) Contains\n");
  printf("8) To Array\n");
  printf("9) Get\n");
  printf("10) Set\n");
  printf("11) Add to Posicion\n");
}


void Add(ptrLista *Inicio, int Numero)
{
  ptrLista Nuevo, Fin=*Inicio;
 
 //Crea el elemento Nuevo
  Nuevo = (ptrLista)malloc(sizeof(tLista));
  Nuevo->NUM = Numero;
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



void Pop_LIFO(ptrLista *Inicio)
{
   ptrLista Borrame, Nuevo=*Inicio,Fin=*Inicio;
   
   while(Fin->Sig != NULL)
      Fin = Fin->Sig;
   while((Nuevo->Sig)->Sig != NULL)
      Nuevo = Nuevo->Sig;

   Nuevo->Sig = NULL;
   Borrame = Fin;
   free(Borrame);   
}

void Pop_FIFO(ptrLista *Inicio)
{
   ptrLista Borrame, Nuevo;
   
   Nuevo = (*Inicio)->Sig;
   Nuevo->Ant = NULL;
   Borrame = *Inicio;
   *Inicio = Nuevo;
   free(Borrame);  
}

void Show(ptrLista Inicio)
{
  if(Inicio == NULL)
      printf("\nFIN de la lista\n");
  if(Inicio != NULL)
    {
      printf("%d-",Inicio->NUM);
      Show(Inicio->Sig);
    }
    printf("\n");
}

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


int Size(ptrLista Inicio)
{
  ptrLista Fin=Inicio;
  int Cont=0;

  while(Fin->Sig != NULL)
    {
      Fin = Fin->Sig;
      Cont = Cont + 1;
    }

   return Cont+1; 
}

int Empty(ptrLista Inicio)
{
  int x=2;
  if(Inicio == NULL)
      x=1;
  else
    x=0;
  printf("%d\n", x);
  return x;
}

int Contains(ptrLista Inicio, int Numero)
{
  ptrLista Fin=Inicio;

  while(Fin->Sig != NULL)
    {
      if (Fin->NUM == Numero)
        return 1;
      Fin = Fin->Sig;
    }

   return 0; 
}


int * To_Array(ptrLista Inicio)
{
  ptrLista Fin=Inicio;
  int Cont=0, *Array;

  while(Fin->Sig != NULL)
    {
      Fin = Fin->Sig;
      Cont = Cont + 1;
    }
    Array = (int *)malloc(sizeof(int)*Cont);
  Fin=Inicio;
  Cont = 0;
  while(Fin->Sig != NULL)
    {
      Array[Cont]=Fin->NUM;
      Fin = Fin->Sig;
      Cont = Cont + 1;
    }

    return Array;
}


int Get(ptrLista Inicio, int Posicion)
{
  ptrLista Fin=Inicio;
  int i, Numero, Cont;

  while(Fin->Sig != NULL)
    {
      Fin = Fin->Sig;
      Cont = Cont + 1;
    }
  Fin=Inicio;
  if (Cont>= Posicion)
  {
    for (i = 0; i < Posicion; i++)
    {
      Fin = Fin->Sig;
    }
    Numero = Fin->NUM;
    return Numero; 
  }
  
  return 0;  
}


void Set(ptrLista Inicio, int Posicion, int Numero)
{
  ptrLista Fin=Inicio;
  int i, Cont;

  while(Fin->Sig != NULL)
    {
      Fin = Fin->Sig;
      Cont = Cont + 1;
    }
  Fin=Inicio;
  if (Cont>= Posicion)
  {
    for (i = 0; i < Posicion; i++)
    {
      Fin = Fin->Sig;
    }
    Fin->NUM = Numero;
  } 
}


void Add2(ptrLista *Inicio, int Posicion, int Numero)
{
  ptrLista Fin=*Inicio, Next, Nuevo;
  int i, Cont;

  Nuevo = (ptrLista)malloc(sizeof(tLista));
  Nuevo->NUM = Numero;
  Nuevo->Sig = NULL;

  while(Fin->Sig != NULL)
    {
      Fin = Fin->Sig;
      Cont = Cont + 1;
    }
  Fin= *Inicio;
  if (Cont >= Posicion)
  {
     if(*Inicio == NULL)
    {
      *Inicio = Nuevo;
      Nuevo->Ant = NULL;
    }
    else
    {
      for (i = 0; i < Posicion; i++)
        Fin = Fin->Sig;
      Next = Fin->Sig;
      Fin->Sig =  Nuevo;
      Next-> Ant = Nuevo;
      Nuevo->Ant = Fin;
      Nuevo->Sig = Next;
    }
  }
  else
    if (Cont== Posicion)
    {
      while (Fin->Sig != NULL)
        Fin = Fin->Sig;
      Fin->Sig = Nuevo;
      Nuevo->Sig = Fin;
    }
    
}
  