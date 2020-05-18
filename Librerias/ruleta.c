#include <time.h>

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

int comprobarPar(int numero)
{
	int par, impar;
	if(numero%2==1){
		par++;
		return 1;
	}
	else{
		impar++;
		return -1;
	}
}

int comprobarColor(int numero)
{
    int rojo, negro;
	if(numero==1||numero==3||numero==5||numero==7||numero==9||
	numero==12||numero==14||numero==16||numero==18||numero==21||
	numero==23||numero==25||numero==19||numero==27||numero==30||
	numero==32||numero==34||numero==36){
	rojo++;
	return 1;
	}
	else{
		negro++;
		return -1;
	}
}

int comprobarMitad(int numero)
{
	int n;
	srand(time(NULL));
    n = rand() % 37 + 1;
	int m1, m2;
	if(n<=18&&n>0){
		m1++;
		return m1;
	}
	else if(n<37&&n>18){
	    m2++;
		return m2;
	}
}

int comprobarColumna(int numero)
{ 
int i, n;

	srand(time(NULL));
    n = rand() % 37 + 1;
    int col1, col2, col3;
	for(i=0; i<12; i++)
	{
		col1=1+3*i;
		col2=2+3*i;
		col3=3+3*i;
	}
	if(n==col1){
		col1++;
		return col1;
	}
	else if(n==col2){
		col2++;
		return col2;
	}
	else if(n==col3){
		col3++;
		return col3;
	}
}

int comprobarDocena(int numero)
{
	int n;
	srand(time(NULL));
    n = rand() % 37 + 1;
	int d1, d2, d3;
	if(n<=12&&n>0)
	{
	d1++;
	return ;
	}
	else if(n>12&&n<=24)
	{
	d2++;
	return 0;
	}
	else if(n>24&&n<=36)
	{
	d3++;
	return -1;
	}
}

int comprobarFila(int n)
{
	int n;
	srand(time(NULL));
    n = rand() % 37 + 1;
    fila[p]=
}

int comprobarCalle(int n)
{
	int n, k;
	srand(time(NULL));
    n = rand() % 37 + 1;
	int calle0[6]={1,2,3,4,5,6};
	int calle1[6]={7,8,9,10,11,12};
	int calle2[6]={13,14,15,16,17,18};
	int calle3[6]={19,20,21,22,23,24};
	int calle4[6]={25,26,27,28,29,30};
	int calle5[6]={31,32,33,34,35,36};
	for(k=0;k<6;k++){
		calle[k];
	}
}





