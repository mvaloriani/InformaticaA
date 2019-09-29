/*

Una matrice quadrata di NxN punti del piano cartesiano è definita come segue:
typedef struct { float x, y; } Punto;
typedef Punto Matrice[N][N];
Gli N punti della diagonale, quelli di ogni riga e quelli di ogni 
colonna definiscono linee spezzate di N-1 lati. Diciamo che una
matrice di punti è regolare se la lunghezza della spezzata
definita dalla diagonale principale è maggiore della lunghezza
di tutte le spezzate definite dalle righe e dalle colonne della matrice.

Sapendo di poter disporre di una funzione di prototipo float 
dist( Punto a, Punto b ) che calcola la distanza euclidea tra 
due punti, si codifichi in C la funzione regolare(...) che, data una matrice, 
restituisce 1 se è regolare, 0 altrimenti;
int regolare( Matrice m );
int regolare( Punto m[][N] );


*/
#include <stdlib.h>
#include <stdio.h>

typedef struct { float x, y; } Punto;
typedef Punto Matrice[N][N];


int regolare(Matrice m) {
	int i, j;  float lunD = 0.0, lun;
	for (i = 0; i < N - 1; i++)
		lunD += dist(m[i][i], m[i + 1][i + 1]);       /* La diagonale principale */ 
	
	for (i = 0; i < N; i++) {
		lun = 0.0;                /* Azzero per la nuova riga(colonna) */
		for (j = 0; j < N - 1; j++) {
			lun += dist(m[i][j], m[i][j + 1]);      /* i-esimo segmento riga    */
		}
		if (lun > lunD) /* Basta una sola lunghezza maggiore */
			return 0;
	}
	for (i = 0; i < N; i++) {
		lun = 0.0;                /* Azzero per la nuova riga(colonna) */
		for (j = 0; j < N - 1; j++) {
			lun += dist(m[j][i], m[j + 1][i]);      /* i-esimo segmento colonna */
		}
		if (lun > lunD) /* Basta una sola lunghezza maggiore */
			return 0;
	}
	return 1;
}
