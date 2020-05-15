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
void espacios(int n);
int main()
{
srand(time(NULL));
usuario persona[30];
int i, apuesta;
persona[i].saldo=100000;
char *baraja;
char reglas,ronda;
int n=0,resultado;
	baraja = crearbaraja(2);
	printf("\n %s \n", baraja);
	baraja=barajar(baraja);
	printf("\nSe va a jugar con 2 barajas \nBarajando...\nListo!");
	printf("\nSu saldo es de %i. La apuesta minima son 5\n",persona[i].saldo);
	printf("Desea una breve explicacion de las reglas?('y' para si),('n' para no)\n");
		scanf("%c", &reglas);
		if(reglas=='y')
		{
	 		printf("El blackjack es un juego de cartas en el que el jugador juega contra el crupier. El objetivo es quedar lo mas cerca de\n21 puntos sin pasarse.");
	 		printf("Las figuras valen 10 puntos y el resto de cartas su valor numerico. El As actua como un comodin y\nvale 11 o 1 puntos dependiendo de lo que ");
	 		printf("favorezca al jugador. Cada ronda comenzara repartiendo dos cartas al jugador y una al crupier. A partir de aqui el jugador podra doblar la ");
	 		printf("apuesta, pedir carta hasta que desee (siempre que no supere\nlos 21 puntos) o plantarse. Al plantarse se repartiran cartas al crupier, el cual robara");
	 		printf("carta siempre que tenga 16\no menos y se plantara con 17 o mas puntos\n");
		}
	printf("Que comience el juego, ");
	printf("Cuanto desea apostar?\n");
		scanf("%i",&apuesta);
		if(apuesta<5||apuesta>persona[i].saldo)
		{
			printf("Debe cambiar su apuesta\n");
			scanf("%i",&apuesta);
		}
	persona[i].saldo= juego(baraja, apuesta, persona[i].saldo);
	printf("\nTe queda %i saldo, quieres jugar otra ronda?('y' para si),('n' para no)\n",persona[i].saldo);
	scanf(" %c",&ronda);
		while(ronda!='n')
		{
			if(ronda=='y')
			{
			espacios(23);
			baraja=barajar(baraja);
			persona[i].saldo= juego(baraja, apuesta, persona[i].saldo);
			printf("\nTe queda %i saldo, quieres jugar otra ronda?('y' para si),('n' para no)\n",persona[i].saldo);
			scanf(" %c",&ronda);
			}
		}
	printf("GRACIAS POR JUGAR VUELVA PRONTO");
	free(baraja);
	return 0;
}
	int aleatorio(int minimo,int maximo)
	{     int numero;
		numero=rand()%((maximo-minimo)+1)+minimo;
		return numero;
	}
	void espacios(int n)
	{	int i;
		for(i=0;i<n;i++)
		{	printf("\n");
		}
	}
