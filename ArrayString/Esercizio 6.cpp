#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Scrivere un programma C che legge da tastiera una
sequenza di 100 numeri interi.

Dopo avere letto tutti i numeri cercare le coppie di
numeri tali che il primo sia il doppio dell’altro.
*/


#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema

#define MAXDIM 10

int main()
{
	int dati[MAXDIM];
	int i = 0, j = 0;
	do {
		scanf("%d", &dati[i]);
		i++;
	} while (i < MAXDIM);

	for (i = 0; i < MAXDIM; i++) {
		for (j = 0; j < MAXDIM; j++) {
			if (dati[i] == 2 * dati[j] && i != j) {
				printf("\ncoppia: %d e %d", dati[i], dati[j]);
			}
		}
	}


	printf("\n\n");
	system("pause");
	return 0;
}

