/*
Scrivere una funzione che riceve in input due array di N elementi
e copia nel secondo gli elementi di valore pari del primo senza
lasciare buchi. La funzione restituisce il numero di elementi copiati.

*/

#include <stdlib.h>
#include <stdio.h>
#define N 10

typedef struct { int v[N]; int cont; } arrayConCont;

int copiaPari(int A[], int B[]) {
	int i, j = 0;
	// i usato per scorrere A
	// j punta sempre al primo elemento libero di B

	for (i = 0; i<N; i++)
	if (A[i] % 2 == 0) {
		B[j] = A[i];
		j++;
	}

	return j;
}

/*
Scrivere una funzione che riceve in input un array di N elementi e
restituisce una struct composta da un intero e da un array.
La funzione inserisce nell’array contenuto nella struct gli
elementi pari dell’array che riceve in input e assegna all’intero
contenuto nella struct il numero di elementi copiati.

*/

arrayConCont copiaPari2(int A[]) {
	arrayConCont ac;
	int i;	// i usato per scorrere A
	ac.cont = 0; // ac.cont punta sempre al primo
	// elemento di ac.v

	for (i = 0; i<N; i++)
	if (A[i] % 2 == 0) {
		ac.v[ac.cont] = A[i];
		ac.cont++;
	}

	return ac;
}

arrayConCont copiaPari3(int A[]) {
	arrayConCont ac;
	ac.cont = copiaPari(A, ac.v);
	return ac;
}

/*
Scrivere una funzione che riceve in input un array di N elementi
e una struct composta da un intero e da un array. La funzione
modifica la struct inserendo nell’array gli elementi pari dell’array
che riceve in input e assegna all’intero contenuto nella struct il
numero di elementi copiati.

*/


void copiaPari4(int A[], arrayConCont *ac) {
	int i;	// i usato per scorrere A
	ac->cont = 0; // ac->cont punta sempre al primo
	// elemento di ac.v

	for (i = 0; i<N; i++)
	if (A[i] % 2 == 0) {
		ac->v[ac->cont] = A[i];
		ac->cont++;
	}
}

void copiaPari5(int A[], arrayConCont *ac) {
	int i;	// i usato per scorrere A
	ac->cont = 0; // ac->cont punta sempre al primo
	// elemento di ac.v
	ac->cont = copiaPari(A, ac->v);	
}



int main() {
	int A[N] = { 1, 2, 3, 4, 5, 6,7,8,9,10 };
	int B[N];
	copiaPari(A, B);
	printf("vettore \n");
	for (int j = 0; j<N; j++)
		printf("%d\n", A[j]);
	printf("\nCopia Pari:\n");
	for (int j = 0; j<N; j++)
		printf("%d\n", B[j]);

	arrayConCont ac = copiaPari2(A);
	printf("\nCopia Pari2:\n");
	for (int j = 0; j<N; j++)
		printf("%d\n", ac.v[j]);

	ac = copiaPari3(A);
	printf("\nCopia Pari3:\n");
	for (int j = 0; j<N; j++)
		printf("%d\n", ac.v[j]);

	copiaPari4(A,&ac);
	printf("\nCopia Pari4:\n");
	for (int j = 0; j<N; j++)
		printf("%d\n", ac.v[j]);

	copiaPari5(A, &ac);
	printf("\nCopia Pari5:\n");
	for (int j = 0; j<N; j++)
		printf("%d\n", ac.v[j]);

	system("pause"); 
	return 0;
}


