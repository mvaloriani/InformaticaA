/*
Si consideri la seguente definizione di un albero
binario (binario=con due rami in ogni nodo):
typedef struct EL { int dato;
struct EL * left,  * right; } node;
typedef node * tree;
Si scriva una funzione che prende in ingresso un albero 
binario e 
restituisce 1 se tutti i nodi godono delle proprietà 
di avere come discendenti
a sinistra solo nodi con valori più piccoli e a
destra solo nodi con valori più grandi, 0 altrimenti.

*/


#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

typedef struct EL {
	int dato;
	struct EL * left, *right;
} node;
typedef node * tree;


int max(int a, int b) {
	if (a>b)
		return a;
	else
		return b;
}

int max3(int a, int b, int c) {
	return max(a, max(b, c));
}

int min(int a, int b) {
	if (a<b)
		return a;
	else
		return b;
}

int min3(int a, int b, int c) {
	return min(a, min(b, c));
}


int cercaMax(tree t) {
	int s, d, m;
	if (t == NULL)
		return 0;//eseguita solo se da subito l’albero è vuoto
	if (t->left == NULL && t->right == NULL)
		return t->info;
	if (t->left == NULL)
		return max(t->info, cercaMax(t->right));
	if (t->right == NULL)
		return max(t->info, cercaMax(t->left));
	return max3(cercaMax(t->right), cercaMax(t->left), t->info);
}

int cercaMin(tree t) {
	int s, d, m;
	if (t == NULL)
		return 0;//eseguita solo se da subito l’albero è vuoto
	if (t->left == NULL && t->right == NULL)
		return t->info;
	if (t->left == NULL)
		return min(t->info, cercaMin(t->right));
	if (t->right == NULL)
		return min(t->info, cercaMin(t->left));
	return min3(cercaMin(t->right), cercaMin(t->left), t->info);
}


int f(tree t) {
	int max, min;
	if (t == NULL)
		return 1;

	if (t->left == NULL && t->right == NULL)
		return 1;

	if (t->left != NULL) {
		max = cercaMax(t->left);
		if (t->dato<max)
			return 0;
	}
	if (t->right != NULL) {
		min = cercaMin(t->right);
		if (t->dato>min)
			return 0;
	}

	return f(t->left) && f(t->right);
}

