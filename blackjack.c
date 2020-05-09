#include "blackjack.h"

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
	int i = 0;
		while(i < n)
		{
		r = aleatorio(0,n-1);
		if(baraja[r] != 0)	
			{
			barajado[i] = baraja[r];
			baraja[r] = 0;	
			i++;
			}
		}
	free(baraja);
	return barajado;	
}

