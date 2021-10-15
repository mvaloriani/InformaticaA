/*
Sia data una lista concatenata semplice non ordinata di interi senza valori duplicati.
La struttura è:
typedef struct Elem { int    dato;
struct Elem * next;  } Nodo;
typedef Nodo * Lista;
La lista rappresenta un insieme di numeri.
Una funzione incrocia() riceve come parametri:
la lista, un vettore dinamico di interi
(anch’esso senza duplicati, allocato dal programma chiamante)
e la lunghezza di tale vettore dinamico.


La funzione rimuove dalla lista originaria (deallocandoli)
tutti i valori contenuti nel vettore (se presenti) e
aggiunge in coda tutti i valori contenuti nel vettore e non nella lista originaria.
Si definisca opportunamente il prototipo della funzione incrocia()
e si descriva sinteticamente (ma in modo preciso) come opera un algoritmo che la implementa.

In particolare, si badi a evitare che un valore presente nella lista
e non nel vettore sia prima aggiunto e poi rimosso (o viceversa)
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
			if ((*lis)->dato == v[i]) {        /* Se il primo valore è v[i] */
				cur = *lis;
				*lis = (*lis)->next;
				free(cur);
			}
			else { /* Altrimenti, saltando il primo nodo */
				cur = (*lis)->next;  prec = *lis;
				found = 0;
				while (!found && cur != NULL) {
					if (cur->dato == v[i]) {
						prec->next = cur->next;
						free(cur);
						found = 1;
					}
					else {
						prec = cur;
						cur = cur->next;
					}
				}
				if (!found) {   /* Ins. in coda, se !trovato */
					prec->next = (Lista)malloc(sizeof(Nodo));

					/*	temp->dato = v[i];
						temp->next = NULL;*/

					prec->next->dato = v[i];
					prec->next->next = NULL;
				}
			}
	}
	return;
}


Lista InsInFondo(Lista lista, int elem);
int VerificaPresenza(Lista lista, int elem);
Lista Cancella(Lista lista, int elem);


Lista incrocia(Lista lis, int * v, int lun) {
	if (lun == 0)
		return lis;
	if (VerificaPresenza(lis, v[0]))
		lis = Cancella(lis, v[0]);	
	else
		lis = InsInFondo(lis, v[0]);
	//lis = VerificaPresenza(lis, v[0]) ? Cancella(lis, v[0]) : InsInFondo(lis, v[0]);

	if (lun == 1)
		return lis;

	return incrocia(lis, &v[1], lun - 1);
}

Lista incrocia(Lista lis, int * v, int lun) {
	for (i = 0; i < lun; i++) {
		if (VerificaPresenza(lis, v[i]))
			lis = Cancella(lis, v[i]);
		else
			lis = InsInFondo(lis, v[i]);
	}
	return lis;
}

Lista incrociaconduplicati(Lista lis, int * v, int lun) {
	
	for (i = 0; i < lun; i++) {
		trovato = 0;
		for (int k = 0; k < i; k++) {		
			if (v[k] == v[i])
				trovato = 1;
		}

		if (trovato == 0) {
			if (VerificaPresenza(lis, v[i]))
				lis = Cancella(lis, v[i]);
			else
				lis = InsInFondo(lis, v[i]);
		}
	}
	return lis;
}



Lista InsInFondo(Lista lista, int elem) {
	Lista punt, cur = lista;

	punt = (Lista)malloc(sizeof(Nodo));
	punt–> next = NULL;
	punt–> dato = elem;

	if (lista == NULL)
		return  punt;
	else {
		while (cur – > next != NULL)
			cur = cur– > next;
		cur – > next = punt;
	}
	return lista;
}

bool VerificaPresenza(Lista lista, int elem) {
	if (lista == NULL)
		return false;
	if (lista–> dato == elem)
		return true;
	
	return VerificaPresenza(lista–> next, elem);
}

Lista VerificaPresenza2(Lista lista, int elem) {
	
	if (lista == NULL && lista->next ==null)
		return NULL;

	if (lista–> next-> dato == elem)
		return lista;

	return VerificaPresenza(lista–> next, elem);
}




int Trova(Lista lista, int elem) {
	if (lista == NULL)
		return 0;
	if (Condizie(lista–>dato, elem))
		return 1;

	return Trova(lista–> next, elem);
}

bool condizione(int dato, int elem)
{
	if(dato==elem)//qualsiasi condizione	
		return 0;
	else 
		return 1;
}


Lista Cancella(Lista lista, int elem) {
	Lista puntTemp;
	if (lista != NULL)
		if (lista–> dato == elem) {
			puntTemp = lista– > next;
			free(lista);
			return puntTemp;
		}
		else
			lista–> next = Cancella(lista–> next, elem);
	return lista;
}

void print(Lista *list) {
	Lista temp = *list;

	while (temp != NULL)
	{
		printf("%d", temp->dato);
		temp = temp->next;
	}
}

void print(Lista list) {
	Lista temp = list;
	
	while (temp!= NULL)
	{
		printf("%d", temp->dato);
		temp = temp->next;
	}
}

void printRIC(Lista list) {
	Lista temp = list;

	if (temp == NULL)
		return;

	printf("%d", temp->dato);
	print(temp->next);
	}
}