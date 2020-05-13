#include "bingo.h"
#include <stdio.h>
#include <time.h>

void reglas(int n)
	{	printf("Reglas del juego \n Primero, cada uno de los %i jugadores debera de decidir siquiere diseñar su propio carton o elegir uno predeterminado.\n Precios :		Predeterminado:5\t Personalizado: 7 \n \n Van a ir saliendo numeros aleatorios 	entre el 1 y el 90 y vas a tener que ir marcando si esta en tu carton.\n Si tienes una linea ganaras 12 monedas y si consigues hacer el bingo(carton completo) ganaras 80 monedas.\n\n",n);
	
	}
	int aleat(int minimo,int maximo)
	{     int numero;
		numero=rand()%((maximo-minimo)+1)+minimo;
		return numero;
	}
	void ordenarcarton(int matriz[][5],int n, int c)
	{	int i,j,k,z;
	int valor;
for(i=0;i<5;i++)
	{		for(j=0;j<3;j++)
			{	for(k=0;k<5;k++)
					{	for(z=0;z<3;z++)
						{if(matriz[z][k]>matriz[j][i]) //menor a mayor se pone >
									{	valor=matriz[z][k];
										matriz[z][k]=matriz[j][i];
										matriz[j][i]=valor;
									}
						}
					}
			}
	}
		
			
	}
int comprobarcarton(int matriz[][5], int n,int c)
	{	int i,j,cont[10],contadorfilas[3], mal;
				for(i=0;i<10;i++)
				{	cont[i]=0;
				}
				
	
		for(i=0;i<n;i++)
			{	for(j=0;j<c;j++)
					{	
							if(matriz[i][j]>0&&matriz[i][j]<=9)
							{	cont[0]++;
							
							}
							if(matriz[i][j]>=10&&matriz[i][j]<=19)
							{	cont[1]++;
							
							}
							if(matriz[i][j]>=20&&matriz[i][j]<=29)
							{	cont[2]++;
							
							}
							if(matriz[i][j]>=30&&matriz[i][j]<=39)
							{	cont[3]++;
							}
							if(matriz[i][j]>=40&&matriz[i][j]<=49)
							{	cont[4]++;
							}
							if(matriz[i][j]>=50&&matriz[i][j]<=59)
							{	cont[5]++;
							}
							if(matriz[i][j]>=60&&matriz[i][j]<=69)
							{	cont[6]++;
								
							}
							if(matriz[i][j]>=70&&matriz[i][j]<=79)
							{	cont[7]++;
							
							}
							if(matriz[i][j]>=80&&matriz[i][j]<=89)
							{	cont[8]++;
								
							}
							if(matriz[i][j]>=90&&matriz[i][j]<=99)
							{	cont[9]++;
							}
							else if(matriz[i][j]<=0&&matriz[i][j]>99)
								mal=1;
					}
			}
			for(i=0;i<10;i++)
				{	if(cont[i]>3)
						{	mal=1;
						
						}
					
				}
				for(i=0;i<5;i++)
						{	
						for(j=0;j<3;j++)
									{	for(k=0;k<3;k++)
										{	for(z=0;z<5;z++)
												{		
												if((matriz[j][i]==matriz[k][z])&&((k!=j)||(z!=i)))
														{
															mal=1;
														}
														
												}
										}
									}
						}
			if(mal==1)
				return mal;
			else
				return 2;
	}
	
void disenocarton(int matriz[][5],int n, int c)
{	int v[5],i,j;
	
	
			printf("Cada fila contendra 5 elementos, cada uno de una decena:");
			for(i=0;i<3;i++)
				{	for(j=0;j<5;j++)
						{	scanf("%i",&matriz[i][j]);
						
						}
		}
		
	ordenarcarton(matriz,3,5);
		if(comprobarcarton(matriz,3,5)==1)
				{	while(comprobarcarton(matriz,3,5)==1)
						{	printf("Ooops... Ha habido un error al introducir los datos, recuerda que no debe de haber mas de 3 numeros de la misma decena\n");
							printf("introduce de nuevo tu matriz:\n");
									for(i=0;i<3;i++)
										{	for(j=0;j<5;j++)
												{	scanf("%i",&matriz[i][j]);
						
													}
												}
							comprobarcarton(matriz,3,5);
						}
				}
		else if(comprobarcarton(matriz,3,5)==2)
			printf("Tu carton se ha diseñado perfectamente!\n\n");
	
}

void display(int matriz[][5],int n, int c)
	{	int i,j;
			printf("________________________________________\n");
		for(i=0;i<3;i++)
			
	{		printf("| ");
		for(j=0;j<5;j++)
			{		printf(" %i\t",matriz[i][j]);
			}
			printf(" |\n");
	}
		printf("_______________________________________\n\n");
}


