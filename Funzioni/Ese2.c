/*
Definire un nuovo tipo di dato chiamato VT vettore di 10 int.
Scrivere in C la funzione ft che:
ha in ingresso un vettore A di tipo VT già caricato e restituisce,
attraverso un opportuno parametro, una struct con 2 campi a e b di
tipo int che contengono rispettivamente la somma degli elementi di
A di posto pari e quella degli elementi di A di posto dispari;
restituisce la sommatoria di tutti gli elementi di A.
*/
#include <stdlib.h>
#include <stdio.h>
#define N 10
typedef int VT[N];
typedef struct { int a, b; } SOM;

int ft(VT A, SOM *s) {
	int i, som = 0;
	s->a = 0; s->b = 0; //(*s).a
	for (i = 0; i<10; i++) {
		som = som + A[i];
		if (i % 2 == 0) { s->a = s->a + A[i]; }
		else { s->b = s->b + A[i]; }
	}
	return som;
}

int ft2(VT A, SOM s) {
	int i, som = 0;
	s.a = 0; s.b = 0;
	for (i = 0; i<10; i++) {
		som = som + A[i];
		if (i % 2 == 0) { s.a = s.a + A[i]; }
		else { s.b = s.b + A[i]; }
	}
	return som;
}

int main() { //non richiesto dal testo
	VT v = { 2, -4, 3, 9, 12, 1, 6, -9, 5, 13 };
	SOM s,s1;
	int result = ft(v, &s);
	int result1 = ft2(v, s1);
\	printf("%d %d %d\n", result, s.a, s.b);
	printf("%d %d %d\n", result1, s1.a, s1.b);

	system("pause");     return 0;
}

