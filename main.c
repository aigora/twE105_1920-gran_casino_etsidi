#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "blackjack.h"
typedef struct{
		char nombre[30];
		char apellido[30];
		char contrasena[15];
		int saldo; //int, long int
		
}usuario;

int aleatorio(int minimo,int maximo);
char *crearbaraja(int n);
char *barajar(char *baraja);
char *juego(char *baraja,int apuesta, int saldo);
int cambio(char n);
int main()
{
srand(time(NULL));
usuario persona[30];
int i, apuesta;
persona[i].saldo=100000;
char *baraja,*resultado;
int n=0;
	baraja = crearbaraja(2);
	printf("\n %s \n", baraja);
	baraja=barajar(baraja);
	printf("Baraja:\n %s", baraja);
	printf("\nSe va a jugar con 2 barajas \nBarajando...\nListo!");
	printf("\n Su saldo es de %i \n La apuesta minima son 5\n",persona[i].saldo);
	printf("Que comience el juego!\n");
	printf("Cuanto desea apostar?\n");
		scanf("%i",&apuesta);
		if(apuesta<5||apuesta>persona[i].saldo)
		{
			printf("Debe cambiar su apuesta");
			scanf("%i",&apuesta);
		}
	resultado= juego(baraja, apuesta, persona[i].saldo);
	free(baraja);
	free(resultado);
return 0;
}
	int aleatorio(int minimo,int maximo)
	{     int numero;
		numero=rand()%((maximo-minimo)+1)+minimo;
		return numero;
	}
	
	char *juego(char *baraja,int apuesta, int saldo)
	{
		int i=0;
		char carta1=baraja[i];
		char carta2=baraja[i+1];
		char carta3=baraja[i+2];
		char cartaextra, opcion;
		printf("Crupier: |%c|\nJugador:|%c|\t|%c|\n",carta1,carta2,carta3);
		printf("Tienes %i puntos y el Crupier tiene %i puntos|\n",(cambio(carta2)+cambio(carta3)),cambio(carta1));
		printf("Puedes:\nPedir carta:'p'\nDoblar apuesta:'d'\nPlantarte:'f'\n");
		scanf(" %c",&opcion);
			while(opcion!='p'&&opcion!='d'&&opcion!='f')
				{
				printf("No es una opcion valida");
				scanf("%c",&opcion);
				}
		switch(opcion)
		{
		case 'p':
		case 'd':
		case 'f':	
		
		
		}	
		printf("\n %s \n",baraja);
		return baraja;
	}
	int cambio(char n)
	{
	int num = 0;
	switch(n)	{
		case 'A':
			num = 1;
		break;
		case 'K':
		case 'Q':
		case 'J':
		case '0':
			num = 10;
		break;
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			num = n - '0';
		break;
	}
	return num;
	}
