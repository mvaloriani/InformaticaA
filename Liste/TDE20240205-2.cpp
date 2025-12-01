/*
Si scriva in C una funzione dividiListe che riceve in ingresso
una lista di interi lis e due interi s1 e s2.
La funzione dividiListe restituisce una lista di tre sottoliste,
definite come segue:
- La prima sottolista contiene tutti gli interi minori s1,
- la seconda sottolista contiene tutti gli interi da s1 a s2 compresi
- la terza sottolista tutti gli interi maggiori di s2.

Si invochi la funzione dividiListe nel main e si stampi la lista di sottoliste restituita

N.B:
- La lista di partenza non deve essere modificata.
- Si definisca un nuovo tipo idoneo per descrivere la lista di sottoliste

Se completato correttamente il programma stamperà

Lista originale:
2->4->7->21->9->11->5->1->3->4->12->6->23->11->8->12->7->11->4->100->6->22->8->89->10->4->12->22->8->89->10->4->12->16->65->1->-8->-6->4->2->---|

Sottoliste generate:
2->4->7->9->5->1->3->4->6->8->7->4->6->8->4->8->4->1->-8->-6->4->2->---|
11->12->11->12->11->10->12->10->12->16->---|
21->23->100->22->89->22->89->65->---|
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct nodo {
	int dato;
	struct nodo* next;
} Nodo;
typedef Nodo* Lista;

Lista costruisci();
Lista IIT(Lista l, int e);
Lista FL(int v[], int l);
void stampaLista(Lista lista);

/* Nuovo tipo per la lista delle tre sottoliste */
typedef struct treListe {
	Lista minori;
	Lista compresi;
	Lista maggiori;
} TreListe;

TreListe dividiListe(Lista lis, int s1, int s2);


int main() {
	int s1 = 10, s2 = 20;
	Lista Lis = costruisci();
	stampaLista(Lis);


	//INSERIRE QUI INVOCAZIONI DI FUNZIONE E STAMPE USANDO Lis, s1, s2 DEFINITI SOPRA
	TreListe ris3 = dividiListe(Lis, s1, s2);

	printf("\nSottoliste generate:\n");
	stampaLista(ris3.minori);
	stampaLista(ris3.compresi);
	stampaLista(ris3.maggiori);

	return 0;
}

/* inserisce in fondo ad una lista tramite puntatore a testa e coda */
void appendInFondo(Lista* head, Lista* tail, int valore) {
    Nodo* nuovo = (Nodo*)malloc(sizeof(Nodo));
    nuovo->dato = valore;
    nuovo->next = NULL;

    if (*head == NULL) {
        *head = nuovo;
        *tail = nuovo;
    }
    else {
        (*tail)->next = nuovo;
        *tail = nuovo;
    }
}

/* dividiListe: NON modifica la lista originale, crea nodi nuovi */
TreListe dividiListe(Lista lis, int s1, int s2) {
    TreListe risultato;
    risultato.minori = NULL;
    risultato.compresi = NULL;
    risultato.maggiori = NULL;

    /* code per tenere traccia delle code delle tre liste,
       così l'inserimento in fondo è O(1) */
    Lista tailMin = NULL;
    Lista tailComp = NULL;
    Lista tailMag = NULL;

    Lista p = lis;
    while (p != NULL) {
        if (p->dato < s1) {
            appendInFondo(&risultato.minori, &tailMin, p->dato);
        }
        else if (p->dato <= s2) {
            appendInFondo(&risultato.compresi, &tailComp, p->dato);
        }
        else {
            appendInFondo(&risultato.maggiori, &tailMag, p->dato);
        }
        p = p->next;
    }

    return risultato;
}


Lista costruisci() {
	int v[] = { 2,4,7,21,9,11,5,1,3,4,
			  12,6,23,11,8,12,7,11,4,100,
			  6,22,8,89,10,4,12,22,8,89,
			  10,4,12,16,65,1,-8,-6,4,2 }; return FL(v, 40);
}
Lista IIT(Lista l, int e) {
	Lista p = (Lista)malloc(sizeof(Nodo));
	p->dato = e; p->next = l; return p;
}

Lista FL(int v[], int l) {
	Lista lis = NULL;
	for (l = l - 1; l >= 0; l--)
		lis = IIT(lis, v[l]);
	return lis;
}

void stampaLista(Lista lis) {
	while (lis != NULL) {
		printf("%d->", lis->dato);
		lis = lis->next;
	}
	printf("---|\n");
}


