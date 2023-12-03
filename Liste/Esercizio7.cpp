#include <stdio.h> 
#include <math.h>
#include <stdlib.h>

/*
Supponendo date le seguenti definizioni:
*/
typedef int Tipo;
typedef struct El {
	Tipo s;
	struct El* next;
} Elemento;
typedef Elemento* Lista;

/*
definire una funzionefoo che, data una Lista l
ed un intero el inserisce el dopo il terzo elemento di l.
Se quest’ultima non contiene almeno tre elementi,
viene lasciata inalterata.
*/

Lista third(Lista lis) {
	int count = 1;
	while ((lis != NULL) && (count < 3)) {
		count++;
		lis = lis->next;
	}
	if (count == 3)
		return lis;
	else
		return NULL;
}

void foo(Lista lis, Tipo el) {
	Lista tmp, new2;
	tmp = third(lis);
	if (tmp != NULL) {
		new2 = malloc(sizeof(Elemento));
		new2->next = tmp->next;
		new2->s = el;
		tmp->next = new2;
	}
}


void foo2(Lista lis, Tipo el) {

	if (lis != NULL && lis->next != NULL && lis->next->next != NULL) {
		Lista tmp, new2;
		tmp = lis->next->next;

		new2 = malloc(sizeof(Elemento));
		new2->next = tmp->next;
		new2->s = el;
		tmp->next = new2;
	}
	else
		return;


}
