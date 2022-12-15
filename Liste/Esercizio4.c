#include <stdio.h> 
#include <math.h>
#include <stdlib.h>

//Supponendo date le seguenti definizioni :
typedef struct El {
	int s;
	struct El* next;
}Elemento;
typedef Elemento* ListaDiInteri;
/*
definire una funzione MinEven che, data una
ListaDiInteri restituisce la posizione(puntatore)
del minimo elemento pari nella lista(restituisce NULL
se la lista non contiene elementi pari).
*/

ListaDiInteri MinEven(ListaDiInteri lis) {
	ListaDiInteri ris;
	ris = FirstEven(lis);
	if (ris != NULL) {
		lis = ris->next;
		while (lis != NULL) {
			if (((lis->s) % 2 == 0) && (lis->s < ris->s))
				ris = lis;
			lis = lis->next;
		}
	}
	return ris;
}

//Definiamo una funzione MinEl che restituisce il minimo tra due elementi
ListaDiInteri MinEl(ListaDiInteri p, ListaDiInteri q) {
	if ((p->s) < (q->s))
		return p;
	else
		return q;

	//return (p->s) < (q->s) ? p : q;
}

ListaDiInteri MinEven(ListaDiInteri lis) {
	ListaDiInteri p;
	if (lis == NULL)
		p = NULL;

	else
		if ((lis->s) % 2 != 0)
			p = MinEven(lis->next);
		else {
			p = MinEven(lis->next);
			if (p != NULL)  p = MinEl(lis, p);
			else  p = lis;
		}
	return p;
}

ListaDiInteri MinEven2(ListaDiInteri lis) {
	ListaDiInteri p;

	if (lis == NULL)
		return  NULL;

	if ((lis->s) % 2 != 0)
		return MinEven(lis->next);

	p = MinEven(lis->next);

	return (p != NULL)? MinEl(lis, p) : lis;
}
