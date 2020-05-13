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
int cambio(char cartas[]);
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
	printf("\n Su saldo es de %i. La apuesta minima son 5\n",persona[i].saldo);
	printf("Que comience el juego, ");
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
		int i=0,n=0, j=0, k=0;
		char cartajugador[5];
		char cartacrupier[5];
		char opcion;
		cartacrupier[i]=baraja[n];
		n++;
		k++;
		if(cartacrupier[0]=='0')
		{
		printf("Crupier:\t|10|");
		}
		else
		printf("Crupier:\t|%c|",cartacrupier[0]);
		printf("Jugador: ");
		for(i=0;i<2;i++)
			{
			cartajugador[i]=baraja[n];
				if(cartajugador[i]=='0')
					{
					printf("|10|\t");
					n++;
					j++;
					}
				else
					{
					printf("|%c|\t",cartajugador[i]);
					n++;
					j++;
					}
			}
		printf("Tienes %i puntos ",cambio(cartajugador));
		printf("y el Crupier tiene %i puntos|\n",cambio(cartacrupier));
		printf("Puedes:\nPedir carta:'p'\nDoblar apuesta:'d'\nPlantarte:'f'\n");
		scanf(" %c",&opcion);
			while(opcion!='p'&&opcion!='d'&&opcion!='f')
				{
				printf("No es una opcion valida");
				scanf("%c",&opcion);
				}
				
		do
		{
		switch(opcion)
			{
			case 'p':
				j++;
				cartajugador[i]=baraja[n];
				n++;
				printf("Jugador: ");
				for(i=0;i<j;i++)
				{
				if(cartajugador[i]=='0')
					{
					printf("|10|\t");
					}
				else
					{
					printf("|%c|\t",cartajugador[i]);
					}
				}
				if(cambio(cartajugador)>21)
				{
				opcion='e';
				break;
				}
				printf("Tienes %i puntos ",cambio(cartajugador));
				printf("Quieres pedir otra? (p para pedir o f para terminar la ronda)\n");
				scanf(" %c",&opcion);
				break;
			case 'd':
				printf("%i,%i\n",saldo,apuesta);
				if(apuesta+apuesta>saldo)
					{
					printf("No tienes suficiente saldo, cambia de opcion\n");
					scanf(" %c",&opcion);
					}			
					apuesta=apuesta*2;
					printf("Esta es tu nueva apuesta: %i\nQue desea hacer a continuacion?",apuesta);
					scanf(" %c",&opcion);
				break;
			case 'f':
				if(cambio(cartajugador)>21)
				{
				opcion='e';
				break;
				}
				printf("Crupier:");
				do
				{
					i=k;
					cartacrupier[i]=baraja[n];
					n++;
					k++;
				if(cambio(cartacrupier)>21)
					{
						opcion='e';
						break;
					}
				}
				
				while(cambio(cartacrupier)<=16);
				for(i=0;i<k;i++)
					{
						if(cartacrupier[i]=='0')
							{
								printf("\t|10|");
							}
						else
							printf("\t|%c|",cartacrupier[i]);
					}
				
				printf("\nTienes %i puntos y el Crupier tiene %i puntos|\n",cambio(cartajugador),cambio(cartacrupier));
			
				opcion='e';
				break;		
			}	
		}
		while(opcion!='e');
		if(cambio(cartajugador)>21)
					{
					printf("Tienes %i puntos, son mas de 21 has perdido",cambio(cartajugador));
					}
		if(cambio(cartacrupier)>21)
					{
					printf("El crupier tiene %i puntos, son mas de 21 has ganado",cambio(cartacrupier));	
					}
		if(cambio(cartacrupier)>cambio(cartajugador&&cambio(cartacrupier)<=21))
					{
					printf("El crupier tiene mas puntos que tu has perdido J=%i;C=%i",cambio(cartajugador),cambio(cartacrupier));
					}
		if(cambio(cartacrupier)<cambio(cartajugador)&&cambio(cartajugador)<=21)
					{
					printf("Tienes mas puntos que el Crupier, HAS GANADO! J=%i;C=%i",cambio(cartajugador),cambio(cartacrupier));
					}			
		return baraja;
	}
	int cambio(char cartas[])
	{
	int i=0,j=0;
	char n=cartas[0];
	int total=0,num = 0;
	while(cartas[i]!='\0')
	{
		n=cartas[i];
		
		switch(n)	
		{
		case 'A':
			if(total+11<=21)
			{
			total=total+11;
			}
			else
			total=total+1;
		break;
		case 'K':
		case 'Q':
		case 'J':
		case '0':
			num = 10;
			total=total+num;
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
			total=total+num;
		break;
		}
	
	i++;
	j=i;
	}
	if(total>21)
		{
			for(i=0;i<j;i++)
				{
					if(cartas[i]=='A')
					total=total-10; 	
				}			
		}
	return total;
}
