#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

typedef struct Node { int dato; struct Node * next; } Nodo;
typedef Nodo * Lista;

// Costruisci NODO
Lista buildNode(int word) {
	Lista lista;
	lista = (Lista)malloc(sizeof(Nodo));
	lista->dato = word;
	return lista;
}

Nodo * buildNode(int word) {
	Nodo * lista;
	lista = (Nodo *)malloc(sizeof(Nodo));
	lista->dato = word;
	return lista;
}
// Testa = 0x01 [0xa1]
// N0 [0xff]
// N1 [0x01]
// N2 [0x22]

// Inserimento in testa
Lista InserisciInTesta(Nodo* n, Lista testa) { //(Lista n, nodo* testa)
	n->next = testa;
	testa = n;
	return testa;
}
void InserisciInTestaRif(Nodo* n, Lista* PuntatoreATesta) { //(Nodo* n, Nodo** testa)
	n->next = *PuntatoreATesta;
	*PuntatoreATesta = n;
	return;
}

// Inserimento in coda
void InserisciInCoda(Nodo* n, Lista testa) { //(Lista n, nodo* testa)
	Nodo* temp = testa;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = n;
	return; // controllo se la lista è vuota all'esterno
}

void InserisciInCodaRic(Nodo* n, Lista testa) { //(Lista n, nodo* testa)
	if (testa->next != NULL)
		InserisciInCodaRic(n, testa->next);
	else
		testa->next = n;
}