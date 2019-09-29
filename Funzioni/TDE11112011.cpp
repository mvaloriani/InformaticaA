/*

Un numero si dice doppiamente primo se è primo e tutte 
le sue cifre sono numeri primi.
Si scriva una funzione f che riceve una matrice NxN di interi e
restituisce 1 se tutti
i numeri doppiamente primi che contiene sono circondati solo da numeri
che non sono 
doppiamente primi nelle otto direzioni possibili per le caselle centrali, 
nelle cinque 
o tre possibili per le caselle sul bordo della matrice, 0 altrimenti.
int f(int M[][N]);

Un insieme di celle di una matrice si dice connesso se esiste un percorso
che partendo
da una delle celle permette di raggiungere le altre muovendosi 
di un passo alla volta 
nelle otto direzioni attraversando solo celle dell’insieme stesso.

Si scriva una funzione g che riceve una matrice NxN di interi e restituisce 1
se tutti
i numeri doppiamente primi che contiene appartengono a un unico insieme
connesso di celle, 0 altrimenti.
int g(int M[][N]);


*/
#include <stdlib.h>
#include <stdio.h>

#define N 10


int primo(int n) {
	int j;
	for (j = 2; j <= n / 2; j++) {
		if (n % j == 0)
			return 0;
	}
	return 1;
}

int DP(int n) {
	int cifra, num = n;

	if (primo(n) == 0)
		return 0;

	for (num = n; num != 0; num = num / 10) {
		cifra = num % 10;
		if (primo(cifra) == 0)
			return 0;
	}
	return 1;
}


int f(int M[][N]) {
	int i, j, k, t;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			// verifico che è un doppio primo
			if (DP(M[i][j])) {
				
				for (k = i - 1; k <= i + 1; k++) {
					for (t = j - 1; t <= j + 1; t++) {
						if (k < 0 || k >= N || t < 0 || t >= N)
							; //non fare nulla		 
						else if (!(k == i && t == j) && DP(M[k][t]))
							return 0;
					}
				}
			}
		}
	}
	return 1;
}


int g(int M[][N]) {
	int i, j, k, t, primo = 1, aux[N][N];	//aux serve per marcare i numeri
											// ha tante caselle quante M 
	int cambiato = 1;
	//scorro tutta la matrice mettendo in aux un 2 in corrispondenza del primo numero 
	//doppiamente primo che trovo, un 1 in corrispondenza di tutti gli altri numeri 
	//doppiamente primi, 0 in corrispondenza di numeri non doppiamente primi
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (DP(M[i][j])) {
				if (primo) {
					primo = 0;
					aux[i][j] = 2;
				}
				else
					aux[i][j] = 1;
			}
			else
				aux[i][j] = 0;
		}
	}
	while (cambiato == 1) { //propago il 2 in aux trasformando in 2 tutti gli 1 vicini a un 2
		cambiato = 0;
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				if (aux[i][j] == 1)
					for (k = i - 1; k <= i + 1; k++)
						for (t = j - 1; t <= j + 1; t++)
							if (k < 0 || k >= N || t < 0 || t >= N)
								; //non fare nulla
							else if (!(k == i && t == j) && aux[k][t] == 2) {
								aux[i][j] = 2;
								cambiato = 1;
							}
	}
	// se è rimasto un 1 in aux vuol dire che esiste un doppiamente primo non connesso
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			if (aux[i][j] == 1)
				return 0;
	return 1;
}

