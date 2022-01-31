//Programa de tareas
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

struct nodo
  {
	int dato;
	struct nodo *siguiente;
  };

typedef struct nodo NODO;
typedef NODO *NODOSIG;
void instrucciones(void);
void insertar_final(NODOSIG *, int);
char borrar_medio(NODOSIG *, int);
void printlista(NODOSIG);

int main()
{
 NODOSIG lista = NULL;
 int op;
 int ele;
char tarea[50];
	do
	 {
	 	printlista(lista);
		system("cls");
		instrucciones();
		printf("\n\n => ");
		scanf("%d", &op);
		switch (op) 
		 {
			case 1:
				printf("\n Introduzca el elemento: ");
				scanf("\n %d", &ele);
				insertar_final(&lista, ele);
				printlista(lista);
				printf("\n\n Oprima cualquier tecla para continuar ");
				getch();
				break;
			case 2:
				if (!isempty(lista)) 
				  {
					printf("Elemento a borrar: ");
					scanf("\n%d", &ele);
					if (borrar_medio(&lista, ele)) 
					  {
						printf("%d borrado", ele);
						printlista(lista);
					  }
					else
						printf("%d no existe \n\n",ele);
				  }
				else
				  {
					printf("Lista esta vacia\n\n");
					free(lista);
					lista=NULL;
				  }
				getch();
				break;
		 }
	 }while (op != 7);
	system("cls");
	printf("\n\n\n\n\n\n\t\t\t\t F I N\n");
	getch();
 return 0;
}
void insertar_final(NODOSIG *lista, int valor)
{
  NODOSIG nuevo, previo, actual;
	nuevo = malloc(sizeof(NODO));
	if (nuevo != NULL) 
	  {
		nuevo->dato = valor;
		nuevo->siguiente = NULL;
		previo = NULL;
		actual = *lista;
		while (actual != NULL) 
		  {
			previo = actual;
			actual = actual -> siguiente;
		  }
		if (previo == NULL) 
		  {
			nuevo -> siguiente = *lista;
			*lista = nuevo;
		  }
		else 
		  {
			previo -> siguiente = nuevo;
			nuevo -> siguiente = actual;
		  }
	  }
}
void printlista(NODOSIG actual)
{
	if (actual == NULL)/*Si no hay elementos en la lista*/
		printf("Lista vacia \n\n");
	else 
	 {/*si hay elementos en la lista*/
		printf("\n\n La lista es: \n\n");
		while (actual != NULL) 
		  {/*se imprimira la lista hasta llegar al final*/
			printf("%d --> ",actual -> dato);/*se imprime el contenido del nodo*/
			actual = actual -> siguiente;/*se avanza la posicion de actual al siguiente nodo*/
		  } 
		printf("NULL \n\n");
	 }
}
char borrar_medio(NODOSIG *lista, int valor)
{
  NODOSIG  previo, actual, temporal;/*variables auxiliares*/
	previo = *lista;/*previo toma el inicio de la lista*/
	actual = (*lista) -> siguiente;/*actual toma la posicion del siguiente nodo*/
	while (actual != NULL && actual -> dato != valor)
	  {/*mientras no se llege al final de la lista y no sea el numero que se quiere borrar*/
		previo = actual;/*previo toma la posicion de actual*/
		actual = actual -> siguiente;/*actual avanza al siguiente nodo*/
	  }
	if (actual != NULL) 
	  {/*pregunta si no es el ultimo nodo en la lista*/
		temporal = actual;/*temporal toma la posicion de alctual que es el nodo a borrar*/
		previo -> siguiente = actual -> siguiente;/*previo en siguiente toma el enlace al siguiente nodo*/
		free(temporal);/*de actual y entonces se libera el espacio que ocupaba el nodo a borrar*/
		return(valor);/*regresa el elemento borrado*/
	  }
	return '\0';/*regresa este valor para indicar que es el ultimo nodo en la lista*/
}
int isempty(NODOSIG lista)
 {
   return lista == NULL;/*pregunta si hay elemento en la lista, regresa nulo si no hay*/
 }
void instrucciones()
{
  printf("\n\n\n\t\t OPERACIONES CON LISTAS ENCADENADAS\n\n");
  printf("\n\t\t\t Que opcion desea :\n\n"
	"   \t\t 1 insertar tarea\n"
	"   \t\t 2 Eliminar tarea\n"
	);
}

