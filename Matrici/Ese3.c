#include<stdio.h>

/*
Scrivere un programma che chiede all’utente di inserire una matrice 20x30,
poi (dopo aver terminato la fase di inserimento) copia gli elementi
dispari in una seconda matrice 20x30 senza lasciare buchi, se non in fondo.
Gli elementi in fondo (i "buchi") siano messi a zero.
*/

#define N 20
#define M 30
int main() {
	int i = 0, j = 0, k = 0, r = 0, mat1[N][M], mat2[N][M] = {0}; //mat2[N][M] = { 1 }; NO
	
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			scanf("%d", &mat1[i][j]);


	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (mat1[i][j] % 2 != 0) {
				mat2[r][k] = mat1[i][j];
				k++;
				if (k == M) { k = 0; r++; }
			}
		}
	}
	return 0;
}
