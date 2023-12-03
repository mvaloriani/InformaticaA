#include <stdio.h> 
#include <math.h>
#include <stdlib.h>


/*
 Si consideri una lista dinamica di interi,
 i cui elementi sono del tipo definito come 
 di seguito riportato:
	typedef struct El {
	  int dato;
	  struct El *next;
	} ELEMENTO;

Si codifichi in C la funzione somma avente
il seguente prototipo:
	int somma(ELEMENTO *Testa, int M)
Tale funzione riceve come parametro la testa
della lista e un intero M. Quindi,
restituisce la somma dei soli valori della
lista che sono multipli di M.

Se la lista è vuota, la funzione restituisce il valore -1.

 */


typedef struct El {
	int dato;
	struct El *next;
} ELEMENTO;


int somma(ELEMENTO *Testa, int M) {
	int sum = 0;
	if (Testa == NULL)
		return -1;

	while (Testa != NULL) {
		if (Testa->dato%M == 0)
			sum = sum + Testa->dato; //(*Testa).dato

		Testa = Testa->next;//(*(*Testa).next).next
	}
	return sum;
}

int sommaRic2(ELEMENTO *Testa, int M) {
	if (Testa == NULL)
		return -1;
	return sommaRic(Testa, M);
}

int sommaRic(ELEMENTO *Testa, int M) {
	if (Testa == NULL)
		return -1;

	int sum = 0;
	if (Testa->dato%M == 0)
		sum = Testa->dato;

	if (Testa->next == NULL)
		return sum;
	else
		return sommaRic(Testa->next, M) + sum;
}
