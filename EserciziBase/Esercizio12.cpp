#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Dato un numero positivo Q, scrivere la sua
rappresentazione in binario naturale,
indicando anche il minimo numero di bit utilizzato.
Il programma dovrà esibire un comportamento
come nell'esempio seguente:
	Input: 19 in decimale
	Output: con 5 bit  =  10011 in binario.


*/

#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema

int main() {
	int i, Q, n=0, d=1;
	do { 
		printf("Inserire un numero positivo:"); 
		scanf("%d", &Q); }
	while (Q <= 0);

	while (Q >= d) {		
		n = n + 1;
		d = d * 2; }

	/* d è la più piccola potenza di 2 maggiore di Q, n l'esponente della
		 potenza di 2 in d e il numero di bit minimo per rappresentare Q. */
	printf("\n%d in decimale, con %d bit = ", Q, n);
	
	/* esponente più significativo della rappresentazione binaria di Q. */
	i = n - 1;
	while (i >= 0) {
		d = d / 2;
		if (Q >= d) { 
			printf("1");
			Q = Q - d; 
		}
		else { printf("0"); }
		i--;
	}

	printf("\n");
	system("pause");

	return 0;
}
