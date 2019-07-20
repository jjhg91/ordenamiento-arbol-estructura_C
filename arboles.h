#ifndef arboles_h
#define arboles_h

#include <stdio.h>
#include <stdlib.h>


void arboles();
	
typedef struct nodo{
	int valor;
	struct nodo *der;
	struct nodo *izq;
	struct nodo* padre;
} NodoA;

typedef NodoA Arbol;
NodoA* CrearNodo(int valor, NodoA* padre);
void DestrutiNodoArbol(NodoA* nodo);
static void InsertarConPadre(NodoA** arbol,NodoA* padre, int valor);
void Insertar(NodoA** arbol, int valor);
int Existe(NodoA* arbol, int valor);
void DeterminarExistencia(NodoA * arbol, int valor);
void Reemplazar(NodoA* arbol, NodoA* nuevoNodo);	
NodoA* Minimo(NodoA* arbol);
static void EliminarNodo(NodoA* nodoEliminar);
void Eliminar(NodoA* arbol, int valor);
void mostrarArbol(NodoA *arbol, int cont);	
void PreOrden(NodoA *arbol);
void InOrden(NodoA *arbol);
void PosOrden(NodoA *arbol);
	
	
	
#endif
