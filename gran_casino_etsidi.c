#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void espacios(int n);
int aleatorio(int minimo,int maximo);
typedef struct{
		char nombre[30];
		char apellido[30];
		char contrasena[15];
		int saldo; //int, long int
		
}usuario;

int main ()
{	srand(time(NULL));
  int opcion,num,tam,i,aux,salir=0,mod;
  char r,name[30],pass[30];
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
								printf("%s",persona[i].contrasena);
								scanf("%s",pass);
								if(strcmp(pass,persona[i].contrasena)==0)
									{	printf("Has iniciado sesión correctamente,tu saldo actual es:%i \n ",persona[i].saldo);
										
									}
							}
							
								
						}
						while(salir==0&&fscanf(usu," %i\t%[^\t]\t%[^\t]\t%[^\t]\n",&persona[i].saldo,persona[i].nombre,persona[i].apellido,persona[i].contrasena)!=EOF);
					if(salir==0)
					{		printf("no se ha enocntrado información tuya en el archivo\n");
									
								
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
			printf("%i",&persona[i].saldo);
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
					usu=fopen("jugadores.txt","a");	
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
		    	scanf("%s",&r);
		     	 break;
		   	case 3:
		    	espacios(10);
		    	printf("Has elegido: ");
		    	printf(" la Maquina de slots\n");
		    	printf("Pulse 'c' para continuar \n Pulse 'r' para cambiar de juego\n");
		    	scanf("%s",&r);
		      	break;
		   	 case 4:
		   		espacios(10);
		    	printf("Has elegido: ");
		    	printf(" el Bingo\n");
		    	printf("Pulse 'c' para continuar \n Pulse 'r' para cambiar de juego\n");
		   		scanf("%s",&r);
		   			if(r=='c')
		   				{	
						   }
		     	break;
		      
			}
 
	}
		while(r=='r');
	
	
return 0;
}
	
	void espacios(int n)
	{	int i;
		for(i=0;i<n;i++)
		{	printf("\n");
		}
	}
	
	int aleatorio(int minimo,int maximo)
	{     int numero;
		numero=rand()%((maximo-minimo)+1)+minimo;
		return numero;
	}

