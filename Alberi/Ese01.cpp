/*
Sia data la seguente struttura per la memorizzazione 
di alberi binari etichettati con numeri interi:

typedef struct nodo {
int info;
struct nodo *left, *right;
} NODO;

typedef NODO *tree;
Si devono scrivere due funzioni ricorsive
int sommaNodi(tree t);
int cercaMax(tree t);
delle quali, sommaNodi somma i valori delle etichette nell'albero,
mentre cercaMax cerca il valore dell'etichetta massima dell'albero.
int sommaNodi(tree t);
int cercaMax(tree t);
*/

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>


typedef struct nodo {
	int info;
	struct nodo *left, *right;
} NODO;

typedef NODO *tree;




int sommaNodi(tree t) {
	int s = 0;
	if (t == NULL)
		return 0;
	s = t->info;
	if (t->left != NULL)
		s += sommaNodi(t->left);
	if (t->right != NULL)
		s += sommaNodi(t->right);
	return s;
}

// Compatta
int sommaNodi(tree t) {
	if (t == NULL)
		return 0;
	return t->info + sommaNodi(t->left) + sommaNodi(t->right);
}

int max(int a, int b) {
	if (a>b)
		return a;
	else
		return b;
}

int max3(int a, int b, int c) {
	return max(a, max(b, c));
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

