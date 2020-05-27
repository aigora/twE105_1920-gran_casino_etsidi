#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bingo.h"
#include "blackjack.h"
#include "Maquina_tragaperras.h"
#include "ruleta.h"
#define N 99

typedef struct{
		char nombre[30];
		char apellido[30];
		char contrasena[15];
		float saldo; //int, long int
		int carton[3][5];
}usuario;
void espacios(int n);
int aleato(int minimo,int maximo);

int main ()
{	srand(time(NULL));
  int opcion,num,tam,i=0,aux,salir=0,cont=0,n=0,option;
  int numbingo[99],bolita,tiradab,ca,lineasfich=0,apuest;
  int j,k,question,ganador=-1,nlinea[30];
  int rodillos[3][3];
  	int regl, numero, normas, volver, cambiojuego, njugadores, h;
	float  saldoruleta, saldoanterior, saldototal;
  float win=0,total,ganancia=0,apuesta,resultado,auf,linea;
  char continuar,regla,ronda;
  char r,name[30],pass[30];
  char *baraja;	
  	usuario persona[N];
  	usuario modif[N];
  	
  	char tipo;
	char par = 'p';
    char impar = 'i';
    char rojo = 'r';
    char negro = 'n';
    char primeramitad = 'p';
    char segundamitad = 's';
    char primeradoc = 'x';
    char segundadoc = 'y';
    char terceradoc = 'z';
    char primeracol = 'i';
    char segundacol = 'j';
    char terceracol = 'k';
    char primeracall = 'q';
    char segundacall = 'w';
    char terceracall = 'e';
    char cuartacall = 'r';
    char quintacall = 't';
    char sextacall = 'o';
    
    int odd_check=compruebaPar(numero);
    int color_check=compruebaColor(numero);
    int half_check=compruebaMitad(numero);
    int twelve_check=compruebaDocena(numero);
    int column_check=compruebaColumna(numero);
    int street_check=compruebaCalle(numero);
    int line_check=compruebaLinea(numero);
  	
  	FILE *usu;
  	FILE *cart;
		
	
	i=0;
		
 	printf("Bienvenido al Gran Casino ETSIDI\n");
	printf("Comencemos con indicar el numero de participantes y sus datos:\n");
	printf("- Numero de participantes:");
	scanf(" %i",&tam);
	//ignorar: persona = malloc(sizeof(usuario) * tam);
				
	for(i=0;i<tam;i++)
	{	salir=0;
		printf("Jugador n %i \n Has jugado alguna vez ya en el Gran Casino?(Si:1//No:0)\n",i+1);
		scanf("%i",&opcion);
		while(opcion!=0&&opcion!=1)
			{	printf("Introduce una de las opciones");
				scanf("%i",&opcion);
			}
		if(opcion==1)
			{	printf("Escribe tu nombre: ");
				scanf(" %s",name);
				for(k=0;k<i;k++)
								{	while(strcmp(name,persona[k].nombre)==0)
									{	printf("Escribe de nuevo tu nombre: ");
										scanf(" %s",name);
									}
								}
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
									{	printf("Contrasena incorrecta, intentelo de nuevo\n Te quedan %i intentos",3-cont);
										scanf("%s",pass);
										cont++;
										
									}
									if(cont==3)
										{	printf("error en el inicio de sesion");
											opcion=0;
										}
									if(strcmp(pass,persona[i].contrasena)==0)
									{printf("Has iniciado sesion correctamente,tu saldo actual es:%.2f \n ",persona[i].saldo);
										
									}
									
							}
							
								
						}
						while(salir==0&&fscanf(usu," %f\t%[^\t]\t%[^\t]\t%[^\t]\n",&persona[i].saldo,persona[i].nombre,persona[i].apellido,persona[i].contrasena)!=EOF);
					if(salir==0)
					{		printf("no se ha enocntrado información tuya en el archivo\n");
									opcion=0;
								
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
			scanf(" %f", &persona[i].saldo);
			
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
				fprintf(usu,"\n %f\t%s\t%s\t%s",persona[i].saldo,persona[i].nombre,persona[i].apellido,persona[i].contrasena);
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
		  		while(r!='r'&& r!='c')
                {
                   printf("Debe introducir 'c' o 'r'\n");
						scanf(" %c", &r);

                }
                if(r=='c'){
                	 printf("Bienvenido al juego de la ruleta.\n");
	printf("1) Reglas 2)Jugar\n");
	scanf("%i", &regl);
	while(regl!=1 && regl!=2)
	{
	printf("1) Reglas 2)Jugar: ");
	scanf("%i", &regl);
	}
	do{
	while(regl==1)
	{
		printf("Las reglas de la ruleta:\n");
		printf("Tienes que escoger un tipo de apuesta\n");
		printf("Solo podras apostar a una unica caracteristica, es decir si apuetas a rojo solo podras apostar rojo\n");
		while(regl!=2){
			printf("Pulse 2 para jugar: \n");
		scanf("%i", &regl);
		}
	}
	if(regl==2)
	{
		
		njugadores=tam;
		for(h=0; h<njugadores; h++){
		printf("Jugador %i, %s Elija cuanto dinero quiere apostar: \n", h+1, persona[h].nombre);
		scanf("%f", &saldoanterior);
			while((persona[h].saldo-saldoanterior)<0)
				{	printf("No le queda saldo para realizar esa apuesta, introduzca mas saldo:\n");
					scanf("%f",&saldoanterior);
					persona[h].saldo+=saldoanterior;
					printf("introduzca la apueta:\n");
					scanf("%f",&saldoanterior);
				}
				persona[h].saldo-=saldoanterior;
		printf("Elija su apuesta:\n");
		printf("1) Par/Impar\n");
		printf("2) Rojo/Negro\n");
		printf("3) 1ªMitad/ 2ª Mitad\n");
		printf("4) Docena\n");
		printf("5) Columna\n");
		printf("6) Linea\n");
		printf("7) Calle\n");
		printf("8) Pleno\n");
		scanf("%i", &opcion);
		
		while(opcion>8||opcion<1)
		{
		printf("Por favor elija su apuesta: ");
		printf("1) Par/Impar\n");
		printf("2) Rojo/Negro\n");
		printf("3) 1ªMitad/ 2ª Mitad\n");
		printf("4) Docena\n");
		printf("5) Columna\n");
		printf("6) Linea\n");
		printf("7) Calle\n");
		printf("8) Pleno\n");
		scanf("%i", &opcion);
		}
		switch (opcion)
		{
			case 1:
				do{
                printf("Va a apostar a par o impar.\n");
                printf("Pulse p para par o i para impar: ");
                scanf(" %c", &tipo);
                numero = aleator(1,36);
                odd_check=compruebaPar(numero);
                if(tipo=='p')
                {    
                printf("Ha salido el %i\n", numero);
                    if(odd_check==1)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*2;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else if(tipo=='i')
                {
                    printf("Ha salido el %i\n", numero);
                    if(odd_check==0)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*2;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else{
            
                    printf("Pulse p para par o i para impar: ");
                    scanf(" %c", &tipo);
                
                }
                
                }
                while(tipo!='p'&&tipo!='i');
				
				break;
			case 2:
				do{
                printf("Va a apostar a rojo o negro.\n");
                printf("Pulse r para rojo o n para negro: ");
                scanf(" %c", &tipo);
                numero = aleator(1,36);
                color_check=compruebaColor(numero);
                if(tipo=='r')
                {    
                printf("Ha salido el %i\n", numero);
                    if(color_check==1)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*2;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else if(tipo=='n')
                {
                    printf("Ha salido el %i\n", numero);
                    if(color_check==0)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*2;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else{
            
                    printf("Pulse n para negro o r para rojo: ");
                    scanf(" %c", &tipo);
                
                }
                
                }
                while(tipo!='r'&&tipo!='n');
				
				break;
			case 3:
				do{
                printf("Va a apostar a primera mitad o segunda mitad.\n");
                printf("Pulse p para primera mitad o s para la segunda: ");
                scanf(" %c", &tipo);
                numero = aleator(1,36);
                half_check=compruebaMitad(numero);
                if(tipo=='p')
                {    
                printf("Ha salido el %i\n", numero);
                    if(half_check==1)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*2;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else if(tipo=='s')
                {
                    printf("Ha salido el %i\n", numero);
                    if(half_check==0)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*2;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else{
            
                    printf("Pulse p para primera mitad o s para la segunda: ");
                    scanf(" %c", &tipo);
                
                }
                
                }
                while(tipo!='p'&&tipo!='s');
				
				break;
			case 4:
			    do{
                printf("Va a apostar a primera, segunda o tercera docena.\n");
                printf("Pulse x para la primera, y para la segunda, z para la tercera: ");
                scanf(" %c", &tipo);
                numero = aleator(1,36);
                twelve_check=compruebaDocena(numero);
                if(tipo=='x')
                {    
                printf("Ha salido el %i\n", numero);
                    if(twelve_check==1)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*3;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else if(tipo=='y')
                {
                    printf("Ha salido el %i\n", numero);
                    if(twelve_check==0)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*3;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else if(tipo=='z')
                {
                    printf("Ha salido el %i\n", numero);
                    if(twelve_check==2)
                    {
                        printf("Has ganado\n");
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else{
            
                    printf("Pulse x para la primera, y para la segunda, z para la tercera: ");
                    scanf(" %c", &tipo);
                
                }
                
                }
                while(tipo!='x'&&tipo!='y'&&tipo!='z');
				break;
			case 5:
				do{
                printf("Va a apostar a primera, segunda o tercera columna.\n");
                printf("Pulse i para la primera, j para la segunda, k para la tercera: ");
                scanf(" %c", &tipo);
                numero = aleator(1,36);
                column_check=compruebaColumna(numero);
                if(tipo=='i')
                {    
                printf("Ha salido el %i\n", numero);
                    if(column_check==1)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*3;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else if(tipo=='j')
                {
                    printf("Ha salido el %i\n", numero);
                    if(column_check==0)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*3;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else if(tipo=='k')
                {
                    printf("Ha salido el %i\n", numero);
                    if(column_check==2)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*3;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else{
            
                    printf("Pulse i para la primera, j para la segunda, k para la tercera: ");
                    scanf(" %c", &tipo);
                
                }
                
                }
                while(tipo!='i'&&tipo!='j'&&tipo!='k');
				
    
				break;
			case 6:
				do{
                printf("Va a apostar a una de las 6 lineas.\n");
                printf("Pulse 'q' para la 1ª, 'w' para la 2ª, 'e' para la tercera\n ");
                printf("'r' para la 4ª, 't' para la 5, 'o' para la 6: ");
                scanf(" %c", &tipo);
                numero = aleator(1,36);
                line_check=compruebaLinea(numero);
                if(tipo=='q')
                {    
                printf("Ha salido el %i\n", numero);
                    if(line_check==1)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*6;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else if(tipo=='w')
                {
                    printf("Ha salido el %i\n", numero);
                    if(line_check==2)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*6;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else if(tipo=='e')
                {
                    printf("Ha salido el %i\n", numero);
                    if(line_check==3)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*6;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else if(tipo=='r')
                {
                    printf("Ha salido el %i\n", numero);
                    if(line_check==4)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*6;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else if(tipo=='t')
                {
                    printf("Ha salido el %i\n", numero);
                    if(line_check==5)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*6;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else if(tipo=='o')
                {
                    printf("Ha salido el %i\n", numero);
                    if(line_check==6)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*6;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else{
                     printf("Pulse 'q' para la 1ª, 'w' para la 2ª, 'e' para la tercera\n ");
                     printf("'r' para la 4ª, 't' para la 5, 'o' para la 6: ");
                     scanf(" %c", &tipo);
                
                }
                
                }
                while(tipo>6&&tipo<1);
				
				break;
			case 7:
				do{
                printf("Va a apostar a una de las 12 calles.\n");
                printf("Pulse 'a' para la 1ª, 's' para la 2ª, 'd' para la tercera\n ");
                printf("'f' para la 4ª, 'g' para la 5, 'h' para la 6: ");
                printf("'j' para la 7ª, 'k' para la 8, 'l' para la 9: ");
                printf("'m' para la 10ª, 'p' para la 11, 'u' para la 12: ");
                scanf(" %c", &tipo);
                numero = aleator(1,36);
                street_check=compruebaCalle(numero);
                if(tipo=='a')
                {    
                printf("Ha salido el %i\n", numero);
                    if(street_check==1)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*12;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else if(tipo=='s')
                {
                    printf("Ha salido el %i\n", numero);
                    if(street_check==2)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*12;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else if(tipo=='d')
                {
                    printf("Ha salido el %i\n", numero);
                    if(street_check==3)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*12;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else if(tipo=='f')
                {
                    printf("Ha salido el %i\n", numero);
                    if(street_check==4)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*12;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else if(tipo=='g')
                {
                    printf("Ha salido el %i\n", numero);
                    if(street_check==5)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*12;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else if(tipo=='h')
                {
                    printf("Ha salido el %i\n", numero);
                    if(street_check==6)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*12;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else if(tipo=='j')
                {
                    printf("Ha salido el %i\n", numero);
                    if(street_check==7)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*12;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else if(tipo=='k')
                {
                    printf("Ha salido el %i\n", numero);
                    if(street_check==8)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*12;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else if(tipo=='l')
                {
                    printf("Ha salido el %i\n", numero);
                    if(street_check==9)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*12;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else if(tipo=='m')
                {
                    printf("Ha salido el %i\n", numero);
                    if(street_check==10)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*12;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else if(tipo=='p')
                {
                    printf("Ha salido el %i\n", numero);
                    if(street_check==11)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*12;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else if(tipo=='u')
                {
                    printf("Ha salido el %i\n", numero);
                    if(street_check==12)
                    {
                        printf("Has ganado\n");
                        saldoruleta=saldoanterior*12;
                        printf("Ha ganado %f euros", saldoruleta);
                    }
                    else{
                        printf("Lo siento, has perdido\n");
                    }
                }
                else{
                     printf("Va a apostar a una de las 12 calles.\n");
                printf("Pulse 'a' para la 1ª, 's' para la 2ª, 'd' para la tercera\n ");
                printf("'f' para la 4ª, 'g' para la 5, 'h' para la 6\n");
                printf("'j' para la 7ª, 'k' para la 8, 'l' para la 9\n");
                printf("'m' para la 10ª, 'p' para la 11, 'u' para la 12: ");
                     scanf(" %c", &tipo);
                
                }
                
                }
                while(tipo!='a'&&tipo!='s'&&tipo!='d'&&tipo!='f'&&tipo!='g'&&tipo!='h'&&tipo!='j'&&tipo!='k'&&tipo!='l'&&tipo!='m'
				&&tipo!='n'&&tipo!='u');
				break;
			case 8:
				printf("Elige un numero para hacer pleno:\n");
				scanf("%i", &n);
				numero = aleator(1,36);
				printf("El numero que ha salido en la ruleta es el %i\n", numero);
				if(n==numero)
				{
				printf("Has ganado");
				saldoruleta=saldoanterior*36;
                printf("Ha ganado %f euros", saldoruleta);
				}
				else{
					printf("Has perdido.");
				}
				break;
				}
					persona[h].saldo=persona[h].saldo+saldoruleta;
	
		}
	
		}
		
		printf("Quieres jugar otra ronda?: (si:y,no:n)\n");
										scanf("%c",&ronda);
											while(ronda!='y'&&ronda!='n')
											{
											printf("Debe introducir 'y' o 'n'");
												scanf(" %c", &ronda);
											}

		
		}
		while(ronda=='y');
		
			printf("Quiere salir o jugar a otro juego?\n 'e' para salir y 'r' para cambiar de juego\n");
				scanf(" %c",&r);
				while(r!='e'&&r!='r')
				{
					printf("Debe introducir 'e' o 'r'");
							scanf(" %c", &r);
				}
		
	}
				
		   		break;
		      
			case 2:
				espacios(10);
				printf("Has elegido: ");
		   		printf(" Blackjack\n");
		    	printf("Pulse 'c' para continuar \n Pulse 'r' para cambiar de juego\n");
		    	scanf("%s",&r);
		    	while(r!='r'&& r!='c')
                {
                   printf("Debe introducir 'c' o 'r'\n");
						scanf(" %c", &r);

                }
		    	if(r=='c')
		    	{
				i=0;
					baraja = crearbaraja(2);
					printf("\n %s \n", baraja);
					baraja=barajar(baraja);
					printf("\nSe va a jugar con 2 barajas \nBarajando...\nListo!");
					for(i=0;i<tam;i++){
					
					printf("\n%s su saldo es de %.2f. \n",persona[i].nombre,persona[i].saldo);
				}
					printf("Desea una breve explicacion de las reglas?('y' para si),('n' para no)\n");
						scanf(" %c", &regla);
						while(regla!='y'&&regla!='n')
						{
						printf("Debe introducir 'y' o 'n'");
						scanf(" %c", &regla);
						}
						if(regla=='y')
						{
					 		printf("El blackjack es un juego de cartas en el que el jugador juega contra el crupier. El objetivo es quedar lo mas cerca de\n21 puntos sin pasarse.");
					 		printf("Las figuras valen 10 puntos y el resto de cartas su valor numerico. El As actua como un comodin y\nvale 11 o 1 puntos dependiendo de lo que ");
					 		printf("favorezca al jugador. Cada ronda comenzara repartiendo dos cartas al jugador y una al crupier. A partir de aqui el jugador podra doblar la ");
					 		printf("apuesta, pedir carta hasta que desee (siempre que no supere\nlos 21 puntos) o plantarse. Al plantarse se repartiran cartas al crupier, el cual robara");
					 		printf(" carta siempre que tenga 16\no menos y se plantara con 17 o mas puntos\n");
						}
					if(regla=='n')
					{
						printf("Que comience el juego, ");
					}
					
					for(i=0;i<tam;i++)
					{
					printf("%s te toca jugar:\n",persona[i].nombre);
					printf("Cuanto desea apostar? La apuesta minima es 5\n");
						scanf(" %f",&apuesta);
						while(apuesta<5||apuesta>persona[i].saldo)
						{
							printf("Debe cambiar su apuesta\n");
							scanf(" %f",&apuesta);
						}
					
					persona[i].saldo= juego(baraja, apuesta, persona[i].saldo);
					
					
					printf("\n%s te queda %.2f saldo\n",persona[i].nombre,persona[i].saldo);
				
					
					printf("%s quieres jugar otra ronda?('y' para si),('n' para no)\n",persona[i].nombre);
					scanf(" %c",&ronda);
						while(ronda!='n')
						{
							if(ronda=='y')
							{
							espacios(23);
							baraja=barajar(baraja);
							persona[i].saldo= juego(baraja, apuesta, persona[i].saldo);
							printf("\n%s te queda %.2f saldo\n",persona[i].nombre,persona[i].saldo);
							printf("quieres jugar otra ronda?('y' para si),('n' para no)\n");
							scanf("%c",&ronda);
							}
							else
							printf("Debe introducir 'y' o 'n'");
							scanf("%c", &ronda);
						}
					printf("GRACIAS POR JUGAR VUELVA PRONTO\n");
					}
					free(baraja);
					}
				printf("Quiere salir o jugar a otro juego?\n 'e' para salir y 'r' para cambiar de juego\n");
				scanf(" %c",&r);
				while(r!='e'&&r!='r')
				{
					printf("Debe introducir 'e' o 'r'");
							scanf(" %c", &r);
				}
		     	 break;
		   	case 3:
		    	espacios(10);
		    	printf("Has elegido: ");
		    	printf(" la Maquina de slots\n");
		    	printf("Pulse 'c' para continuar \n Pulse 'r' para cambiar de juego\n");
		    	scanf("%s",&r);
		    	while(r!='r'&& r!='c')
                {
                   printf("Debe introducir 'c' o 'r'\n");
						scanf(" %c", &r);

                }
		    	if(r=='c')
		    	{

				printf("Bienvendio a la maquina de slots:\n");
				do
				{
					
				for(i=0;i<tam;i++)
				{
				printf("Por favor %s, elija su opcion: \n",persona[i].nombre);
				printf("1. Reglas del juego\n");
				printf ("2. Jugar\n");
				scanf ("%d",  &option);
				printf("\n");

				if(option==1)
				{
					printf("El juego consiste en conseguir el maximo de numeros iguales por linea o por diagonal.\n");
					printf("La ganancia que se obtenga sera proporcional a lo apostado y los numeros de los rodillos\n");
					printf("\n");
				}

				if (option==2)
					printf("A jugar!\n");
				else if (option!=1 && option!=2)
				{
					printf("Lo sentimos, esa opcion no existe. Por favor, pulse 1 si quiere saber como se juega y 2 para jugar\n");
					scanf("%d", &option);
				}

				printf("Su saldo es de %f euros\n", persona[i].saldo);
				printf("Por favor, introduzca la cantidad a apostar. Esta deber ser un minimo de 5 y maximo de 10:\n");
				scanf("%d", &apuest);

				while(apuest>persona[i].saldo || (apuest<5 || apuest>10))
					{
					printf("Debe apostar una cantidad entre 5 y 10 (valores enteros). Por favor, vuelva a introducir la cantidad: \n");
					scanf("%d", &apuest);
					}
				persona[i].saldo-=apuest;
				printf("Girando los rodillos... Listo!\n");
				printf("\n");
				vueltas(rodillos, 3, 3);
				total=ganado(rodillos, 3, 3);

				switch(apuest)
				{
					case 5:
						win=total*0.5;
						break;
					case 6:
						win=total*0.8;
						break;
					case 7:
						win=total*1;
						break;
					case 8:
						win=total*1.5;
						break;
					case 9:
						win=total*2;
						break;
					case 10:
						win=total*3;
						break;

				}
				ganancia= apuest-win;
				if(ganancia<=0)
				{
					printf("\n");
					printf("Vaya! Parece que la suerte no esta de su parte. ");
				}
				else
				{
					printf("\n");
					printf("Ha ganado %.2f\n", ganancia);
					persona[i].saldo+=ganancia;
				}
				}
					printf("Quieres jugar otra ronda?: (si:y,no:n)\n");
										scanf("%c",&ronda);
											while(ronda!='y'&&ronda!='n')
											{
											printf("Debe introducir 'y' o 'n'");
												scanf(" %c", &ronda);
											}
				}
				while (ronda=='y');
				}

				
					printf("Quiere salir o jugar a otro juego?\n 'e' para salir y 'r' para cambiar de juego\n");
				scanf(" %c",&r);
				while(r!='e'&&r!='r')
				{
					printf("Debe introducir 'e' o 'r'");
							scanf(" %c", &r);
				}
				break;
		   	 case 4:
				
		   		espacios(10);
		    	printf("Has elegido: ");
		    	printf(" el Bingo\n");
		    	printf("Pulse 'c' para continuar \n Pulse 'r' para cambiar de juego\n");
		   		scanf("%s",&r);
		   			while(r!='r'&& r!='c')
                {
                   printf("Debe introducir 'c' o 'r'\n");
						scanf(" %c", &r);

                }
		   			if(r=='c')	
				{		reglas(tam);
						do
						{	for(i=0;i<tam;i++)
		   				{
						   
		   				printf(" %s quieres diseñar el carton, generarlo aleatoriamente, o sacar uno del fichero? (1||0||2)",persona[i].nombre);
		   					scanf("%i",&aux);
		   						switch(aux)
		   							{	case 1:
		   								printf("Se te van a descortar 7 monedas de tu saldo\n");
		   								while((persona[i].saldo-7)<0)
		   									{	printf("No tienes dinero suficiente, mete mas dinero en tu saldo si queires continuar:");
		   										scanf("%i",&persona[i].saldo);
											   }						
										persona[i].saldo-=7	;			   
		   								disenocarton(persona[i].carton,3,5);
		   								ordenarcarton(persona[i].carton,3,5);
		   								break;
		   								case 0:
		   									printf("\n Se te van a descortar 7 monedas de tu saldo\n");
		   										while((persona[i].saldo-7)<0)
		   											{	printf("No tienes dinero suficiente, mete mas dinero en tu saldo si queires continuar:\n");
		   												scanf("%i",&persona[i].saldo);
														   }						
												persona[i].saldo-=7	;			   
		   										
		   										for(cont=-1;cont<i;cont++)//para que no haya dos cartones iguales
		   											{	cartonaleatorio(persona[i].carton,3,5);
													   }
		   									
		   											display(persona[i].carton,3,5);
		   										printf("\n notas algun error, tu cartón es el mismo que el de otro jugador?(Si:1;No=0)");
		   											
  												scanf("%i",&question);
  												while(question==1)
  											{	printf("vamos a solucionarlo\n");
  												cartonaleatorio(persona[0].carton,3,5);
  												display(persona[0].carton,3,5);
  													printf("notas algun error, tu cartón es el mismo que el de otro jugador?(Si:1;No=0)\n");
  													scanf("%i",&question);
  												}
		   										break;
		   								case 2:
		   										printf("Se te van a descortar 5 monedas de tu saldo\n");
		   								while((persona[i].saldo-5)<0)
		   									{	printf("No tienes dinero suficiente, mete mas dinero en tu saldo si queires continuar:\n");
		   										scanf("%f",&persona[i].saldo);
											   }						
										persona[i].saldo-=5	;			   
		   								
		   										cart=fopen("Ficheros/cartones.txt","r");	
													if (cart == NULL)
														{// Si el resultado es NULL mensaje de error
																printf("Error al abrir el fichero.\n");
																return -1;
															}
												for(ca=-1;ca<i;ca++)
												{	if(feof(cart)!=0) 	fseek(cart, 0, SEEK_SET);
												
												for(k=0;k<3;k++)
												
												{	
												for(j=0;j<5;j++)
														{		if(j==4&&k==2)
															{	fscanf(cart,"%i\n",&persona[i].carton[k][j]);
															
															}
														fscanf(cart,"%i,",&persona[i].carton[k][j]);
															
														}
												}
												}
												ordenarcarton(persona[i].carton,3,5);
												display(persona[i].carton,3,5);
												fclose(cart);
												break;
									   }
								
								display(persona[i].carton,3,5);
								if(aux==2)
								printf("continuemos\n");
								else
								{	printf("Quieres guardarlo en un Fichero para proximas jugadas? (si:1||no:0)\n");
		   									scanf("%i",&question);
		   									if(question==0)
		   										{	printf("perfecto, vamos a continuar\n");
												   }
		   									if(question==1)
		   										{	
								usu=fopen("Ficheros/cartones.txt","a");	
													if (usu == NULL)
														{// Si el resultado es NULL mensaje de error
																printf("Error al abrir el fichero.\n");
																return -1;
															}
												fseek(usu, 0, SEEK_END);
													fprintf(usu,"\n");
												
												for(k=0;k<3;k++)
												{	for(j=0;j<5;j++)
												
														{	if(j==4&&i==2)
															{	fprintf(usu,"%i",persona[i].carton[k][j]);
															}
														fprintf(usu,"%i,",persona[i].carton[k][j]);
												
											
														}
												}
												
												fclose(usu);
												   }
								}
							
						
									
										}
											
										for(k=0;k<99;k++)
										{	numbingo[k]=k+1;
										}
										bolita=aleatorio(1,99);
										cont=0;
										while(ganador==-1)
										{cont++;
												if(cont==100)
													{	ganador=aleatorio(0,tam-1);
													}
													printf("\n numero:%i   \n ",bolita);
														for(i=0;ganador==-1&&i<tam;i++)
													{
													
													switch(bingolinea(persona[i].carton,3,5,bolita))
														{	
														
															case 1:
																printf("Bingo para %s!!\n",persona[i].nombre);
																saldobingo(&persona[i].saldo,80);
																printf("%s:\n",persona[i].nombre);
																display(persona[i].carton,3,5);
																ganador=i;
																break;
														case 2:
															printf("Linea para %s!!\n",persona[i].nombre);
																	printf("%s:\n",persona[i].nombre);
																display(persona[i].carton,3,5);
																nlinea[i]++;
																if(nlinea[i]>3)
																	{	nlinea[i]=3;
																	}
															break;
															case 0:
																		printf("%s:\n",persona[i].nombre);
																display(persona[i].carton,3,5);													
															break;
														}
													
													
													}
													tiradab=0;
													while(tiradab==0)
													{
													
														if(numbingo[bolita-1]==0)
																{	bolita=aleato(1,99);
																	tiradab=0;
																}
																else
																{	numbingo[bolita-1]=0;
																tiradab=1;
																}
														
													}
														printf("pulse enter para sacar otra bola:\n");
																scanf("%c",&continuar);
																if(ganador==-1)
																	{	printf("siguiente numero\n");
																	}
																	else printf("Pulse enter para salir del bingo!\n");
															
												
													}
										printf("Felicidades %s, has Ganado el bingo!\n",persona[ganador].nombre);
										saldobingo(&persona[ganador].saldo,80);
										for(i=0;i<tam;i++)
											{	if(nlinea[i]!=0)
													{linea=12*nlinea[i];
												
													saldobingo(&persona[i].saldo,linea);
													printf("%s tu saldo es: %f\n",persona[i].nombre,persona[i].saldo);
														}	
														else 
														{	printf("%s tu saldo es: %f\n",persona[i].nombre,persona[i].saldo);
														}
											}
										printf("Quieres jugar otra ronda?: (si:y,no:n)\n");
										scanf("%c",&ronda);
											while(ronda!='y'&&ronda!='n')
											{
											printf("Debe introducir 'y' o 'n'");
												scanf(" %c", &ronda);
											}
								}
								while(ronda=='y');
		   				
						   }	
				printf("Quiere salir o jugar a otro juego?\n 'e' para salir y 'r' para cambiar de juego");
				scanf(" %c",&r);		  
					while(r!='e'&&r!='r')
				{
					printf("Debe introducir 'e' o 'r'");
							scanf(" %c", &r);
				} 
		     	break;
		      
			}
 		
	}

while(r=='r');
	
	i=0;
	
			usu=fopen("Ficheros/jugadores.txt","r");
					
  					if (usu == NULL)
					{// Si el resultado es NULL mensaje de error
					printf("Error al abrir el fichero.\n");
					return -1;
						}
							fseek(usu, 0, SEEK_SET);
						while(fscanf(usu,"%c",&r)!=EOF)
			{	if(r=='\n') ++lineasfich;
			}		
		
			fseek(usu, 0, SEEK_SET);
		//se quita el ultimo salto de linea
				j=0;
				while(feof(usu)==0)	
						{
						fscanf(usu," %f\t%[^\t]\t%[^\t]\t%[^\t]\n",&modif[j].saldo,modif[j].nombre,modif[j].apellido,modif[j].contrasena);
						j++;
						}
			
				
					fclose(usu);
				for(j=0;j<tam;j++)
				{	for(i=0;i<lineasfich;i++)
						{		if(strcmp(modif[i].contrasena, persona[j].contrasena)==0&&strcmp(modif[i].nombre, persona[j].nombre)==0&&strcmp(modif[i].apellido, persona[j].apellido)==0)
									{	modif[i].saldo=persona[j].saldo;
									}
								
						}
							
				}
	
		usu=fopen("Ficheros/jugadores.txt","w");
	
  					if (usu == NULL)
					{// Si el resultado es NULL mensaje de error
					printf("Error al abrir el fichero.\n");
					return -1;
						}
							
						else
						{for(i=0;i<lineasfich;i++)
			{	fprintf(usu," %f\t%s\t%s\t%s\t\n",modif[i].saldo,modif[i].nombre,modif[i].apellido,modif[i].contrasena);
			}
						}
		
				fclose(usu);
return 0;
}
	int aleato(int minimo,int maximo)
	{ 
    
		int numero;
		numero=rand()%((maximo-minimo)+1)+minimo;
		return numero;
	}
	void espacios(int n)
	{	int i;
		for(i=0;i<n;i++)
		{	printf("\n");
		}
	}
