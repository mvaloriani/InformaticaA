#include <stdio.h> 
#include <math.h>
#include <stdlib.h>

typedef struct Node {
	int numero;
	struct Node* next;
} Nodo;
typedef Nodo* Lista;

/*
Si progetti e codifichi una funzione C che
riceve in ingresso una lista definita

La funzione deve verificare se l’andamento
della lista è monotono crescente
, cioè se ogni elemento è strettamente
superiore al suo predecessore.
*/

int monotona(Lista L) {
	Lista Cursore1 = L, Cursore2;

	if (L != NULL)
		Cursore2 = L->next;

	while (Cursore2 != NULL) {
		if (Cursore2->numero < Cursore1->numero)
			return 0;
		Cursore1 = Cursore2;
		Cursore2 = Cursore2->next;
	}
	return 1;
}

int monotonaRIC(Lista lis) {
	if (lis == NULL)
		return 1;
	if (lis->next == NULL)
		return 1;
	if (lis->numero < lis->next->numero)
		return monotonaRIC(lis->next);
	else return 0;
}
