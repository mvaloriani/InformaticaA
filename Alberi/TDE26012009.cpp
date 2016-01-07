/*
Si consideri la seguente definizione di un albero binario (binario=con due rami in ogni nodo):
typedef struct EL { int dato;
struct EL * left,
struct EL * right; } node;
typedef node * tree;
Codificare una funzione che riceve in input due alberi e restituisce 1 se i due alberi sono identici, 0 altrimenti. 
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


int f(tree t1, tree t2) {
	if (t1 == NULL && t2 == NULL)
		return 1;
	if (t1 == NULL || t2 == NULL)
		return 0;
	return (t1->dato == t2->dato &&
		f(t1->right, t2->right) && f(t1->left, t2->left));
}
