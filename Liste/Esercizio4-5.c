//Supponendo date le seguenti definizioni :
#include <cstddef>
#include <stdio.h> 
#include <math.h>
#include <stdlib.h>

typedef struct El {
	int s;
	struct El* next;
} ElementoLista;
typedef ElementoLista* ListaDiInteri;

/*definire una funzione FirstEven che, data
una ListaDiInteri restituisce la posizione(puntatore) 
del primo elemento pari nella lista(restituisce NULL se
la lista non contiene elementi pari).
*/

ListaDiInteri FirstEven(ListaDiInteri lis) {
	while (lis != NULL) {
		if (lis->s % 2 == 0)
			return lis;
		/* il primo pari è in lis */
		else
			lis = lis->next;
	}
	return NULL;
}

ListaDiInteri FirstEvenRIC(ListaDiInteri lis) {
	ListaDiInteri ris = NULL;
	if (lis != NULL) {
		if ((lis->s) % 2 == 0)
			ris = lis;
		else
			ris = FirstEvenRIC(lis->next);
	}
	return ris;
}

/*
definire una funzione MinEven che, 
data una ListaDiInteri restituisce la posizione (puntatore)
del minimo elemento pari nella lista 
(restituisce NULL se la lista non contiene elementi pari).
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

ListaDiInteri MinEven2(ListaDiInteri lis) {
	ListaDiInteri ris;
	ris = FirstEven(lis);
	if (ris != NULL) {
		lis = FirstEven(ris->next);
		while (lis != NULL) {
			if (lis->s < ris->s)
				ris = lis;
			lis = FirstEven(ris->next);
		}
	}
	return ris;
}

ListaDiInteri MinEl(ListaDiInteri p, ListaDiInteri q) {
	if ((p->s) < (q->s))
		return p;
	else
		return q;

	//return (p->s) < (q->s) ? p : q;
}

ListaDiInteri MinEvenRIC(ListaDiInteri lis) {
	ListaDiInteri p;
	if (lis == NULL)
		p = NULL;
	else {
		if ((lis->s) % 2 != 0)
			p = MinEvenRIC(lis->next);
		else {
			p = MinEvenRIC(lis->next);
			if (p != NULL)
				p = MinEl(lis, p);
			else  p = lis;
		}
	}
	return p;
}

ListaDiInteri MinEvenRIC2(ListaDiInteri lis) {
	ListaDiInteri p;

	if (lis == NULL)
		return  NULL;

	if ((lis->s) % 2 != 0)
		return MinEvenRIC2(lis->next);

	p = MinEvenRIC2(lis->next);

	return (p != NULL) ? MinEl(lis, p) : lis;
}
