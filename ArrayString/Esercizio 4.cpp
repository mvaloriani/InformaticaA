#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Scrivere un programma C che faccia quanto segue:
- Legge una sequenza di numeri interi e quei numeri compresi
tra 0 e 1023 vengono memorizzati in un vettore di nome V. 
La lettura termina quando nel vettore sono stati inseriti 10 numeri

- Per ogni numero in V il programma esegue la conversione in binario,
memorizza i resti ottenuti in un vettore R opportunamente dimensionato
e stampa il contenuto di R


*/


#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema

#define N 10
#define M 10
#define MAXVAL 1023


int main()
{
	int i = 0, j, V[N], R[M];

	// leggo fino a quando non raggiunto N valori validi
	do {
		scanf("%d", &V[i]);
		if (V[i] >= 0 && V[i] <= MAXVAL)
			i++; //incremento solo quando ho un valore valido
	} while (i<N);


	for (i = 0; i<N; i++) {
		for (j = M - 1; j >= 0; j--) {
			R[j] = V[i] % 2;
			V[i] = V[i] / 2;
		}
		for (j = 0; j<M; j++)
			printf("%d ", R[j]);
		printf("\n");
	}


	printf("\n");
	system("pause");
	return 0;
}

