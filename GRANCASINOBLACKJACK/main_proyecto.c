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
  int opcion,num,tam,i,aux,salir=0,cont=0;
  char r,n,name[30],pass[30];
  float auf;
  	usuario persona[30];
  	FILE *usu;
  		
 	printf("Bienvenido al Gran Casino ETSIDI\n");
	printf("Comencemos con indicar el numero de participantes y sus datos:\n");
	printf("- Numero de participantes:");
	scanf(" %i",&tam);
	//ignorar: persona = malloc(sizeof(usuario) * tam);
				
	for(i=0;i<tam;i++)
	{	salir=0;
		printf("Jugador n %i \n Has jugado alguna vez ya en el Gran Casino?(Si:1//No:0)\n",i+1);
		scanf("%i",&opcion);
		if(opcion==1)
			{	printf("Escribe tu nombre: ");
				scanf(" %s",name);
				printf("vamos a buscarte...\n");
				usu=fopen("Ficheros/jugadores.txt","r");
  					if (usu == NULL)
					{// Si el resultado es NULL mensaje de error
					printf("Error al abrir el fichero.\n");
					return -1;
						}
				fseek(usu, 0, SEEK_SET);
					do
				{
					if(strcmp(name, persona[i].nombre)==0)
							{salir=1;
								printf("Escribe tu contrasena:");
								scanf("%s",pass);
								while(cont<3&&strcmp(pass,persona[i].contrasena)!=0)
									{	printf("Contrasena incorrecta, inténtelo de nuevo\n Te quedan %i intentos",3-cont);
										scanf("%s",pass);
										cont++;
										
									}
									if(cont==3)
										{	printf("error en el incicio de sesion");
										}
									if(strcmp(pass,persona[i].contrasena)==0)
									{
											printf("Has iniciado sesión correctamente,tu saldo actual es:%i \n ",persona[i].saldo);
											while(n=!' '){
											persona[1].nombre[n]=persona[i].nombre[n];	
											}
											persona[1].saldo=persona[i].saldo;
									}
									
							}
							
								
						}
						while(salir==0&&fscanf(usu," %i\t%[^\t]\t%[^\t]\t%[^\t]\n",&persona[i].saldo,persona[i].nombre,persona[i].apellido,persona[i].contrasena)!=EOF);
					if(salir==0)
					{		
					printf("no se ha enocntrado información tuya en el archivo\n");
					}
				fclose(usu);		
			}
					
    	if(opcion==0)
    		{
    		printf("Vamos a proceder a registrarte.");
			printf("Escribe tu nombre:\n");
			scanf("%s", persona[i].nombre);
			printf("Escribe tu apellido:\n");
			scanf(" %[^\n]", persona[i].apellido);
			printf("Escribe tu saldo:\n");
			scanf(" %i", &persona[i].saldo);
			
			printf("Escribe tu contraseña:\n");
			scanf(" %[^\n]", persona[i].contrasena);
			printf("Vuelve a escribir tu contraseña:\n");
			scanf(" %[^\n]", pass);
				while(strcmp(pass, persona[i].contrasena)!=0)
				{
				printf("Las contraseñas no coinciden, repite el proceso");
				printf("Escribe tu contraseña:\n");
				scanf("%s", persona[i].contrasena);
				printf("Vuelve a escribir tu contraseña:\n");
				scanf("%s", pass);
				}
				if(strcmp(pass, persona[i].contrasena)==0)
				{
					usu=fopen("Ficheros/jugadores.txt","a");	
					if (usu == NULL)
						{// Si el resultado es NULL mensaje de error
						printf("Error al abrir el fichero.\n");
						return -1;
						}
				fseek(usu, 0, SEEK_END);
				fprintf(usu,"\n%i\t%s\t%s\t%s",persona[i].saldo,persona[i].nombre,persona[i].apellido,persona[i].contrasena);
				fclose(usu);
				}
			}
	}
	printf("\n%i\n",persona[1].saldo);
	do
	{
  		printf("Escoge entre una de los siguientes juegos:\n");
  		printf("\t _______________________________________\n");
  		printf("\t|	1) Ruleta			|\n");
 		printf("\t|	2) Blackjack			|\n");
 		printf("\t|	3) Maquina de slots		|\n ");
  		printf("\t|	4) Bingo			|\n");
  		printf("\t|_______________________________________|\n");

   		scanf("%i",&opcion);
	
		while(opcion<1||opcion>4) //bucle para asegurar que se escoja una de las opciones
		{
		printf("Elige una opcion disponible: \n");
		scanf("%i", &opcion);
		}
		
		switch(opcion) //Aquí vamos a comenzar el switch case, pidiendo al usuario que escoja entre 4 opciones, cada una asignada con un número
		  {
		  	case 1:
		  		espacios(10);
				printf("Has elegido: ");
		   		printf(" La Ruleta! \n");
		       	printf("Pulse 'c' para continuar \n Pulse 'r' para cambiar de juego\n"); // más adelante, si se pulsa c se ejecutará el juego
		  		scanf("%s",&r);
		   		break;
		      
			case 2:
				espacios(10);
				printf("Has elegido: ");
		   		printf(" Blackjack\n");
		    	printf("Pulse 'c' para continuar \n Pulse 'r' para cambiar de juego\n");
		    	scanf(" %c",&r);
		    	if(r=='c')
		    	{
		    	
int apuesta;
char *baraja;
char reglas,ronda;
int n=0,resultado;
	baraja = crearbaraja(2);
	printf("\n %s \n", baraja);
	baraja=barajar(baraja);
	printf("\nSe va a jugar con 2 barajas \nBarajando...\nListo!");
	printf("\nSu saldo es de %i. La apuesta minima son 5\n",persona[1].saldo);
	printf("Desea una breve explicacion de las reglas?('y' para si),('n' para no)\n");
		scanf(" %c", &reglas);
		if(reglas=='y')
		{
	 		printf("El blackjack es un juego de cartas en el que el jugador juega contra el crupier. El objetivo es quedar lo mas cerca de\n21 puntos sin pasarse.");
	 		printf("Las figuras valen 10 puntos y el resto de cartas su valor numerico. El As actua como un comodin y\nvale 11 o 1 puntos dependiendo de lo que ");
	 		printf("favorezca al jugador. Cada ronda comenzara repartiendo dos cartas al jugador y una al crupier. A partir de aqui el jugador podra doblar la ");
	 		printf("apuesta, pedir carta hasta que desee (siempre que no supere\nlos 21 puntos) o plantarse. Al plantarse se repartiran cartas al crupier, el cual robara");
	 		printf("carta siempre que tenga 16\no menos y se plantara con 17 o mas puntos\n");
		}
	else
	printf("Que comience el juego, ");
	printf("Cuanto desea apostar?\n");
		scanf("%i",&apuesta);
		if(apuesta<5||apuesta>persona[1].saldo)
		{
			printf("Debe cambiar su apuesta\n");
			scanf("%i",&apuesta);
		}
	persona[1].saldo= juego(baraja, apuesta, persona[1].saldo);
	printf("\nTe queda %i saldo, quieres jugar otra ronda?('y' para si),('n' para no)\n",persona[1].saldo);
	scanf(" %c",&ronda);
		while(ronda!='n')
		{
			if(ronda=='y')
			{
			espacios(23);
			baraja=barajar(baraja);
			persona[i].saldo= juego(baraja, apuesta, persona[1].saldo);
			printf("\nTe queda %i saldo, quieres jugar otra ronda?('y' para si),('n' para no)\n",persona[1].saldo);
			scanf(" %c",&ronda);
			}
		}
	printf("GRACIAS POR JUGAR VUELVA PRONTO");
	free(baraja);
		}
	
}
}
	while(r=='r');
	
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
