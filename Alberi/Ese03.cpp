/*
Si consideri un albero ternario privo di dati e
rappresentato dalla seguente definizione ricorsiva:
typedef struct Elemento {
int dato;
struct Elemento * left, * center, * right; } Nodo;
typedef Nodo * Tree;
Si progetti un algoritmo ed eventualmente si codifichi una funzione C
che restituisce 1 se tutti i cammini dalla radice dell'albero
alle foglie hanno la stessa lunghezza, e restituisce 0 altrimenti.
*/
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>


typedef struct EL {
	int dato;
	struct EL* left;
	struct EL* right;
} node;
typedef node* tree;

int isobato(Tree t) {
	int foo;
	return isobatoAux(t, &foo);
}

int isobatoAux(Tree t, int* depth) {
	int dl, dc, dr, il, ic, ir;    /* 3 profondità per i rami e 3 booleani */ 
	if (t == NULL) {
		*depth = 0;                  /* Un albero vuoto è isobato di profondità 0 */
		return 1;
	}
	il = isobatoAux(t->left, &dl);  /* Controlliamo l'isobaticità dei rami    */
	ic = isobatoAux(t->center, &dc);  /* Memorizzando le (eventuali) profondità */
	ir = isobatoAux(t->right, &dr);
	if (!il || ic == 0 || ir != 1 ||
		(dl != dc && dc != 0 && dl != 0) ||
		(dc != dr && dc != 0 && dr != 0)
		)
		return 0;

	*depth = dl + 1;  /* tanto le profondità sono tutte uguali */ 

	return 1;
}


int maxdepth(tree t) {
	int D, S;
	if (t == NULL)
		return 0;

	S = maxdepth(t->left);
	C = maxdepth(t->center);
	D = maxdepth(t->right);

	if (S > D)
		return  S > C ? S + 1 : C + 1;
	else
		return D > C ? D + 1 : C + 1;

}

int mindepth(tree t) {
	int D, S;
	if (t == NULL)
		return 0;

	S = mindepth(t->left);
	C = mindepth(t->center);
	D = mindepth(t->right);

	if (S == 0 && C == 0 && D == 0)
		return 1;

	if (S == 0 && C == 0)
		return D + 1;
	if (D == 0 && C == 0)
		return S + 1;
	if (S == 0 && D == 0)
		return C + 1;

	if (S == 0)
		return (C < D) ? C + 1 : D + 1;
	if (C == 0)
		return (S < D) ? S + 1 : D + 1;
	if (D == 0)
		return (S < C) ? S + 1 : C + 1;

	if (S < D)
		return (S < C) ? S + 1 : C + 1;
	else
		return (D < C) ? D + 1 : C + 1;
}

int isobato(tree t) {
	return maxdepth(t) == mindepth(t);
}

