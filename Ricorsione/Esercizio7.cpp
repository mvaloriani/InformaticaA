#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*

Scrivere un programma C che stampi a video tutte le possibili N! permutazioni
degli elementi di un vettore di N interi.

Il problema proposto si presta in modo naturale 
ad una formulazione ricorsiva, infatti:
Il vettore è lungo “len” e inizialmente dobbiamo costruire
le permutazioni di “n = len” elementi:

Per generare tutte le possibili permutazioni di
n elementi, si può pensare di tenere fisso l’
elemento in prima posizione e stampare l’intera
sequenza per ognuna delle permutazioni dei restanti n-1 elementi.

Scambiare il primo degli n elementi  da permutare con il secondo
ripetere considerando n-1 elementi (tranne il primo)
scambiare nuovamente il primo degli n elementi con il secondo
Scambiare il primo degli n elementi elemento con il terzo
ripetere considerando n-1 elementi
scambiare nuovamente il primo degli n elementi con il secondo

Vettore V con len elementi, vogliamo costruire le
permutazioni dei suoi primi n = len elementi.
 
caso base
	se N=1 allora la stampo il vettore V stesso.
 
passo induttivo
	se N>1
	per ogni elemento V[i] tra V[len-n] e V[len-1]
si scambia l’elemento V[len-n] con l’elemento V[len-n+i]
si stampano i vettori contenenti le permutazioni del sotto-vettore tra V[len-n] e V[len-1].
si scambia l’elemento V[len-n] con l’elemento V[len-n+i]

*/

#include <stdio.h>

void stampaVett(int *V, int len);
void scambia(int *x, int *y);
void permuta(int *V, int n, int len);

int main() {
	int V[] = { 1,2,3,4,5,6 };
	int len = 6;

	permuta(V, len, len);  // dopo la chiamata a sottoprogramma l’array V 
						   // non risulta essere stato modificato.

	return 0;
} // end main

void stampaVett(int *V, int len) {
	int i;
	printf("\n");
	for (i = 0; i < len; i++)
		printf(" %c ", V[i]);
}

void scambia(int *x, int *y) {
	int aux;

	aux = *x;
	*x = *y;
	*y = aux;
}

void permuta(int *V, int n, int len) {
	int i;

	if (n == 1) {
		stampaVett(V, len);
	}
	else {
		for (i = 0; i < n; i++) {
			scambia(&V[len - n], &V[len - n + i]);
			permuta(V, n - 1, len);
			scambia(&V[len - n], &V[len - n + i]);
		}
	}
}