void cartonaleatorio(int matriz[][5],int n, int c)
{int i,j,k,z,cont[10],r=0;
int comprobacion=0;
for(i=0;i<10;i++)
				{	cont[i]=0;
				}
				
				for(j=0;j<5;j++)
					{	
							matriz[0][j]=aleat(1,99);
							if(matriz[0][j]>=90&&matriz[0][j]<=97)
							{		matriz[1][j]=matriz[0][j]+2;
									matriz[2][j]=matriz[0][j]-2;
							}
								if(matriz[0][j]>=98&&matriz[0][j]<=99)
							{		matriz[1][j]=matriz[0][j]-5;
									matriz[2][j]=matriz[0][j]-2;
							}
							
							else
							{	matriz[2][j]=matriz[0][j]-9;
								matriz[1][j]=matriz[0][j]+11;
							}
						
						
					}	
			ordenarcarton(matriz,3,5);
			
			while(comprobacion==0)	
			{	comprobacion=1;
			r++;
			if(r==15)
				{
				
				for(j=0;j<5;j++)
					{	
							matriz[0][j]=aleat(1,99);
							if(matriz[0][j]>=90&&matriz[0][j]<=97)
							{		matriz[1][j]=matriz[0][j]+2;
									matriz[2][j]=matriz[0][j]-2;
							}
								if(matriz[0][j]>=98&&matriz[0][j]<=99)
							{		matriz[1][j]=matriz[0][j]-5;
									matriz[2][j]=matriz[0][j]-2;
							}
							
							else
							{	matriz[2][j]=matriz[0][j]-9;
								matriz[1][j]=matriz[0][j]+11;
							}
						
						
					}
				}
			
			
				for(i=0;i<10;i++)
				{	cont[i]=0;
				}
			
			for(i=0;i<n;i++)
			{	for(j=0;j<c;j++)
					{	
							if(matriz[i][j]>0&&matriz[i][j]<=9)
							{	cont[0]++;
								if(cont[0]>3)
									{	matriz[i][j]=matriz[i][j]+10;
									}
									
							}
							if(matriz[i][j]>=10&&matriz[i][j]<=19)
							{	cont[1]++;
							if(cont[1]>3)
									{	matriz[i][j]=matriz[i][j]+10;
									}
									
							}
							if(matriz[i][j]>=20&&matriz[i][j]<=29)
							{	cont[2]++;
								if(cont[2]>3)
									{	matriz[i][j]=matriz[i][j]+10;
									}
									
							}
							if(matriz[i][j]>=30&&matriz[i][j]<=39)
							{	cont[3]++;
								if(cont[3]>3)
									{	matriz[i][j]=matriz[i][j]+10;
									}
									
							}
							if(matriz[i][j]>=40&&matriz[i][j]<=49)
							{	cont[4]++;
								if(cont[4]>3)
									{	matriz[i][j]=matriz[i][j]+10;
									}
									
							}
							if(matriz[i][j]>=50&&matriz[i][j]<=59)
							{	cont[5]++;
								if(cont[5]>3)
									{	matriz[i][j]=matriz[i][j]+10;
									}
									
							}
							if(matriz[i][j]>=60&&matriz[i][j]<=69)
							{	cont[6]++;
								if(cont[6]>3)
									{	matriz[i][j]=matriz[i][j]+10;
									}
									
							}
							if(matriz[i][j]>=70&&matriz[i][j]<=79)
							{	cont[7]++;
								if(cont[7]>3)
									{	matriz[i][j]=matriz[i][j]+10;
									}
									
							}
							if(matriz[i][j]>=80&&matriz[i][j]<=89)
							{	cont[8]++;
								if(cont[8]>3)
									{	matriz[i][j]=matriz[i][j]+10;
									}
									
							}
							if(matriz[i][j]>=90&&matriz[i][j]<=99)
							{	cont[9]++;
								if(cont[9]>3)
									{	matriz[i][j]=matriz[i][j]-10;
									}
									
							}
							if(matriz[i][j]>99)
								matriz[i][j]=matriz[i][j]-30;
								if(matriz[i][j]<=0)
								matriz[i][j]=matriz[i][j]+10;	
								
						}
					}
					for(i=0;i<10;i++)
				{	if(cont[i]>3)
						{	comprobacion=0;
						
						}
					
				}
						ordenarcarton(matriz,3,5);
					
					for(i=0;i<5;i++)
						{	
						for(j=0;j<3;j++)
									{	for(k=0;k<3;k++)
										{	for(z=0;z<5;z++)
												{		
												if((matriz[j][i]==matriz[k][z])&&((k!=j)||(z!=i)))
														{matriz[j][i]=matriz[j][i]+3;
														
														comprobacion=0;
													
														}
														if(matriz[k][z]<=0)
															{	matriz[k][z]=-1*matriz[k][z];
															}
												}
										}
									}
						}
					
					}
				
		//bucle while cuya condicion sea mirar si todos locntadores sean menor que tres
			
}

