#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ruleta.h"

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
	
    if(numero==1||numero==4||numero==7||numero==10||
	   numero==13||numero==16||numero==19||numero==22||
	   numero==25||numero==28||numero==31||numero==34){
        return 1;
    }
    else if (numero==2||numero==5||numero==8||numero==11||
	   numero==14||numero==17||numero==20||numero==23||
	   numero==26||numero==29||numero==32||numero==35){
    return 0;
    }
    else {
    	return 2;
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

int aleator(int minimo,int maximo)
{ 
    
	int numero;
	numero=rand()%((maximo-minimo)+1)+minimo;
	return numero;
}
       

