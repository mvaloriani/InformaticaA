#include <stdio.h>
#define N 10

/*
Sia data una struttura dati dinamica di tipo lista
semplicemente concatenata. Ogni nodo della lista
contiene un numero intero come valore.

Si scriva la funzione che, 
dato un vettore di N numeri interi,
restituisce la lista contenente gli N elementi del vettore;
l’elemento di indice 0 va in testa alla lista, ecc.
Si scriva la funzione che stampa a terminale i 
valori contenuti nella lista in ordine
inverso rispetto a quello della lista stessa
(leggendoli dalla lista, non dal vettore).
*/
typedef struct Node {
	int val;
	struct Node* prox;
} Nodo;
typedef Nodo* lista;

lista crea(int n, int V[]);
void stampaInverso(lista lis);

int main() {
	int v[N] = { 0,1,2,3,4,5,6,7,8,9 };
	stampaInverso(crea(N, v));
	return 0;
}

lista crea(int n, int V[]) {
	lista testa;
	if (n == 0)
		return NULL;
	testa = (lista)malloc(sizeof(Nodo));//il cast può essere omesso
	testa->val = V[0];
	testa->prox = crea(n - 1, &V[1]);
//	testa->prox = crea(n - 1, V + 1);
	
//	printf("%d\n", testa->val);
//	printf("%d\n", V[0]);

	return testa;
}
void stampaInverso(lista lis) {
	if (lis == NULL)
		return;
	stampaInverso(lis->prox);
	printf("%d\n", lis->val);
}



