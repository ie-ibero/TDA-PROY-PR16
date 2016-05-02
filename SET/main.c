// http://progra.usm.cl/apunte/materia/conjuntos.html

/*@file  main.c
*
*@brief Este modulo contine la funcion main. Es el motor del programa. Los 
*		elementos del conjunto se guardan uno seguido de otro mediante un
*		array. Las estructuras se pasan por referencia y dado que se trata
*		de una coleccion tipo conjunto, los elementos no estan ordenados.
*
*@autor Avila Cortes Karina
*@date  28/04/2016
*/

/**
*@brief     Esta funcion ejecuta el proceso del main.
 *
 *@variables *ptr : puntero que deriva de la estructura arbol. Recorre arbol.
 *           int opcion : recibe opcion de menu del usuario.
 *           int a : recibe valor y lo toma como argumento para llamar una funcion.
 *           int b : recibe valor y lo toma como argumento para llamar una funcion.
 *           int i : contador.
 *			 int resultado: muestra resultado al realizar operacion en funciones.
 *							Se inicializa en 0. 
 *           int res : valor de que permite obtener valor de string dado por el usuario.
 *           char input : string para leer string del usuario.
 *
 *@return    regresa valor igual a 0.
 *
 *@autor     Avila Cortes Karina
 */

#include "biblioteca.h"

extern int menu(void);
extern void creaArbol(arbol **ptr);
extern void addAll(arbol **ptr, int elemento); 
extern int clear();
extern boolean contains(arbol *ptr, int elemento);
extern void removes(arbol **ptr, int elemento);
extern void verColeccion(arbol *ptr);
//extern int size();

int main(int argc, char *argv[]) {

    arbol *ptr;

	int opcion;
	int a, b, i;
	int resultado = 0;
    char input[10];
    int res = 0;

    system("clear");

    creaArbol(&ptr);

    while(opcion != 4) {

        opcion = menu();
        system("clear");

        printf("Introduce una opcion del menu: %d \n",opcion);
        switch (opcion) {
            case 1:
                printf("\nFormatos:\n");
                printf("\tadd(ValorNodo)\n");
                printf("\tclear(ValorNodo)\n");
                printf("\tcontains(ValorNodo)\n");
                printf("\tremoves(ValorNodo)\n");
                printf("\tsize(ValorNodo)\n");
                printf("\tregresar\n");
                printf("\n");

                scanf("%s", input);

                if (res = sscanf(input, "add(%d)", &a)) {
                    addAll(&ptr, a);
                }
                else if (res = sscanf(input, "clear(%d)", &a)) {
                    clear();
                }
                else if (res = sscanf(input, "contains(%d)", &a)) {
                    contains(ptr, a);
                }
                else if (res = sscanf(input, "removes(%d)", &a)) {
                    removes(&ptr, a);
                }
                // else if (res = sscanf(input, "size(%d)", &a)) {
                //     size(&ptr, a);
                // }
                else if (res = sscanf(input, "regresar")) {
                    exit(1);
                }
                else {
                    printf("Error: Operacion incorrecta.\n");
                }
                break;
            case 2:
                printf("Numero de nodos a insertar:  ");
                scanf("%d",&a);
                if((a != 1) && (a == 1.0)) {
                    printf("Error: Opcion debe ser numerica\n");
                }
                else{
                    printf("\nFormato: addAll(ValorNodo)\n\n");
                    for (i = 0; i < a; i++) {
                        printf("%d: ", i);
                        scanf("%s", input);
                        if (res = sscanf(input, "addAll(%d)", &b)) {
                            addAll(&ptr, b);
                        }
                        else {
                            printf("Error: Dato anterior no se agrega.\n");
                        }
                       
                    }
                }
                break;
            
            case 3:
               	printf("\tVer coleccion\n\n");
                printf("Imprimiendo coleccion...\n");
                sleep(1);
                verColeccion(ptr);
                break;

            case 4:
                exit(1);
                system("clear");
                break;

            default:
                printf ("Error: Opcion no valida\n");
                system("clear");
                break;
        }
    }
    return 0;
}
