#include <stdio.h>
#include <stdlib.h>
typedef struct{
		char nombre[30];
		char apellido[30];
		char contrasena[15];
		int saldo; //int, long int
		int carton[3][5];
}usuario;
int aleat(int minimo,int maximo);
void reglas(int n);
void disenocarton(int matriz[][5],int n, int c);
void display(int matriz[][5],int n, int c);
int comprobarcarton(int matriz[][5], int n,int c);
void ordenarcarton(int matriz[][5],int n, int c);
void cartonaleatorio(int matriz[][5],int n, int c);
int bingolinea(int matriz[][5],int n, int c,int numero);
void saldobingo(int *saldo,int mas);

