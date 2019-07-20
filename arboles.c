#include "arboles.h"

#include <stdio.h>
#include <stdlib.h>




	
void arboles(){
	Arbol *arbol = NULL;
		

	
	
	int opcion; 
	do{
		system("cls");		
		printf("          INICIO > ARBOLESAS\n\n");
		printf(
			"1. Mostrar Arbol \n"
			"2. Insertar Nodo \n"
			"3. Existe Nodo \n"
			"4. Eliminar Nodo \n"
			"5. Pre Orden \n"
			"6. In Orden \n"
			"7. Pos Orden \n"
			"0. Atras \n"
			"\nopcion: ");
		opcion = soloNum();
		
		switch(opcion){
			case 1:
				mostrarArbol(arbol,0);
				system("pause");
				continue;
			case 2:
				printf("Insertar Valor En El Arbol: ");
				int va;
				scanf("%d",&va);
				Insertar(&arbol,va);
				system("pause");
				continue;
			case 3:
				printf("Buscar Valor: ");
				int bu;
				scanf("%d",&bu);
				DeterminarExistencia(arbol,bu);
				system("pause");
				continue;
			case 4:
				mostrarArbol(arbol,0);
				printf("\n\nCual Valor Quieres Eliminar: ");
				int el;
				scanf("%d",&el);
				Eliminar(arbol,el);
				system("pause");
				continue;
			case 5:
				PreOrden(arbol);
				printf("\n");
				system("pause");
				continue;
			case 6:
				InOrden(arbol);
				printf("\n");
				system("pause");
				continue;
			case 7:
				PosOrden(arbol);
				printf("\n");
				system("pause");
				continue;
			case 0:
				printf("ATRAS..\n");
				continue;
			default:
				printf("OPCION INVALIDA, VUELVE A INTENTAR\n");
				system("pause");				
		}
		
	
	}while(opcion != 0);
		
		
		

	
		

}





NodoA* CrearNodo(int valor, NodoA* padre){
	NodoA* nuevoNodo = (NodoA *) malloc(sizeof(NodoA));
	nuevoNodo->valor = valor;
	nuevoNodo->izq = nuevoNodo->der = NULL;
	nuevoNodo->padre = padre;
	return nuevoNodo;
}

void DestruirNodoArbol(NodoA* nodo){
	nodo->izq = NULL;
	nodo->der = NULL;
	free(nodo);
}

static void InsertarConPadre(NodoA** arbol,NodoA* padre, int valor){
	if(*arbol == NULL){
		*arbol = CrearNodo(valor, padre);	
	}else{
		int valorRaiz = (*arbol)->valor;
		if(valor < valorRaiz){
			InsertarConPadre(&(*arbol)->izq, *arbol, valor);
		}else{
			InsertarConPadre(&(*arbol)->der,*arbol,  valor);
		}
	}
}

void Insertar(NodoA** arbol, int valor){
	InsertarConPadre(arbol,NULL,valor);	
}

int Existe(NodoA* arbol, int valor){
	if(arbol == NULL){
		return 0;
	}else if(arbol->valor == valor){
		return 1;
	}else if(valor < arbol->valor){
		return Existe(arbol->izq, valor);
	}else{
		return Existe(arbol->der, valor);
	}
}

void DeterminarExistencia(NodoA * arbol, int valor){
	if(Existe(arbol, valor)){
		printf("el nodo %d existe en el arbol.\n", valor);
	}else{
		printf("el nodo %d NO existe en el arbol.\n", valor);
	}
}

void Reemplazar(NodoA* arbol, NodoA* nuevoNodo){
	if(arbol->padre){
		if(arbol->valor == arbol->padre->izq->valor){
			arbol->padre->izq = nuevoNodo;
		}else if(arbol->valor == arbol->padre->der->valor){
			arbol->padre->der = nuevoNodo;
		}
	}
	if(nuevoNodo){
		nuevoNodo->padre = arbol->padre;
	}
}

NodoA* Minimo(NodoA* arbol){
	if(arbol == NULL){
		return NULL;
	}else if(arbol->izq){
		return Minimo(arbol->izq);
	}else{
		return arbol;
	}
}

static void EliminarNodo(NodoA* nodoEliminar){
	if(nodoEliminar->izq && nodoEliminar->der){
		NodoA* minimo = Minimo(nodoEliminar->der);
		nodoEliminar->valor = minimo->valor;
		EliminarNodo(minimo);
	}else if(nodoEliminar->izq){
		Reemplazar(nodoEliminar,nodoEliminar->izq);
		DestruirNodoArbol(nodoEliminar);
	}else if(nodoEliminar->der){
		Reemplazar(nodoEliminar,nodoEliminar->der);
		DestruirNodoArbol(nodoEliminar);
	}else{
		Reemplazar(nodoEliminar, NULL);
		DestruirNodoArbol(nodoEliminar);
	}
}

void Eliminar(NodoA* arbol, int valor){
	if(arbol == NULL){
		return;
	}else if(valor < arbol->valor){
		Eliminar(arbol->izq, valor);
	} else if(valor > arbol->valor){
		Eliminar(arbol->der, valor);
	}else{
		EliminarNodo(arbol);
	}
}

void mostrarArbol(NodoA *arbol, int cont){
	int i;
	if(arbol == NULL){
		return;
	}else{
		mostrarArbol(arbol->der,cont+1);
		for(i=0;i<cont;i++){
			printf("   ");
		}
		printf("%u\n",arbol->valor);
		mostrarArbol(arbol->izq,cont+1); 
	}
}

void PreOrden(NodoA *arbol){
	if(arbol == NULL){
		return;
	}else{
		printf("%u - ",arbol->valor);
		PreOrden(arbol->izq);
		PreOrden(arbol->der);
	}
	
}

void InOrden(NodoA *arbol){
	if(arbol == NULL){
		return;
	}else{
		InOrden(arbol->izq);
		printf("%u - ",arbol->valor);	
		InOrden(arbol->der);
	}
}

void PosOrden(NodoA *arbol){
	if(arbol == NULL){
		return;
	}else{
		PosOrden(arbol->izq);
		PosOrden(arbol->der);
		printf("%u - ",arbol->valor);
	}
}


