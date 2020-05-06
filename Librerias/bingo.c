#include "bingo.h"
typedef struct{
		char nombre[30];
		char apellido[30];
		char contrasena[15];
		int saldo; //int, long int
		int carton[3][5];
}usuario;
void reglas()
	{	printf("Reglas del juego \n Primero, cada jugador debera de decidir si \
		quiere diseñar su propio carton o elegir uno predeterminado.\n Precios :\
		Predeterminado:5\t Personalizado: 7 \n \n Van a ir saliendo numeros aleatorios \
		entre el 1 y el 90 y vas a tener que ir marcando si esta en tu carton.\n Si tienes una linea\
		ganaras 12 monedas y si consigues hacer el bingo(carton completo) ganaras 80 monedas.")
		
	}
	
void disenocarton(usuario *person, int nuser)
{	int v[5],i,j;
	for(i=0;i<nuser;i++)
		{	printf("Cada fila contendra 5 elementos, cada uno de una decena:")
			for(i=0;i<3;i++)
				{	for(j=0;j<5;j++)
						{	scanf("%i",person->carton[i][j]);
						
						}
				}
		}
	ordenarcarton(*person);
	comprobarcarton(*person);
}
void ordenarcarton(usuario *matriz)
	{	int i,j,k
for(i=0;i<5;i++)
	{	for(j=0;j<3;j++)
			{	for(k=0;k<5;k++)
					{	for(z=0;z<3;z++)
							if(matriz->carton[z][k]<matriz->carton[j][i]) //menor a mayor se pone >
									{	valor=matriz->carton[z][k];
										matriz->carton[z][k]=matriz->carton[j][i];
										matriz->carton[j][i]=valor;
									}
					}
			}
	}
	}


