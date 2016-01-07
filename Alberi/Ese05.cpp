/*
Si consideri la seguente definizione di un albero binario (binario=con due rami in ogni nodo):
typedef struct EL { int dato;
struct EL * left, right; } node;
typedef node * tree;
Definiamo un albero come "artussiano" se è composto solo da
nodi foglia
nodi con un solo figlio
nodi con due figli aventi lo stesso numero di discendenti
Codificare una funzione che riceve in input un albero e restituisce 1 se l’albero è "artussiano", 0 altrimenti. Nel risolvere il problema è consigliato servirsi di opportune funzioni ausiliarie.
*/


#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

typedef struct EL {
	int dato;
	struct EL * left, right;
} node;
typedef node * tree;

int contaNodi(tree t) {
	if (t == NULL)
		return 0;
	else
		return (contaNodi(t->left) +
			contaNodi(t->right)
			+ 1); /* c’è anche il nodo corrente */
}


int artussiano(tree t) {
	if (t == NULL)
		return 1;
	if (t->left == NULL && t->right == NULL)
		return 1;
	if (t->left == NULL)
		return artussiano(t->right)
		if (t->right == NULL)
			return artussiano(t->left)
			if (contaNodi(t->left) == contaNodi(t->right) &&
				artussiano(t->left) && artussiano(t->right))
				return 1;
	return 0;
}
