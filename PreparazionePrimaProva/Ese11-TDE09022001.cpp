/*
Si definisca una funzione che riceve in input due matrici m1 e m2 di NxN interi.

La funzione calcola e restituisce il numero di elementi di m2 che sono pari alla
somma di due qualsiasi elementi di m1 (se un dato elemento di m2 è somma di 
più coppie di elementi di m1, viene contato comunque una volta sola)
La funzione abbia la seguente intestazione: int numSomme (int m1[][N], int m2[][N])
*/


#define N 100
#include <stdio.h>
int numSomme (int m1[][N], int m2[][N]){
	int count =0;
	//scorro m2
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (verifica(m2[i][j], m1)==1)
				count++;
		}
	}
	return count;
}


int verifica(int n, int m1[][N]){
	
	for (int c = 0; c < N; c++)
	{
		for (int r = 0; r < N; r++)
		{
			return trovato(m1[c][r], n, m1);
		}
	}
	
	return 0;
}

int trovato(int el, int n, int m1[][N]){
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (m1[i][j] + el == n)
				return 1;
		}
	}
	return 0;
}

int verifica2(int n, int m1[][N]){

	for (int c = 0; c < N; c++)
	{
		for (int r = 0; r < N; r++)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (m1[i][j] + m1[c][r] == n)
						return 1;
				}
			}
		}
	}

	return 0;
}