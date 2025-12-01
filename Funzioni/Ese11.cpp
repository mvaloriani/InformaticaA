/*
Scrivere in linguaggio C, un programma che letta una sequenza
di N numeri complessi dallo standard input
(rappresentati con parte reale e parte immaginaria)
stampi video la sequenza ordinata in maniera crescente
secondo il valore dei loro moduli.
*/

#include <stdio.h>
#include <math.h>
#define MAX_LEN 100

typedef struct { float re;  float im; } complex;

void scambio(complex* p1, complex* p2);
float modulo2(complex x);
int cmp_complex(complex c1, complex c2);
void ordina_vettore(int N, complex v_in[], complex v_out);

int main() {
	complex A[MAX_LEN], B[MAX_LEN];
	int N=-1, i;

	// === Lettura del numero di elementi ===
	printf("Inserisci il numero di numeri complessi (max %d): ", MAX_LEN);
	while (scanf("%d", &N) != 1 || N <= 0 || N > MAX_LEN) {
		printf("Errore: N non valido (deve essere tra 1 e %d). Riprova\n", MAX_LEN);
		fflush(stdin);
	}

	// === Lettura dei numeri complessi ===
	printf("Inserisci i numeri complessi (parte_reale parte_immaginaria):\n");
	for ( i = 0; i < N; ++i) {
		printf("[%d] ", i + 1);
		while (scanf("%f %f", &A[i].re, &A[i].im) != 2) {
			printf("Errore in lettura al numero complesso %d. RIprova\n", i + 1);
			fflush(stdin); //scanf("%*[^\n]%*c");
		}
	}

	// === Ordinamento dei numeri complessi ===
	ordina_vettore(N, A, B);

	// === Stampa del risultato ===
	printf("\nSequenza ordinata per modulo crescente:\n");
	for ( i = 0; i < N; ++i) {
		printf("(%8.3f, %8.3f)\n", B[i].re, B[i].im);
	}

	return 0;
}

void scambio(complex* p1, complex* p2) {
	complex aux;
	aux = *p1;
	*p1 = *p2;
	*p2 = aux;
}

float modulo2(complex x) {
	return sqrt((x.re * x.re) + (x.im * x.im));
}

int cmp_complex(complex c1, complex c2) {
	if (modulo2(c1) > modulo2(c2)) return 1;
	if (modulo2(c1) < modulo2(c2)) return -1;
	return 0;
}

void ordina_vettore(int N, complex v_in[], complex v_out[]) {
	int i, j;

	for (i = 0; i < N - 1; i++) { v_out[i] = v_in[i]; }
	// Questa copia tra vettori si rende necessaria, visto che non 
	// si desidera che dopo la chiamata a questo sottoprogramma il 
	// vettore V_in[] nel chiamante risulti modificato. 

	for (i = 0; i < N - 1; i++) 
		for (j = 0; j < N - i - 1; j++) 
			if (cmp_complex(v_in[j], v_in[j + 1]) > 0) 
				scambio(&v_in[j], &v_in[j + 1]);
}


