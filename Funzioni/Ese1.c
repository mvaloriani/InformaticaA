/*
Definire un nuovo tipo di dato chiamato VT vettore di 10 interi. 
Scrivere in C la funzione ft che:

ha in ingresso un vettore A di tipo VT già caricato e restituisce,
attraverso un opportuno parametro, un vettore di tipo VT
che contiene gli stessi elementi del vettore di ingresso 
ma in ordine inverso;
restituisce il prodotto di tutti gli elementi di A.
*/

#include <stdlib.h>
#include <stdio.h>
#define N 10
typedef int VT[N];

typedef struct {
	int p;
	VT B;
} RES;

// SOLUZIONE CON STRUTTURA RITORNATA
RES ft3(VT A) {
	int i, j;
	RES temp;
	temp.p = 1;

	for (i = 0; i < N; i++) {
		temp.B[N - i - 1] = A[i];
		temp.p = temp.p * A[i];
	}
	return temp;
}

// SOLUZIONE SOLO PUNTATORI
void ft2(VT A, VT B, int *p) {
	int i, j;
	(*p) = 1;
	for (i = 0; i < N; i++) {
		B[N - i - 1] = A[i];
		*p = (*p) * A[i];
	}

	return;
}

// SOLUZIONE RETURN + VETTORI
int ft(VT A, VT B) {
	int i, prod = 1;
	for (i = 0; i < N; i++) {
		B[N - i - 1] = A[i];
		prod = prod * A[i];
	}
	return prod;
}


//int ft(VT A, VT B) {
//	int i, j, prod = 1;
//	for (i = 0, j = N - 1; i<N; i++, j--) {
//		B[j] = A[i];
//		prod = prod * A[i];
//	}
//	/*for (i = 0; i < N; i++) {
//		prod = prod * A[i];
//	}
//	for (i = 0; i < N; i++) {
//		B[N - i - 1] = A[i];
//	}*/
//	return prod;
//}





int main() { 
	VT v = { 2, -4, 8, 9, 12, 1, 6, -9, 5, 3 };
	int w[N];
	int j, res;
	for (j = 0; j<10; j++)
		printf("%d\n", v[j]);

	res = ft(&v[0], w);
	//res = ft(v, w);
	//res = ft(&v[0], &w[0]);

	ft2(v, w, &res);
	RES res3 = ft3(v);

	printf("prodotto: %d\n", res3.p);

	printf("vettore invertito");
	for (j = 0; j<10; j++)
		printf("%d\n", res3.B[j]);
	system("pause");  return 0;
}
