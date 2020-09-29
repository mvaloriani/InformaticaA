#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Si scriva un programma in linguaggio C che
letto un numero intero positivo dallo
standard input, visualizzi a terminale
il cubo del numero stesso facendo uso
soltanto di operazioni di somma.

*/

#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema

int main() {

	int i, N, S = 0, cubo = 0;
	do { /* Finché il numero inserito N non è positivo ripetere */
		printf("\n Inserisci un numero positivo N: ");
		scanf("%d", &N);
	} while (N <= 0);
	

	//Trovo il quadrato
	for (i = 0; i < N; i++)
	{
		S = S + N;
	}
	
	// N^3= N^2 * N = N^2 + N^2 + ... + N^2
	i = 0;
	while (i < N) {
		cubo = cubo + S;
		i++;
	}

	printf("Il cubo del numero inserito e': %d \n", cubo);

	system("pause");
	return 0;
}
