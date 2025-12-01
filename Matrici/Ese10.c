#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
Si scriva una frammento di codice che usa una matrice di interi NxN
(con N costante predefinita) e un array di caratteri.
Ogni elemento dell’array contiene solo i caratteri ‘0’, ‘1’ o ‘\0’
e rappresenta una stringa che è la codifica binaria di un intero. 
Il programma deve stampare VERO se il numero decimale corrispondente 
all’intero codificato in binario nell’array è uguale alla media degli 
interi contenuti nella matrice, FALSO altrimenti.

*/

#define N 3  

int main() {
	int m[N][N], i, j, trovato, cont = 0, cont2 = 0;
	char c[33] = { 0 };

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("\nInserisci un elemento della matrice [%d][%d]: ", i, j);
			scanf("%d", &m[i][j]);
		}
	}

	printf("\nInserisci un numero binario:");
	scanf("%s", &c);
}