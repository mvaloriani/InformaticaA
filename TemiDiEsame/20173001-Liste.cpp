/*Si considerino le seguenti definizioni di tipi di dati
che rappresentano una lista di visite a siti Web di cui
si registra link, data e ora della visita in ordine
cronologico(ovviamente lo stesso sito Web può essere
stato visitato più volte in momenti diversi) e
una lista di statistiche che registrano per ogni
sito il numero totale di visite*/


typedef struct { int giorno, mese, anno; } Data;
typedef struct { int ora, min, sec, milli; } Ora;

typedef struct n {
	char link[1000];
	Data d;
	Ora o;
	struct n* next;
} Visita;
typedef Visita* Visite;

typedef struct li {
	char link[1000];
	int visiteTotali;
	struct li* next;
} Statistica;
typedef Statistica* Statistiche;

/*Si codifichi in C una funzione che riceve come parametro
una lista di visite V e alloca e restituisce una lista
contenente le visite totali per tutti i siti visitati
almeno una volta nel 2016.*/

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

Statistiche calcola(Visite V) {

	Statistiche temp, VisiteTot = NULL;
	Visite V2 = V;

	if (V == NULL) return NULL;

	while (V != NULL)
	{
		if (V->d.anno == 2016) {

			temp = NULL;
			temp = Trova(VisiteTot, V->link);
			if (temp != NULL)
				temp->visiteTotali++;
			else
			{
				temp = buildNode(V->link);

				temp->next = VisiteTot;
				VisiteTot = temp;

				//InserisciInCoda(temp, VisiteTot);
			}
		}
		V = V->next;
	}

	return VisiteTot;
}

Statistiche Trova(Statistiche lista, char* link) {
	if (lista == NULL)
		return NULL;

	if (strcmp(lista->link, link)==0)
		return lista;

	return Trova(lista–>next, link);
}


Statistiche TrovaOCrea(Statistiche lista, char* link) {
	if(lista==NULL)
		return lista = buildNode(link);

	if (strcmp(lista->link, link) == 0)
		return lista;

	if (lista->next == NULL)
		return lista->next = buildNode(link);

	return Trova(lista– > next, link);
}

Statistiche buildNode(char* link) {
	Statistiche lista;
	lista = (Lista)malloc(sizeof(Statistica));
	strcpy(lista->link, link);
	lista->visiteTotali = 1;
	return lista;
}

// Inserimento in coda
void InserisciInCoda(Statistica* n, Statistiche testa) { //(Lista n, nodo* testa)
	Statistica* temp = testa;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = n;
	return; // controllo se la lista è vuota all'esterno
}



