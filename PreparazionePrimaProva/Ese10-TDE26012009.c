/*
La matrice M[6][156] contiene le 156 estrazioni del 2010 dei 6 numeri del SuperEnalotto. 

Scrivere una funzione 
int f(int M[][156])

che riceve la matrice M e restituisce quanti numeri tra 1 e 90 non sono mai usciti nel 2010.

*/



int f1(int M[6][156]){

	int trovato, count=0;
	// per ogni numero 
	for (int n = 1; n <= 90; n++)
	{		
		trovato=0;
		//cerco se trovo il numero
		for (int i = 0; i < 156; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if(M[j][i]==n)
					trovato=1;
			}
		}
		// elemnto non trovato quindi incremento
		if (trovato==0)
			count++;
	}
	return count;
}

int f2(int M[6][156]){

	int trovato, count=0;
	// per ogni numero 
	for (int n = 1; n <= 90; n++)
	{
		trovato=0;
		//cerco se trovo il numero
		for (int i = 0; i < 156 && trovato==0; i++)
		{
			for (int j = 0; j < 6 && trovato==0; j++)
			{
				if(M[j][i]==n)
					trovato=1;
			}
		}
		// elemnto non trovato quindi incremento
		if (trovato==0)
			count++;	
	}
	return count;
}

int f3(int M[6][156]){
	int estratti[90];
	for (int n = 0; n < 90; n++)
	{
		estratti[n]=0;
	}

	int count=0;
	//scorro la matrice
	for (int i = 0; i < 156; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			estratti[M[j][i]-1]=1;
		}
	}

	// conto i numeri non torvati
	for (int n = 0; n < 90; n++)
	{
		if (estratti[n]==0)
			count++;
	}	

	return count;
}

int f4(int M[6][156]){
	int estratti[90];
	for (int n = 0; n < 90; n++)
	{
		estratti[n]=0;
	}

	int  count=0;
	//scorro la matrice
	for (int i = 0; i < 156; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (estratti[M[j][i]-1]==0)
			{
				count++;
				estratti[M[j][i]-1]=1;
			}
			
		}
	}


	return count;
}


// f1 90 X 6 X 156
// f2 caso peggiore - 90 X 6 X 156 - caso migliore 91 X 45
// f3 6 X 156 + 90 + 90
// f4 6 X 156 + 90