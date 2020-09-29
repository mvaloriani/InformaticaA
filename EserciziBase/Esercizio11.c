#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Si definisce Triangolare un numero costituito dalla
somma dei primi N numeri interi positivi per un certo N.
Ad esempio: per Q = 10 si ha Q =1+2+3+4, da cui N = 4.
Scrivere un programma C che stabilisca se un numero 
intero positivo Q, letto dallo standard input, 
è un numero triangolare o meno, utilizzando soltanto operazioni 
tra numeri interi. In caso affermativo stampare a video il numero
inserito e il massimo degli addendi che lo compongono.

*/

#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema

int main() {
	int i = 0, Q, S;
	do {
		printf("\n Inserisci un numero positivo Q: "); 
		scanf("%d", &Q);
	} while (Q <= 0);

	S = Q;        /* copia del valore del dato in ingresso        */
	while (S > 0) {
		i = i + 1;
		S = S - i;
	}
	if (S == 0) {
		/*i contiene qui il valore del massimo addendo componente il numero*/
		printf("\n %d = alla somma dei primi %d numeri positivi!", Q, i);
	}
	else {
		printf("\n Il numero %d non e' un numero triangolare! \n", Q);
	}
	system("pause");

	return 0;


}