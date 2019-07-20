
#ifndef estructura_h
#define estructura_h

#include <stdio.h>
#include <stdlib.h>


void Pilas();
void Colas();
void Listas();




//typedef struct Nodo{
//	int dato;
//	struct Nodo *siguiente;
//} Nodo;


//__________________________PILAS____________________________________________



//______________________________COLA________________________________________________	




//____________________________LISTAS__________________________________________________



	
typedef struct NodoLista {
	int valor;
	struct NodoLista *Siguiente;
} Nodo;
int InsertarElemento(Nodo **Inicio);
void ListarElementos(Nodo *Inicio);
int BorrarElementoListaPrincipio(Nodo **Inicio);
int BorrarElementoListaFinal(Nodo **Inicio);
void ListaVacia(Nodo **Inicio);




#endif
