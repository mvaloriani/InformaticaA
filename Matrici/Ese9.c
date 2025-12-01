#include<stdio.h>
#include<stdlib.h>

/*
Scrivere un programma che chiede all’utente di inserire una matrice NxN
e stampa gli elementi di tale matrice secondo un ordinamento a spirale,
partendo dalla cornice più esterna e procedendo verso l’interno.
*/

#include <stdio.h>
#define N 20

int main() {
	int m[N][N], i, k;
	//leggi mtrice
	for (i = 0; i < N; i++)
		for (k = 0; k < N; k++) {
			printf("Inserisci elemento (%d,%d): ", i, k);
			scanf("%d",&m[i][k]);
		}
	//stampa a spirale
	for (k = 0; k < N / 2 + 1; k++) {
		for (i = k; i < N - k; i++)
			printf("%d ", m[k][i]);
		for (i = k + 1; i < N - k; i++)
			printf("%d ", m[i][N - 1 - k]);
		for (i = N - 2 - k; i >= k; i--)
			printf("%d ", m[N - 1 - k][i]);
		for (i = N - 2 - k; i >= k + 1; i--)
			printf("%d ", m[i][k]);
	}
	return 0;
}
