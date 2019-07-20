#include "ordenamiento.h"

#include <stdio.h>
#include <stdlib.h>


int lista[10] ;
int tam; 



void ordenamiento() {

	
	int opcion; 
	
	do{
		system("cls");
		printf("          INICIO > ORDENAMIENTO\n\n");
		
		
		printf(
			"1. Cargar Vector \n"
			"2. Bubble Sort \n"
			"3. Select Sort  \n"
			"4. Binarie Sort \n"
			"5. Quick Sort Sort \n"
			"0. Atras \n");
			
		printf("Vector: ");
		if(tam){
			mostrar(lista,tam);
		}else{
			printf("Vacio");
		}
		printf("\n");
		printf("\nopcion: ");
		opcion = soloNum();
		
		switch(opcion){
			case 1:
				cargarVector();
				system("pause");
				continue;
			case 2:
				burbuja(lista,tam);
				system("pause");
				continue;
			case 3:
				seleccion(lista,tam);
				system("pause");
				continue;
			case 4:
				binaria(lista,tam);
				system("pause");
				continue;
			case 5:
				quicksort(lista,tam);
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



void cargarVector(){
	int i;
	printf("Escriba la Dimension del Vector: ");
	tam = soloNum();
	for(i=0;i<tam;i++){
		printf("inserte un numero(%d/%d): ",(i+1),tam);
		lista[i] = soloNum();
	}
}



/*
	EMETODO BUBBLE SORT ESTE SELECCIONA
	EL PRIMERO Y LO COMPARA CON EL SIGUIENTE
	SI ES MAYOR LOS INTERCAMBIA SI NO
	PROSIGUE HACER LO MISMO CON EL SIGUIENTE 
*/
void burbuja(int list[], int size){
    int i,j,temp;

	printf("         Ordenando Vector Con Bubble Sort \n");
    for (i=0;i<size;i++){
        for (j=0;j<(size-i-1);j++){
            if (list[j] > list[j+1]){
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
        
        mostrar(list,size);  
    } 
}


/*
	METODO SELECTION SORT ESTE 
	SELECCIONA EL ELEMENTO MENOR
	DEL VECTOR Y LUEGO LOS VA 
	ITENRCAMBIANDO EN ESE ORDEN 
	SELECCIONADO
	 
*/
void seleccion(int list[], int size){
	int i,j,k,temp,menor;

	//DEFINE CUAL ES EL MENOR DE LA LISTA
	printf("         Ordenando Vector Con Selection Sort \n");
	for(i=0;i<size;i++){
		menor = i;
		for(j=i+1;j<size;j++){
			if(list[menor] > list[j]){
				menor = j;
					
			}
		}
		printf("Menor: %i ...", list[menor]);
		temp = list[menor];
		list[menor] = list[i];
		list[i] = temp;
		
		mostrar(list,size);	
	}
	puts("presione una tecla para continuar..");
    getch();
}

/*
	METODO DE BINARIO HALLAMOS UN ELEMENTO CENTRAL
	COMPARAMOS CON EL ELEMENTO A INSERTAR SI DICHO
	ELEMENTO ES MENOR O IGUAL SE QUEDA EN LA DERECHA
	EN CASO CONTRARIO SE QUEDA CON LA PARTE IZQUIERDA
	SE REPITE EL PROCESO CON EL AREA CON LA QUE SE QUEDA.
*/
void binaria(int list[],int size){
	
	int auxiliar,centro,izquierda,derecha,i,k;
	printf("         Ordenando Vector Con Binaria Sort \n");
    for (k = 1; k < size; k++)
    {
        auxiliar=list[k];
        izquierda=0;
        derecha = k-1;
        //busqueda binaria de la posicion de insercion
        while (izquierda <= derecha)
        {
            centro = (int) ((izquierda + derecha)/2);
            
                if (auxiliar <= list[centro])
                    derecha = centro-1;
                else
                    izquierda = centro+1;
        }
        //se desplazan a la derecha los elementos ordenados
		for (i = k-1; i>= izquierda; i--)
            list[i+1] = list[i];
        list[izquierda] = auxiliar;
    	
		
		mostrar(list,size);   
    }
	puts("presione una tecla para continuar..");
	getch();
	
}





/*
	METODO QUICKSORT, SE SELECCIONA UN PIVOTE
	LUEGO SE LE COLOCAN DEL LADO IZQ TODOS LOS
	MENORES Y DEL LADO DER TODOS LOS MAYORES
	Y ASI HASTA QUE QUEDE ORDENADA.
*/
void quicksort(int list[], int size){
	printf("         Ordenando Vector Con QuickSort \n");
	void quick(int list[], int izq, int der){
		int i = izq, j = der, tmp;
		int p = list[(izq +der)/2];
		while(i<=j){
			while(list[i] < p) i++;
			while(list[j] > p) j--;
			if(i<=j){
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
				i++;
				j--;

			}
		}
		printf("pivote: %d", p);
		mostrar(list,size);
		if(izq<j) quick(list,izq,j);
		if(i<der) quick(list,i,der);	
	}

	quick(list,0,size-1);
	puts("presione una tecla para continuar..");
	getch();
	
}




/*
	IMPRIME EN PANTALLA EL MENU
	DE LAS DIFERENTES OPCIONES 
	DE LOS METODOS DE ORDENAMIENTO
*/
void panel(int list[], int size){
	int i;
	system("cls");	
	printf(
		"   __________________________________________________\n"
		"  |                                                  |\n"
		"  | 1. Cargar Vector                                 |\n"
		"  | 2. Bubble Sort                                   |\n"
		"  | 3. Select Sort                                   |\n"
		"  | 4. Binarie Sort                                  |\n"
		"  | 5. Quick Sort                                    |\n"
		"  | 0. Salir                                         |\n"
		"  |__________________________________________________|\n"
		"                  Vector Original                      \n"
		"   "
	);

	mostrar(list,size);	
}

/*
	IMPRIME EN PANTALLA LOS PASOS
	QUE VA DANDO AL MOMENTO DEL
	ORDENAMIENTO DEL VECTOR
*/
void mostrar(int list[], int size){
	int i;
	
	printf("   ");
    for (i=0;i<size;i++){
        printf("| %d ", list[i]);
    }
	
	if(!size){
		printf("| vector vacio ");
	}
	printf("|\n");
	Sleep(1000);
}

