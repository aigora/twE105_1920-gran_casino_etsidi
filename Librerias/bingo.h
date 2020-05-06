#include <stdio.h>
#include <stdlib.h>
typedef struct{
		char nombre[30];
		char apellido[30];
		char contrasena[15];
		int saldo; //int, long int
		int carton[3][5];
}usuario;
void reglas();
void disenocarton(usuario *person,int nuser);
void displaycarton(usuario *person,int nuser);
void comprobarcarton(usuario *usur, int n);
void ordenarcarton(usuario *matriz);
