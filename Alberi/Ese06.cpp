/*
Si consideri la seguente definizione di un albero binario (binario=con due rami in ogni nodo):
typedef struct EL { int dato;
struct EL * left, right; } node;
typedef node * tree;
in cui dato assume sempre valori positivi.
Supponiamo che percorrendo un cammino dalla radice alle foglie si totalizzi un punteggio pari alla somma dei valori contenuti nei nodi percorsi.
Scrivere una funzione maxPunti che calcola il punteggio massimo che possiamo totalizzare percorrendo un cammino dalla radice alle foglie.
Vogliamo percorrere l’albero dalla radice ad una foglia totalizzando esattamente un certo punteggio: né far meno, né sforare. Scrivere una funzione esisteCammino che dati un albero ed un intero k, dice se esiste un cammino dalla radice ad una foglia che permette di totalizzare esattamente k punti.

*/

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

typedef struct EL {
	int dato;
	struct EL * left, right;
} node;
typedef node * tree;

int maxPunti(tree t) {
	int D, S;
	if (t == NULL)
		return 0;
	S = maxPunti(t->left);
	D = maxPunti(t->right);
	if (S > D)
		return S + t->dato;
	else
		return D + t->dato;
}

int esisteCammino(tree t, int k) {
	int D, S;
	if (t == NULL && k == 0)
		return 1;
	if (t == NULL)
		return 0;
	if (k – t->dato <0)
		return 0;
	if (t->left == NULL)
		return esisteCammino(t->right, k - t->dato);
	if (t->right == NULL)
		return esisteCammino(t->left, k - t->dato);
	return (esisteCammino(t->left, k - t->dato) ||
		esisteCammino(t->right, k - t->dato));
}
