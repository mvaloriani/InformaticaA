/*
Si implementi una funzione che riceve
in input una matrice NxM di float.
Definito “picco” un numero circondato
in tutte le otto posizioni intorno solo da
numeri inferiori alla sua metà, la funzione
conta il numero di “picchi” della matrice
(attenzione a gestire correttamente gli
elementi ai bordi della matrice).
*/

#include <stdio.h>
const int N=5,M=3;

int f(float m[N][M]) {
  int i,j,k,t,cont,quantiPicchi=0;

  //esploro la matrice
  for(i=0; i < N;i++) {
	for(j=0; j < M;j++) {
		cont=0;

		// valuto i valori intorno alla posizione i,j
		for(k=i-1; k <= i+1;k++) {
			for(t=j-1; t <= j+1;t++) {
				// sono fuori dalla matrice
				if(k < 0 || k >= N || t < 0 || t >= M) {
				cont++;
				}
				// condizione da verificare
				else if(condPicco(m[i][j], m[k][t]))
					cont++;

				//// escludo i bordi
				//if (!(k < 0 || k >= N || t < 0 || t >= M)) {
				//if (k >= 0 && k < N && t >= 0 && t < M)) {

				//	if (condPicco(m[i][j], m[k][t]))
				//		cont++;
				//}
			}
		}
		//tutti gli elementi verificano la condizione
		if(cont==8)
			quantiPicchi++;
	}
    }
    return quanti;
}

int f1(float m[N][M]) {
	int contPicchi = 0;
	//esploro la matrice
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (condVerificaPicco(N, M, m, i, j) == 1) {
				contPicchi++;
			}
		}
	}
	return contPicchi;
}

int condVerificaPicco(int numR, int numC, float mat[][], int i, int j) {
	int cont = 0;

	for (int k = i-1; k <= i + 1; k++)
	{
		for (int t = j - 1; t <= j + 1; t++)
		{
			if (k < 0 || k >= numR || t < 0 || t >= numC) {
				cont++;
			}
			else if (condPicco(mat[i][j], mat[k][t]))
				cont++;
		}
	}	
	return cont >= 8; //cont >= 8 ? 1 : 0
}

int condPicco(int centro, int intorno){
	return (intorno*2<centro) ? 1 :  0 ;
}

int condPozzo(int centro, int intorno){
	return intorno>centro*2 ? 1 :  0 ;
}