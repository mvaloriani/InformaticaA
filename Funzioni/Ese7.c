/*
Definire un tipo di dato MATR, 
matrice 10x10 di interi ed un tipo di dato EST, 
struct con un campo di nome X di tipo MATR e un campo L di tipo intero. 

Scrivere una funzione in linguaggio C con due parametri formali: 
A di tipo MATR e V di tipo puntatore ad un elemento di tipo EST.
La funzione deve modificare l’area di memoria indirizzata da V 
inserendo nel campo X di tale area di memoria la differenza tra 
la matrice A e la matrice identità 10x10.
Si ricorda che la matrice identità 10x10 è una matrice di 10x10 
componenti contenente tutti valori nulli ad eccezione della diagonale 
principale i cui valori sono uguali ad 1.
*/

#include <stdlib.h>
#include <stdio.h>

#define N 10
typedef int MATR[N][N];
typedef struct { MATR x; int L; } EXT;

void f(MATR A, EXT *V) {
	int i, j, elemMatrDiag;
	for (i = 0; i<N; i++) {
		for (j = 0; j<N; j++) {
			if (i == j)
				//elemMatrDiag = 1;
				V->x[i][j] = A[i][j] - 1;
			else
				//elemMatrDiag = 0;
				V->x[i][j] = A[i][j];

			//V->x[i][j] = A[i][j] - elemMatrDiag;
		}
	}
}

