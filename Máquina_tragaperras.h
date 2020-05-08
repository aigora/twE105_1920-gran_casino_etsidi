int aleatorio(int minimo,int maximo)
	{     
		int numero;
		numero=rand()%((maximo-minimo)+1)+minimo;
		return numero;
	}
	
float ganancia(int rodillos[3][3])
	{
		float ganancia= 0;
		int i, j;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if ((rodillos[i][j]== rodillos[i][j+1])||(rodillos[i][j]== rodillos[i][j+2])||(rodillos[i][j+2]== rodillos[i][j+1]))
				{
				ganancia= ganancia*2;
				}
				else if (rodillos[i][j]== rodillos[i][j+1]== rodillos[i][j+2])
			}
		
		}
		return ganancia;
	}
	
float vueltas()
	{
	
	}
