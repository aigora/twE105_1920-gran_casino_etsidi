#include "Maquina_tragaperras.h"
#include <stdio.h>
#include <time.h>
int aleatorio(int minimo,int maximo)
	{ 
	    
		int numero;
		numero=rand()%((maximo-minimo)+1)+minimo;
		return numero;
	}
	
void vueltas(int rodillos[3][3], int filas, int columnas)
{
	int i,j,k;
	int repeat;
	
	//Matriz de números aleatorios comprendidos entre el 0 y 7.
	for(i=0;i<3; i++)
	{
		for(j=0;j<3;j++)
		{
		rodillos[i][j]=aleatorio(0,7);
		}
	}
	//Comprobar que dentro de la misma columna no hay dos núemros iguales 
	//En cada rodillo (columna de la matriz) aparece cada símbolo una sola vez
	for(i=0;i<3;i++)
	{ 
		repeat=rodillos[0][i];   
		for(k=1;k<3;k++)
	      {  
		  	while(rodillos[k][i]==repeat) 
	            {  
				rodillos[k][i]=aleatorio(0,7);
				}
		  }
		repeat=rodillos[1][i];  
		for(k=2;k<3;k++)
	      {  
		  	while(rodillos[k][i]==repeat)
	            {  
				rodillos[k][i]=aleatorio(0,7);
				}
		  }   
	}
	
	for(k=0;k<3;k++)
	{
		while(rodillos[0][k]==rodillos[2][k])
		{
			rodillos[2][k]=aleatorio(0,7);
		}
	}

	for(i=0;i<3; i++)
	{
		for(j=0;j<3;j++)
		{
		printf("%d\t", rodillos[i][j]);
		}
		printf ("\n");
	}
}

float ganado(int rodillos[3][3], int filas, int columnas)
{
	int i, j, k, h;
	float ganancia=0, ganancia1=0;
	int gana[9];
	
	//ganancias de los números de la matriz
	for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
			gana[k]= rodillos[i][j];
			if(gana[k]==0 || gana[k]==1 || gana[k]==2 || gana[k]==3)
				{
				ganancia= ganancia+0.02;
				}
			else if(gana[k]==4 || gana[k]==5 || gana[k]==6)
				{
				ganancia= ganancia+0.05;
				}
			else if (gana[k]==7)
				{
				ganancia= ganancia+0.1;
				}
			}
		}
	
	// ganancias de la diagonal
	if (rodillos[0][0]== rodillos[1][1]== rodillos[2][2])
		{
			ganancia= ganancia+ rodillos[0][0]*0.2;
		}
	else if (rodillos[0][0]== rodillos[1][1])
		{
			ganancia= ganancia+ rodillos[0][0]*0.1;
		}	
	else if (rodillos[2][2]== rodillos[1][1])
		{
			ganancia= ganancia+ rodillos[2][2]*0.1;
		}	
	else if (rodillos[0][0]== rodillos[2][2])
		{
			ganancia= ganancia+ rodillos[0][0]*0.1;
		}
	
	//ganancias cuando se repiten dos números en una fila
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				if(rodillos[i][j]== rodillos[i][k] && k!=j)
				{
					ganancia1= rodillos[i][j]*0.5;
				}
			}
		}
	}
	
	//ganancias si una línea tiene todos los números iguales
	do
	{
		if (rodillos[i][j]== rodillos[i][j+1]== rodillos[i][j+2])
		{
		ganancia= ganancia+ rodillos[i][j];	
		}
	}
	while(j=0);
	
	ganancia= ganancia+ ganancia1;
	return ganancia;
}
