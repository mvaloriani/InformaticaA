/*
Un albero binario si dice isobato se tutti i cammini dalla radice alle foglie hanno la stessa lunghezza
Data la seguente definizione di albero
typedef struct EL    {	int dato;
struct EL *left;
struct EL *right;   } Node;
typedef Node *tree;
codificare una funzione che riceve in input un albero e restituisce 1 se l’albero è isobato, 0 altrimenti.
*/

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

typedef struct EL {
	int dato;
	struct EL * left;
	struct EL * right;
} node;
typedef node * tree;


int isobato(tree t) {
	if (contaProfonditaSeIsobato(t) == -1)
		return 0;
	else
		return 1;
}

int contaProfonditaSeIsobato(tree t) {
	int s, d;
	if (t == NULL)
		return 0;

	s = contaProfonditaSeIsobato(t->left);
	d = contaProfonditaSeIsobato(t->right);

	if (d == -1 || s == -1)
		return -1;
	if (d == s)
		return d + 1;
	if (d == 0)
		return s + 1;
	if (s == 0)
		return d + 1;

	return -1;//d!=s
}



int maxdepth(tree t) {
	int D, S;
	if (t == NULL)
		return 0;
	S = maxdepth(t->left);
	D = maxdepth(t->right);
	if (S > D)
		return S + 1;
	else
		return D + 1;
}

int mindepth(tree t) {
	int D, S;
	if (t == NULL)
		return 0;
	S = mindepth(t->left);
	D = mindepth(t->right);
	if (S == 0)
		return D + 1;
	if (D == 0)
		return S + 1;
	if (S < D)
		return S + 1;
	else
		return D + 1;
}

int isobato(tree t) {
	return maxdepth(t) == mindepth(t);
}
