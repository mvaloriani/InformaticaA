#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Scrivere un programma C che:
ha in ingresso due file denominati rispettivamente A.txt e B.txt 
contenenti su ogni riga un numero intero.
Il numero di righe dei due file non è noto a priori ma è uguale nei due file;

definisce una matrice di nome MATRI  2 X 10 di tipo opportuno e 
riempie la prima riga di MATRI con gli elementi di A.txt fino al 
riempimento della riga o all'esaurimento dei dati letti dal file; 
poi riempie la seconda riga di MATRI con gli elementi di B.txt 
fino al riempimento della riga o all'esaurimento dei dati letti dal file;

copia in un vettore VETT gli elementi presenti nella prima riga 
della matrice che soddisfano i seguenti criteri:
- il valore è copiato solo se è maggiore o uguale al valore 
corrispondente nella seconda riga della matrice;
- il vettore non deve presentare buchi, ovvero deve essere 
riempito senza soluzione di continuità.
Il programma stampa i valori effettivamente inseriti in VETT.


*/


#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema

int main() {
	FILE *fA, *fB;
	int MATRI[2][10], VETT[10], el;
	int indR, indV, j;

	fA = fopen("A.txt", "r");
	fB = fopen("B.txt", "r");

	if (fA == NULL || fB == NULL)
		exit(-1);

	indR = 0;
	// reimpro la prima riga afacendo attenzione al numero di elementi
	while (fscanf(fA, "%d", &el) != EOF && indR<10) {
		MATRI[0][indR] = el;
		indR++;
	}

	//riempo la secodna riga
	for (j = 0; j<indR; j++) //fA e fB contengono lo stesso num di el  
		fscanf(fB, "%d", &MATRI[1][j]);

	
	// reimpro la prima riga afacendo attenzione al numero di elementi
	//while (fscanf(fA, "%d", &el) != EOF && indR<10) {
	//	fscanf(fB, "%d", &MATRI[1][indR]);
	//	MATRI[0][indR] = el;
	//	indR++;
	//}


	//riempo il vettore facendo attenzione a non lasciare buchi
	for (indV = 0, j = 0; j<indR; j++) {
		if (MATRI[0][j] >= MATRI[1][j]) {
			VETT[indV] = MATRI[0][j];
			indV++;
		}
	}

	//stampo il vettore
	for (j = 0; j<indV; j++)
		printf("%d\n", VETT[j]);

	fclose(fA); fclose(fB);


	system("pause");

	return 0;
}

