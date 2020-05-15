#include <stdio.h>
#include "bingo.h"
typedef struct{
		char nombre[30];
		char apellido[30];
		char contrasena[15];
		int saldo; //int, long int
		int carton[3][5];
}jugador; 



int main()
{	jugador matriz; 
matriz.saldo=0;
int tam=5,i,j,x;	

	reglas(tam);
	cartonaleatorio(matriz.carton,3,5);
	display(matriz.carton,3,5);
		switch(bingolinea(matriz.carton,3,5,aleat(1,99)))
				{	case 1:
						printf("linea");
						
					default:
						printf("siguiente numero");
				}
	saldobingo(&matriz.saldo,4);
	saldobingo(&matriz.saldo,3);
	printf("%i",matriz.saldo);
		
return 0;
}

