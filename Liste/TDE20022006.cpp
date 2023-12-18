/*
Sia data una lista concatenata semplice non ordinata di interi senza
valori duplicati. La struttura è:
typedef struct Elem { int    dato;
struct Elem * next;  } Nodo;
typedef Nodo * Lista;

La lista rappresenta un insieme di numeri. Una funzione incrocia()
riceve come parametri: la lista, un vettore dinamico di interi 
(anch’esso senza duplicati, allocato dal programma chiamante) 
e la lunghezza di tale vettore dinamico. La funzione rimuove dalla
lista originaria (deallocandoli) tutti i valori contenuti nel 
vettore (se presenti) e aggiunge in coda tutti i valori contenuti
nel vettore e non nella lista originaria.
Si definisca opportunamente il prototipo della funzione incrocia()
e si descriva sinteticamente (ma in modo preciso) come opera un
algoritmo che la implementa. In particolare, si badi a evitare che
un valore presente nella lista e non nel vettore sia prima aggiunto
e poi rimosso (o viceversa)
Si codifichi poi in C la funzione secondo l’algoritmo precedentemente dettagliato

*/

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

typedef struct Elem {
	int    dato;
	struct Elem * next;
} Nodo;
typedef Nodo * Lista;


void incrocia(Lista * lis, int * v, int lun) {
	Lista cur, prec; int i, found;
	for (i = 0; i < lun; i++) {

		if (*lis == NULL) {  /* Se la lista è vuota       */
			*lis = (Lista)malloc(sizeof(Nodo));
			(*lis)->dato = v[i];
			(*lis)->next = NULL;
		}

		else
		if ((*lis)->dato == v[i]){        /* Se il primo valore è v[i] */
			cur = *lis;
			*lis = (*lis)->next;
			free(cur);
		}
		else { /* Altrimenti, saltando il primo nodo */
			cur = (*lis)->next;  prec = *lis;
			found = 0;
			while (!found && cur != NULL) {
				if (cur->dato == v[i]) {
					prec->next = cur->next; free(cur);
					found = 1;
				}
				else {
					prec = cur;
					cur = cur->next;
				}
			}
			if (!found) {   /* Ins. in coda, se !trovato */
				prec->next = (Lista)malloc(sizeof(Nodo));
				prec->next->dato = v[i];
				prec->next->next = NULL;
			}
		}
	}
	return;
}

//Lista InsInFondo(Lista lista, int elem);
//int VerificaPresenza(Lista lista, int elem);
//Lista Cancella(Lista lista, int elem);
//Lista incrocia(Lista lis, int * v, int lun) {
//	if (lun == 0)
//		return lis;
//	if (VerificaPresenza(lis, v[0]))
//		lis = Cancella(lis, v[0]);
//	else
//		lis = InsInFondo(lis, v[0]);
//	if (lun == 1)
//		return lis;
//	lis = incrocia(lis, &v[1], lun - 1);
//	return lis;
//}

