#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ruleta.h"
int aleato(int minimo,int maximo);
int comprobarPar(int numero);
int comprobarColor(int numero);
int comprobarMitad(int numero);
int comprobarColumna(int numero);
int comprobarDocena(int numero);
int comprobarFila(int numero);
int compruebaCalle(int numero);
void reglasRuleta();

int main()
{
	int regla, opcion, n, numero, normas;
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
    
	printf("1) Reglas 2)Jugar\n");
	scanf("%i", &regla);
	while(regla!=1 && regla!=2)
	{
	printf("1) Reglas 2)Jugar: ");
	scanf("%i", &regla);
	}
	while(regla==1)
	{
		normas=reglasruleta();
	    printf("%i", normas);
		scanf("%i", &regla);
	}
	if(regla==2)
	{
		printf("Elija su apuesta:");
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
                numero = aleato(1,36);
                odd_check=compruebaPar(numero);
                if(tipo=='p')
                {    
                printf("Ha salido el %i\n", numero);
                    if(odd_check==1)
                    {
                        printf("Has ganado\n");
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
                numero = aleato(1,36);
                color_check=compruebaColor(numero);
                if(tipo=='r')
                {    
                printf("Ha salido el %i\n", numero);
                    if(color_check==1)
                    {
                        printf("Has ganado\n");
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
                numero = aleato(1,36);
                half_check=compruebaMitad(numero);
                if(tipo=='p')
                {    
                printf("Ha salido el %i\n", numero);
                    if(half_check==1)
                    {
                        printf("Has ganado\n");
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
                numero = aleato(1,36);
                twelve_check=compruebaDocena(numero);
                if(tipo=='x')
                {    
                printf("Ha salido el %i\n", numero);
                    if(twelve_check==1)
                    {
                        printf("Has ganado\n");
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
                numero = aleato(1,36);
                column_check=compruebaColumna(numero);
                if(tipo=='i')
                {    
                printf("Ha salido el %i\n", numero);
                    if(column_check==1)
                    {
                        printf("Has ganado\n");
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
                numero = aleato(1,36);
                line_check=compruebaLinea(numero);
                if(tipo=='q')
                {    
                printf("Ha salido el %i\n", numero);
                    if(line_check==1)
                    {
                        printf("Has ganado\n");
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
                numero = aleato(1,36);
                street_check=compruebaCalle(numero);
                if(tipo=='a')
                {    
                printf("Ha salido el %i\n", numero);
                    if(street_check==1)
                    {
                        printf("Has ganado\n");
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
				printf("El numero que ha salido en la ruleta es el %i\n", n);
				if(n==numero)
				{
				printf("Has acetado");
				}
				else{
					printf("Has perdido.");
				}
				break;
				}
		}
		
	}
	
void reglasRuleta()
{
		printf("Las reglas de la ruleta:\n");
		printf("1): Tienes que escoger un tipo de apuesta\n");
		printf("2)Entre las apuestas que puedes elegir se encuentran:");
		printf("par o impar, rojo o negro, elegir una fila, una columna,\n");
		printf("Tambien se puede escoger entre 3 numeros, 2 o 1\n");
		printf("Solo podras apostar a una unica caracteristica, es decir si apuetas a rojo solo podras apostar rojo\n");
		printf("Pulse 2 para jugar");
}

int compruebaPar(int numero)
{
    if(numero%2==0){
        return 1;
    }
    else{
    return 0;
    }
   
}

int compruebaColor(int numero)
{
    if(numero==1||numero==3||numero==5||numero==7||numero==9||
    numero==12||numero==14||numero==16||numero==18||numero==21||
    numero==23||numero==25||numero==19||numero==27||numero==30||
    numero==32||numero==34||numero==36){
        return 1;
    }
    else{
    return 0;
    }
   
}

int compruebaMitad(int numero)
{
    if(numero<=18&&numero>0){
        return 1;
    }
    else{
    return 0;
    }
   
}

int compruebaColumna(int numero)
{
	int i;
	int c1;
	int c2;
	int c3;
	for(i=0; i<13; i++){
	
    if(c1=1+3*i){
        return 1;
    }
    else if (c2=2+3*i){
    return 0;
    }
    else if (c3=3+3*i){
    	return 2;
	}
	}
   
}

int compruebaDocena(int numero)
{
    if(numero>=1&&numero<=12){
        return 1;
    }
    else if(numero>=12&&numero<=24){
    return 0;
    }
    else{
    	return 2;
	}
   
}

int compruebaLinea(int numero)
{
    if(numero>=1&&numero<=6){
    return 1;
    }
    else if(numero>6&&numero<=12){
    return 2;
    }
    else if(numero>12&&numero<=18){
    return 3;
    }
    else if(numero>18&&numero<=24){
    return 4;
    }
    else if(numero>24&&numero<=30){
    return 5;
    }
    else{
    	return 6;
	}
   
}

int compruebaCalle(int numero)
{
    if(numero>=1&&numero<=3){
    return 1;
    }
    else if(numero>3&&numero<=6){
    return 2;
    }
    else if(numero>6&&numero<=9){
    return 3;
    }
    else if(numero>9&&numero<=12){
    return 4;
    }
    else if(numero>12&&numero<=15){
    return 5;
    }
    else if(numero>15&&numero<=18){
    return 6;
    }
    else if(numero>18&&numero<=21){
    return 7;
    }
    else if(numero>21&&numero<=24){
    return 8;
    }
    else if(numero>24&&numero<=27){
    return 9;
    }
    else if(numero>27&&numero<=30){
    return 10;
    }
    else if(numero>30&&numero<=33){
    return 11;
    }
    else{
    	return 12;
	}
   
}

int aleato(int minimo,int maximo)
{ 
    
	int numero;
	numero=rand()%((maximo-minimo)+1)+minimo;
	return numero;
}
       

	

