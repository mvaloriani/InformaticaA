#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Scrivere un programma C, in grado di acquisire
in ingresso dall'utente un valore intero num
e una sequenza di interi che termina con uno 0 (zero).

Il programma deve stampare a video il numero di
valori pari nella sequenza che sono divisori di num.
0 viene considerato come valore sentinella.
*/

#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema

int main() {

	int num, valore, cont = 0;
	printf("Inserisci un numero intero \n");
	scanf("%d", &num);

	printf("Inserisci una serie di interi(0 per terminare) :\n");
	do {
		scanf("%d", &valore);
		if (valore != 0 
			&& (valore % 2) == 0 
			&& (num%valore) == 0)
			cont++;
	} while (valore != 0);

	printf("I valori pari divisori di %d sono %d", num, cont);

	printf("\n");
	system("pause");
	return 0;
}
