/*
Si implementi una funzione che riceve in input una matrice NxM di float.
Definito �picco� un numero circondato in tutte le otto posizioni intorno solo da
numeri inferiori alla sua met�, la funzione conta il numero di �picchi� della matrice
(attenzione a gestire correttamente gli elementi ai bordi della matrice).
*/

#include <stdio.h>
const int N=5,M=3;

int f(float m[N][M]) {
  int i,j,k,t,cont,quanti=0;

  //esploro la matrice
  for(i=0; i < N;i++) {
	  for (j = 0; j < M; j++) {


		  //cont=0;
		  //// valuto i valori intorno alla posizione i,j
		  //for(k=i-1; k <= i+1;k++) {
		  //	for(t=j-1; t <= j+1;t++) {
		  //		// sono fuori dalla matrice
		  //		if(k < 0 || k >= N || t < 0 || t >= M) {
		  //			cont++;
		  //		}
		  //		// condizione da verificare
		  //		else if(condPicco(m[i][j], m[k][t]))
		  //			cont++;
		  //	}
		  //}


		  //tutti gli elementi verificano la condizione
		  if (fun2(i, j, m) == 1)
			  quanti++;
	  }
    }
    return quanti;
}


int fun2(int i, int j, float m[N][M]) {
	int cont = 0;
	// valuto i valori intorno alla posizione i,j
	for (int k = i - 1; k <= i + 1; k++) {
		for (int t = j - 1; t <= j + 1; t++) {
			// sono fuori dalla matrice
			if (k < 0 || k >= N || t < 0 || t >= M) {
				cont++;
			}
			// condizione da verificare
			else if (condPicco(m[i][j], m[k][t]))
				cont++;
		}
	}

	if (count == 8) return 1;
	else
		return 0;

}

int condPicco(int centro, int intorno){
	return intorno*2<centro ? 1 :  0 ;
}

int condPozzo(int centro, int intorno){
	return intorno>centro*2 ? 1 :  0 ;
}