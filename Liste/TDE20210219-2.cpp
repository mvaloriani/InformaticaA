/*
Scrivere una funzione "pulisci" che, data una lista i cui elementi
sono liste di interi, elimina tutte le sottoliste che contengono valori ripetuti.
Si consiglia di utilizzare funzioni ausiliarie per inserimenti
e cancellazioni e distruzioni di liste, come illustrato a lezione e nella dispensa.

Scrivere le funzioni necessarie per svolgere l'esercizio subito
dopo il main e prima delle funzioni fornite.

Output atteso:
Lista (ogni elemento in una riga)
5 --->  4 --->  1 --->  5 --->  2 --->  7 --->  ---|
1 --->  6 --->  9 --->  1 --->  5 --->  7 --->  9 --->  0 --->  ---|
1 --->  5 --->  1 --->  1 --->  2 --->  8 --->  9 --->  0 --->  ---|
1 --->  3 --->  2 --->  4 --->  0 --->  9 --->  8 --->  6 --->  ---|
1 --->  2 --->  9 --->  8 --->  4 --->  0 --->  9 --->  0 --->  ---|
1 --->  8 --->  7 --->  8 --->  3 --->  ---|
1 --->  3 --->  4 --->  2 --->  5 --->  7 --->  9 --->  0 --->  ---|
7 --->  8 --->  9 --->  ---|

Lista dopo pulizia
1 --->  3 --->  2 --->  4 --->  0 --->  9 --->  8 --->  6 --->  ---|
1 --->  3 --->  4 --->  2 --->  5 --->  7 --->  9 --->  0 --->  ---|
7 --->  8 --->  9 --->  ---|
*/

#include<stdio.h>
#include<stdlib.h>


typedef struct EL {
	int info;
	struct EL* prox;
} ElemLista;
typedef ElemLista* SottoLista;

typedef struct ELL {
	SottoLista lista;
	struct ELL* prox;
} NodoLista;
typedef NodoLista* ListaDiListe;

SottoLista InsInFondoInt(SottoLista lista, int elem);
ListaDiListe InsInFondoLista(ListaDiListe lista, SottoLista lis);
void VisualizzaListaInt(SottoLista lista);
void VisualizzaListaDiListe(ListaDiListe lista);
ListaDiListe costruisci();
//
// TODO: PROTOTIPI DELLE FUNZIONI RICHIESTE
//
int verificaDoppi(SottoLista lis);
int countValue(SottoLista lis, int v);
void eliminaLista(SottoLista lis);
ListaDiListe pulisci(ListaDiListe lis);

int main() {
	ListaDiListe lis;
	lis = costruisci();
	printf("Lista (ogni elemento in una riga)\n");
	VisualizzaListaDiListe(lis);

	//TODO: invocazione funzione
	printf("Lista dopo pulizia\n");
	VisualizzaListaDiListe(lis);


	return 0;
}


//
// TODO: SVILUPPARE QUI LE FUNZIONI RICHIESTE
//

int countValue(SottoLista lis, int v) {
	if (lis == NULL) return 0;
	if (lis->prox == NULL) return lis->info == v ? 1 : 0;
	
	return (lis->info == v) + countValue(lis->prox, v);
}

int trova(SottoLista lis, int v) {
	if (lis == NULL) return 0;
	if (lis->info == v)
		return 1;
	return trova(lis->prox, v);
	
	//return (lis->info == v)? 1 :trova(lis->prox, v);
}

int verificaDoppi(SottoLista lis) {
	if (lis == NULL || lis->prox==NULL) return 0;
	int temp;
	do
	{
		//temp = trova(lis, lis->info); //<-- sbaglaito
		//temp = countValue(lis, lis->info);
		temp = countValue(lis->prox, lis->info);
		if (temp > 0)
			return 1;
		lis = lis->prox;
	} while (lis->prox!=NULL);
	return 0;
}

void eliminaLista(SottoLista lis) {
	if (lis == NULL) return;
	if (lis->prox != NULL)
		eliminaLista(lis->prox);
	free(lis);		
}

ListaDiListe pulisci(ListaDiListe lis) {
	if (lis == NULL) return lis;
	if (lis->prox != NULL)
		lis->prox=pulisci(lis->prox);
	if (verificaDoppi(lis->lista) == 0) 
		return lis;

	eliminaLista(lis->lista);
	ListaDiListe temp = lis->prox;
	free(lis);
	return temp;
}



ListaDiListe costruisci() {
	int M[8][10] = { 5,4,1,5,2,7,-1,-1,-1,-1,1,6,9,1,5,7,9,0,-1,-1,1,5,1,1,2,8,9,0,-1,-1,
				  1,3,2,4,0,9,8,6,-1,-1,1,2,9,8,4,0,9,0,-1,-1,1,8,7,8,3,-1,-1,-1,-1,-1,
				  1,3,4,2,5,7,9,0,-1,-1,7,8,9,-1,-1,-1,-1,-1,-1,-1 };
	int i, k; ListaDiListe ris = NULL; SottoLista temp = NULL;
	for (i = 0; i < 8; i++) {
		temp = NULL; for (k = 0; k < 10; k++)if (M[i][k] != -1)temp = InsInFondoInt(temp, M[i][k]);
		ris = InsInFondoLista(ris, temp);
	}
	return ris;
}


SottoLista InsInFondoInt(SottoLista lista, int elem) {
	SottoLista punt;
	if (lista == NULL) {
		punt = malloc(sizeof(ElemLista));
		punt->prox = NULL; punt->info = elem; return  punt;
	}
	else { lista->prox = InsInFondoInt(lista->prox, elem); return lista; }
}


ListaDiListe InsInFondoLista(ListaDiListe lista, SottoLista lis) {
	ListaDiListe punt;
	if (lista == NULL) {
		punt = malloc(sizeof(NodoLista));
		punt->prox = NULL; punt->lista = lis; return  punt;
	}
	else { lista->prox = InsInFondoLista(lista->prox, lis); return lista; }
}


void VisualizzaListaInt(SottoLista lista) {
	if (lista == NULL) printf(" ---| \n");
	else { printf(" %d ---> ", lista->info); VisualizzaListaInt(lista->prox); }
}
void VisualizzaListaDiListe(ListaDiListe lista) {
	if (lista == NULL) printf("\n");
	else { VisualizzaListaInt(lista->lista); VisualizzaListaDiListe(lista->prox); }
}
