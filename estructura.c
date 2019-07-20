#include "estructura.h"
#include <stdio.h>
#include <stdlib.h>


void estructura(){
	int opcion; 
	do{
		system("cls");
		printf("          INICIO > ESTRUCTURAS\n\n");
		printf(
			"1. Pilas \n"
			"2. Colas \n"
			"3. Listas  \n"
			"0. Atras \n"
			"\nopcion: ");
		opcion = soloNum();
		
		switch(opcion){
			case 1:
				Pilas();
				continue;
			case 2:
				Colas();
				continue;
			case 3:
				Listas();
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





//__________________________PILAS______________________________________
void Pilas(){
	
	
	typedef struct nodo_s
	{
	 int dato;
	 struct nodo_s *siguiente;
	} nodo_t;
	 
	typedef nodo_t *ptrNodo;
	typedef nodo_t *ptrPila;

	ptrPila pila = NULL;

			 
	/*
	    Agrega un nodo al inicio de la lista ligada
	    *pila es el apuntador que apunta al primer nodo de la lista ligada (la cima de la pila)
	*/
	void push(ptrPila *pila, int x)
	{
		
	 // Crea un nuevo nodo
	 ptrNodo nodo;
	 nodo = (ptrNodo)malloc(sizeof(nodo_t));
	 if (nodo != NULL)
	    {
	     nodo->dato = x;
	     // El apuntador nodo->siguiente va a apuntar al primer nodo de la lista ligada
	     nodo->siguiente = *pila;
	     // pila va a apuntar al nuevo nodo, con esto hacemos que el nuevo nodo sea ahora el primer nodo de la lista ligada
	     *pila=nodo;
	     
	    }
	}
	
	
	int pila_vacia(ptrPila *pila)
	{
	 return (*pila == NULL ? 1:0);
	}
	
	/*
	    Elimina el primer nodo de la lista ligada
	    *pila es el apuntador que apunta al primer nodo de la lista ligada (la cima de la pila)
	*/
	
	int pop(ptrPila *pila)
	{
		if(pila_vacia(pila) == 0){
			// Crea un nuevo nodo
			ptrNodo nodo;
			int x=0;
			
			// El nuevo nodo va a apuntar al primer nodo de la lista ligada
			nodo = *pila;
			x = (*pila)->dato;
			// Ahora el segundo nodo de la lista ligada va a ser el primero
			*pila = (*pila)->siguiente;
			// Borra el primer nodo de la lista ligada
			free(nodo);
			// Regresa el valor que contenía el nodo que se eliminó
			printf("Se a sacado el numero %d de la pila\n",x);
			return x;
		}else{
			printf("la pila esta vacia\n");
		return 0;
		}
	 
	}
	 
	/*
	    Regresa 1 si no hay nodos en la lista ligada y cero en caso contrario
	    *pila es el apuntador que apunta al primer nodo de la lista ligada (la cima de la pila)
	*/

	
	
	 
	void nodos_pila(ptrNodo nodo)
	{
	 if (nodo == NULL)
	     printf("La pila está vacia\n");
	 else
	     {
	      while (nodo != NULL)
	            {
	             printf("%d\n",nodo->dato);
	             nodo = nodo->siguiente;
	            }
	      printf("\n");
	     }
	}
	
	void PilaVacia(){
		if(pila_vacia(&pila) == 0){
			printf("La Pila NO Esta Vacia\n");
		}else{
			printf("La Pila ESTA Vacia\n");
		}
	}
	
	void MostrarPila(){

	    ptrPila reco = pila;
	    printf("\nListado de elementos de la Pila");
	    printf("\n===================================");
	    while (reco != NULL)
	    {
	        printf("%i  \n", reco->dato);
	        reco = reco->siguiente;
	    }
	    printf("\n===================================\n\n");
		printf("\n");
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	int opcion;
	
	do{
		system("cls");


		printf("          INICIO > ESTRUCTURAS > PILAS \n\n");
		printf(
			"1. Pila Vacia  \n"
			"2. Apilar  \n"
			"3. Desapilar \n"
			"4. Mostrar Pila \n"
			"0. Atras \n"
			"\nopcion: ");
		opcion = soloNum();
		
		switch(opcion){
			case 1:
				PilaVacia();
				system("pause");
				continue;
			case 2:
				printf("introduce un numero a la Pila: ");
				int x = soloNum();
				push(&pila, x);
				system("pause");
				continue;
			case 3:
				pop(&pila);
				system("pause");
				continue;
			case 4:
				MostrarPila();
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




//_________________________________COLAS_____________________________________________
void Colas(){

	
	struct nodo {
	    int info;
	    struct nodo *sig;
	};
	
	struct nodo *raiz=NULL;
	struct nodo *fondo=NULL;
	
	
	int vacia()
	{
	    if (raiz == NULL)
	        return 1;
	    else
	        return 0;
	}
	
	void ColaVacia(){
		if(vacia() == 0){
			printf("La Cola NO Esta Vacia\n");
		}else{
			printf("La Cola ESTA Vacia\n");
		}
	}
	
	void insertar(int x)
	{
	    struct nodo *nuevo;
	    nuevo=malloc(sizeof(struct nodo));
	    nuevo->info=x;
	    nuevo->sig=NULL;
	    if (vacia())
	    {
	        raiz = nuevo;
	        fondo = nuevo;
	    }
	    else
	    {
	        fondo->sig = nuevo;
	        fondo = nuevo;
	    }
	    
	}
	
	int extraer()
	{
	    if (!vacia())
	    {
	        int informacion = raiz->info;
	        struct nodo *bor = raiz;
	        if (raiz == fondo)
	        {
	            raiz = NULL;
	            fondo = NULL;
	        }
	        else
	        {
	            raiz = raiz->sig;
	        }
	        free(bor);
	        printf("Se a despachado el numero %d de la cola\n",informacion);
	        return informacion;
		}
	    else
	    	printf("La Cola ya esta vacia! \n");
	        return -1;
	}
	
	void imprimir()
	{
	    struct nodo *reco = raiz;
	    printf("\nListado de elementos de la Cola");
	    printf("\n===================================\n");
	    while (reco != NULL)
	    {
	        printf("%i \n", reco->info);
	        reco = reco->sig;
	    }
	    printf("\n===================================\n\n");
	}
	
	












		
	int opcion; 
	do{
		system("cls");
		printf("          INICIO > ESTRUCTURAS > COLAS \n\n");
		printf(
			"1. Cola Vacia  \n"
			"2. Mostrar Cola  \n"
			"3. Encolar \n"
			"4. Despachar Cola  \n"
			"0. Atras \n"
			"\nopcion: ");
		opcion = soloNum();
		
		switch(opcion){
			case 1:
				ColaVacia();
				system("pause");
				continue;
			case 2:
				imprimir();
				system("pause");
				continue;
			case 3:
				printf("Introduce un Numero a la Cola: ");
				int n = soloNum();
				insertar(n);
				system("pause");
				continue;
			case 4:
				extraer();
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



//_________________________________LISTAS_____________________________________________
void Listas(){
	
	
	// Función para insertar un elemento en la lista
	// al final de la misma, como se puede observar
	// el puntero de inicio que se recibe se ha pasado
	// por referencia y por tanto se ha de especificar
	// con un doble asterisco
	int InsertarElemento(Nodo **Inicio)
	{
	     Nodo *Elemento = NULL;
	     Nodo *Recorrer = NULL;
	     Nodo *Ultimo = NULL;
	     // Recorremos la lista hasta llegar al final
	     // de la misma, en el puntero ultimo se quedara
	     // almacenado la dirección de memoria del ultimo
	     // elemento de la lista, si no existe ningún elemento
	     // en la lista se queda con valor nulo asignado
	     // En primer lugar se asigna el contenido del puntero
	     // de inicio al puntero recorrer
	     Recorrer = *Inicio;
	     while(Recorrer!=NULL) {
	       Ultimo = Recorrer;
	       Recorrer=Recorrer->Siguiente;
	     }
	     // Creamos el nuevo nodo o elemento que se quiere
	     // insertar
	     Elemento = (Nodo *)malloc(sizeof(Nodo));
	     // si ha existido un problema y no se crea el elemento
	     // devolver un error, este tipo de interrupción del código
	     // es preferible realizarlo utilizando condicionales y
	     // insertando un return para forzar la finalización de
	     // la función
	     if(Elemento == NULL ) return -1;
	     // Si se llega a este punto el elemento ha sido creado y
	     // solicitamos el nombre que se ha de almacenar en el
	     // mismo
	     printf("\nIntroduce un Numero a la Lista: ");
	     scanf(" %d",&Elemento->valor);
	     // asignamos el valor nulo al puntero siguiente de la lista
	     // ya que este elemento será el ultimo de la misma y por
	     // tanto no hay mas elementos posteriores
	     Elemento->Siguiente = NULL;
	     // Modificamos el puntero siguiente del ultimo elemento de la
	
	     // lista para que apunte al elemento nuevo creado preguntando
	     // primero si el valor de ultimo es null, ya que si es así
	     // significa que el elemento nuevo creado es el primero y por
	     // tanto hay que modificar el puntero de inicio
	     if (Ultimo == NULL ) {
	        // Es el primero de la lista
	        *Inicio = Elemento;
	     } else {
	        // Es el ultimo de la lista
	       Ultimo->Siguiente = Elemento;
	     }
	     // Salir de la función sin errores
	     
		 return 0;
	}
	
	// Función para listar elementos de la lista
	// Se recibe como valor el contenido del puntero
	// que indica el primer elemento de la lista
	void ListarElementos(Nodo *Inicio)
	{
	     // Se crea una variable para recorrer la lista
	     // asignándole como primer valor el elemento al
	     // cual apunta el puntero de inicio
	     Nodo *Recorrer = Inicio;
	     // Se visualiza un mensaje
	     printf("\nListado de elementos de la lista");
	     printf("\n===================================");
	     // Si hay elementos en la lista se recorre
	     // intercambiando el valor del puntero siguiente
	     // asignándolo al puntero recorrer que indica que
	     // existe o no un elemento según su valor
	     while(Recorrer!=NULL)
	     {
	        // Se visualiza el elemento
	        printf("\n%d",Recorrer->valor);
	        // Se cambia al elemento siguiente
	        Recorrer=Recorrer->Siguiente;
	     }
	     printf("\n===================================\n\n");
	}
	// Función Borrar elemento de la lista al principio
	int BorrarElementoListaPrincipio(Nodo **Inicio)
	{
	    // Variable para almacenar el elemento a borrar
	    Nodo *Borrar=NULL;
	    // Se comprueba si el puntero de inicio apunta a
	    // algún elemento si es así es que existen elementos
	    // y se puede borrar el primero en caso contrario
	    // no existe ningún elemento y no se puede borrar nada
	    if (*Inicio==NULL) {
	       printf("\nNo hay elementos que borrar\n");
	       return -1;
	    } else {
	      Borrar = *Inicio;
	      *Inicio = (*Inicio)->Siguiente;
	      free (Borrar);
	    }
	    return 0;
	}
	// Función Borrar elemento de la lista al final
	int BorrarElementoListaFinal(Nodo **Inicio)
	{
	    Nodo *Borrar=NULL;;
	    Nodo *Recorrer=NULL;
	    Recorrer=*Inicio;
	    if(Recorrer==NULL) {
	     printf("\nNo existen elementos que borrar\n");
	     return -1;
	    }
	    // Mientras no se llegue al ultimo elemento
	    while(Recorrer->Siguiente!=NULL) {
	      Borrar = Recorrer;
	      Recorrer= Recorrer->Siguiente;
	    }
	    // Si borrar es null es que solo existe un elemento
	   // y por tanto el valor de inicio ha de cambiar si no
	   // es así existen mas elementos y se ha borrar el ultimo
	   if(Borrar==NULL) {
	       Borrar = *Inicio;
	      *Inicio = NULL;
	      free (Borrar);
	   } else {
	     free(Borrar->Siguiente);
	     Borrar->Siguiente=NULL;
	   }
	   
	    return 0;
	}
	
	
	


	void ListaVacia(Nodo **Inicio){
		if (*Inicio==NULL) {
	       printf("\nLa Lista Esta Vacia.\n");
	    } else {
			printf("\n La Lista NO Esta Vacia.\n");
		}
	}

	Nodo *inicio = NULL;
	
	
	
	int opcion; 
	do{
		
		system("cls");
		printf("          INICIO > ESTRUCTURAS > LISTAS \n\n");
		printf(
			"1. Lista Vacia  \n"
			"2. Obtener Lista \n"
			"3. Insertar en Lista  \n"
			"4. Eliminar Principio de Lista  \n"
			"5. Eliminar Final de Lista  \n"
			"0. Atras \n"
			"\nopcion: ");
		opcion = soloNum();


		switch(opcion){
			case 1:
				ListaVacia(&inicio);
				system("pause");
				continue;
			case 2:
				ListarElementos(inicio);
				system("pause");
				continue;
			case 3:
				InsertarElemento(&inicio);
				system("pause");
				continue;
			case 4:
				BorrarElementoListaPrincipio(&inicio);
				system("pause");
				continue;
			case 5:
				BorrarElementoListaFinal(&inicio);
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
