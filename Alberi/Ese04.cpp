/*
Un albero N-ario generico è un albero i cui nodi
possono avere un numero arbitrariamente grande
di rami uscenti. Si definisca una struttura
dati adatta a rappresentare un albero N-ario.
Per semplicità si consideri il caso in cui i
nodi contengono, come dati utili, dei semplici numeri interi.
Ogni nodo contiene, invece di una coppia di
puntatori a nodi, come nel caso degli alberi binari,
una lista di puntatori a nodo. Tale lista è una
lista concatenata semplice, realizzata tramite la struttura Ramo.
typedef Nodo * Albero;
typedef struct Branch { Albero child;  struct Branch * next; } Ramo;
typedef struct Knot { int  dato; Ramo * rami;  } Nodo;
Si progetti (e/o codifichi) la funzione int conta( … ) 
che conta il numero di nodi di un albero N-ario.

*/
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

typedef Nodo * Albero;
typedef struct Branch { Albero child;  struct Branch * next; } Ramo;
typedef struct Knot { int  dato; Ramo * rami; } Nodo;


int conta(Albero t) {
	int n;
	if (t == NULL) {
		return 0;
	}
	else {
		n = 1;
		Ramo * cur = t->rami;
		while (cur != NULL) {
			n += contaRami(cur->child);
			cur = cur->next;
		}
		return n;
	}
}


int contaNodi(Albero t) {
	if (t == NULL)
		return 0;
	else
		return 1 + contaRami(t->rami);
}

int contaRami(Ramo * b) {
	if (b == NULL)
		return 0;
	else
		return contaNodi(b->child) + contaRami(b->next);
}
