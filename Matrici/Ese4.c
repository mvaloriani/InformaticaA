#include<stdio.h>

/*
Si scriva un programma che acquisisce una matrice quadrata NxN
(con N costante predefinita con l’struzione #define N …)
di interi positivi M ed un array A di dimensione N.
La funzione restituisce 1 se almeno uno degli elementi di A
è divisore di tutti gli elementi di una qualsiasi riga di M
*/

#define N 3

int main() {
	int M[N][N], A[N], i, j, k, counter = 0;

	//leggo matrice
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			do {
				printf("Inserire M[%d][%d] intero posito: ", i, j);
				scanf("%d", &M[i][j]);
			} while (M[i][j] <= 0);
		}
	//leggo vettorre
	for (k = 0; k < N; k++) {
		printf("Inserire valore in A[%d]: ", k);
		scanf("%d", &A[k]);
	}

	//stamp matrice
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%4d", M[i][j]);	// stampa lasciando 4 spazzi		
		}
		printf("\n");
	}
	//stampo vettore
	for (k = 0; k < N; k++) {
		printf("%d", A[k]);
	}

	//scorro tutti gli elementi del vettore
	for (k = 0; k < N; k++) {
		//scorro tutta la matrice
		for (i = 0; i < N; i++) {
			counter = 0;
			for (j = 0; j < N; j++) {
				if (M[i][j] % A[k] == 0) {
					counter++;
				}
			}
			//sono alla fine di una riga
			if (counter == N) {
				printf("La riga %d contiene tutti divisori di A[%d]", i, k);
				return 1;
			}
		}
	}

	return 0;
}
