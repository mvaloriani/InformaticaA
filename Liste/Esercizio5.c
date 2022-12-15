//Supponendo date le seguenti definizioni :
#include <cstddef>

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
