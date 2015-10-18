/*
Definire un nuovo tipo di dato chiamato VT vettore di 10 interi. Scrivere in C la funzione ft che:

ha in ingresso un vettore A di tipo VT già caricato e restituisce,
attraverso un opportuno parametro, un vettore di tipo VT
che contiene gli stessi elementi del vettore di ingresso ma in ordine inverso;
restituisce il prodotto di tutti gli elementi di A.
*/

#include <stdlib.h>
#include <stdio.h>
#define N 10
typedef int VT[N];

int ft(VT A, VT B) {
	int i, j, prod = 1;
	for (i = 0, j = N - 1; i<N; i++, j--) {
		B[j] = A[i];
		prod = prod * A[i];
	}
	return prod;
}

int main() { 
	VT v = { 2, -4, 8, 9, 12, 1, 6, -9, 5, 3 }, w;
	int j;
	for (j = 0; j<10; j++)
		printf("%d\n", v[j]);

	printf("prodotto: %d\n", ft(v, w));

	printf("vettore invertito");
	for (j = 0; j<10; j++)
		printf("%d\n", w[j]);
	system("pause");  return 0;
}
