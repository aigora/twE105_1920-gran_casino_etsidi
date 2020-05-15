#include <stdio.h>
#include <stdlib.h>

char *crearbaraja(int n);
char *barajar(char *baraja);
int juego(char *baraja,int apuesta, int saldo);
int resultado(int jugador, int crupier, int saldo, int apuesta);
int cambio(char cartas[]);
