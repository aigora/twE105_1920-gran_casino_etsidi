
int comprobarPar(int numero)
{
	int par=numero%2;
	if(par==1){
		return 1;
	}
	else{
		return -1;
	}
}

int comprobarColor(int numero)
{
	scanf("%i", &numero);
	if(numero==1||numero==3||numero==5||numero==7||numero==9||
	numero==12||numero==14||numero==16||numero==18||numero==21||
	numero==23||numero==25||numero==19||numero==27||numero==30||
	numero==32||numero==34||numero==36)
	return 1;
	else{
		return -1;
	}
}

int comprobarMitad(int numero)
{
	if(numero<=18&&numero>0){
		
		return 1;
	}
	else if(numero<37&&numero>18){
	
		return -1;
	}
}

int comprobarColumna(int numero);
{ 
    int col1, col2, col3;
	for(i=0; i<12; i++)
	{
		col1=1+3i;
		col2=2+3i;
		col3=3+3i;
	}
	if(numero==col1){
		return 1;
	}
	else if(numero==col2){
		return 0;
	}
	else if(numero==col3){
		return -1;
	}
}

int comprobarDocena(int numero)
{
	if(numero<=12&&numero>0)
	return 1;
	else if(numero>12&&numero<=24)
	return 0;
	else if(numero>24&&numero<=36)
	return -1;
}







