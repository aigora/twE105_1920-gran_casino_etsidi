#include <stdio.h>
#include <stdlib.h>
int main ()
{
  int opcion;
  char r;
  	system("color 70");
 	printf("Buenos dias!! Bienvenido al Gran Casino ETSIDI\n");

  //En un futuro aqu� se pedir� al usuario que introduzca sus datos y saldo

  
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
		
		switch(opcion) //Aqu� vamos a comenzar el switch case, pidiendo al usuario que escoja entre 4 opciones, cada una asignada con un n�mero
		  {
		  	case 1:
		  		system("cls");
				printf("Has elegido: ");
		   		printf(" La Ruleta! \n");
		       	printf("Pulse 'c' para continuar \n Pulse 'r' para cambiar de juego\n"); // m�s adelante, si se pulsa c se ejecutar� el juego
		  		scanf("%s",&r);
		   		break;
		      
			case 2:
				system("cls");
				printf("Has elegido: ");
		   		printf(" Blackjack\n");
		    	printf("Pulse 'c' para continuar \n Pulse 'r' para cambiar de juego\n");
		    	scanf("%s",&r);
		     	 break;
		   	case 3:
		    	system("cls");
		    	printf("Has elegido: ");
		    	printf(" la Maquina de slots\n");
		    	printf("Pulse 'c' para continuar \n Pulse 'r' para cambiar de juego\n");
		    	scanf("%s",&r);
		      	break;
		   	 case 4:
		    	system("cls");
		    	printf("Has elegido: ");
		    	printf(" el Bingo\n");
		    	printf("Pulse 'c' para continuar \n Pulse 'r' para cambiar de juego\n");
		   		scanf("%s",&r);
		     	break;
		      
			}
 
	}
		while(r=='r');
return 0;}




