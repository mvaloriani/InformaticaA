#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Scrivere un programma C, completo delle opportune
dichiarazioni di variabili,in grado di acquisire in
ingresso dall'utente un valore intero positivo num.

Il programma deve stampare a video tutti i fattori primi di num
*/

#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema

int main() {

	int num, fatt, cont;
	printf("\nInserisci un numero intero \n");
	scanf("%d", &num);

	printf("\n i fattori primi di %d sono:", num);

	//ipotesi: se num è primo considero num
	//divisore primo di se stesso
	for (fatt = num; fatt > 1; fatt--) {

		/*se fatt è divisore di num cerca se ha divisori*/
		if (num%fatt == 0) {
			// tutti i numeri son divisibili per se stessi, quindi fatt-1
			cont = fatt - 1; 

			while ((cont > 1) && (fatt%cont != 0))
				cont--;

			/* se sono arrivato a 1 vuol dire che non ho trovato divisori
			quindi stampo fatt perché primo */
			if (cont == 1)
				printf(" %d ", fatt);
		}
	}

	printf("\n");
	system("pause");
	return 0;
}
