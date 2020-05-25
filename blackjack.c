#include "blackjack.h"

#include <string.h>

char *crearbaraja(int n)
{
char *palo = "A234567890JQK";
int i = 0;
int palos=0;
	int v1 = 0;
	char *cartas;
	cartas = calloc(sizeof(char)*52+1,n);
		while(palos < 8)	
		{
			memcpy(cartas+v1,palo,13); //en memcopy copia de mazo a cartas,
			v1+=13;
			palos++;
		}	
	
	
	return cartas;
	}	
char *barajar(char *baraja)
{
int n = strlen(baraja);
	char *barajado = calloc((n+1),1);
	int r;
	int z = 0;
	
		while(z < n)
		{
		r = aleato(0,n-1);
		if(baraja[r] != 0)	
			{
			barajado[z] = baraja[r];
			baraja[r] = 0;	
			z++;
			}
		}
	free(baraja);
	return barajado;	
}
float juego(char *baraja,float apuesta, float saldo)
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
		printf("\nJugador: ");
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
		if(cambio(cartajugador)==21)
		{
			printf("BLACKJACK, HAS GANADO");
			saldo=saldo+(apuesta*3);
			return saldo;
		}
		else
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
				printf("%.2f,%.2f\n",saldo,apuesta);
				if(apuesta+apuesta>saldo)
					{
					printf("No tienes suficiente saldo, cambia de opcion\n");
					scanf(" %c",&opcion);
					}			
					apuesta=apuesta*2;
					printf("Esta es tu nueva apuesta: %.2f\nQue desea hacer a continuacion?",apuesta);
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
		saldo=resultado(cambio(cartajugador),cambio(cartacrupier),saldo,apuesta);
		return saldo;
		
	}
float resultado(int jugador, int crupier, float saldo, float apuesta)
	{
		if(jugador>21)
					{
					printf("Tienes %i puntos, son mas de 21 has perdido J=%i;C=%i",jugador, jugador, crupier);
					saldo=saldo-apuesta;
					return saldo;
					}
		if(crupier>21)
					{
					printf("El crupier tiene %i puntos, son mas de 21 has ganado J=%i;C=%i",crupier, jugador, crupier);
					saldo+=apuesta*2;
					return saldo;	
					}
		if(crupier>jugador&&crupier<=21)
					{
					printf("El crupier tiene mas puntos que tu has perdido J=%i;C=%i",jugador,crupier);
					saldo=saldo-apuesta;
					return saldo;
					}
		if(crupier<jugador&&jugador<=21)
					{
					printf("Tienes mas puntos que el Crupier, HAS GANADO! J=%i;C=%i",jugador,crupier);
					saldo+=apuesta*2;
					return saldo;
					}
		if(crupier==jugador)
					{
					printf("Habeis empatado J=%i;C=%i",jugador,crupier);
					
					return saldo;
					}
		printf("fallo");
		return 0;
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
