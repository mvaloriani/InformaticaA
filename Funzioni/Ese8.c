/*
Esercizio (tde 16-11-2007)
*/
#include <stdlib.h>
#include <stdio.h>
#define N 10

int quantiUgualiConNestedLoop(int A[][N], int B[][N], int k) {
	int cont = 0, howMany = 0, i, j;

	for (i = 0; i < N && howMany < k; i++) {
		for (j = 0; j < N && howMany < k; j++) {
			if (A[i][j] == B[i][j])
				cont++;
			howMany++;
		}
	}

	return cont;
}

int quantiUgualiConMergeLoop(int A[][N], int B[][N], int k) {
	int cont = 0, howMany = 0, i, numElem;
	int dn = 1;//numero diagonale 
	while (dn <= 2 * N - 1 && howMany < k) {
		i = 0;
		if (dn <= N) {    //prima meta'      
			numElem = dn;  //indica quanti elementi in diagonale
			while (i < numElem && howMany < k) {
				if (A[i][dn - 1 - i] == B[i][dn - 1 - i])
					cont++;
				howMany++;
				i++;
			}
		}

		else {  //seconda meta‘
			numElem = N - (dn - N);
			while (i < numElem && howMany < k) {
				if (A[dn - N + i][N - 1 - i] == B[dn - N + i][N - 1 - i])
					cont++;
				howMany++;
				i++;
			}
		}
		dn++;
	}
	return cont;
}

int quantiUgualiConMergeLoop2(int A[][N], int B[][N], int k) {
	int i, j, cont = 0, quanti = 0;
	i = 0; j = 0;
	while (quanti < k){//prima metà
		//guarda casella giusta
		if (A[i][j] == B[i][j])
			cont++;
		quanti++;
		//trova casella giusta
		i++; j--;
		if (j == -1) {
			if (i == N - 1)
				break;
			j = i;  i = 0;
		}
	}
	while (quanti < k){
		//guarda casella giusta
		if (A[i][j] == B[i][j])
			cont++;
		quanti++;
		//trova casella giusta
		i++; j--;
		if (i == N - 1) {
			i = j + 2; j = N - 1;
		}
	}

	return cont;
}




