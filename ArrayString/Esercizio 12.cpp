#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Scrivere un programma che chieda di inserire una
sequenza di caratteri, fino allo spazio, riconosca
se i caratteri inseriti sono cifre pari o dispari o
se sono altro, visualizzi le tre sequenze divise per tipo.
Memorizzo le pari in un array, le dispari in un
secondo array e tutto il resto in un terzo, controllando le dimensioni
*/

#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema
#include <string.h>  // inclusione libreria standard per gestione stringhe

#define lung 100 

int main() {
	int p = 0, d = 0, a = 0, i = 0;
	char cosa, pari[lung], dispari[lung], altro[lung];
	do {
		scanf("%c", &cosa);
		fflush(stdin);
		switch (cosa) {
		case '0': 
		case '2': 
		case '4': 
		case '6': 
		case '8': 
			pari[p] = cosa;
			p++;
			break;
		case '1': 
		case '3': 
		case '5': 
		case '7': 
		case '9': 
			dispari[d] = cosa;
			d++; 
			break;
		default: 
			if (cosa != ' ')
			{ altro[a] = cosa; 
			a++; } 
			break;
		}
	} while (cosa != ' ' && p < lung && d < lung && a < lung);

	printf("\nle cifre pari sono: ");
	for (i = 0; i < p; i++)
		printf(" %c ", pari[i]);

	printf("\nle cifre dispari sono: ");
	for (i = 0; i < d; i++)
		printf(" %c ", dispari[i]);

	printf("\ni caratteri non cifre sono: ");
	for (i = 0; i < a; i++)
		printf(" %c ", altro[i]);
	
	//////Soluazione 2
	//pari[p] = '\0';
	//printf(" \nle cifre pari sono: %s", pari);
	//
	//dispari[d] = '\0';
	//printf(" \nle cifre dispari sono: %s", dispari);
	//
	//altro[a] = '\0';
	//printf(" \ni caratteri non cifre sono: %s", altro);

	printf("\n");
	system("pause");
	return 0;
}

