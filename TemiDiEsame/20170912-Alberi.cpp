/*

Esercizio  6  ( 4 punti )
Si consideri la seguente definizione di un albero ternario:
*/

#define N 100
typedef struct ET {
	int dati[N];
	struct ET* left, * right;
} treeNode;
typedef treeNode* tree;

/*
Si codifichi in C la seguente funzione che riceve un albero T e un vettore V di dimensione N
int f(tree T, int V[])
e che restituisce il numero di nodi di T che contengono un vettore che è una permutazione di V
*/


#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int f(tree T, int V[]) {

	int L = 0, R = 0;

	if (T == NULL) 
		return 0;

	if (T->left == NULL && T->right == NULL) 
		return permutazione(V, T->dati);

	return permutazione(V, T->dati) + f(T->left, V) + f(T->right, V);

}

int permutazione(int A[], int B[]) {

	int Temp[N];
	int t = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (A[i] == B[j] && Temp[j] != 1) {
				Temp[j] = 1;
				t = 1;
				break;
			}
		}

		if (t == 0) return 0;
		t = 0;
	}

	return 1;
}
