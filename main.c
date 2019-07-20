#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "ordenamiento.h"
#include "arboles.h"
#include "estructura.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int  soloNum();




int main(int argc, char *argv[]) 
{
	int opcion; 
	do{
		system("cls");
		printf("          INICIO\n\n");
		printf(
			"1. ordenamiento \n"
			"2. arboles \n"
			"3. estructura \n"
			"0. Salir \n"
			"\nopcion: ");
		opcion = soloNum();
		
		switch(opcion){
			case 1:
				ordenamiento();
				continue;
			case 2:
				arboles();
				continue;
			case 3:
				estructura();
				continue;
			case 0:
				printf("Adios..\n");
				continue;
			default:
				printf("OPCION INVALIDA, VUELVE A INTENTAR\n");
				system("pause");
				
				
		}
		
	
	}while(opcion != 0);
	
	return 0;
}




int  soloNum(){
	int ok = 0;
	int tam;
	while(ok == 0){
		ok = scanf( "%d", &tam );
		if (!ok){
			printf( "\ndato invalido, vuelve a intentar: " );
			getchar();
		}
	}
	return tam;
}

