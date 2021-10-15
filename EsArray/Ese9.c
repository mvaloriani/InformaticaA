#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*

Scrivere un programma che stampi tutti i numeri fortunati minori di 200.

Un numero fortunato è un numero naturale in un insieme generato come segue:
Si inizia con la successione di tutti i numeri interi:
	1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25…
Si eliminano poi tutti i secondi numeri (ovvero si lasciano solo i numeri dispari):
	1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43…
Il secondo termine rimasto in questa sequenza è 3. Si eliminano dunque tutti i terzi numeri che rimangono nella sequenza:
	1, 3, 7, 9, 13, 15, 19, 21, 25, 27, 31, 33, 37, 39, 43…
Il terzo numero rimasto ora è 7.  Si eliminano dunque tutti i settimi numeri che rimangono nella sequenza:
	1, 3, 7, 9, 13, 15, 21, 25, 27, 31, 33, 37, 43…  poi i noni numeri, poi i tredicesimi…
Ripetendo la procedura indefinitamente, i rimanenti sono numeri fortunati:
	 1, 3, 7, 9, 13, 15, 21, 25, 31, 33, 37, 43, 49, 51, 63, 67, 69, 73, 75, 79, 87, 93, 99... 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXDIM 200 
int main() {
	int vet[MAXDIM];
	int n = 2, iter = 1, cont, next = 1, i;

	for (int i = 0; i < MAXDIM; i++) {
		vet[i] = i + 1;
		printf("%d ", vet[i]);
	}
	printf("\n");

	while (n < MAXDIM && next == 1) {

		cont = 0;
		printf("%d: ", n);
		// Fase di cancellazione
		for (int i = 0; i < MAXDIM; i++)
		{
			if (vet[i] != 0)
				cont++;

			//if (cont == n) {
			//	vet[i] = 0;
			//	cont = 0;
			//}
			//if(vet[i]!=0 && cont!=0)
			//	printf("%i ", vet[i]);

			if (cont % n ==0) {
				vet[i] = 0;
			}

			if (vet[i] != 0 && cont%n !=0)
				printf("%i ", vet[i]);

		}
		printf("\n");

		// Riduco il numero di iterazioni
		if (cont < n) 
			break;

		// trovo il prossimo passo
		cont = 0;
		next = 0;
		for (int i = 0; i < MAXDIM && next == 0; i++)
		{
			if (vet[i] != 0)
				cont++;
			if (cont == iter + 1) {
				n = vet[i];
				iter++;
				next = 1;
			}
		}
	}


	system("pause");
	return 0;
}