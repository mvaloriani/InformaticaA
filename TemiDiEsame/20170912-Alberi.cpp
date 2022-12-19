/*
Esercizio  6  ( 4 punti )
Si consideri la seguente definizione di un albero binario:
*/

#define N 100
typedef struct ET {
	int dati[N];
	struct ET* left, * right;
} treeNode;
typedef treeNode* tree;

/*
Si codifichi in C la seguente funzione che riceve un albero T e
un vettore V di dimensione N
int f(tree T, int V[])
e che restituisce il numero di nodi di T 
che contengono un vettore che è una permutazione di V
*/


#include <stdio.h> 
#include <string.h>
#include <stdlib.h>


int f(tree T, int V[]) {

	if (T == NULL)
		return 0;

	if (T->left == NULL && T->right == NULL)
		return permutazione(V, T->dati);

	return permutazione(T->dati, V) + f(T->left, V) + f(T->right, V);
}

int permutazione(int A[], int B[]) {

	int Temp[N];
	int t = 0;

	// A = 012355
	// B = 512034
	// T = 111110

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N && t == 0; j++) {
			if (A[i] == B[j] && Temp[j] != 1) {
				Temp[j] = 1;
				t = 1;
				//break;
			}
		}
		if (t == 0) return 0;
		t = 0;
	}
	return 1;
}

int permutazione2(int A[], int B[]) {

	int countA;
	int j, i;

	// A = 012355
	// B = 512430
	// T = 100001

	for (i = 0; i < N; i++) {
	
		countA = 0;
		for (j = 0; j < N; j++)
		{
			if (A[i] == A[j])
				countA++;
		}

		for (j = 0; j < N; j++)
		{
			if (A[i] == B[j])
				contA--;
		}

		if (countA != 0)
			return 0;
	}
	return 1;
}
